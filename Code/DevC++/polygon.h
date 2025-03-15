#ifndef POLYGON_H
#define POLYGON_H

#include <list>
#include "primitive.h"
#include "screen.h"
#include "point2D.h"
#include "color.h"
#include "geometricTransformation.h"

using std::list;

class Polygon: public Primitive {
	private:
		list<Point2D *> listOfPoints;
		bool showEdges;
		Color edgeColor;
		bool isFilled;
		Color fillColor;
		void scanline (Screen &) const;
		
	public:
		Polygon(bool = true, Color = RED, bool = true, Color = WHITE);
		virtual void draw(Screen &) const;
		void addVertex(Point2D *);
		void setShowEdges(bool v) { showEdges = v; };
		void setEdgeColor(Color c) { edgeColor = c; }; 
		void setIsFilled(bool v) { isFilled = v; };
		void setFillColor(Color c) { fillColor = c; };
		bool getShowEdges() const { return showEdges; };
		Color getEdgeColor() const { return edgeColor; };
		bool getIsFilled() const { return isFilled; };
		Color getFillColor() const { return fillColor; };
		Polygon * transform(GeometricTransformation *);
};

#endif