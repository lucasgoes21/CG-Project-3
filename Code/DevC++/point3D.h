#ifndef POINT3D_H
#define POINT3D_H

#include "point2D.h"

class Point3D: public Point2D {
	private:
		double z;
		
	public:
		Point3D(double _x = 0, double _y = 0, double _z = 0, Color _c=WHITE):Point2D(_x, _y, _c),z(_z) {};
//		Point3D(const Point3D &);
		virtual void draw(Screen &) const{};
		void setZ(double zz) { z = zz; };
		double getZ() const { return z; };
};
#endif