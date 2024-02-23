#pragma once
#include <vector>
#include <iostream>

namespace frac
{
	struct MixedFraction;

	// Класс дробей
	// (реализации методов находятся в fraction.cpp)
	class Fraction
	{
	private:
		long long numerator_;	// Числитель
		long long denominator_;	// Знаменатель
	public:
		
		Fraction() = delete;
		Fraction(long num, long denum);
		~Fraction();

		// Геттеры
		long GetNum() const noexcept;
		long GetDenom() const noexcept;

		// Сеттеры
		void SetNum(long num) noexcept;
		void SetDenom(long denom) noexcept;

		// Функция сокращения дроби
		void Reduce() noexcept;
		// Функция вывода дроби
		void Print() const noexcept;

		// Функции суммирования
		static Fraction Summation(Fraction& a, Fraction& b) noexcept;
		static Fraction Summation(double a, Fraction& b) noexcept;

		// Функции вычитания
		static Fraction Subtraction(Fraction& a, Fraction& b) noexcept;
		static Fraction Subtraction(double a, Fraction& b) noexcept;
		static Fraction Subtraction(Fraction& a, double b) noexcept;

		// Функции умножения
		static Fraction Multiplication(Fraction& a, Fraction& b) noexcept;
		static Fraction Multiplication(double a, Fraction& b) noexcept;

		// Функции деления
		static Fraction Division(Fraction& a, Fraction& b);
		static Fraction Division(double a, Fraction& b);
		static Fraction Division(Fraction& a, double b);

		// Функция перевода числа в дробь
		static Fraction NumToFrac(double a) noexcept;
		// Функция перевода дроби в число
		double FracToNum() const noexcept;
		// Функция перевода дроби в смешанную дробь
		MixedFraction FracToMixedFrac() const noexcept;

		// Функции проверки на идентичность
		static bool AreEqual(Fraction a, Fraction b) noexcept;
		static bool AreEqual(Fraction a, double b) noexcept;

		// Функции получения большего/меньшего числа
		static Fraction GetBiggest(Fraction a, Fraction b) noexcept;
		static Fraction GetSmallest(Fraction a, Fraction b) noexcept;

		// Функции сравнения
		static bool isGreater(Fraction a, Fraction b) noexcept;
		static bool isGreater(double a, Fraction b) noexcept;
		static bool isSmaller(Fraction a, Fraction b) noexcept;
		static bool isSmaller(double a, Fraction b) noexcept;
		

		// --- Перегрузки операторов ---

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

	// Структура смешанной дроби
	struct MixedFraction
	{
		long long integer = 0;
		Fraction fract{ 0, 0 };
	};
}