#include "fraction.h"

namespace frac
{
	Fraction::Fraction(long num, long denum)
	{
		numerator_ = num;
		denominator_ = denum;
	}

	Fraction::~Fraction() {}

	long Fraction::GetNum() const noexcept { return numerator_; }

	long Fraction::GetDenom() const noexcept { return denominator_; }

	void Fraction::SetNum(long num) noexcept { numerator_ = num; }

	void frac::Fraction::SetDenom(long denom) noexcept { denominator_ = denom; }

	void Fraction::Reduce() noexcept
	{
		if (numerator_ % denominator_ == 0)
		{
			numerator_ = numerator_ / denominator_;
			denominator_ = 1;
			return;
		}

		while (true) {
			long check_num = numerator_ < denominator_ ? abs(numerator_) : abs(denominator_);

			bool cycle_ended = true;
			for (auto a = 2; a <= check_num; a++)
			{
				bool is_num_divided = (numerator_ % a == 0);
				bool is_denom_divided = (denominator_ % a == 0);

				if (is_num_divided && is_denom_divided)
				{
					numerator_ /= a;
					denominator_ /= a;
					cycle_ended = false;
					break;
				}
			}

			if (cycle_ended)
				break;
		}
	}

	void Fraction::Print() const noexcept
	{
		std::cout << numerator_ << " / " << denominator_ << '\n';
	}

