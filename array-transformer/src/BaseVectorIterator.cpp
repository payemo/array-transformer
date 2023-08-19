#include "BaseVectorIntersector.hpp"

namespace net_games
{
	// PUBLIC DEFINITIONS

	template<typename T, class P>
	BaseVectorIntersector<T, P>::BaseVectorIntersector(VectorSorter<T, P>* sorter)
		: sorter_(sorter)
	{
		//this->sorter_ = &sorter;
	}

	template<typename T, class P>
	BaseVectorIntersector<T, P>::~BaseVectorIntersector()
	{
		if (sorter_ != nullptr)
		{
			delete sorter_;
		}
	}

	// DESTRUCTOR TEMPLATE

	template BaseVectorIntersector<int>::BaseVectorIntersector(VectorSorter<int>* sorter);
	template BaseVectorIntersector<unsigned int>::BaseVectorIntersector(VectorSorter<unsigned int>* sorter);

	template BaseVectorIntersector<int>::~BaseVectorIntersector();
	template BaseVectorIntersector<unsigned int>::~BaseVectorIntersector();
}