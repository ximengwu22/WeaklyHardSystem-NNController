CXX = g++-8
HOME= /usr/local/include
LIBS = -lflowstar -lmpfr -lgmp -lgsl -lgslcblas -lm -lglpk -lpython3.6m -lboost_filesystem -lboost_system -lboost_iostreams
CFLAGS = -I . -I../flowstar -I $(HOME) -I /usr/include/python3.6m/ -g -O3 -std=c++11
LINK_FLAGS = -g -L ../graph -L/usr/local/lib -L../flowstar
OBJ = Interval.o Variables.o settings.o Matrix.o Geometry.o Constraints.o Continuous.o lex.yy.o modelParser.tab.o


../graph_in_grids: graph_in_grids.o
	g++ -O3 -w $(LINK_FLAGS) -o $@ $^ $(OBJ) libbernstein_poly_approx.a $(LIBS)

%.o: %.cc
	$(CXX) -O3 -c $(CFLAGS) -o $@ $<
%.o: %.cpp
	$(CXX) -O3 -c $(CFLAGS) -o $@ $<
%.o: %.c
	$(CXX) -O3 -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o graph_in_grids
