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
	double f         = 311;
	double a         = 3.0;
	double qs        = .60; //.28; // 56 quarter steps total
	double startWait = 4;
	double endWait   = 8;

	startTime   =  0.0;
	duration    =  startWait + 56 * qs + endWait;
	attack      =  0.5;
	decay       =  0.0;
	release     =  0.5;
	attackDelta =  1.0;
	decayDelta  =  0.0;

// pretty good:
// 3a
//	push(startWait, qs, f * .81, 3.0);
//	push(startWait + 56 * qs * .05, qs * .90, f * .90, 3.0);
//	push(startWait + 56 * qs * .095, qs * .81, f, 4.0);

// interesting:
// 3b
	endWait   = 18;
	duration    =  startWait + 56 * qs + endWait;
	decay       =  3.0;
	push(startWait                 , qs       , f * .618, 3.0);
	push(startWait + 56 * qs * .618, qs * .618, f       , 3.0);

// 3c
//	push(startWait                 , qs       , f * .618 * .618, 3.0);
//	push(startWait                 , qs * 1, f                 , 9.0);

// good:
// 3d
//	qs = .34;
//	push(startWait                 , qs       , f * .618 * .618, 3.0);
//	push(startWait + 14 * qs       , qs       , f              , 9.0);

// maybe use following to replace 3d
//	qs = .34;
//	push(startWait                 , qs       , f * .618 * .618, 3.0);
//	push(startWait + 14 * qs       , qs       , f              , 5.0);

//	push(startWait                       , qs       , f * .618 * .618, 3.0);
//	push(startWait                       , qs * .50, f              , 2.0);
//	push(startWait + 56 * qs * (1 - .5), qs * .50, f              , 2.0);

// good:
//	push(startWait, qs, f * .618 * .618, 3.0);
//	push(startWait, qs, f              , 3.0);

// 3e
//	push(startWait + 56 * qs * .025, qs * .95, f, 3.5);
//	push(startWait + 57 * qs * .050, qs * .90, f, 4.0);

/*
	// level 1

	push(waitTime + len * 0 , qs , f       , 3.0);
//	push(waitTime + len * 0 , 0.28 , f / 2.0 , 6.0);
//	push(waitTime + len * 0 , 0.28 , f / 4.0 , 9.0);

//	push(waitTime + len * 1 , 0.28 , f       , 3.0);
	push(waitTime + len * 1 , 0.28 , f / 2.0 , 6.0);
//	push(waitTime + len * 1 , 0.28 , f / 4.0 , 9.0);

//	push(waitTime + len * 2 , 0.28 , f       , 3.0);
//	push(waitTime + len * 2 , 0.28 , f / 2.0 , 6.0);
	push(waitTime + len * 2 , 0.28 , f / 4.0 , 9.0);

//	push(waitTime + len * 3 , 0.28 , f       , 3.0);
//	push(waitTime + len * 3 , 0.28 , f / 2.0 , 6.0);
//	push(waitTime + len * 3 , 0.28 , f / 4.0 , 9.0);

	// level 2

	push(waitTime + len * 0 * 2 , 0.28 * 2 , f       , 3.0);
	push(waitTime + len * 0 * 2 , 0.28 * 2 , f / 2.0 , 6.0);
//	push(waitTime + len * 0 * 2 , 0.28 * 2 , f / 4.0 , 9.0);

//	push(waitTime + len * 1 * 2 , 0.28 * 2 , f       , 3.0);
	push(waitTime + len * 1 * 2 , 0.28 * 2 , f / 2.0 , 6.0);
	push(waitTime + len * 1 * 2 , 0.28 * 2 , f / 4.0 , 9.0);

	// level 3

	push(waitTime + len * 0 * 4 , 0.28 * 4 , f       , 3.0);
	push(waitTime + len * 0 * 4 , 0.28 * 4 , f / 2.0 , 6.0);
	push(waitTime + len * 0 * 4 , 0.28 * 4 , f / 4.0 , 9.0);
*/

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

