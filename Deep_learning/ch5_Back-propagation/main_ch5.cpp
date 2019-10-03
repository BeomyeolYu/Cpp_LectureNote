/*
Programming Back-propagation
C++ Implementation of a Single Neuron
*/

#include <iostream>
#include <stdio.h>
#define MAX2(a, b) (a) > (b) ? (a) : (b) // Max macro

class Neuron
{
public:
	Neuron()
		: w_(2.0), b_(1.0)
	{}

	Neuron(const double& w_input, const double& b_input)
		: w_(w_input), b_(b_input)
	{}

public: // attributes
	double w_; // weight
	double b_; // bias

	double input_, output_; // saved for back-prop

public: // behaviors
	double feedForward(const double& _input)
	{
		input_ = _input; // save input

		const double sigma = (w_ * input_) + b_;

		output_ = getAct(sigma); // save output

		return output_;
	}

	void propBackward(const double& target)
	{
		const double alpha = 0.1; // learning rate

		const double grad = (output_ - target) * getActGrad(output_);

		// w_ = w_ - alpha * grad * input_;
		w_ -= alpha * grad * input_; // last input_ came from d(wx+b)/dw = x
		b_ -= alpha * grad * 1.0;	 // last 1.0 came from d(wx+b)/db = 1
		// 1.0 will be deleted due to optimization
	}

	double getAct(const double& x) // Activation
	{
		// (1) for linear or identity activation functions
		return x;

		// (2) for ReLU activation functions
		// return MAX2(0.0, x);
	}

	double getActGrad(const double& x) // = f_dot (= round(f)/round(sigma))
	{
		// (1) for linear or identity activation functions
		return 1.0;

		// (2) for ReLU activation functions
		//if (x > 0.0)
		//	return 1.0;
		//else
		//	return 0.0;
	}

	void feedForwardAndPrint(const double& input)
	{
		printf("%f %f \n", input, feedForward(input));
	}
};

void main()
{
	// initialize my_neuron, w = 2.0, b = 1.0
	Neuron my_neuron(2.0, 1.0);

	my_neuron.feedForwardAndPrint(1.0);	// input = 1.0
	my_neuron.propBackward(4.0);		// target = 4.0
	my_neuron.feedForwardAndPrint(1.0); // result = 3.2

	for (int r = 0; r < 100; r++) // number of iteration = 100
	{
		std::cout << "Traing: " << r << std::endl;
		my_neuron.feedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		std::cout << "w = " << my_neuron.w_ << ", b = " << my_neuron.b_ << std::endl;
	}
}