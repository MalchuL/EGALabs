#include "AbstractBackpackSearchMethod.h"
#include <algorithm>
#include "ByteVectorMath.h"
namespace BackpackSearchMethod {
	class GreedyDancigBackpackSearchMethod :
		public AbstractBackpackSearchMethod
	{
	private:
		static	bool compare(object first, object second);
		static void PrintWeightList(list& printedList);
	public:
		GreedyDancigBackpackSearchMethod(vector<weightvalue> weights, vector<costvalue> costs, weightvalue maxWeight);

		ByteVector find();

	};

}