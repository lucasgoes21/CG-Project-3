#include "activeEdgeTable.h"

// compara por X
bool compareX (const EdgeInfo * first, const EdgeInfo * second)
{
	return (first->getX() < second->getX());
}

void ActiveEdgeTable::extend(const list<EdgeInfo *> &edges) {
	AET.insert(AET.end(), edges.begin(), edges.end());
}

void ActiveEdgeTable::sort() {
	AET.sort(compareX);
	it = AET.begin();
}

bool ActiveEdgeTable::getOneBlockLimits(double *xI, double *xF) {
	if (it != AET.end()) {
		*xI = (*it)->getX();
		++it;
		*xF = (*it)->getX();
	    ++it;
	    
	    return true;
	}
	
	return false;
}

void ActiveEdgeTable::updateXValues() {
	for (it = AET.begin(); it != AET.end(); ++it) 
		(*it)->updateX();
}

void ActiveEdgeTable::removeEdgesByYMax(int yMax) {
	for (it = AET.begin(); it != AET.end(); ++it) {
		if ((*it)->getYMax() == yMax)
			AET.erase(it);
    }
}

void ActiveEdgeTable::print() const {
	list<EdgeInfo *>::const_iterator it2;
	
	for (it2 = AET.begin(); it2 != AET.end(); ++it2) {
		(*it2)->print();
    }
}