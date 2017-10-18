#include "AbstractBackpackSearchMethod.h"
#include <algorithm>
#include "ByteVectorMath.h"
namespace BackpackSearchMethod {
	class GreedyDancigBackpackSearchMethod :
		public AbstractBackpackSearchMethod
	{
	private:
		static	bool compare(object first, object second) {
			//Взять из первой пары и из второй только их стоимости и сравнить
			return get<COST>(first)/ get<WEIGHT>(first) < get<COST>(second)/ get<WEIGHT>(second);
		}
		void PrintWeightList(list& printedList) {
			for (object i : printedList) {
				clog << "i:" << get<INDEX>(i) << " w:" << get<WEIGHT>(i) << " c:" << get<COST>(i) << " c/w:" << get<COST>(i) / get<WEIGHT>(i) << endl;
			}
		}
	public:
		GreedyDancigBackpackSearchMethod(vector<weightvalue> weights, vector<costvalue> costs, weightvalue maxWeight) :AbstractBackpackSearchMethod(weights, costs, maxWeight) {}


	
		ByteVector find() {
			clog << "in list" << endl;
			printlist(*objects);
			costvalue currentCost = 0;
			weightvalue currentWeight = 0;
			ByteVector returnedvector(objects->size());
			sort(objects->begin(), objects->end(), compare);
			reverse(objects->begin(), objects->end());
			clog << "\n\n\sorted list" << endl;
			PrintWeightList(*objects);

			for (size_t i = 0; i < objects->size(); i++)
			{
				if (currentWeight + get<WEIGHT>(objects->at(i)) <= maxWeight) {
					currentCost += get<COST>(objects->at(i));
					currentWeight += get<WEIGHT>(objects->at(i));
					returnedvector.setByte(get<INDEX>(objects->at(i)), 1);
					clog << "set byte at pos:" << get<INDEX>(objects->at(i)) << " cost:" << currentCost << " weight:" << currentWeight << endl;
				}
				else
				{
					//Иначе мб уже с минимальными вессами, но с самой маленькой стоимостью
				}
			}
			clog << "Cost:" << currentCost << " Weight:" << currentWeight << endl;

			return ByteVectorMath::Reverse(returnedvector);

		}

	};

}