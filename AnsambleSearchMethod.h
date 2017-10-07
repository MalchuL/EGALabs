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
	vector<AbstractMethodSearching> methods;
public:
	ByteVector find() {
		funcvalue max = 0;
		
		for (size_t i = 0; i < NSteps; i++)
		{
			k = rand() % 3;
			methods[k].addReorderedNums();
			ByteVector tempanswer = methods[k].find();
			
		}
		return methods[k].find();
	}
		AnsambleSearchMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int inMethodNSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps),inMethodNSteps(inMethodNSteps)
	{
		k = 0;
		this->randomseed = randomseed;
		srand(randomseed);
		methods = { MonteCarlosMethodSearching(vectors,values,size,inMethodNSteps,randomseed),
					SearchInWidthMethod(vectors,values,size,inMethodNSteps,randomseed),
					DepthSearchMethod(vectors,values,size,inMethodNSteps,randomseed) };

	}

	AnsambleSearchMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int inMethodNSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps), inMethodNSteps(inMethodNSteps)
	{
		k = 0;
		this->randomseed = randomseed;
		srand(randomseed);
		methods = { MonteCarlosMethodSearching(vectors,values,inMethodNSteps,randomseed),
			SearchInWidthMethod(vectors,values,inMethodNSteps,randomseed),
			DepthSearchMethod(vectors,values,inMethodNSteps,randomseed) };

	}

};

