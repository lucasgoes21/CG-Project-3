#ifndef SCALE3D_H
#define SCALE3D_H

#include "geometricTransformation.h"

class Scale3D : public GeometricTransformation {
    public:
        // construtor da Classe
        Scale3D(double Sx, double Sy, double Sz)
            : GeometricTransformation({
                {Sx, 0, 0, 0},
                {0, Sy, 0, 0},
                {0, 0, Sz, 0},
                {0, 0, 0, 1}
            }) {}
};

#endif