	Fraction Fraction::Summation(Fraction& a, Fraction& b) noexcept
	{
		long nom = a.GetNum() * b.GetDenom() + b.GetNum() * a.GetDenom();
		long denum = a.GetDenom() * b.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction frac::Fraction::Summation(double a, Fraction& b) noexcept
	{
		long nom = a * b.GetDenom() + b.GetNum();
		long denum = b.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Subtraction(Fraction& a, Fraction& b) noexcept
	{
		long nom = a.GetNum() * b.GetDenom() - b.GetNum() * a.GetDenom();
		long denum = a.GetDenom() * b.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Subtraction(double a, Fraction& b) noexcept
	{
		long nom = a * b.GetDenom() - b.GetNum();
		long denum = b.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Subtraction(Fraction& a, double b) noexcept
	{
		long nom = a.GetNum() - b * a.GetDenom();
		long denum = a.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Multiplication(Fraction& a, Fraction& b) noexcept
	{
		long nom = a.GetNum() * b.GetNum();
		long denum = a.GetDenom() * b.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Multiplication(double a, Fraction& b) noexcept
	{
		long nom = a * b.GetNum();
		long denum = b.GetDenom();
		Fraction result(nom, denum);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Division(Fraction& a, Fraction& b)
	{
		if (b.GetNum() == 0)
			throw std::runtime_error("Error: Attempted to divide by Zero\n");

		Fraction temp(b.GetDenom(), b.GetNum());
		Fraction result = Multiplication(a, temp);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Division(double a, Fraction& b)
	{
		if (b.GetNum() == 0)
			throw std::runtime_error("Error: Attempted to divide by Zero\n");

		Fraction temp(b.GetDenom(), b.GetNum());
		Fraction result = Multiplication(a, temp);
		result.Reduce();

		return result;
	}

	Fraction Fraction::Division(Fraction& a, double b)
	{
		if (b == 0)
			throw std::runtime_error("Error: Attempted to divide by Zero\n");

		Fraction temp(1, b);
		Fraction result = Multiplication(a, temp);
		result.Reduce();

		return result;
	}

	Fraction Fraction::NumToFrac(double a) noexcept
	{
		unsigned int denom = 1;
		while (a - (int)a != 0.0)
		{
			a *= 10;
			denom *= 10;
		}
		Fraction frac(a, denom);
		frac.Reduce();

		return frac;
	}

	double Fraction::FracToNum() const noexcept
	{
		return ((double)this->numerator_ / (double)this->denominator_);
	}

	MixedFraction Fraction::FracToMixedFrac() const noexcept
	{
		MixedFraction result;
		result.fract.denominator_ = this->denominator_;

		long long temp_num = this->numerator_;

		while (temp_num - this->denominator_ >= 0)
		{
			temp_num -= this->denominator_;
			result.integer++;
		}

		result.fract.numerator_ = temp_num;
		return result;
	}

	bool Fraction::AreEqual(Fraction a, Fraction b) noexcept
	{
		a.Reduce();
		b.Reduce();

		bool are_nums_equal = (a.GetNum() == b.GetNum());
		bool are_denoms_equal = (a.GetDenom() == b.GetDenom());
		if (are_nums_equal && are_denoms_equal)
			return true;

		return false;
	}

	bool Fraction::AreEqual(Fraction a, double b) noexcept
	{
		return AreEqual(a, NumToFrac(b));
	}

	Fraction Fraction::GetBiggest(Fraction a, Fraction b) noexcept
	{
		a.Reduce();
		b.Reduce();

		long num_a = a.GetNum() * b.GetDenom();
		long num_b = b.GetNum() * a.GetDenom();

		return (num_a < num_b ? b : a);
	}

	Fraction Fraction::GetSmallest(Fraction a, Fraction b) noexcept
	{
		a.Reduce();
		b.Reduce();

		long num_a = a.GetNum() * b.GetDenom();
		long num_b = b.GetNum() * a.GetDenom();

		return (num_a < num_b ? a : b);
	}

	bool Fraction::isGreater(Fraction a, Fraction b) noexcept
	{
		return (a == GetBiggest(a, b) ? true : false);
	}

	bool Fraction::isGreater(double a, Fraction b) noexcept
	{
		return isGreater(NumToFrac(a), b);
	}

	bool Fraction::isSmaller(Fraction a, Fraction b) noexcept
	{
		return (a == GetSmallest(a, b) ? true : false);;
	}

	bool frac::Fraction::isSmaller(double a, Fraction b) noexcept
	{
		return isSmaller(NumToFrac(a), b);
	}

	Fraction Fraction::operator+(Fraction& frac) noexcept		{ return Summation(*this, frac); }

	Fraction Fraction::operator+(double frac) noexcept			{ return Summation(frac, *this); }

	Fraction operator+(double frac1, Fraction& frac2) noexcept	{ return Fraction::Summation(frac1, frac2); }


	Fraction Fraction::operator-(Fraction& frac) noexcept		{ return Subtraction(*this, frac); }

	Fraction Fraction::operator-(double frac) noexcept			{ return Subtraction(*this, frac); }

	Fraction operator-(double frac1, Fraction& frac2) noexcept	{ return Fraction::Subtraction(frac1, frac2); }


	Fraction Fraction::operator*(Fraction& frac) noexcept		{ return Multiplication(*this, frac); }

	Fraction Fraction::operator*(double frac) noexcept			{ return Multiplication(frac, *this); }

	Fraction operator*(double frac1, Fraction& frac2) noexcept	{ return Fraction::Multiplication(frac1, frac2); }


	Fraction Fraction::operator/(Fraction& frac)				{ return Division(*this, frac); }

	Fraction Fraction::operator/(double frac)					{ return Division(*this, frac); }

	Fraction operator/(double frac1, Fraction& frac2)			{ return Fraction::Division(frac1, frac2); }


	bool Fraction::operator==(Fraction frac) noexcept			{ return AreEqual(*this, frac); }

	bool Fraction::operator==(double frac) noexcept				{ return AreEqual(*this, frac); }

	bool operator==(double frac1, Fraction frac2) noexcept		{ return Fraction::AreEqual(frac2, frac1); }


	bool Fraction::operator> (Fraction frac) noexcept			{ return isGreater(*this, frac); }

	bool Fraction::operator>(double frac) noexcept				{ return isSmaller(frac, *this); }

	bool operator>(double frac1, Fraction frac2) noexcept		{ return Fraction::isGreater(frac1, frac2); }


	bool Fraction::operator<(Fraction frac) noexcept			{ return isSmaller(*this, frac); }

	bool Fraction::operator<(double frac) noexcept				{ return isGreater(frac, *this); }

	bool operator<(double frac1, Fraction frac2) noexcept		{ return Fraction::isSmaller(frac1, frac2); }


	bool Fraction::operator>= (Fraction frac) noexcept			{ return (!isSmaller(*this, frac)); }

	bool Fraction::operator>=(double frac) noexcept				{ return (!isGreater(frac, *this)); }

	bool operator>=(double frac1, Fraction frac2) noexcept		{ return (!Fraction::isSmaller(frac1, frac2)); }


	bool Fraction::operator<= (Fraction frac) noexcept			{ return (!isGreater(*this, frac)); }

	bool Fraction::operator<=(double frac) noexcept				{ return (!isSmaller(frac, *this)); }

	bool operator<=(double frac1, Fraction frac2) noexcept		{ return (!Fraction::isGreater(frac1, frac2)); }
}