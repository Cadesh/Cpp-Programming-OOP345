
/*
https://scs.senecac.on.ca/~john.blair/workshops/w7.html

Here are the nine lines of Python code :
++++++++++++++++++++++++++++++++++++++++++ + nine.py
from numpy import exp, array, random, dot
training_set_inputs = array([[0, 0, 1], [1, 1, 1], [1, 0, 1], [0, 1, 1]])
training_set_outputs = array([[0, 1, 1, 0]]).T
random.seed(1)
synaptic_weights = 2 * random.random((3, 1)) - 1
for iteration in xrange(10000) :
output = 1 / (1 + exp(-(dot(training_set_inputs, synaptic_weights))))
synaptic_weights += dot(training_set_inputs.T, (training_set_outputs - output) * output * (1 - output))
print 1 / (1 + exp(-(dot(array([1, 0, 0]), synaptic_weights))))
++++++++++++++++++++++++++++++++++++++++++ + nine.
*/

//CONVERT THE ABOVE PYTHON CODE TO C++

#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <numeric>      // std::inner_product
#include <algorithm>   // transform
#include <iomanip>     // setprecision

using namespace std;

auto matTranspose (vector<vector<double>>& Y, vector<vector<double>>& X) {
	size_t rows = X.size();    //  number of rows    for matrix X
	size_t cols = X[0].size(); //  number of columns for matrix X
	Y.resize(cols);             // set nunber of rows for Y
	for (auto&e : Y)             // set nunber of cols for each row of Y
		e.resize(rows);
	for (size_t r = 0; r < rows; r++)   // copy data
		for (size_t c = 0; c < cols; c++)
			Y[c][r] = X[r][c];
};

auto matMult (vector<double>& Y, vector<vector<double>>& M, vector<double>& X) { // Y = M * X
	for (size_t i = 0; i < M.size(); i++)
		Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
};

auto vectorPrint (vector<double>& V) {
	for (auto col : V)
		cout << col << " ";
	cout << "\n";
};
auto matrixPrint (vector<vector<double>>& M) {
	for (auto row : M)
		vectorPrint(row);
};

void main(void) {

	vector <vector<double>> training_set_inputs{ { 0,0,1 },
	                                             { 1,1,1 },
	                                             { 1,0,1 },
	                                             { 0,1,1 } };
	vector <double> training_set_outputs{ 0, 1, 1, 0 };

	cout << "training_set_inputs\n";
	matrixPrint(training_set_inputs);
	cout << "training_set_outputs: ";
	vectorPrint(training_set_outputs);

	srand(1); //random seed 1

	//get 3x1 vector of decimal random numbers from -1 to +1 decimals
	vector <double> synaptic_weights(training_set_inputs[0].size());
	//for (int i = 0; i < 2; i++) {
	//	synaptic_weights[i] = (2 * (rand() / double(RAND_MAX))) - 1.;
	//}
	for (auto& e : synaptic_weights)
		e = 2. * rand() / double(RAND_MAX) - 1.;

	cout << "synaptic_weights: ";
	vectorPrint(synaptic_weights);
	
	vector<vector<double>> training_set_inputsT;
	matTranspose(training_set_inputsT, training_set_inputs);

	vector<double> output(training_set_outputs.size());
	vector<double> correction(training_set_outputs.size());

	int iterate = 10000;
	cout << "iterate=" << iterate << "\n";

	for (int i = 0; i < iterate; i++) {

		matMult(output, training_set_inputs, synaptic_weights);

		transform(output.begin(), output.end(),	output.begin(),
			[](double element) { return 1. / (1. + exp(-element)); });  // sigmoid


		transform(training_set_outputs.begin(), training_set_outputs.end(),   // prediction error * sigmoid derivative
			output.begin(),
			output.begin(),
			[](double t, double o) { return (t - o) * o * (1. - o); }
		);
		matMult(correction, training_set_inputsT, output);                    // weight correction
		transform(synaptic_weights.begin(), synaptic_weights.end(),           // update weights
			correction.begin(),
			synaptic_weights.begin(),
			[](double weight, double correction) { return weight += correction; }
		);
	}
	cout << "synaptic_weights: ";
	vectorPrint(synaptic_weights);

	vector<double> input = { 1,0,0 };
	cout << "input: ";
	vectorPrint(input);
	cout << "1 / (1 + exp(-dot(input, synaptic_weights))): "; // sigmoid( dot(input, weights) )
	cout << setprecision(8)  // C++ defaults to 6 decimal places. Python  defaults to 8.
		<< 1. / (1. + exp(-inner_product(input.begin(), input.end(), synaptic_weights.begin(), 0.))) << "\n";
	return;
}


