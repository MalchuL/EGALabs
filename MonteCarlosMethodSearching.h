#pragma once
#include "AbstractMethodSearching.h"
#include <vector>
#include <algorithm>
namespace MethodSearching {
	class MonteCarlosMethodSearching :public AbstractMethodSearching
	{
	private:
		const int NSteps;
		int randomseed;
		vector<ByteVector*>* reorderednums;

		void printdata() {
			clog << endl;
			for (auto it = reorderednums->begin(); it != reorderednums->end(); it++)
			{
				clog << **it<<" "<<elements->at(*it)<<endl;
			}
			clog << endl;
		}

	public:
		MonteCarlosMethodSearching(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size),NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			reorderednums = new vector<ByteVector*>();
			//Добавить ключи в переупорядоченный лист
			for (map<ByteVector*, funcvalue>::iterator it = elements->begin(); it != elements->end(); ++it) {
				reorderednums->push_back(it->first);

			}
			printdata();

			random_shuffle(reorderednums->begin(), reorderednums->end());
			printdata();
			//
			
		}
		
		MonteCarlosMethodSearching(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			reorderednums = new vector<ByteVector*>();
			//Добавить ключи в переупорядоченный лист
			for (map<ByteVector*, funcvalue>::iterator it = elements->begin(); it != elements->end(); ++it) {
				reorderednums->push_back(it->first);

			}
			printdata();

			random_shuffle(reorderednums->begin(), reorderednums->end());
			printdata();
			//

		}

		ByteVector find() {
			int i = 0;
			ByteVector* Sstar = reorderednums->at(i);
			funcvalue max = elements->at(Sstar);
			for (; i < reorderednums->size(); i++)
			{
				ByteVector* Si = reorderednums->at(i);
				funcvalue Mu = elements->at(Si);
				if (Mu > max) { max = Mu;Sstar = Si; }
			}
			clog <<endl<<"value:"<<*Sstar<<" answer:"<< elements->at(Sstar);
			return *Sstar;
		}
		~MonteCarlosMethodSearching() {
			delete reorderednums;
		}
	};
}

