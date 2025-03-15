#include <cstring>
#include <cassert>
#include <iostream>
#include "primitive.h"

int Primitive::ID = 0;

using std::cout;

Primitive::Primitive(const char *n) {
	type = new char[strlen(n) + 1];
	assert(type != 0);
	strcpy(type, n);
			
	id = ++ID; 
	
	//cout << "Primitiva Criada: (" << id << ", " << type << ")" << std::endl;
}

Primitive::~Primitive() {
	//cout << "Primitiva Destruida: (" << id << ", " << type << ")" << std::endl;
	
	delete [] type;
}