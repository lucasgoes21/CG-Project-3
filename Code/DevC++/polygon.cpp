#include <iterator>
#include <iostream>
#include <cmath>
#include "polygon.h"
#include "line.h"
#include "edgeTable.h"
#include "activeEdgeTable.h"

Polygon::Polygon(bool showE, Color edgeC, bool fill, Color fillC):Primitive("Polygon"), showEdges(showE), edgeColor(edgeC), isFilled(fill), fillColor(fillC) {
	
}

void Polygon::draw(Screen &screen) const {
	if (listOfPoints.size() < 3) {
		std::cout << "Nao forma polígono. Menos de 3 vértices.\n";
        return;
	}
            
    // Desenha arestas se desejar
    if (isFilled)
        scanline(screen);
        
    if (showEdges) {
    	list<Point2D *>::const_iterator it;
    	it = listOfPoints.begin();
    	for (int i = 0; i < listOfPoints.size() - 1; i++, ++it) {
    		Point2D *pI = *it;
    		Point2D *pF = *(next(it));
    		
    		Line line = Line(*pI, *pF, edgeColor);
    		line.draw(screen);
		}
    	
    	it = prev(listOfPoints.end());
    	Point2D *pI = *it;
    	std::cout << "I(" << pI->getX() << ", " << pI->getY() << ")\n";
    	it = listOfPoints.begin();
    	Point2D *pF = *it;
    	std::cout << "I(" << pF->getX() << ", " << pF->getY() << ")\n";
    	Line line = Line(*pI, *pF, edgeColor);
        line.draw(screen);
        
        for (it = listOfPoints.begin(); it != listOfPoints.end(); ++it)
        	(*it)->draw(screen);
	}
}

void Polygon::addVertex(Point2D *p) {
	listOfPoints.push_back(p);
}

void Polygon::scanline (Screen & screen) const {
	EdgeTable ET(listOfPoints);
	
	ActiveEdgeTable AET;
	
	int y = ET.getYMin();
	
    // Laço principal
    while (y <= ET.getYMax()) {
        //# Move a lista y na ET para AET (ymin = y), mantendo a AET ordenada em x
        AET.extend(ET.getList(y));
        //ET.clearList(y);
        AET.sort();
              
        // Desenhe os pixels do bloco na linha de varredura y, 
        // usando os pares de coordenadas x da AET (cada dois nós definem um bloco)
        double xI, xF;
        while (AET.getOneBlockLimits(&xI, &xF)) {
        	for (int x = ceil(xI); x <= floor(xF); x++)	
                screen.setPixel(x, y, fillColor);
        }
		 
        //Atualiza o valor de y para a próxima linha de varredura
        y = y + 1;
        
        // Remova as arestas que possuem ymax = y da AET
        AET.removeEdgesByYMax(y);
            
        // Para cada aresta na AET, atualize x = x + 1/m
        AET.updateXValues();
    }
}

Polygon * Polygon::transform(GeometricTransformation *T) {
	Polygon *p = new Polygon(showEdges, edgeColor, isFilled, fillColor);
	list<Point2D *>::const_iterator it;
    for (it = listOfPoints.begin(); it != listOfPoints.end(); ++it) {
    	Point2D *point = *it;
        //vector<double,4> point(item.x, item.y, 0, 1]).T
        double v[4] = {point->getX(), point->getY(), 0, 1};
        double res[4];
        for (int i = 0; i < 4; i++) {
        	res[i] = 0;
        	for (int k = 0; k < 4; k++)
        		res[i] += T->getValue(i,k) * v[k];
    	}
        
        p->addVertex(new Point2D(round(res[0]), round(res[1]),point->getColor()));
	}
        
    return p;
}