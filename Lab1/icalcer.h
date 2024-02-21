#pragma once

#include <optional>
#include <iostream>

namespace calc
{
	typedef unsigned int UINT;

	// ����� ICalcer
	class ICalcer
	{
	protected:
		UINT	dot_quantity_;	// ���������� �����
		double	increment_;		// ���
		double	accuracy_;		// ��������

		double GetIncrement(double a, double b, UINT n = 0) const noexcept;
		UINT GetDotQuantity(double a, double b, double inc = 0.0) const noexcept;
	public:
		// ������� ���������� ��������� (��������� �� �������, ����� �������, ������ �������)
		virtual std::optional<double> calcInt(double(*func)(double), double a, double b) noexcept = 0;

		ICalcer();
		void SetDotQuantity(UINT quantity);
		void SetIncrement(double increment);
		void SetAccuracy(double accuracy);
		virtual ~ICalcer() {}
	};

	// ����� TrapezeCalcer � �������� ��������� ����� ����� ��������
	class TrapezeCalcer : public ICalcer 
	{
	private:
		double CalculateTrapeze(double(*func)(double), double a, double b, double inc, UINT n);
	public:
		TrapezeCalcer() {}
		virtual ~TrapezeCalcer() {}

		std::optional<double> calcInt(double(*func)(double), double a, double b) noexcept override;
	};

	// ����� TrapezeCalcer � �������� ��������� ����� ����� ��������
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