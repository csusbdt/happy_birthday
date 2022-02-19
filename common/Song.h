#pragma once

#include <vector>
#include "Sound.h"

using namespace std;

class Song : public Sound {
public:
	virtual double sample(double t) const;

protected:
	Song();
	vector<Sound *> sounds;
};

