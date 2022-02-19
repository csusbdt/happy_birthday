#include "Song.h"
#include "Sinc.h"
#include "Note.h"
#include <iostream>
#include <vector>

Song::Song() : Sound() {
	startTime   =  0.0;
	duration    = 24.0;
	attack      =  0.5;
	decay       =  0.0;
	release     =  0.5;
	attackDelta =  1.0;
	decayDelta  =  0.0;
}

double Song::sample(double t) const {
	double s = 0;
	for (int i = 0; i < sounds.size(); ++i) {
		s += sounds[i]->sample(t);
	}
	s /= 4;
	return envelope(t, s);
}


