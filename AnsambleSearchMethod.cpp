#include "stdafx.h"
#include "AnsambleSearchMethod.h"

ByteVector AnsambleSearchMethod::find() {
	int i = 0;
	clog << "Ensemble Iteration:" << i + 1 << endl;
	clog << "/---------------------------------------------\\" << endl;
	k = rand() % 3;
	switch (k)
	{
	case 0:
		clog << "Monte Carlo's" << endl;;
		break;
	case 2:
		clog << "In Depth" << endl;;
		break;
	case 1:
		clog << "In Width" << endl;
		break;
	default:
		break;
	}
	ByteVector bestAnswer = methods[k]->find();
	funcvalue max = elements->at(bestAnswer);
	clog << "\\---------------------------------------------/" << endl;
	clog << "Best max value" << bestAnswer << ":" << max << endl;
	for (i = 1; i < NSteps; i++)
	{
		clog << "Ensemble Iteration:" << i + 1 << endl;
		clog << "/---------------------------------------------\\" << endl;
		k = rand() % 3;
		switch (k)
		{
		case 0:
			clog << "Monte Carlo's" << endl;;
			break;
		case 2:
			clog << "In Depth" << endl;;
			break;
		case 1:
			clog << "In Width" << endl;
			break;
		default:
			break;
		}
		methods[k]->addReorderedNums();
		ByteVector tempAnswer = methods[k]->find();
		clog << "\\---------------------------------------------/" << endl;
		float tempFuncValue = elements->at(tempAnswer);
		clog << "Finded value:" << tempAnswer << ":" << tempFuncValue << endl;
		if (tempFuncValue > max) { bestAnswer = tempAnswer;max = tempFuncValue; }
		clog << "Best max value" << bestAnswer << ":" << max << endl;

	}
	clog << endl << "Best finded value" << bestAnswer << ":" << max << endl;;
	return bestAnswer;
}

AnsambleSearchMethod::AnsambleSearchMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int inMethodNSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps), inMethodNSteps(inMethodNSteps)
{
	k = 0;
	this->randomseed = randomseed;
	srand(randomseed);
	methods = vector<AbstractMethodSearching*>();
	methods.push_back(new MonteCarlosMethodSearching(vectors, values, size, inMethodNSteps, randomseed));
	methods.push_back(new SearchInWidthMethod(vectors, values, size, inMethodNSteps, randomseed));
	methods.push_back(new DepthSearchMethod(vectors, values, size, inMethodNSteps, randomseed));
	/*methods = { MonteCarlosMethodSearching(vectors,values,size,inMethodNSteps,randomseed),
	SearchInWidthMethod(vectors,values,size,inMethodNSteps,randomseed),
	DepthSearchMethod(vectors,values,size,inMethodNSteps,randomseed) };*/

}

AnsambleSearchMethod::AnsambleSearchMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int inMethodNSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps), inMethodNSteps(inMethodNSteps)
{
	k = 0;
	this->randomseed = randomseed;
	srand(randomseed);
	methods = vector<AbstractMethodSearching*>();
	methods.push_back(new MonteCarlosMethodSearching(vectors, values, inMethodNSteps, randomseed));
	methods.push_back(new SearchInWidthMethod(vectors, values, inMethodNSteps, randomseed));
	methods.push_back(new DepthSearchMethod(vectors, values, inMethodNSteps, randomseed));
	/*methods = { MonteCarlosMethodSearching(vectors,values,inMethodNSteps,randomseed),
	SearchInWidthMethod(vectors,values,inMethodNSteps,randomseed),
	DepthSearchMethod(vectors,values,inMethodNSteps,randomseed) };*/

}
