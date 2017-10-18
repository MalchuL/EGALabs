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
	constexpr int INDEX = 0;
	constexpr int WEIGHT = 1;
	constexpr int COST = 2;

	class AbstractBackpackSearchMethod
	{
	protected:

		void printlist(list& printedList) {
			for (object i : printedList) {
				clog << "i:" << get<INDEX>(i) << " w:" << get<WEIGHT>(i) << " c:" << get<COST>(i) << endl;
			}
		}
		list * objects;
		weightvalue maxWeight;
	public:
		AbstractBackpackSearchMethod(vector<weightvalue> weights, vector<costvalue> costs, weightvalue maxWeight) {
			this->maxWeight = maxWeight;
			this->objects = new list();
			int size = (weights.size() < costs.size()) ? weights.size() : costs.size();
			for (size_t i = 0; i < size; i++)
			{
				clog << i;
				objects->push_back(object(i,weights[i],costs[i]));
			}
		}
		virtual ByteVector find() = 0;
		~AbstractBackpackSearchMethod() {
			delete objects;
		}
	};
}

