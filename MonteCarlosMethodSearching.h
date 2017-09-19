#pragma once
#include "AbstractMethodSearching.h"
#include <vector>
namespace MethodSearching {
	class MonteCarlosMethodSearching :public AbstractMethodSearching
	{
		const int NSteps;
		int randomseed;
		vector<int> reorderednums;
	public:
		MonteCarlosMethodSearching(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed) :AbstractMethodSearching(vectors, values, size),NSteps(NSteps)
		{
			this->randomseed = randomseed;
			srand(randomseed);
			reorderednums = 
		}
		ByteVector find() {
			ByteVector
			for (int i = 0; i < length; i++)
			{

			}
		}
		~MonteCarlosMethodSearching();
	};
}

