#ifndef ARRAY3D_H
#define ARRAY3D_H

#include <cmath>
#include <array>

class Axis3D {
	private:
	    std::array<double, 3> v;

	public:
    // construtor da Classe
    Axis3D(double x, double y, double z) : v({x, y, z}) {}

    double norm() const {
        return std::sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    }

    Axis3D getUnityVector() const {
        double n = norm();
        return Axis3D(v[0]/n, v[1]/n, v[2]/n);
    }

    const std::array<double, 3>& getV() const {
        return v;
    }

    void setV(double x, double y, double z) {
        v = {x, y, z};
    }
    
    double getValue(int i) {
    	return v[i];
	}
	
	void print() const {
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}

};
#endif