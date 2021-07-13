SRCVEC = main.cpp containers/vector/vector.class.hpp iterators/vector_iterator.hpp containers/vector/test_vector.cpp

SRCMAP = containers/map/main.cpp containers/map/map.class.hpp

SRCUTILS = utils_containers/main.cpp

FLAGS = -Wall -Werror -Wextra

DELETE = a.out vector.class.hpp.gch map.class.hpp.gch ft_utils.hpp.gch iterators/vector_iterator.hpp.gch containers/map/map.class.hpp.gch

vector :
	clang++ $(SRCVEC) && ./a.out 'vector' && rm -rf $(DELETE)

map :
	clang++ $(SRCMAP) && ./a.out && rm -rf $(DELETE)

utils :
	clang++ $(SRCUTILS) && ./a.out && rm -rf $(DELETE)

clean :
	rm -rf $(DELETE)

.PHONY: vector clean