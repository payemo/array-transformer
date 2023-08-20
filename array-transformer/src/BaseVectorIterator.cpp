#include "BaseVectorIntersector.hpp"

namespace ng
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

	template BaseVectorIntersector<>::BaseVectorIntersector(VectorSorter<>*);
}