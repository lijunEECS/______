#ifndef PAUTILS_H
#define PAUTILS_H

#include <string>
#include <time.h>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "oaDesignDB.h"
using namespace std;
using namespace oa;

struct macroPin
{
	macroPin(oaString& _macroName, oaString& _instTermName) :macroName(_macroName), instTermName(_instTermName)
	{}
	oaString macroName;
	oaString instTermName;
};

typedef map<macroPin, oaPoint> PAsolution;
typedef map<macroPin, oaPoint>::iterator solutionIter;

bool operator < (const macroPin& _l, const macroPin& _r);
bool operator == (const macroPin& _l, const macroPin& _r);

oaString getMacroName(oaInst* inst);

macroPin getMacroPin(oaInstTerm* instTerm);

int getHPWL(oaNet* net);

oaBox GetAbsoluteInstTermBBox(oaInst* inst, oaPin* pin);

bool isExternalPin(oaInstTerm* instTerm);

bool adjacent(oaBox& box1, oaBox& box2);

void printDataForMatlab(oaBlock* topBlock, const char* filename);

#endif