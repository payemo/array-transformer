#include "ArrayTransformerFactory.hpp"
#include "TwoVectorIntersector.hpp"
#include "ThreeVectorIntersector.hpp"
#include "ReverseOrderedThreeVecDifference.hpp"

namespace ng
{
	template<typename T>
	ArrayTransformer<T>* ArrayTransformerFactory<T>::CreateTransformer(Command cmd)
	{
		switch (cmd)
		{
		case Command::SORT_ARRAYS:
			return new VectorSorter<T>();
		case Command::INTERSECT_TWO:
			return new TwoVectorIntersector<T>();
		case Command::INTERSECT_THREE:
			return new ThreeVectorIntersector<T>();
		case Command::SYM_DIFF:
			return new ReverseOrderedThreeVecDifference<T>();
		default:
			break;
		}
	}

	template struct ArrayTransformerFactory<>;
	template ArrayTransformer<>* ArrayTransformerFactory<>::CreateTransformer(Command op);
}