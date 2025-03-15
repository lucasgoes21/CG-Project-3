#include "point2D.h"
#include <cmath>
Point2D::Point2D(double xx , double yy, Color c):Primitive("Point2D"), x(xx), y(yy), color(c) {
}

Point2D::Point2D(const Point2D &p):Primitive("Point2D") {
	x = p.x;
	y = p.y;
	color = p.color;
}

void Point2D::draw(Screen &screen) const{
	screen.setPixel(x, y, color);
}
Point2D * Point2D::transform(GeometricTransformation *T) {
	
	Point2D *p = new Point2D(x,y,color);
	
    Point2D *point = p;
    //vector<double,4> point(item.x, item.y, 0, 1]).T
    double v[4] = {point->getX(), point->getY(), 0, 1};
    double res[4];
    for (int i = 0; i < 4; i++) {
        res[i] = 0;
        for (int k = 0; k < 4; k++)
        res[i] += T->getValue(i,k) * v[k];
    }
    
    Point2D *p2 = new Point2D(round(res[0]), round(res[1]),point->getColor());
    
    return p2;


}