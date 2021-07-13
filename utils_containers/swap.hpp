#ifndef FT_UTILS_HPP
#define FT_UTILS_HPP

namespace ft {
	template <typename U>
	void swap(U& a, U&b)
	{
		U tmp = a;
		a = b;
		b = tmp;
	}
}


#endif
