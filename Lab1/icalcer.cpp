#include "icalcer.h"

namespace calc
{
	double ICalcer::GetIncrement(double a, double b, UINT n) const noexcept
	{
		if (n == 0)
			n = dot_quantity_;

		if (dot_quantity_ || accuracy_)
			return ((b - a) / (double)n);
		else if (increment_)
			return increment_;
		else
			return 0.0;
	}

	UINT ICalcer::GetDotQuantity(double a, double b, double inc) const noexcept
	{
		if (inc == 0.0)
			inc = increment_;

		if (increment_)
			return (b - a) / inc;
		else if (dot_quantity_)
			return dot_quantity_;
		else
			return 0;
	}

	ICalcer::ICalcer()
	{
		dot_quantity_ = 0;
		increment_ = 0.0;
		accuracy_ = 0.0;
	}

	void ICalcer::SetDotQuantity(UINT quantity)
	{
		dot_quantity_ = quantity;
		increment_ = 0.0;
		accuracy_ = 0.0;
	}

	void ICalcer::SetIncrement(double increment)
	{
		dot_quantity_ = 0;
		increment_ = increment;
		accuracy_ = 0.0;
	}

	void ICalcer::SetAccuracy(double accuracy)
	{
		dot_quantity_ = 0;
		increment_ = 0.0;
		accuracy_ = accuracy;
	}

	std::optional<double> TrapezeCalcer::calcInt(double(*func)(double), double a, double b) noexcept
	{
		if (!(increment_ || dot_quantity_ || accuracy_))
			return std::nullopt;
		
		if (increment_ || dot_quantity_)
		{
			UINT n = GetDotQuantity(a, b);
			double inc = GetIncrement(a, b);

			return CalculateTrapeze(func, a, b, inc, n);
		}
		else
		{
			UINT n = 1;

			double I_2, I_1 = CalculateTrapeze(func, a, b, GetIncrement(a, b, n), n);
			while (true)
			{
				n *= 2;
				I_2 = CalculateTrapeze(func, a, b, GetIncrement(a, b, n), n);

				if (abs(I_2 - I_1) <= accuracy_)
					break;

				I_1 = I_2;
			}

			return I_2;
		}
	}

	double TrapezeCalcer::CalculateTrapeze(double(*func)(double), double a, double b, double inc, UINT n)
	{
		double sum = 0;

		double x = a + inc;
		for (auto i = 1; i != n; i++)
		{
			sum += func(x);
			x += inc;
		}

		sum += (func(a) + func(b)) / 2.0;

		return (sum * inc);
	}

	std::optional<double> SimpsonCalcer::calcInt(double(*func)(double), double a, double b) noexcept
	{
		if (!(increment_ || dot_quantity_ || accuracy_))
			return std::nullopt;

		if (increment_ || dot_quantity_)
		{
			UINT n = GetDotQuantity(a, b);
			double inc = GetIncrement(a, b);

			return CalculateSimpson(func, a, b, inc, n);
		}
		else
		{
			UINT n = 1;

			double I_2, I_1 = CalculateSimpson(func, a, b, GetIncrement(a, b, n), n);
			while (true)
			{
				n *= 2;
				I_2 = CalculateSimpson(func, a, b, GetIncrement(a, b, n), n);

				if (abs(I_2 - I_1) <= accuracy_)
					break;

				I_1 = I_2;
			}

			return I_2;
		}
	}

	double calc::SimpsonCalcer::CalculateSimpson(double(*func)(double), double a, double b, double inc, UINT n)
	{
		double sum = 0;

		double x = a + inc;
		for (auto i = 1; i != n; i++)
		{
			sum += func(x);
			x += inc;
		}

		x = a + 0.5 * inc;
		for (auto i = 1; i != n; i++)
		{
			sum += 2 * func(x);
			x += inc;
		}

		sum += (func(a) + func(b)) / 2.0;

		return (sum * inc / 3.0);
	}
}