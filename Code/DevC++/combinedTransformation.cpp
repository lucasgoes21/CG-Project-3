#include "combinedTransformation.h"

void CombinedTransformation::add(GeometricTransformation* matrix) {
    stackOfTransformations.push(matrix);
}

void CombinedTransformation::combine() {
    while (stackOfTransformations.size() > 1) {
        GeometricTransformation *m2 = stackOfTransformations.top();
        stackOfTransformations.pop();
        GeometricTransformation *m1 = stackOfTransformations.top();
        stackOfTransformations.pop();
        vector<vector<double>> resultMatrix(4, vector<double>(4));
        for (int i = 0; i < 4; i++) 
            for (int j = 0; j < 4; j++) {
                double sum = 0;
                for (int k = 0; k < 4; k++) 
                    sum += m2->getValue(i,k) * m1->getValue(k,j);
                    
                resultMatrix[i][j] = sum;
            }
        
        delete m2;
        delete m1;
                	
        stackOfTransformations.push(new GeometricTransformation(resultMatrix));
    }    
        
    // Retira o item restante da pilha    
    // Esta é a matrix combinada
    GeometricTransformation *m = stackOfTransformations.top();
    setMatrix(m->getMatrix());
    stackOfTransformations.pop();
    
    delete m;
}