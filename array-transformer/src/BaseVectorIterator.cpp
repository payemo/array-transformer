#include "BaseVectorIntersector.hpp"

namespace net_games
{
	// PUBLIC DEFINITIONS

	template<typename T>
	BaseVectorIntersector<T>::BaseVectorIntersector(VectorSorter<T>* sorter)
		: sorter_(sorter)
	{
		//this->sorter_ = &sorter;
	}

	template<typename T>
	BaseVectorIntersector<T>::~BaseVectorIntersector()
	{
		if (sorter_ != nullptr)
		{
			delete sorter_;
		}
	}

	// PROTECTED DEFINITIONS

	template<typename T>
	void BaseVectorIntersector<T>::Intersect(Vec<T>& v1, Vec<T>& v2)
	{
		VecIter<T> first = v1.begin(), fLast = v1.end();
		VecIter<T> second = v2.begin(), sLast = v2.end();

		while (first != fLast && second != sLast)
		{
			if (*first < *second)
			{
				++first;
			}
			else
			{
				if (!(*second < *first))
				{
					this->out_.push_back(*first++);
				}
				++second;
			}
		}
	}

	// DESTRUCTOR TEMPLATE

	template BaseVectorIntersector<int>::BaseVectorIntersector(VectorSorter<int>* sorter);
	template BaseVectorIntersector<unsigned int>::BaseVectorIntersector(VectorSorter<unsigned int>* sorter);

	template BaseVectorIntersector<int>::~BaseVectorIntersector();
	template BaseVectorIntersector<unsigned int>::~BaseVectorIntersector();

	// PROTECTED TEMPLATES

	template void BaseVectorIntersector<int>::Intersect(Vec<int>& v1, Vec<int>& v2);
	template void BaseVectorIntersector<unsigned int>::Intersect(Vec<unsigned int>& v1, Vec<unsigned int>& v2);
}