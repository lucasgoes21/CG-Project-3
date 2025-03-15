#include <cmath>
#include "line.h"

Line::Line(Point2D _p1, Point2D _p2, Color c):Primitive("Line"), p1(_p1), p2(_p2), color(c) {
}

void Line::draw(Screen &screen) const{
	DDA(screen);
	//bresenham(screen);
}

void Line::DDA(Screen &screen) const{ 
	// Definição e Inicialização de Variáveis locais
    int dx = 0, dy = 0, k = 0;
    double x_inc = 0, y_inc = 0;
    double x = 0, y = 0;
	int iter = 0;
    
    // Define os deslocamentos nas direções x e y
    dx = p2.getX() - p1.getX();
    dy = p2.getY() - p1.getY();
    
    // Define qual a direção de incremento fixo
    if (abs(dx) > abs(dy))
        iter = abs(dx);
    else
        iter = abs(dy);
        
    // Define os incrementos para cada direção
    x_inc = dx/(double)iter;
    y_inc = dy/(double)iter;

    // Define o ponto inicial
    x = p1.getX();
    y = p1.getY();

    // Desenha o ponto inicial na tela
    screen.setPixel(round(x), round(y), color);

    // Geração e renderização dos pontos seguintes da linha
    for (k=1; k < iter; k++) {
        // Gera o próximo ponto
        x = x + x_inc;
        y = y + y_inc;
            
        // Desenha o ponto
        screen.setPixel(round(x), round(y), color);
    }
}

void Line::bresenham(Screen &screen) const { 
	// Definição e inicialização de variáveis locais
	int dx = 0, dy = 0, d = 0;
	int incrE = 0, incrNE = 0;
	int x = 0, y = 0, xFinal = 0;

	// Define os deslocamentos absolutos nas direções x e y
	dx = abs(p2.getX() - p1.getX());
	dy = abs(p2.getY() - p1.getY());

	// Define o d de teste inicial
	d = 2 * dy - dx;

	// Define os incrementos nas direções x e y
	incrE = 2 * dy;
	incrNE = 2 * (dy - dx);

	// Troca a ordem dos pontos em caso de segundo ponto à esquerda de primeiro ponto
	if (p1.getX() > p2.getX()) {
    	x = p2.getX();
    	y = p2.getY();
    	xFinal = p1.getX();
	}
	else {
    	x = p1.getX();
    	y = p1.getY();
    	xFinal = p2.getX();
	}

	// Desenha o ponto inicial na tela
	screen.setPixel(x, y, color);

	// Gera e renderiza os pontos seguintes da linha
	while (x < xFinal) {
    	// Gera o próximo ponto
    	x = x + 1;

    	if (d < 0)
        	d = d + incrE;
    	else {
        	y = y + 1;
        	d = d + incrNE;
    	}

    	// Desenha o próximo ponto
    	screen.setPixel(x, y, color);
	}
}