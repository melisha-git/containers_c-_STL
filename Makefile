SRC = main.cpp containers/vector/test_vector.cpp containers/map/test_map.cpp containers/stack/test_stack.cpp

SRCUTILS = utils_containers/main.cpp

FLAGS = -Wall -Werror -Wextra

DELETE = a.out vector.class.hpp.gch map.class.hpp.gch ft_utils.hpp.gch iterators/vector_iterator.hpp.gch containers/map/map.class.hpp.gch containers/vector/vector.class.hpp.gch

all: 
	clang++ $(SRC) && ./a.out && rm -rf $(DELETE)
vector :
	clang++ $(SRC) && ./a.out 'vector' && rm -rf $(DELETE)

map :
	clang++ $(SRC) && ./a.out 'map' && rm -rf $(DELETE)

stack :
	clang++ $(SRC) && ./a.out 'stack' && rm -rf $(DELETE)

utils :
	clang++ $(SRCUTILS) && ./a.out && rm -rf $(DELETE)

clean :
	rm -rf $(DELETE)

.PHONY: vector clean