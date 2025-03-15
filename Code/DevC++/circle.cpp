#include <cmath>
#include <iostream>
#include "circle.h"

Circle::Circle(Point2D p, int r, Color c):Primitive("Circle"), center(p), radius(r), color(c) {
}

//Usando o algoritmo de Bresenham
void Circle::draw(Screen &screen) const {
    // Definição e Inicialização de Variáveis locais      
	//Coniderando a circunferência ao redor da origem, mas renderizada transladada
    int x = 0;          // x inicial
    int y = radius;		// y inicial
    int d = 1 - radius;   // d de teste inicial

    // Desenha os pontos inicias de cada quadrante
	drawCirclePoints(x, y, screen);
        
    // Gera os novos pontos e os renderiza
    while (x < y) {         
        if (d < 0)   // Direção E
            d = d + 2 * x + 3;
        else {       // Direção SE
            d = d + 2 * (x - y) + 5;
            y = y - 1;
    	}
		
		x = x + 1;
		
        drawCirclePoints(x, y, screen);
	}
}
            
void Circle::drawCirclePoints(int x, int y, Screen &screen) const {
    int xCenter = center.getX();
    int yCenter = center.getY();
    screen.setPixel(xCenter + x, yCenter + y, color);
    screen.setPixel(xCenter + y, yCenter + x, color);
    screen.setPixel(xCenter + y, yCenter - x, color);
    screen.setPixel(xCenter + x, yCenter - y, color);
    screen.setPixel(xCenter - x, yCenter - y, color);
    screen.setPixel(xCenter - y, yCenter - x, color);
    screen.setPixel(xCenter - y, yCenter + x, color);
    screen.setPixel(xCenter - x, yCenter + y, color);	
}