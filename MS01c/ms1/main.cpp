
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

void vectorPrint(vector<double>& V) {
	for (auto col : V)
		cout << col << " ";
	cout << "\n";
};
void matrixPrint(vector<vector<double>>& M) {
	for (auto row : M)
		vectorPrint(row);
};

auto matTranspose(vector<vector<double>>& Y, vector<vector<double>>& X) {
	size_t rows = X.size();    //  number of rows    for matrix X
	size_t cols = X[0].size(); //  number of columns for matrix X
	Y.resize(cols);             // set nunber of rows for Y
	for (auto&e : Y)             // set nunber of cols for each row of Y
		e.resize(rows);
	for (size_t r = 0; r < rows; r++)   // copy data
		for (size_t c = 0; c < cols; c++)
			Y[c][r] = X[r][c];
};

auto matMult(vector<double>& Y, vector<vector<double>>& M, vector<double>& X) { // Y = M * X
	for (size_t i = 0; i < M.size(); i++)
		Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
};

class NeuralNetwork {

public:
	vector <double> synaptic_weights;

	NeuralNetwork() {
		srand(1);
		synaptic_weights.resize(3);
		for (int i = 0; i < 3; i++) {
			synaptic_weights[i] = 2. * rand() / double(RAND_MAX) - 1.;
		}
	};

	double __sigmoid(double x) {
		return 1. / (1. + exp(-x));
	};

	double __sigmoid_derivative(double x) {

		return x * (1. - x);
	};

	void train(vector<vector<double>>&training_set_inputs, vector<double>&training_set_outputs, int number_of_training_iterations)
	{
		vector<double> output(training_set_inputs.size());
		vector<double> error(training_set_inputs.size());
		vector<double> adjustments(training_set_inputs.size());
		vector<vector<double>> training_set_inputsT;
		matTranspose(training_set_inputsT, training_set_inputs);

		for (int iteration = 0; iteration < number_of_training_iterations; iteration++) {
			think(output, training_set_inputs);

			transform(training_set_outputs.begin(), training_set_outputs.end(),
				output.begin(), error.begin(), [](double t, double o) { return t - o; });

			transform(error.begin(), error.end(),
				output.begin(), output.begin(), [this](double e, double o) { return e * __sigmoid_derivative(o); });

			matMult(adjustments, training_set_inputsT, output);

			transform(synaptic_weights.begin(), synaptic_weights.end(),
				adjustments.begin(), synaptic_weights.begin(), [](double w, double a) { return w + a; });
		}
	};

	double think(vector <double>& input) {
		return __sigmoid(inner_product(input.begin(), input.end(), synaptic_weights.begin(), 0.));
	};
	void think(vector <double>& output, vector<vector<double>>& inputs) {
		matMult(output, inputs, synaptic_weights);
		for (auto&e : output) e = __sigmoid(e);
	};

};

int main() {

	NeuralNetwork neural_network;
	vector <vector<double>> training_set_inputs{ { 0,0,1 },
	{ 1,1,1 },
	{ 1,0,1 },
	{ 0,1,1 } };
	vector <double> training_set_outputs{ 0, 1, 1, 0 };

	cout << "Ramdom start synaptic weights";
	vectorPrint(neural_network.synaptic_weights);
	cout << "training_set_inputs\n";
	matrixPrint(training_set_inputs);
	cout << "training_set_outputs: ";
	vectorPrint(training_set_outputs);

	neural_network.train(training_set_inputs, training_set_outputs, 10000);

	cout << "New synapitc weights after training: "; 
	vectorPrint(neural_network.synaptic_weights);

	cout << "Considereing new situation [1,0,0] -> ?: ";
	vector<double> input = { 1,0 ,0 };
	cout << setprecision(8) << neural_network.think(input) << "\n"; 

	return 0;
}