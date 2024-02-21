#pragma once
#include <vector>
#include <iostream>

namespace frac
{
	// ����� ������
	// (���������� ������� ��������� � fraction.cpp)
	class Fraction
	{
	private:
		long numerator_;	// ���������
		long denominator_;	// �����������
	public:
		Fraction() = delete;
		Fraction(long num, long denum);
		~Fraction();

		// �������
		long GetNum() const noexcept;
		long GetDenom() const noexcept;

		// �������
		void SetNum(long num) noexcept;
		void SetDenom(long denom) noexcept;

		// ������� ���������� �����
		void Reduce() noexcept;
		// ������� ������ �����
		void Print() const noexcept;

		// ������� ������������
		static Fraction Summation(Fraction& a, Fraction& b) noexcept;
		static Fraction Summation(double a, Fraction& b) noexcept;

		// ������� ���������
		static Fraction Subtraction(Fraction& a, Fraction& b) noexcept;
		static Fraction Subtraction(double a, Fraction& b) noexcept;
		static Fraction Subtraction(Fraction& a, double b) noexcept;

		// ������� ���������
		static Fraction Multiplication(Fraction& a, Fraction& b) noexcept;
		static Fraction Multiplication(double a, Fraction& b) noexcept;

		// ������� �������
		static Fraction Division(Fraction& a, Fraction& b);
		static Fraction Division(double a, Fraction& b);
		static Fraction Division(Fraction& a, double b);

		// ������� �������� ����� � �����
		static Fraction NumToFrac(double a) noexcept;

		// ������� �������� �� ������������
		static bool AreEqual(Fraction a, Fraction b) noexcept;
		static bool AreEqual(Fraction a, double b) noexcept;

		// ������� ��������� ��������/�������� �����
		static Fraction GetBiggest(Fraction a, Fraction b) noexcept;
		static Fraction GetSmallest(Fraction a, Fraction b) noexcept;

		// ������� ���������
		static bool isGreater(Fraction& a, Fraction& b) noexcept;
		static bool isSmaller(Fraction& a, Fraction& b) noexcept;
		

		// --- ���������� ���������� ---

		Fraction operator+ (Fraction& frac) noexcept;
		Fraction operator+ (double frac) noexcept;
		friend Fraction operator+ (double frac1, Fraction& frac2) noexcept;

		Fraction operator- (Fraction& frac) noexcept;
		Fraction operator- (double frac) noexcept;
		friend Fraction operator- (double frac1, Fraction& frac2) noexcept;

		Fraction operator* (Fraction& frac) noexcept;
		Fraction operator* (double frac) noexcept;
		friend Fraction operator* (double frac1, Fraction& frac2) noexcept;

		Fraction operator/ (Fraction& frac);
		Fraction operator/ (double frac);
		friend Fraction operator/ (double frac1, Fraction& frac2);

		bool operator== (Fraction frac) noexcept;
		bool operator== (double frac) noexcept;
		friend bool operator== (double frac1, Fraction frac2) noexcept;

		bool operator> (Fraction frac) noexcept;
		bool operator> (double frac) noexcept;
		friend bool operator> (double frac1, Fraction frac2) noexcept;

		bool operator< (Fraction frac) noexcept;
		bool operator< (double frac) noexcept;
		friend bool operator< (double frac1, Fraction frac2) noexcept;

		bool operator>= (Fraction frac) noexcept;
		bool operator>= (double frac) noexcept;
		friend bool operator>= (double frac1, Fraction frac2) noexcept;

		bool operator<= (Fraction frac) noexcept;
		bool operator<= (double frac) noexcept;
		friend bool operator<= (double frac1, Fraction frac2) noexcept;
	};
}