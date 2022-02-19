#pragma once

#include <limits>
#include "Sound.h"
#include "Envelope.h"

#include <iostream>

using namespace std;

class Sinc : public Sound {
public:
	Sinc(	double frequency = 120, 
		double a = 2 ,
		double peak = 0,
		double normalizedPhase = 0
	) : 
	Sound(	0, 
		99999, //std::numeric_limits<double>::max(), 
		0.2, 
		0, 
		1, 
		1, 
		0
	) , 
	frequency(frequency), a(a), peak(peak), normalizedPhase(normalizedPhase) {
	}

	double sinc(double t, double a, double m) const;
	virtual double sample(double clockTime) const;

	double frequency;
	double a;
	double peak;
	double normalizedPhase;
};

