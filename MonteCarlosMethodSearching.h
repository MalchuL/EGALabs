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
		MonteCarlosMethodSearching(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed);
		
		MonteCarlosMethodSearching(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed);

		ByteVector find();
		~MonteCarlosMethodSearching();
	};
}

