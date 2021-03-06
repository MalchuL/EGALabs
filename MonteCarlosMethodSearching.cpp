#include "stdafx.h"
#include "MonteCarlosMethodSearching.h"

MethodSearching::MonteCarlosMethodSearching::MonteCarlosMethodSearching(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps)
{
	this->randomseed = randomseed;
	srand(randomseed);
}

MethodSearching::MonteCarlosMethodSearching::MonteCarlosMethodSearching(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
{
	this->randomseed = randomseed;
	srand(randomseed);


}

ByteVector MethodSearching::MonteCarlosMethodSearching::find() {

	int i = 0;
	ByteVector Si = getReorderedNums()->at(i);
	ByteVector Sstar = Si;
	funcvalue max = elements->at(Sstar);
	clog << "S*:" << Sstar << ", max:" << max << endl;

	for (i = 1; i < getReorderedNums()->size() && i<NSteps; i++)
	{
		clog << "iter" << i << endl;
		Si = getReorderedNums()->at(i);
		funcvalue Mu = elements->at(Si);
		//clog << *Si << " " << elements->at(Si)<<endl;
		if (Mu > max) { max = Mu;Sstar = Si;clog << "S* changed "; }
		clog << "Si:" << Si << ", f(Si):" << elements->at(Si) << ", S*:" << Sstar << ", f(S*):" << max << endl;
	}
	//clog <<endl<<"value:"<<*Sstar<<" answer:"<< elements->at(Sstar);
	clog << "answer:" << Sstar << " value:" << elements->at(Sstar) << endl;
	return Sstar;
}

MethodSearching::MonteCarlosMethodSearching::~MonteCarlosMethodSearching() {

}
