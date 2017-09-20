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
		
	
	public:
		MonteCarlosMethodSearching(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size),NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			//Добавить ключи в переупорядоченный лист
			addReorderedNums();
			
			//
			
		}
		
		MonteCarlosMethodSearching(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values), NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			
			//Добавить ключи в переупорядоченный лист
			addReorderedNums();
			//

		}

		ByteVector find() {
			int i = 0;
			ByteVector* Sstar,*Si ;
			Sstar = Si = reorderednums->at(i);
			funcvalue max = elements->at(Sstar);
			clog << endl;
			for (i=1; i < reorderednums->size()&&i<NSteps; i++)
			{
				Si = reorderednums->at(i);
				funcvalue Mu = elements->at(Si);
				clog << *Si << " " << elements->at(Si)<<endl;
				if (Mu > max) { max = Mu;Sstar = Si; }
			}
			clog <<endl<<"value:"<<*Sstar<<" answer:"<< elements->at(Sstar);
			return *Sstar;
		}
		~MonteCarlosMethodSearching() {
			
		}
	};
}

