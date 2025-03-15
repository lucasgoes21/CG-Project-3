#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "screen.h"
#include "point2D.h"
#include "color.h"
#include "line.h"
#include "picture.h"
#include "circle.h"
#include "polygon.h"
#include "translation3D.h"
#include "combinedTransformation.h"
#include "rotationInArbitraryAxis.h"
#include "scaleWithFixedPoint.h"
#include "windowToViewportTransformation.h"
#include "picture5.h"

int main(int argc, char *argv[])
{
    /*
	
	Screen screen("Aula 3", BLACK, 700, 700);

    Point2D p3(350, 450);

    Picture p;
    
    // Telhado
    Line l1(Point2D(350, 50), Point2D(50, 250), RED);
    Line l2(Point2D(50, 250), Point2D(650, 250), RED);
    Line l3(Point2D(650, 250), Point2D(350, 50), RED);
        
    // Parede
    Line l4(Point2D(50, 250), Point2D(50, 650), GREEN);
    Line l5(Point2D(50, 650), Point2D(650, 650), GREEN);
    Line l6(Point2D(650, 650), Point2D(650, 250), GREEN);
        
    Circle circ(p3, 150, BLUE);
        
    // Insere primitivas na lista
    p.add(&l1);
    p.add(&l2);
    p.add(&l3);
    p.add(&l4);
    p.add(&l5);
    p.add(&l6);
    p.add(&circ);
        
    screen.run(p);
    */
    
    // Aula - Preenchimento de Polígonos
    /*Screen screen2("Aula 4", BLACK, 700, 700);

	Polygon pol(true, RED, true, WHITE);
	Point2D v1(20,30,GREEN);
	Point2D v2(70,10,GREEN);
	Point2D v3(130,50,GREEN);
	Point2D v4(130,110,GREEN);
	Point2D v5(70,70,GREEN);
	Point2D v6(20,90,GREEN);
	
	pol.addVertex(&v1);
	pol.addVertex(&v2);
	pol.addVertex(&v3);
	pol.addVertex(&v4);
	pol.addVertex(&v5);
	pol.addVertex(&v6);
	
	Picture p2;
	p2.add(&pol);
	
	screen2.run(p2);*/
	
	//Aula 05 - Transformações
	Screen screen2("Aula 5", WHITE, 710, 710);
		
	Picture5 pic;
	
	screen2.run(pic);

    return 0;
}