#ifndef PICTURE_5_H
#define PICTURE_5_H

#include <list>
#include "picture.h"
#include "screen.h"
#include "line.h"
#include "polygon.h"
#include "point2D.h"


using std::list;

class Screen;

class Picture5: public Picture {
	private:
		double count = 0;
		Line *l1, *l2;
		Polygon *pol, *pol21;
		Point2D *p1, *p2, *p3;

		
	public:
		Picture5();
		~Picture5();
		virtual void draw(Screen &screen);
};
#endif