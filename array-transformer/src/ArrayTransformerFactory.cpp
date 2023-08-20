#include "ArrayTransformerFactory.hpp"
#include "TwoVectorIntersector.hpp"
#include "ThreeVectorIntersector.hpp"
#include "ReverseOrderedThreeVecDifference.hpp"

namespace ng
{
	template<typename T>
	ArrayTransformer<T>* ArrayTransformerFactory<T>::CreateTransformer(Operation op)
	{
		switch (op)
		{
		case Operation::SORT_ARRAYS:
			return new VectorSorter<T>();
		case Operation::INTERSECT_TWO:
			return new TwoVectorIntersector<T>();
		case Operation::INTERSECT_THREE:
			return new ThreeVectorIntersector<T>();
		case Operation::SYM_DIFF:
			return new ReverseOrderedThreeVecDifference<T>();
		default:
			break;
		}
	}

	template struct ArrayTransformerFactory<>;
	template ArrayTransformer<>* ArrayTransformerFactory<>::CreateTransformer(Operation op);
}