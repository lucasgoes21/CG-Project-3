#ifndef COLOR_H
#define COLOR_H

class Color {
	private:
		Uint8 r;
		Uint8 g;
		Uint8 b;
	public:
		Color(Uint8 rr=0, Uint8 gg=0, Uint8 bb=0):r(rr), g(gg), b(bb) {};
		Color(const Color &c) {
			r = c.r;
			g = c.g;
			b = c.b;
		}
		Uint8 getR() const { return r; };
		Uint8 getG() const { return g; };
		Uint8 getB() const { return b; };
		void setR (Uint8 v) { r = v; };
		void setG (Uint8 v) { g = v; };
		void setB (Uint8 v) { b = v; };
		
};

const Color WHITE(255,255,255);
const Color BLACK(0,0,0);
const Color RED(255,0,0);
const Color GREEN(0,255,0);
const Color BLUE(0,0,255);


#endif