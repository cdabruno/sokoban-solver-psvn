CC = gcc
CXX = g++
OPT = -g -Wall -O3 -Wno-unused-function -Wno-unused-variable
PSVNOPT = --no_state_map --no_abstraction --no_backwards_moves --history_len=0

psvn2c_core.c:
	cp ../psvn/psvn2c_core.c ./psvn2c_core.c

psvn2c_state_map.c:
	cp ../psvn/psvn2c_state_map.c ./psvn2c_state_map.c

psvn2c_abstraction.c:
	cp ../psvn/psvn2c_abstraction.c ./psvn2c_abstraction.c

%.c: %.psvn  psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c  $(PSVNOPT) --name=$(*F)  < $< > $@
	rm -f ./psvn2c_core.c ./psvn2c_state_map.c ./psvn2c_abstraction.c

.PRECIOUS: %.c

%.sokobanSolver: %.c sokobanSolver.cpp
	$(CXX) $(OPT) sokobanSolver.cpp -include $< -o $@

.PHONY : clean
clean:
	rm -f *.sokobanSolver *.o sokobanSolver.c psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
