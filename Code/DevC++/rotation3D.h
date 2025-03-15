#ifndef ROTATION3D_H
#define ROTATION3D_H

#include "geometricTransformation.h"

class Rotation3D : public GeometricTransformation {
    private:
        char _axis;
    public:
        // construtor da Classe
        Rotation3D(double theta, char axis) : GeometricTransformation({}),_axis(axis) {
            if (_axis == 'z') {
                setMatrix({
                    {cos(theta), -sin(theta), 0, 0},
                    {sin(theta), cos(theta), 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}
                });
            }
            else if (_axis == 'x') {
                setMatrix({
                    {1, 0, 0, 0},
                    {0, cos(theta), -sin(theta), 0},
                    {0, sin(theta), cos(theta), 0},
                    {0, 0, 0, 1}
                });
            }
            else if (_axis == 'y') {
                setMatrix({
                    {cos(theta), 0, sin(theta), 0},
                    {0, 1, 0, 0},
                    {-sin(theta), 0, cos(theta), 0},
                    {0, 0, 0, 1}
                });
            }
            else {
                cout << "Eixo nao definido!" << endl;
                exit(0);
            }
        }
};

#endif