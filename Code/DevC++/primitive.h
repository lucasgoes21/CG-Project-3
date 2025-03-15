#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <iostream>
#include "screen.h"

using std::cout;

class Screen;

class Primitive {
	private:
		int id;
		char *type;
		static int ID;
		
	public:
		Primitive(const char *n);
		virtual void draw(Screen &) const = 0;
		int getID() const { return id; };
		void print() const { cout << "(" << id << ", " << type << ")" << std::endl;	};
		~Primitive();
};

#endif