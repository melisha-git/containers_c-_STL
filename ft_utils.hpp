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
	template <typename U>
	class less {
	public:
		bool operator()(const U& a, const U& b) {
			return (b > a);
		}
	};
}


#endif
