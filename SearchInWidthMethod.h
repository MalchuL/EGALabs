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
		set* getNeighbors(ByteVector& vect);
		set* getMaxSet(ByteVector& vect, set* Omega, funcvalue* refmaxvalue);
	public:
		SearchInWidthMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed);

		SearchInWidthMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed);
		ByteVector find();
		
		~SearchInWidthMethod();;
	};

}