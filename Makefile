SRC = main.cpp containers/vector/test_vector.cpp containers/map/test_map.cpp containers/stack/test_stack.cpp

SRCUTILS = utils_containers/main.cpp

FLAGS = -Wall -Werror -Wextra

DELETE = a.out vector.class.hpp.gch map.class.hpp.gch ft_utils.hpp.gch iterators/vector_iterator.hpp.gch containers/map/map.class.hpp.gch containers/vector/vector.class.hpp.gch

all: compiler
	./a.out && rm -rf $(DELETE)
vector : compiler
	./a.out 'vector' && rm -rf $(DELETE)

map : compiler
	./a.out 'map' && rm -rf $(DELETE)

stack : compiler
	./a.out 'stack' && rm -rf $(DELETE)

compiler :
	clang++ $(FLAGS) $(SRC)

clean :
	rm -rf $(DELETE)

.PHONY: all vector map stack compiler clean