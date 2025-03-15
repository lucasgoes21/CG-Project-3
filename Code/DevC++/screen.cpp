#include <iostream>
#include <cstring>
#include <cassert>
#include "screen.h"

#include <SDL2/SDL.h>

Screen::Screen(const char *n, const Color bg, int w, int h): width(w), height(h), bgColor(bg) {
	title = new char[strlen(n) + 1];
	assert(title != 0);
	strcpy(title, n);
	
	pitch = width * sizeof(Uint32);
	
	// Criar uma matriz de pixels
    numPixels = width * height;
    pixels = new Uint32[numPixels];
	
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    //Limpa a tela com a cor de fundo
    for (int i = 0; i < numPixels; i++) {
        pixels[i] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, bg.getR(), bg.getG(), bg.getB());
    }
}

void Screen::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
    pixels[y * width + x] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, r, g, b);
}

void Screen::setPixel(int x, int y, Color c) {
    pixels[y * width + x] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, c.getR(), c.getG(), c.getB());
}

void Screen::update() {
	updateScreen();
}

void Screen::setBackColor(Color c) {
	bgColor = c;
	
	for (int i = 0; i < numPixels; i++) {
        pixels[i] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, c.getR(), c.getG(), c.getB());
    }
}

Screen::~Screen() {
	delete [] pixels;
	delete [] title;
	
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
	SDL_Quit();
}


void Screen::run(Picture &obj) {
	bool running = true;
	
	while(running) {
		// captura eventos
		SDL_Event event;
    	if (SDL_PollEvent(&event)) {
            // Captura evento de clicar em botão para fechar
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
    	}
    	
    	if (running) {
    		// preencha a tela com a cor de fundo
    		setBackColor(bgColor);
           
    		// gera o desenho
			obj.draw(*this);
            
    		// aplica o antialiasing
       	 	gaussianFilter();
        
    		// atualiza a tela 
    		update();
    	}
	}
}

void Screen::filter(double mask[3][3]) {
	//Cria imagem auxiliar e faz o padding
    Uint32* auxPixels = new Uint32[(width + 2) * (height + 2)];
	
	//inicializa
	for (int x = 0; x < width + 2; x++) {
		auxPixels[x] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 0, 0, 0);
		auxPixels[(width + 2) * (height - 1) + x] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 0, 0, 0);
    }
    
    for (int y = 0; y < height + 2; y++) {
		auxPixels[y * (width + 2)] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 0, 0, 0);
		auxPixels[y * (width + 2) + (width + 1)] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 0, 0, 0);
    }
    
    for (int x = 0; x < width; x++)
       for (int y = 0; y < height; y++)
          auxPixels[(y+1) * (width + 2) + (x+1)] = pixels[y * width + x];
          
    Uint8 r, g, b;
	for (int x = 0; x < width; x++)
       for (int y = 0; y < height; y++) {
       	  	double R = 0, G = 0, B = 0; //totais
       	  	for (int k = 0; k < 3; k++)
       	    	for (int l = 0; l < 3; l++) {
       	    		SDL_GetRGB(auxPixels[(y+l) * (width + 2) + (x+k)], SDL_GetWindowSurface(window)->format, &r, &g, &b);
       	    		R += r * mask[k][l];
       	    		G += g * mask[k][l];
       	    		B += b * mask[k][l];
       	    	}
          	pixels[y * width + x] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, (Uint8)R, (Uint8)G, (Uint8)B);
       }
    
    delete [] auxPixels;
}

void Screen::meanFilter() {
    double v = 1.0/9.0;
	double mask[3][3] = {
		{v, v, v}, 
		{v, v, v},
		{v, v, v}};
		
	filter(mask);
}

void Screen::gaussianFilter() {	
	double mask[3][3] = {
		{1.0/16, 1.0/8, 1.0/16}, 
		{1.0/8,  1.0/4, 1.0/8},
		{1.0/16, 1.0/8, 1.0/16}};
	
	filter(mask);
}

void Screen::updateScreen() {
 /*   SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(pixels, width, height, 32, pitch, 0xff0000, 0xff00, 0xff, 0);
    if (surface == nullptr) {
        std::cerr << "Failed to create surface: " << SDL_GetError() << std::endl;
        return;
    }
    
    SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
    SDL_BlitSurface(surface, nullptr, windowSurface, nullptr);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(surface);
*/    
    SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(pixels, width, height, 32, pitch, 0xff0000, 0xff00, 0xff, 0);
	if (surface == nullptr) {
    	std::cerr << "Failed to create surface: " << SDL_GetError() << std::endl;
    	return;
	}

	// Create a new surface to hold the flipped pixels
	SDL_Surface* flippedSurface = SDL_CreateRGBSurface(0, width, height, 32, 0xff0000, 0xff00, 0xff, 0);
	if (flippedSurface == nullptr) {
    	std::cerr << "Failed to create surface: " << SDL_GetError() << std::endl;
    	SDL_FreeSurface(surface);
    	return;
	}

	// Flip the pixels vertically
	Uint32* srcPixels = (Uint32*)surface->pixels;
	Uint32* dstPixels = (Uint32*)flippedSurface->pixels;
	int pitch = surface->pitch / 4;
	for (int y = 0; y < height; y++)
    	for (int x = 0; x < width; x++) 
        	dstPixels[(height - 1 - y) * pitch + x] = srcPixels[y * pitch + x];

	// Blit the flipped surface to the window surface
	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	SDL_BlitSurface(flippedSurface, nullptr, windowSurface, nullptr);
	SDL_UpdateWindowSurface(window);

	// Free the surfaces
	SDL_FreeSurface(surface);
	SDL_FreeSurface(flippedSurface);
}