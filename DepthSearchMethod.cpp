#include "stdafx.h"
#include "DepthSearchMethod.h"
using namespace MethodSearching;
set * MethodSearching::DepthSearchMethod::getNeighbors(ByteVector vect) {
	set* returnedset = new set();
	for (auto it = getReorderedNums()->begin(); it != getReorderedNums()->end(); it++)
	{
		if (ByteVectorMath::HemmingLength(*it, vect) == 1) { returnedset->push_back(*it); }
	}
	return returnedset;
}

MethodSearching::DepthSearchMethod::DepthSearchMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps)
{
	this->randomseed = randomseed;
	srand(randomseed);

}

MethodSearching::DepthSearchMethod::DepthSearchMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
{
	this->randomseed = randomseed;
	srand(randomseed);


}

ByteVector MethodSearching::DepthSearchMethod::find() {

	int i = 0;
	ByteVector Si = getReorderedNums()->at(i);
	ByteVector Sstar = Si;
	funcvalue max = elements->at(Sstar);
	clog << "S*:" << Sstar << ", max:" << max << ", Omega:";
	set* Omega = getNeighbors(Sstar);
	printSet(Omega, elements);
	clog << endl;
	for (i = 1; i<NSteps; i++)
	{
		clog << "iter" << i << endl;
		if (Omega->size() != 0) {
			Si = Omega->at(i%Omega->size());
			if (elements->at(Si) > max)
			{
				Sstar = Si;
				max = elements->at(Si);
				delete Omega;
				Omega = getNeighbors(Si);
			}
			else
			{

				Omega->erase(remove(Omega->begin(), Omega->end(), Si));
			}
		}
		else
		{
			clog << "Omega is empty -> exit";break;
		}
		clog << "Si:" << Si << ", f(Si):" << elements->at(Si) << ", S*:" << Sstar << ", f(S*):" << max << ", Omega:";
		printSet(Omega, elements);
		clog << endl;
	}
	delete Omega;
	clog << "answer:" << Sstar << " value:" << elements->at(Sstar) << endl;
	return Sstar;

}
