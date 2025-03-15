#include <iterator>
#include "picture.h"

void Picture::add(Primitive *p) {
	listOfPrimitives.push_back(p);
}

void Picture::draw(Screen &screen) {
	list<Primitive *>::iterator it;
    for (it = listOfPrimitives.begin(); it != listOfPrimitives.end(); ++it)
    	(*it)->draw(screen);
}