#ifndef TRANSLATION3D_H
#define TRANSLATION3D_H

#include "geometricTransformation.h"

class Translation3D : public GeometricTransformation {
    public:
        // construtor da Classe
        Translation3D(double Tx, double Ty, double Tz)
            : GeometricTransformation({
                {1, 0, 0, Tx},
                {0, 1, 0, Ty},
                {0, 0, 1, Tz},
                {0, 0, 0, 1}
            }) {}
};

#endif