/*
Programming The Gradient Descent Method
*/

#include <iostream>

class MyFuction // Linear function 
{
public:
	float a_, b_;

	MyFuction() 
		: a_(0.0f), b_(0.0f) // initialization
	{}

	float getValue(const float& x)
	{
		return a_ * x + b_; // y = ax + b; linear hypothesis
	}
};

void main()
{
	MyFuction mf;

	// (1) single constraint (= sample)
	/*
	const float y_t0 = 1.0f; // y_target
	const float x_0 = 0.0f;  // input

	const float alpha = 0.01f;

	for (int i = 0; i < 1000; i++)
	{
		const float error = y_t0 - mf.getValue(x_0); // E = y_target - y_output (not squared error)

		std::cout << "Squared Error = " << 0.5*error*error << std::endl; // Print a squared error

		const float Ea = error * -x_0; // partial derivative of a
		const float Eb = error * -1;   // partial derivative of b 

		mf.a_ -= alpha * Ea;
		mf.b_ -= alpha * Eb;
	}
	std::cout << std::endl;
	std::cout << "y_target = " << y_t0 << "and y_output = " << mf.getValue(x_0) << std::endl; // y_output
	*/

	// (2) Muliple constraint (= Muliple sample)
	// Mean squared Error
	/*
	const int num_const = 3; // = number of sample
	const float y_t[num_const] = { 1.0f, 1.5f, 2.0f };
	const float x[num_const] = { 0.0f, 0.5f, 1.0f };
	const float alpha = 0.01f;

	for (int i = 0; i < 1000; i++)
	{
		float sqr_error_sum = 0.0f;
		float Ea_sum = 0.0f;
		float Eb_sum = 0.0f;

		for (int c = 0; c < num_const; c++)
		{
			const float error = y_t[c] - mf.getValue(x[c]);
			const float Ea = error * -x[c];
			const float Eb = error * -1;

			sqr_error_sum += error * error;
			Ea_sum += Ea;
			Eb_sum += Eb;
		}

		std::cout << "Squared Error = " << 0.5*sqr_error_sum << std::endl;

		mf.a_ -= alpha * Ea_sum / (float)num_const;
		mf.b_ -= alpha * Eb_sum / (float)num_const;
	}
	std::cout << mf.a_ << " "<< mf.b_ << std::endl;
	*/

	// (3) Stochastic Gradient Descent Method
	// Mean squared Error는 평균적으로 만족하는 에러를 사용하는 것에 반해 SGD는 랜덤하게 선발하여 훈련시킴.
	// Stochastic한 기법으로 전체적으로 학습을 시키다가 월등한 경우를 선발하여 반복 학습. 
	const int num_const = 3; // = number of sample
	const float y_t[num_const] = { 1.0f, 1.5f, 2.0f };
	const float x[num_const] = { 0.0f, 0.5f, 1.0f };
	const float alpha = 0.01f;

	for (int i = 0; i < 1000; i++)
	{
		int c = rand() % num_const;

		const float error = y_t[c] - mf.getValue(x[c]);
		const float Ea = error * -x[c];
		float Eb = error * -1;

		std::cout << "Squared Error = " << 0.5*error*error << std::endl;

		mf.a_ -= alpha * Ea;
		mf.b_ -= alpha * Eb;
	}
	std::cout << mf.a_ << " " << mf.b_ << std::endl;
}