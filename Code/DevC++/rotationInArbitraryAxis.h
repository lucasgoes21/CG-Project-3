#ifndef ROTATION_IN_ARBITRARY_AXIS_H
#define ROTATION_IN_ARBITRARY_AXIS_H

#include <cmath>
#include "combinedTransformation.h"
#include "point3D.h"
#include "rotation3D.h"
#include "translation3D.h"
#include "axis3D.h"

class RotationInArbitraryAxis: public CombinedTransformation {
	public:
    RotationInArbitraryAxis(Point3D A, Point3D B, double theta):CombinedTransformation() {      
    	add(new Translation3D(-A.getX(), -A.getY(), -A.getZ()));
        Axis3D V(B.getX() - A.getX(), B.getY() - A.getY(), B.getZ() - A.getZ());
        Axis3D u = V.getUnityVector();
        double d = sqrt(pow(u.getValue(1),2) + pow(u.getValue(2),2));
        double alpha = acos(u.getValue(2) / d);     
        add(new Rotation3D(alpha, 'x'));
        double beta = acos(d);
        add(new Rotation3D(beta, 'y'));
        add(new Rotation3D(theta, 'z'));
        add(new Rotation3D(-beta, 'y'));
        add(new Rotation3D(-alpha, 'x'));
        add(new Translation3D(A.getX(), A.getY(), A.getZ()));
        combine();
	}
};
#endif