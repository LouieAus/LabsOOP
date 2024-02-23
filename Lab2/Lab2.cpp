// ========= Лабораторная работа №2 =========
// Условие:
// Создаем класс натуральной дроби.Он должен реализовывать методы сложения,
// вычитания, умножения, деления, сравнения на равенство и больше - меньше.
// Также должен иметь метод для преобразования в десятичное представление,
// генерацию натуральной дроби из десятичного представления, упрощение
// натуральной дроби и преобразование в смешанную дробь с целой частью.

#include <iostream>
#include "fraction.h"

int main()
{
	frac::Fraction num1(33, 10);
	frac::Fraction num2(99, 520);

	frac::Fraction temp(1, 1);

	// --- Примеры ---

	// Метод сложения
	temp = frac::Fraction::Summation(num1, num2);
	temp = num1 + num2;

	// Метод вычитания
	temp = frac::Fraction::Subtraction(num1, num2);
	temp = num1 - num2;

	// Метод умножения
	temp = frac::Fraction::Multiplication(num1, num2);
	temp = num1 * num2;

	// Метод деления
	temp = frac::Fraction::Division(num1, num2);
	temp = num1 / num2;

	bool result;
	// Методы сравнения
	result = frac::Fraction::AreEqual(num1, num2);
	result = frac::Fraction::isGreater(num1, num2);
	result = frac::Fraction::isSmaller(num1, num2);

	result = (num1 == num2);
	result = (num1 < num2);
	result = (num1 > num2);
	result = (num1 <= num2);
	result = (num1 >= num2);

	// Методы преобразования
	// Из натуральной дроби в число
	double a = num1.FracToNum();
	// Из числа в натуральную дробь
	temp = frac::Fraction::NumToFrac(5.7f);
	// Из натуральной дроби в смешанную
	frac::MixedFraction mixed = num1.FracToMixedFrac();

	// Метод сокращения дроби
	num1.Reduce();
}