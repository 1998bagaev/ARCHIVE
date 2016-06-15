#include <iostream>
#include <vector>

template <class T, class IT> 
IT find(IT begin, IT end, T val)
{

	for ( IT it = begin; it != end;++it)
			{
		if (*it == val)
		{
			return it;
		}
			}
			return end;

}

template <class IT, class PRED>
	size_t count_if(IT begin, IT end, PRED pred)
{
		int n = 0;
		for ( IT it = begin; it != end; ++it)
			{
				if (pred(*it) == true)
					n++;
			}
			return n;
}


template<class T, class IT>
	T minElem(IT begin, IT end)
{
		T min = *begin;
		for (IT it = begin; it != end; ++it)
			{
				if (*it < min)
					min = *it;
			}
			return min;
}


template <class IT, class PRED>
	void transform(IT begin, IT end, PRED pred)
{
		for (IT it = begin; it != end; ++it)
				*it = pred(*it);
}


template<class T, class IT>
	T mean(IT begin, IT end)
{
		int sum = 0; float d = 0; int n = 0;
			for (IT it = begin; it != end; ++it)
			{
				sum += *it;
				n++;
			}
			d = sum / n;
			return d;
}


template <class T, class IT, class PRED>
	void replace_if(IT begin, IT end, PRED pred, T newValue)
{
		for (IT it = begin; it != end; ++it)
			{
				if (pred(*it) == true)
					newValue = *it;
			}
}

bool foo(int a)
{
			if (a == 0) return true;
			return false;
}

bool foo1(int a)
{
			if ((a % 2) == 0) return true;
	 	return false;
}

int foo2(int a)
{
	return a*a;
}


	



	 void TEST()
	 {
	  std::vector <int> a;
	  for (int i=0; i<10;i++)
	  a.push_back(i);
	       std::vector <int>:: iterator it = ::find(a.begin(), a.end(),7);
	       size_t l = ::count_if(a.begin(),a.end(),foo);
	       int min =  ::minElem<int>(a.begin(), a.end());
	       ::transform(a.begin(), a.end(),foo2);
	 int d = ::mean<float>(a.begin(), a.end());
	 ::replace_if(a.begin(), a.end(),foo1,2);
	 }
