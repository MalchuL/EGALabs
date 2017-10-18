#pragma once
#include "AbstractMethodSearching.h"
#include "DepthSearchMethod.h"
#include "SearchInWidthMethod.h"
#include "MonteCarlosMethodSearching.h"
using namespace MethodSearching;

class AnsambleSearchMethod :
	public AbstractMethodSearching
{
private:


	const int NSteps;
	const int inMethodNSteps;
	int randomseed;
	int k;
	vector<AbstractMethodSearching*> methods;
	
public:
	ByteVector find();
	AnsambleSearchMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int inMethodNSteps, int randomseed);

	AnsambleSearchMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int inMethodNSteps, int randomseed);

};

