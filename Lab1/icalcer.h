#pragma once

#include <optional>
#include <iostream>

namespace calc
{
	typedef unsigned int UINT;

	// Класс ICalcer
	class ICalcer
	{
	protected:
		UINT	dot_quantity_;	// Количество точек
		double	increment_;		// Шаг
		double	accuracy_;		// Точность

		double GetIncrement(double a, double b, UINT n = 0) const noexcept;
		UINT GetDotQuantity(double a, double b, double inc = 0.0) const noexcept;
	public:
		// Функция вычисления интеграла (указатель на функцию, левая граница, правая граница)
		virtual std::optional<double> calcInt(double(*func)(double), double a, double b) noexcept = 0;

		ICalcer();
		void SetDotQuantity(UINT quantity);
		void SetIncrement(double increment);
		void SetAccuracy(double accuracy);
		virtual ~ICalcer() {}
	};

	// Класс TrapezeCalcer с расчетом интеграла через метод трапеций
	class TrapezeCalcer : public ICalcer 
	{
	private:
		double CalculateTrapeze(double(*func)(double), double a, double b, double inc, UINT n);
	public:
		TrapezeCalcer() {}
		virtual ~TrapezeCalcer() {}

		std::optional<double> calcInt(double(*func)(double), double a, double b) noexcept override;
	};

	// Класс TrapezeCalcer с расчетом интеграла через метод Симпсона
	class SimpsonCalcer : public ICalcer
	{
	private:
		double CalculateSimpson(double(*func)(double), double a, double b, double inc, UINT n);
	public:
		SimpsonCalcer() {}
		virtual ~SimpsonCalcer() {}

		std::optional<double> calcInt(double(*func)(double), double a, double b) noexcept override;
	};
}