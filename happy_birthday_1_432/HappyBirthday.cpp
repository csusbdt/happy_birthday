#include "Sinc.h"
#include "Song.h"
#include <iostream>
#include <vector>

class HappyBirthday: public Song { 
public:
	HappyBirthday();

private:
	void push(double startTime, double quarterStep, double baseFrequency, double a);
};

HappyBirthday::HappyBirthday() {
	double waitTime = 4;
	double len  = 30;

	startTime   =  0.0;
	duration    =  2 * waitTime + len;
	attack      =  0.5;
	decay       =  0.0;
	release     =  0.5;
	attackDelta =  1.0;
	decayDelta  =  0.0;

	double f = scale(12, 432, -6);

	// level 1

	double q = len / 56.0;

	push(waitTime + len * 0     , q   , f       , 3.0);
	push(waitTime + len * 0     , q/2 , f       , 6.0);
	push(waitTime + len * 1 / 2 , q/2 , f       , 6.0);
}

void HappyBirthday::push(
	double startTime, 
	double quarterStep, 
	double baseFrequency, 
	double a) 
{
	double t = startTime;
	double f = baseFrequency;
	double q = quarterStep;

	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 3 * q;
	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 1 * q;
	sounds.push_back(new Sinc(scale(12, f,  2), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  5), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  4), a, t));  t += 4 * q;

	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 3 * q;
	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 1 * q;
	sounds.push_back(new Sinc(scale(12, f,  2), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  7), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  5), a, t));  t += 4 * q;

	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 3 * q;
	sounds.push_back(new Sinc(scale(12, f,  0), a, t));  t += 1 * q;
	sounds.push_back(new Sinc(scale(12, f, 12), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  9), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  5), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  4), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  2), a, t));  t += 2 * q;

	sounds.push_back(new Sinc(scale(12, f, 10), a, t));  t += 3 * q;
	sounds.push_back(new Sinc(scale(12, f, 10), a, t));  t += 1 * q;
	sounds.push_back(new Sinc(scale(12, f,  9), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  5), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  7), a, t));  t += 2 * q;
	sounds.push_back(new Sinc(scale(12, f,  5), a, t));  t += 4 * q;
}

int main(int argc, char * argv[]) {
	FILE * outfile = fopen("temp.raw", "wb");
	if (outfile == 0) {
		perror("Error opening temp.raw for writing.");
		exit(1);
	}

	Sound * sound = new HappyBirthday();
	sound->writeSamples(outfile);
}

