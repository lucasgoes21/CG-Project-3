#include <iterator>
#include <iostream>
#include "edgeTable.h"

using std::cout;

EdgeTable::EdgeTable(const list<Point2D *> &listOfPoints) {
	list<Point2D *>::const_iterator it;
	it = listOfPoints.begin();
	
	//Define o maior valor de y, para a varredura de baixo para cima
	yMax = (*it)->getY();
	yMin = yMax;
	for(it = next(it); it != listOfPoints.end(); ++it) {
		int y = (*it)->getY();
		if (y > yMax)
			yMax = y;
		if (y < yMin)
			yMin = y;
	}
	
	//Cria tabela de arestas
	table = new list<EdgeInfo *>[yMax + 1];
	
	it = listOfPoints.begin();
    for (int i = 0; i < listOfPoints.size() - 1; i++, ++it) {
    	Point2D *pI = *it;
    	Point2D *pF = *(next(it));
    	
    	//std::cout << "I(" << pI->getX() << ", " << pI->getY() << ")\n";
    	//std::cout << "F(" << pF->getX() << ", " << pF->getY() << ")\n";
    	
		//exclui arestas horizontais
		if (pI->getY() - pF->getY() != 0) {
			EdgeInfo *edge = new EdgeInfo(*pI, *pF);
			add(edge);
			edge->print();
	    }
	}
    
	//Fecha o polígono	
    it = prev(listOfPoints.end());
    Point2D *pI = *it;
    //std::cout << "I(" << pI->getX() << ", " << pI->getY() << ")\n";
    it = listOfPoints.begin();
    Point2D *pF = *it;
    //std::cout << "I(" << pF->getX() << ", " << pF->getY() << ")\n";
    //exclui arestas horizontais
	if (pI->getY() - pF->getY() != 0) {
		EdgeInfo *edge = new EdgeInfo(*pI, *pF);
		add(edge);
	}
	
	//print()
}

EdgeTable::~EdgeTable() {
	for (int i = 0; i <= yMax; i++) {
		
		list<EdgeInfo *>::const_iterator it;
		for (it = table[i].begin(); it != table[i].end(); ++it) {
			EdgeInfo *temp = *it;
			delete temp;
		}
    }

	delete [] table;
}

void EdgeTable::add(EdgeInfo *edge) {
	table[edge->getYMin()].push_back(edge);
}

void EdgeTable::print() const {
	std::cout << "ymin = " << yMin << std::endl;
	std::cout << "ymax = " << yMax << std::endl;
	
	for (int i = yMin; i <= yMax; i++) {
		std::cout << "y = " << i << std::endl;
		list<EdgeInfo *>::const_iterator it;
		for (it = table[i].begin(); it != table[i].end(); ++it)
			(*it)->print();
	}
}

const list<EdgeInfo *> & EdgeTable::getList(int n) const {
	if (n <= yMax) 
		return table[n];
}

void EdgeTable::clearList(int n) {
	if (n <= yMax) 
		table[n].clear();
}