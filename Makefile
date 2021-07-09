SRCVEC = main.cpp vector.class.hpp iterators/vector_iterator.hpp test_vector.cpp ft_utils.hpp

SRCMAP = main.cpp map.class.hpp ft_utils.hpp test_vector.cpp

SRCUTILS = utils_containers/main.cpp

FLAGS = -Wall -Werror -Wextra

DELETE = a.out vector.class.hpp.gch map.class.hpp.gch ft_utils.hpp.gch iterators/vector_iterator.hpp.gch

vector :
	clang++ $(SRCVEC) && ./a.out 'vector' && rm -rf $(DELETE)

map :
	clang++ $(SRCMAP) && ./a.out 'map' && rm -rf $(DELETE)

utils :
	clang++ $(SRCUTILS) && ./a.out

clean :
	rm -rf $(DELETE)

.PHONY: vector clean