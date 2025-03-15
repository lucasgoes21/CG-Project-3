#ifndef SCALE_WITH_FIXED_POINT
#define SCALE_WITH_FIXED_POINT

#include "combinedTransformation.h"
#include "point3D.h"
#include "scale3D.h"
#include "translation3D.h"

class ScaleWithFixedPoint: public CombinedTransformation {
    public:
	ScaleWithFixedPoint(Point3D p, double Sx, double Sy, double Sz): CombinedTransformation({}) {
		add(new Translation3D(-p.getX(), -p.getY(), -p.getZ()));
		add(new Scale3D(Sx, Sy, Sz));
		add(new Translation3D(p.getX(), p.getY(), p.getZ()));
		combine();
	}
};
        
#endif