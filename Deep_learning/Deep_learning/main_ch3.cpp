/*
Programming Feed-forward of a Single Neuron
C++ Implementation of a Single Neuron
*/

#include <iostream>

#define MAX2(a, b) (a) > (b) ? (a) : (b) // Max macro

class Neuron
{
public:
	double w_; // weight of one input
	double b_; // bias

	double getAct(const double& x)
	{
		// (1) for linear or identity activation functions
		return x;

		// (2) for ReLU activation functions
		// return MAX2(0.0, x);
	}

	double feedForward(const double& input)
	{
		// output y = f(\sigma)
		// \sigma = w_ * input x + b
		// for multiple inputs, \sigma = (w0_ * x0_ + w1_ * w1 + ...) + b

		const double sigma = w_ * input + b_;

		return getAct(sigma);
	}
};

void main()
{
	Neuron my_neuron;
	my_neuron.w_ = 2.0;
	my_neuron.b_ = 1.0;

	std::cout << "Input = 0.0" << my_neuron.feedForward(0.0) << std::endl;
	std::cout << "Input = 1.0" << my_neuron.feedForward(1.0) << std::endl;
	std::cout << "Input = 2.0" << my_neuron.feedForward(2.0) << std::endl;
	std::cout << "Input = 3.0" << my_neuron.feedForward(3.0) << std::endl;
}