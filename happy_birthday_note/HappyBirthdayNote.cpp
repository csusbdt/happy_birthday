#include "Song.h"
#include "Note.h"
#include <iostream>
#include <vector>
//#include <cassert>
#include <cstdio>

using namespace std;

class HappyBirthdayNote : public Song { 
public:
	HappyBirthdayNote();

private:
	void push(double startTime, double quarterStep, double baseFrequency, double a);
};

HappyBirthdayNote::HappyBirthdayNote() {
	startTime   =  0.0;
	duration    = 24.0;
	attack      =  0.5;
	decay       =  0.0;
	release     =  0.5;
	attackDelta =  1.0;
	decayDelta  =  0.0;

	double f = 311;
	push(4 , 0.28 , f       , 3.0);
	push(4 , 0.28 , f / 2.0 , 6.0);
	push(4 , 0.28 , f / 4.0 , 9.0);
}

void HappyBirthdayNote::push(
	double startTime, 
	double quarterStep, 
	double baseFrequency, 
	double a) 
{
	double t = startTime;
	double f = baseFrequency;
	double q = quarterStep;

	sounds.push_back(new Note(scale(12, f, 0), t, 3 * q));  t += 3 * q;
	sounds.push_back(new Note(scale(12, f, 0), t, 1 * q));  t += 1 * q;
	sounds.push_back(new Note(scale(12, f, 2), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f, 0), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f, 5), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f, 4), t, 4 * q));  t += 4 * q;

	sounds.push_back(new Note(scale(12, f, 0), t, 3 * q));  t += 3 * q;
	sounds.push_back(new Note(scale(12, f, 0), t, 1 * q));  t += 1 * q;
	sounds.push_back(new Note(scale(12, f, 2), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f, 0), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f, 7), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f, 5), t, 4 * q));  t += 4 * q;

	sounds.push_back(new Note(scale(12, f,  0), t, 3 * q));  t += 3 * q;
	sounds.push_back(new Note(scale(12, f,  0), t, 1 * q));  t += 1 * q;
	sounds.push_back(new Note(scale(12, f, 12), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  9), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  5), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  4), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  2), t, 2 * q));  t += 2 * q;

	sounds.push_back(new Note(scale(12, f, 10), t, 3 * q));  t += 3 * q;
	sounds.push_back(new Note(scale(12, f, 10), t, 1 * q));  t += 1 * q;
	sounds.push_back(new Note(scale(12, f,  9), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  5), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  7), t, 2 * q));  t += 2 * q;
	sounds.push_back(new Note(scale(12, f,  5), t, 4 * q));  t += 4 * q;
}


int main() {
	FILE * outfile = fopen("temp.raw", "wb");
	if (outfile == 0) {
		perror("Error opening temp.raw for writing.");
		exit(1);
	}

	Sound * sound = new HappyBirthdayNote();
	sound->writeSamples(outfile);
}

