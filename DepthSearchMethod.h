#pragma once
#include "AbstractMethodSearching.h"
#include <vector>
#include <algorithm>
#include "ByteVectorMath.h"
using namespace std;
//typedef vector<ByteVector> set;
namespace MethodSearching {

	class DepthSearchMethod:public AbstractMethodSearching
	{
	private:
		const int NSteps;
		int randomseed;
		set* getNeighbors(ByteVector vect);
		
	public:
		DepthSearchMethod(ByteVector vectors[], funcvalue values[], int size, int NSteps, int randomseed);

		DepthSearchMethod(const vector<ByteVector>& vectors, const vector<funcvalue>& values, int NSteps, int randomseed);
		ByteVector find();
		~DepthSearchMethod(){}
	};

}