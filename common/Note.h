#pragma once

#include "Sound.h"
#include "Envelope.h"

#include <iostream>

using namespace std;

class Note : public Sound {
public:
	Note(	double frequency = 120, 
		double startTime = 0, 
		double duration = 120, 
		double attack = .05,
		double decay = .02, 
		double release = .1, 
		double attackDelta = 1.0, 
		double decayDelta = 0.1
	) : 
	Sound(	startTime, 
		duration, 
		attack, 
		decay, 
		release, 
		attackDelta, 
		decayDelta
	) , 
	frequency(frequency) {
	}

	virtual double sample(double clockTime) const;

	double frequency;
};

