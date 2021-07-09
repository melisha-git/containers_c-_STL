#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

namespace ft {
	template<class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() {}
		pair(first_type const& t1, second_type const& t2) : first(t1), second(t2) {}
		template <class _U1, class _U2>
		pair(const pair<_U1, _U2>& p) : first(p.first), second(p.second) {}
		pair& operator= (const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}

		friend bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return lhs.first == rhs.first && lhs.second == lhs.second;
		}
		friend bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return !(lhs == rhs);
		}
		friend bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}
		friend bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return rhs < lhs;
		}
		friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return !(rhs < lhs);
		}
		friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return !(lhs<rhs);
		}
	};
}

#endif