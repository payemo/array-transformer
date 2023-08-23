#include "ArrayTransformerFactory.hpp"
#include "TwoVectorIntersector.hpp"
#include "ThreeVectorIntersector.hpp"
#include "ReverseOrderedThreeVecDifference.hpp"

namespace ng
{
	template<typename T>
	ArrayTransformer<T>* ArrayTransformerFactory<T>::CreateTransformer(TransformCommand cmd)
	{
		switch (cmd)
		{
		case TransformCommand::SORT_ARRAYS:
			return new VectorSorter<T>();
		case TransformCommand::INTERSECT_TWO:
			return new TwoVectorIntersector<T>();
		case TransformCommand::INTERSECT_THREE:
			return new ThreeVectorIntersector<T>();
		case TransformCommand::SYM_DIFF:
			return new ReverseOrderedThreeVecDifference<T>();
		default:
			break;
		}
	}

	template struct ArrayTransformerFactory<>;
	template ArrayTransformer<>* ArrayTransformerFactory<>::CreateTransformer(TransformCommand op);
}