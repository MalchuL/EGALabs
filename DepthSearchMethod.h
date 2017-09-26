#pragma once
#include "AbstractMethodSearching.h"
#include <vector>
#include <algorithm>
#include "ByteVectorMath.h"
using namespace std;
typedef vector<ByteVector*> set;
namespace MethodSearching {

	class DepthSearchMethod:public AbstractMethodSearching
	{
	private:
		const int NSteps;
		int randomseed;
		set* getNeighbors(ByteVector* vect){
			set* returnedset = new set();
			for (auto it = reorderednums->begin(); it != reorderednums->end(); it++)
			{
				if (ByteVectorMath::HemmingLength(**it, *vect) == 1) { returnedset->push_back(*it); }
			}
			return returnedset;
		}
		
	public:
		DepthSearchMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			//Добавить ключи в переупорядоченный лист
			addReorderedNums();
			printreorderednums();
			//

		}

		DepthSearchMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);

			//Добавить ключи в переупорядоченный лист
			addReorderedNums();
			printreorderednums();
			//

		}
		ByteVector find() {
			int i = 0;
			ByteVector* Sstar,*Si;
			Sstar = Si = reorderednums->at(i);
			funcvalue max = elements->at(Sstar);
			clog << "S*:" << *Sstar << ", max:" << max<<", Omega:";
			set* Omega= getNeighbors(Sstar);
			printset(Omega, elements);
			clog << endl;
			for (i = 1; i<NSteps; i++)
			{
				clog << "iter" << i << endl;
				if (Omega->size() != 0) {
					Si = Omega->at(i%Omega->size());
					if (elements->at(Si) > max) 
					{	Sstar = Si;
						max = elements->at(Si);
						delete Omega;
						Omega = getNeighbors(Si);
					}
					else
					{
						
					Omega->erase(remove(Omega->begin(), Omega->end(), Si),Omega->end());
					}
				}
				clog << "Si:" << *Si << ", f(Si):" << elements->at(Si) << ", S*:" << *Sstar << ", f(S*):" << max << ", Omega:";
				printset(Omega, elements);
				clog << endl;
			}
			delete Omega;
			clog << "answer:" << *Sstar << " value:" << elements->at(Sstar)<<endl;
			return *Sstar;
		
		}
		~DepthSearchMethod(){}
	};

}