#include "stdafx.h"
#include "SearchInWidthMethod.h"
#include "AbstractMethodSearching.h"
using namespace MethodSearching;
inline set * MethodSearching::SearchInWidthMethod::getNeighbors(ByteVector & vect) {
	set* returnedset = new set();
	for (auto it = getReorderedNums()->begin(); it != getReorderedNums()->end(); it++)
	{
		if (ByteVectorMath::HemmingLength(*it, vect) == 1) { returnedset->push_back(*it); }
	}
	return returnedset;
}

set * MethodSearching::SearchInWidthMethod::getMaxSet(ByteVector & vect, set * Omega, funcvalue * refmaxvalue) {
	set* returnedset = new set();
	//Получить максимум
	if (Omega->size() <= 0)throw SetSizeException();
	funcvalue maxvalue = elements->at(*Omega->begin());
	for (auto it = Omega->begin(); it != Omega->end(); it++)
	{
		if (elements->at(*it) > maxvalue)
			maxvalue = elements->at(*it);
	}
	if (refmaxvalue != nullptr)*refmaxvalue = maxvalue;
	for (auto it = Omega->begin(); it != Omega->end(); it++)
	{
		if (elements->at(*it) == maxvalue)
			returnedset->push_back(*it);
	}
	return returnedset;
}

MethodSearching::SearchInWidthMethod::SearchInWidthMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps)
{
	this->randomseed = randomseed;
	srand(randomseed);

}

MethodSearching::SearchInWidthMethod::SearchInWidthMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
{
	this->randomseed = randomseed;
	srand(randomseed);


}

ByteVector MethodSearching::SearchInWidthMethod::find() {

	int i = 0;
	ByteVector Sstar = getReorderedNums()->at(i);
	funcvalue max = elements->at(Sstar);
	clog << "S*:" << Sstar << ", max:" << max << ", Omega:";
	set* Omega = getNeighbors(Sstar);
	printSet(Omega, elements);
	clog << endl;
	for (i = 1; i<NSteps; i++)
	{
		clog << "iter" << i << endl;
		funcvalue value;
		set* MaxOmega = getMaxSet(Sstar, Omega, &value);
		if (value>max) {
			Sstar = *MaxOmega->begin();
			max = value;
			delete Omega;
			Omega = getNeighbors(Sstar);
		}
		else
		{
			clog << "Not bigger than max-> exit" << endl;
			break;
		}
		clog << "S*:" << Sstar << ", f(S*):" << max << ", Omega:";
		printSet(Omega, elements);
		clog << ", MaxOmega:";
		printSet(MaxOmega, elements);
		clog << endl;
		delete MaxOmega;


	}
	delete Omega;
	clog << "answer:" << Sstar << " value:" << elements->at(Sstar) << endl;
	return Sstar;

}

MethodSearching::SearchInWidthMethod::~SearchInWidthMethod() {}
