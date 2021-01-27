//
// Created by Simone Wu on 10/29/20.
//

//#include "nn_1_relu.h"

//#include ".../bp/flowstar/Continuous.h"
#include "../bp/bernstein_poly_approx.h"
#include<fstream>
#include<ctime>

using namespace std;
using namespace flowstar;


int main()
{
    // Declaration of the state variables.
//    unsigned int numVars = 3;
//
//    int x0_id = stateVars.declareVar("x0");
//    int x1_id = stateVars.declareVar("x1");
//    int u_id = stateVars.declareVar("u");
//
//    int domainDim = numVars + 1;
//
//
//    // Define the continuous dynamics.
//    Expression_AST<Real> deriv_x0("x1");  // theta_r = 0
//    Expression_AST<Real> deriv_x1("u*x1^2-x0");
//    Expression_AST<Real> deriv_u("0");
//
//    vector<Expression_AST<Real> > ode_rhs(numVars);
//    ode_rhs[x0_id] = deriv_x0;
//    ode_rhs[x1_id] = deriv_x1;
//    ode_rhs[u_id] = deriv_u;
//
//    Deterministic_Continuous_Dynamics dynamics(ode_rhs);
//
//    // Specify the parameters for reachability computation.
//    Computational_Setting setting;
//
//    unsigned int order = 6;
//
//    // stepsize and order for reachability analysis
//    setting.setFixedStepsize(0.005, order);
//
//    // time horizon for a single control step
//    setting.setTime(0.2);
//
//    // cutoff threshold
//    setting.setCutoffThreshold(1e-10);
//
//    // queue size for the symbolic remainder
//    setting.setQueueSize(1000);
//
//    // print out the steps
//    setting.printOn();
//
//    // remainder estimation
//    Interval I(-0.01, 0.01);
//    vector<Interval> remainder_estimation(numVars, I);
//    setting.setRemainderEstimation(remainder_estimation);
//
//    setting.printOff();
//
//    setting.prepare();

    /*
     * Initial set can be a box which is represented by a vector of intervals.
     * The i-th component denotes the initial set of the i-th state variable.
     */
//    Interval init_x0(0.8,0.9), init_x1(0.5,0.6), init_u(0);
//    std::vector<Interval> X0;
//    X0.push_back(init_x0);
//    X0.push_back(init_x1);
//    X0.push_back(init_u);
    // translate the initial set to a flowpipe
//    Flowpipe initial_set(X0);

    // define the neural network controller
    char const *module_name = "controller_approximation_lib";
    char const *function_name1 = "poly_approx_controller";
    char const *function_name2 = "poly_approx_error";
    char const *function_name3 = "network_lips";
    char const *degree_bound = "[1, 1]";
    char const *activation = "ReLU";
    char const *output_index = "0";
    char const *neural_network = "nn_1_relu";

//    vector<Interval> box;
//    initial_set.intEval(box, order, setting.tm_setting.cutoff_threshold);
//    string strBox = "[" + box[0].toString() + "," + box[1].toString() + "]";
    string strBox =  "[[0.8,0.9],[0.5,0.6]]";

    string strExpU = bernsteinPolyApproximation(module_name, function_name1, degree_bound, strBox.c_str(), activation, output_index, neural_network);

    double err = stod(bernsteinPolyApproximation(module_name, function_name2, degree_bound, strBox.c_str(), activation, output_index, neural_network));

    cout << "NNC: " << *neural_network << " BP:" << strExpU << endl;

    return 0;
}