#ifndef WINDOW_TO_VIEWPORT_TRANSFORMATION
#define WINDOW_TO_VIEWPORT_TRANSFORMATION

#include "combinedTransformation.h"
#include "translation3D.h"
#include "scale3D.h"


class WindowToViewportTransformation: public CombinedTransformation {
	public:
	WindowToViewportTransformation(int xd1, int yd1, int xd2, int yd2, int xv1, int yv1, int xv2, int yv2):CombinedTransformation({}) {
		/*Translation3D T1(-xd1, -yd1, 0);
        add(&T1);
        double x_view_factor = (xv2 - xv1) / (double)(xd2 - xd1);
        double y_view_factor = (yv2 - yv1) / (double)(yd2 - yd1);
        Scale3D T2(x_view_factor, y_view_factor, 0);
        add(&T2);
        Translation3D T3(xv1, yv1, 0);
        add(&T3);*/
        
        add(new Translation3D(-xd1, -yd1, 0));
        double x_view_factor = (xv2 - xv1) / (double)(xd2 - xd1);
        double y_view_factor = (yv2 - yv1) / (double)(yd2 - yd1);
        add(new Scale3D(x_view_factor, y_view_factor, 0));
        add(new Translation3D(xv1, yv1, 0));
        combine();
	}
};
#endif