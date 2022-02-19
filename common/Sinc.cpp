#include "Sinc.h"
#include <cassert>
#include <cmath>
#include <iostream>

double Sinc::sinc(double t, double a, double p) const {
	double x = t - p;
	if (a * x > -.00001 && a * x < .00001) {
		return 1; 
	} else {
		return sin(a * x) / (a * x);
	}
}

double Sinc::sample(double t) const {
	double s = sin(2 * PI * t * frequency - PI / 2 + 2 * PI * normalizedPhase);
	s *= sinc(t, a, peak);
	return envelope(t, s);
}

