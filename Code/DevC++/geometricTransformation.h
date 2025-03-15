#ifndef GEOMETRIC_TRANSFORMATION_H
#define GEOMETRIC_TRANSFORMATION_H

#include <vector>
#include <iostream>

using namespace std;

class GeometricTransformation {
    private:
        vector<vector<double>> _matrix;
    public:
        // construtor da Classe
        GeometricTransformation(vector<vector<double>> matrix) {
            _matrix = matrix;
        }

        vector<vector<double>> getMatrix() {
            return _matrix;
        }

        void setMatrix(vector<vector<double>> matrix) {
            _matrix = matrix;
        }
        
        double getValue(int i, int j) {
        	return _matrix[i][j];
		}
		
		void print() const {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++)
					cout << _matrix[i][j] << " ";
				
				cout << endl;
			}
		}
};

#endif