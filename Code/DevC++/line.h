#ifndef LINE_H
#define LINE_H

#include "primitive.h"
#include "color.h"
#include "point2D.h"

class Line: public Primitive {
	private:
		Point2D p1;
		Point2D p2;
		Color color;
		void DDA(Screen &) const;
		void bresenham(Screen &) const;
	public:
		Line(Point2D, Point2D, Color=WHITE);
		virtual void draw(Screen &) const;
		void setP1(const Point2D p) { p1 = p; };
		void setP2(const Point2D p) { p2 = p; };
		Point2D getP1() const { return p1; };
		Point2D getP2() const { return p2; };
		void setColor(const Color c) {color = c; }
		Color getColor() const { return color; }
};

#endif