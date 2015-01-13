#ifndef _Color_h_
#define _Color_h_

struct Color {
	float red;
	float green;
	float blue;
	float alpha;
	Color() { };
	Color(float in_r, float in_g, float in_b, float in_a) {
		red = in_r;
		green = in_g;
		blue = in_b;
		alpha = in_a;
	}
};

#endif