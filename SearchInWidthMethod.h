#pragma once
#include "AbstractMethodSearching.h"
#include "ByteVectorMath.h"
#include "CustomExceptions.h"
using namespace exceptions;
using namespace std;
namespace MethodSearching {
	class SearchInWidthMethod :public AbstractMethodSearching
	{
	private:
		const int NSteps;
		int randomseed;
		set* getNeighbors(ByteVector* vect) {
			set* returnedset = new set();
			for (auto it = getReorderedNums()->begin(); it != getReorderedNums()->end(); it++)
			{
				if (ByteVectorMath::HemmingLength(**it, *vect) == 1) { returnedset->push_back(*it); }
			}
			return returnedset;
		}
		set* getMaxSet(ByteVector* vect, set* Omega,funcvalue* refmaxvalue) {
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
	public:
		SearchInWidthMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);

		}

		SearchInWidthMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);


		}
		ByteVector find() {
		
			int i = 0;
			ByteVector* Sstar;
			Sstar = getReorderedNums()->at(i);
			funcvalue max = elements->at(Sstar);
			clog << "S*:" << *Sstar << ", max:" << max << ", Omega:";
			set* Omega = getNeighbors(Sstar);
			printset(Omega, elements);
			clog << endl;
			for (i = 1; i<NSteps; i++)
			{	
				clog << "iter" << i << endl;
				funcvalue value;
				set* MaxOmega = getMaxSet(Sstar, Omega,&value);
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
				clog <<"S*:" << *Sstar << ", f(S*):" << max << ", Omega:";
				printset(Omega, elements);
				clog << ", MaxOmega:";
				printset(MaxOmega, elements);
				clog << endl;
				delete MaxOmega;

				
			}
			delete Omega;
			clog << "answer:" << *Sstar << " value:" << elements->at(Sstar) << endl;
			return *Sstar;

		}
		
		~SearchInWidthMethod(){};
	};

}