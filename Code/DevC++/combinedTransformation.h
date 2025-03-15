#ifndef COMBINED_TRANSFORMATION_H
#define COMBINED_TRANSFORMATION_H

#include <stack>
#include "geometricTransformation.h"

class CombinedTransformation : public GeometricTransformation {
    private:
        stack<GeometricTransformation*> stackOfTransformations;
    public:
        CombinedTransformation() : GeometricTransformation({}) {}
        void add(GeometricTransformation* matrix);
        void combine();
};
#endif