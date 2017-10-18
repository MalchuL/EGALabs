#pragma once
#include <vector>
#include <tuple>
#include <utility>
#include "ByteVector.h"
namespace BackpackSearchMethod {
	using namespace std;

	typedef float costvalue;
	typedef float weightvalue;
	
	//Для получения значений из кортежа

	//
	typedef tuple<int, weightvalue, costvalue> object;
	typedef vector<object > list;
	//

	class AbstractBackpackSearchMethod
	{
	protected:

		static constexpr int INDEX = 0;
		static constexpr int WEIGHT = 1;
		static constexpr int COST = 2;
		static void printList(list& printedList);
		list * objects;
		weightvalue maxWeight;
	public:
		AbstractBackpackSearchMethod(vector<weightvalue> weights, vector<costvalue> costs, weightvalue maxWeight);
		virtual ByteVector find() = 0;
		~AbstractBackpackSearchMethod();
	};
}

