#include "edgeInfo.h"

EdgeInfo::EdgeInfo(Point2D initialPoint, Point2D finalPoint) {
        if (initialPoint.getY() <= finalPoint.getY()) {
            yMax = finalPoint.getY();
            x = initialPoint.getX(); // x corrente, inicialmente x in Ymin
            yMin = initialPoint.getY();
        } else {
            yMax = initialPoint.getY();
            x = finalPoint.getX(); // x corrente, inicialmente x in Ymin
            yMin = finalPoint.getY();
        }
        inverseOfAngularCoefficient = (finalPoint.getX() - initialPoint.getX())
									  / (finalPoint.getY() - initialPoint.getY());
    }

void EdgeInfo::updateX() {
    x += inverseOfAngularCoefficient;
}

void EdgeInfo::print() const {
	std::cout << "x = " << x << ", yMin = " << yMin << ", yMax = " << yMax << ", 1/m = " << inverseOfAngularCoefficient << std::endl;
}
