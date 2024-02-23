#pragma once
#include <vector>
#include <iostream>

namespace frac
{
	struct MixedFraction;

	// Êëàññ äðîáåé
	// (ðåàëèçàöèè ìåòîäîâ íàõîäÿòñÿ â fraction.cpp)
	class Fraction
	{
	private:
		long long numerator_;	// ×èñëèòåëü
		long long denominator_;	// Çíàìåíàòåëü
	public:
		
		Fraction() = delete;
		Fraction(long num, long denum);
		~Fraction();

		// Ãåòòåðû
		long GetNum() const noexcept;
		long GetDenom() const noexcept;

		// Ñåòòåðû
		void SetNum(long num) noexcept;
		void SetDenom(long denom) noexcept;

		// Ôóíêöèÿ ñîêðàùåíèÿ äðîáè
		void Reduce() noexcept;
		// Ôóíêöèÿ âûâîäà äðîáè
		void Print() const noexcept;

		// Ôóíêöèè ñóììèðîâàíèÿ
		static Fraction Summation(Fraction& a, Fraction& b) noexcept;
		static Fraction Summation(double a, Fraction& b) noexcept;

		// Ôóíêöèè âû÷èòàíèÿ
		static Fraction Subtraction(Fraction& a, Fraction& b) noexcept;
		static Fraction Subtraction(double a, Fraction& b) noexcept;
		static Fraction Subtraction(Fraction& a, double b) noexcept;

		// Ôóíêöèè óìíîæåíèÿ
		static Fraction Multiplication(Fraction& a, Fraction& b) noexcept;
		static Fraction Multiplication(double a, Fraction& b) noexcept;

		// Ôóíêöèè äåëåíèÿ
		static Fraction Division(Fraction& a, Fraction& b);
		static Fraction Division(double a, Fraction& b);
		static Fraction Division(Fraction& a, double b);

		// Ôóíêöèÿ ïåðåâîäà ÷èñëà â äðîáü
		static Fraction NumToFrac(double a) noexcept;
		// Ôóíêöèÿ ïåðåâîäà äðîáè â ÷èñëî
		double FracToNum() const noexcept;
		// Ôóíêöèÿ ïåðåâîäà äðîáè â ñìåøàííóþ äðîáü
		MixedFraction FracToMixedFrac() const noexcept;

		// Ôóíêöèè ïðîâåðêè íà èäåíòè÷íîñòü
		static bool AreEqual(Fraction a, Fraction b) noexcept;
		static bool AreEqual(Fraction a, double b) noexcept;

		// Ôóíêöèè ïîëó÷åíèÿ áîëüøåãî/ìåíüøåãî ÷èñëà
		static Fraction GetBiggest(Fraction a, Fraction b) noexcept;
		static Fraction GetSmallest(Fraction a, Fraction b) noexcept;

		// Ôóíêöèè ñðàâíåíèÿ
		static bool isGreater(Fraction a, Fraction b) noexcept;
		static bool isGreater(double a, Fraction b) noexcept;
		static bool isSmaller(Fraction a, Fraction b) noexcept;
		static bool isSmaller(double a, Fraction b) noexcept;
		


		// --- Ïåðåãðóçêè îïåðàòîðîâ ---

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

	// Ñòðóêòóðà ñìåøàííîé äðîáè
	struct MixedFraction
	{
		long long integer = 0;
		Fraction fract{ 0, 0 };
	};
}
