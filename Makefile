HOME = /usr/local/include
OBJ = Interval.o Variables.o settings.o Matrix.o Geometry.o Constraints.o Continuous.o lex.yy.o modelParser.tab.o
CPP = graph_in_grids.cpp
LIBS = -lflowstar -lmpfr -lgmp -lgsl -lgslcblas -lm -lglpk -lpython3.6m -lboost_filesystem -lboost_system -lboost_iostreams
LINK_FLAGS = -g -L/usr/local/lib
CFLAGS = -I . -I $(HOME) -I /usr/include/python3.6m/ -g -O3 -std=c++11

.ONESHELL:
all: graph/graph_in_grids.cpp
	@cd flowstar
	@$(MAKE)
	@$(foreach file, $(OBJ), cp $(file) ../graph;)
	@cd ../graph
	@g++ -c bernstein_poly_approx.cpp -I/usr/include/python3.6m/ -lpython3.6m 
	@ar -cr libbernstein_poly_approx.a bernstein_poly_approx.o
	@g++-8 -O3 -w $(LINK_FLAGS) -o ../saw-grids $(CPP) $(OBJ) libbernstein_poly_approx.a $(LIBS) -I../flowstar
	@cd ..

clean:
	@rm -f saw-grids ./graph/*.o
	@cd flowstar
	@$(MAKE) clean
	@cd ..
