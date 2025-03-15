#ifndef EDGE_INFO_H
#define EDGE_INFO_H

#include "Point2D.h"

class EdgeInfo {
private:
    int yMax;
    int yMin;
    double x;
    double inverseOfAngularCoefficient;

public:
    EdgeInfo(Point2D, Point2D);
    int getYMax() const { return yMax; };
    void setYMax(int v) { yMax = v; };
    int getYMin() const { return yMin; };
    void setYMin(int v) { yMin = v; };
    double getX() const { return x; };
    void setX(double v) { x = v; };
    void updateX();
    void print() const;
};

#endif