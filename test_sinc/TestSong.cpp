#include "Song.h"
#include "Sinc.h"
#include <iostream>
#include <vector>

class TestSong : public Song { 
public:
	TestSong();

private:
	void push(double startTime, double baseFrequency, double a);
};

TestSong::TestSong() : Song() {
	startTime   =  0.0;
	duration    = 24.0;
	attack      =  0.5;
	decay       =  0.0;
	release     =  0.5;
	attackDelta =  1.0;
	decayDelta  =  0.0;

	push(4, 120, 3);
}

void TestSong::push(
	double startTime, 
	double baseFrequency, 
	double a) 
{
	double f = baseFrequency;

	for (int i = 0; i < 4; ++i) {
                double t = startTime + (duration - startTime) / 4.0 * i;
		sounds.push_back(new Sinc(f, a, t));
	}
}

int main(int argc, char * argv[]) {
	FILE * outfile = fopen("temp.raw", "wb");
	if (outfile == 0) {
		perror("Error opening temp.raw for writing.");
		exit(1);
	}

	Sound * sound = new TestSong();
	sound->writeSamples(outfile);
}

