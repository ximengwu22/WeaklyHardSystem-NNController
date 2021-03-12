# Safety Verification Tool on Neural Network Controlled System with Weakly-hard Constraints
This tool is constructed on the basis of #SAW, and it's designed for safety verification analysis of Neural Network Controlled System with Weakly-hard Constraints.

## Dependency
- GNU MPFR Library	http://gmplib.org/
- GNU MPFR Library	http://www.mpfr.org/
- GNU Scientific Library	http://www.gnu.org/software/gsl/
- GNU Linear Programming Kit	http://www.gnu.org/software/glpk/
- Bison - GNU parser generator	http://www.gnu.org/software/bison/
- Flex: The Fast Lexical Analyzer	http://flex.sourceforge.net/
- Gnuplot	http://www.gnuplot.info/
- Boost C++ Library	https://www.boost.org/
- Python3.6

## Installation
Build in your own environment:

Step 1:


Step 2 (We Strongly suggest you using **g++-8** to build the project):
```
cd ./graph
make
cd ..
```

## Usage:
1. Create model file in repo ./example/ as followed:
2. Flow* configuration is also alternatively changeable. 

## Reference:
[1]SAW: https://github.com/551100kk/SAW
[2]Bernstein Polynomial: https://github.com/JmfanBU/ReachNNStar/tree/master/ReachNN/Bernstein_Polynomial_Approximation 
