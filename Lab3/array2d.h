#pragma once
#include <optional>
#include <vector>

namespace arr2d
{
	typedef long long LONG;

	struct Oxy
	{
		LONG x, y;
	};

	// Класс двумерного массива
	// (реализация методов находится в этом файле ниже)
	template <typename T>
	class Array2d
	{
	private:
		Oxy size_;								// Размеры массива
		std::vector<std::vector<T*>> plane_;	// Плоскость данных
	public:
		Array2d();
		Array2d(Oxy size);
		~Array2d();

		Oxy GetSize() const noexcept;

		// Функция вывода плоскости данных
		// (требуется своя функция вывода типа T)
		void Print(void (*print_func)(T*)) const;

		// Функция добавления элементов
		void Add(T input, Oxy position) noexcept;

		// Функция получения элемента
		T* Get(Oxy position) const noexcept;

		// Функция добавления вектора данных
		// (axis = 0 - вставка по оси абсцисс,
		// axis = 1 - вставка по оси ординат)
		void AddLine(std::vector<T>& input_line, LONG position, bool axis) noexcept;

		// Функция получения вектора данных
		// (axis = 0 - вставка по оси абсцисс,
		// axis = 1 - вставка по оси ординат)
		std::vector<std::optional<T>> GetLine(LONG position, bool axis) const noexcept;

		// Функция заполнения плоскости данными
		void Fill(T input) noexcept;
	};

	template<typename T>
	arr2d::Array2d<T>::Array2d()
	{
		size_ = { 0, 0 };
	}

	template<typename T>
	arr2d::Array2d<T>::Array2d(Oxy size)
	{
		size_ = size;

		for (auto i = 0; i != size_.x; i++)
		{
			std::vector<T*> column;
			for (auto j = 0; j != size_.y; j++)
				column.push_back(nullptr);
			plane_.push_back(std::move(column));
		}
	}

	template<typename T>
	arr2d::Array2d<T>::~Array2d()
	{
		for (auto i = 0; i != size_.x; i++)
			for (auto j = 0; j != size_.y; j++)
				delete plane_[i][j];
	}

	template<typename T>
	Oxy arr2d::Array2d<T>::GetSize() const noexcept  { return size_; }

	template<typename T>
	void arr2d::Array2d<T>::Print(void (*print_func)(T*)) const
	{
		for (auto &column: plane_)
		{
			for (T* data : column)
				print_func(data);
			std::cout << '\n';
		}
	}

	template<typename T>
	void arr2d::Array2d<T>::Add(T input, Oxy position) noexcept
	{
		if (position.x >= size_.x)
		{
			for (auto i = size_.x; i != (position.x + 1); i++)
			{
				std::vector<T*> column;
				for (auto j = 0; j != size_.y; j++)
					column.push_back(nullptr);
				plane_.push_back(std::move(column));
			}
			size_.x = position.x + 1;
		}

		if (position.y >= size_.y)
		{
			for (auto i = 0; i != size_.x; i++)
			{
				for (auto j = size_.y; j != (position.y + 1); j++)
					plane_[i].push_back(nullptr);
			}
			size_.y = position.y + 1;
		}

		plane_[position.x][position.y] = new T(input);
	}

	template<typename T>
	T* arr2d::Array2d<T>::Get(Oxy position) const noexcept
	{
		if ((position.x < size_.x) && (position.y < size_.y))
		{
			return plane_[position.x][position.y];
		}
		
		return nullptr;
	}

	template<typename T>
	void arr2d::Array2d<T>::AddLine(std::vector<T>& input_line, LONG position, bool axis) noexcept
	{
		if (axis == 0)
		{
			for (auto j = 0; j != input_line.size(); j++)
				Add(input_line[j], { position, j });
		}
		else
		{
			for (auto i = 0; i != input_line.size(); i++)
				Add(input_line[i], { i, position });
		}
	}

	template<typename T>
	std::vector<std::optional<T>> arr2d::Array2d<T>::GetLine(LONG position, bool axis) const noexcept
	{
		std::vector<std::optional<T>> result;

		if (axis == 0)
		{
			for (auto j = 0; j != size_.y; j++)
			{
				T* get_data = Get({ position, j });
				if (get_data != nullptr)
					result.push_back(*get_data);
				else
					result.push_back(std::nullopt);
			}
		}
		else
		{
			for (auto i = 0; i != size_.x; i++)
			{
				T* get_data = Get({ i, position });
				if (get_data != nullptr)
					result.push_back(*get_data);
				else
					result.push_back(std::nullopt);
			}
		}

		return result;
	}

	template<typename T>
	void arr2d::Array2d<T>::Fill(T input) noexcept
	{
		for (auto i = 0; i != size_.x; i++)
			for (auto j = 0; j != size_.y; j++)
				plane_[i][j] = new T(input);
	}
}