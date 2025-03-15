#include "picture5.h"
#include "circle.h"
#include "line.h"
#include "polygon.h"
#include "point2D.h"
#include "rotationInArbitraryAxis.h"
#include "translation3D.h"
#include "rotation3D.h"
#include "scale3D.h"
#include "scaleWithFixedPoint.h"
Polygon *a;
Polygon *bal;
int count2 =0;
int count3 =0;
Point2D *z1, *z2, *z3;
Point2D *u1, *u2, *u3;
Point2D *b1;


Circle *circ2;



Picture5::Picture5() {
	//l1 = new Line(Point2D(0, 350), Point2D(700, 350), RED);
    //l2 = new Line(Point2D(350, 0), Point2D(350, 700), RED);

    
    
    b1 = new Point2D(360,170);
    circ2 = new Circle(*b1,10,BLUE);
    
    
    pol = new Polygon(true, RED, true, Color(255, 255, 255));
    p1 = new Point2D(350, 350, BLACK);
    pol->addVertex(p1);
    p2 = new Point2D(250, 350, BLACK);
    pol->addVertex(p2);
    p3 = new Point2D(250, 350, BLACK);
    pol->addVertex(p3);
    
    pol21 = new Polygon(true, BLACK, true, Color(255, 255, 255));
    u1 = new Point2D(250, 350, BLACK);
    pol21->addVertex(u1);
    u2 = new Point2D(170, 400, BLACK);
    pol21->addVertex(u2);
    u3 = new Point2D(170, 400, BLACK);
    pol21->addVertex(u3);
    
    
    a = new Polygon(true, BLACK, true, Color(255, 255, 255));
    z1 = new Point2D(170, 400, BLACK);
    a->addVertex(z1);
    z2 = new Point2D(150, 380, BLACK);
    a->addVertex(z2);
    z3 = new Point2D(150, 380, BLACK);
    a->addVertex(z3);
    
    
    
    
}

Picture5::~Picture5() {
	delete l1;
	delete l2;
	delete p1, p2, p3;
	delete pol;
}

void Picture5::draw(Screen &screen){
	RotationInArbitraryAxis T(Point3D(p1->getX(), p1->getY(), 0, RED), Point3D(p1->getX(), p1->getY(), 1, RED), M_PI * count / 180);
	RotationInArbitraryAxis T3(Point3D(u1->getX(), u1->getY(),0, RED), Point3D(u1->getX(), u1->getY(), 1, RED), M_PI * count2 / 180);
	RotationInArbitraryAxis T2(Point3D(u1->getX(), u1->getY(),0, RED), Point3D(u1->getX(), u1->getY(), 1, RED), M_PI * count3 / 180);
    
    
    Circle circ(*b1, 20, BLUE);
    circ2 = &circ;
    
    Polygon *pol22, *pol2;
    Polygon *a2;
    
    count += 8;
    count2 += 8;
    count3 += 8;
    
    
    
    
    if (count >= 90){
    	count = 90;
    	if(count2 >= 120){
    	count2 = 120;
    		if (count3 >= 160){
    			count3 = 0;
    			count2 = 0;
    			count = 0;
    			b1 = new Point2D(360,170);
    			circ2 = new Circle(*b1,10,BLUE);
			}	
		}
    	
	}
    	
      
    pol2 = pol->transform(&T);

    if(count2 >= 90 && count2 <= 120){
    	
    	
    	pol22 = pol21->transform(&T3);
    	a2 = a->transform(&T3);
    	if(count == 90){
    		Translation3D teste(100,-100,0);
    		pol22 = pol22->transform(&teste);
			a2 = a2->transform(&teste);	    	
		}
	}
	if(count2 <= 90){
		
		pol22 = pol21->transform(&T);
    	a2 = a->transform(&T);
	}
	if(count3 > 120){
		
		Translation3D test(80,50,0);
		b1 = b1->transform(&test);
		
		circ2 = new Circle(*b1,20,BLUE);	
	}
	if(count3 >= 159){
		
	}
    
    
	  
    clear();
    add(circ2);
	add(a2);
	add(pol22);
	add(pol2);
	
	Picture::draw(screen);
	
	delete pol2;
}