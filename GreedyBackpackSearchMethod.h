#pragma once
#include "AbstractBackpackSearchMethod.h"
#include <algorithm>
#include "ByteVectorMath.h"
namespace BackpackSearchMethod {
	class GreedyBackpackSearchMethod :
		public AbstractBackpackSearchMethod
	{
	private:
		static	bool compare(object first, object second);
	public:
		GreedyBackpackSearchMethod(vector<weightvalue> weights, vector<costvalue> costs, weightvalue maxWeight);
		ByteVector find();
		
	};

}