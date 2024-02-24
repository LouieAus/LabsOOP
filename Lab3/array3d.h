#pragma once
#include <optional>
#include <vector>

namespace arr3d
{
	typedef long long LONG;

	struct Oxy
	{
		LONG x, y;
	};

	struct Oxyz
	{
		LONG x, y, z;
	};

	enum XYZplane { OXY, OYZ, OXZ };
	enum XYZaxis { OX, OY, OZ };

	// Класс трёхмерного массива
	// (реализация методов находится в этом файле ниже)
	template <typename T>
	class Array3d
	{
	private:
		Oxyz size_;											// Размеры массива
		std::vector<std::vector<std::vector<T*>>> space_;	// Пространство данных
	public:
		Array3d();
		Array3d(Oxyz size);
		~Array3d();

		Oxyz GetSize() const noexcept;

		// Функция вывода пространства данных
		// (требуется своя функция вывода типа T)
		void Print(void (*print_func)(T*)) const noexcept;

		// Функция добавления элементов
		void Add(T input, Oxyz position) noexcept;

		// Функция получения элемента
		T* Get(Oxyz position) const noexcept;

		// Функция добавления вектора данных
		// (plane = OXY = 0 - вставка вдоль оси аппликат,
		// plane = OXZ = 1 - вставка вдоль оси ординат,
		// plane = OYZ = 2 - вставка вдоль оси абсцисс)
		void AddLine(std::vector<T>& input_line, Oxy position, XYZplane plane) noexcept;

		// Функция получения вектора данных
		// (plane = OXY = 0 - получение вдоль оси аппликат,
		// plane = OXZ = 1 - получение вдоль оси ординат,
		// plane = OYZ = 2 - получение вдоль оси абсцисс)
		std::vector<std::optional<T>> GetLine(Oxy position, XYZplane plane) const noexcept;

		// Функция добавления плоскости данных
		// (axis = OX = 0 - вставка по оси абсцисс,
		// axis = OY = 1 - вставка по оси ординат,
		// axis = OZ = 3 - вставка по оси аппликат)
		void AddPlane(std::vector<std::vector<T>>& input_plane, LONG position, XYZaxis axis);

		// Функция получения плоскости данных
		// (axis = OX = 0 - получение по оси абсцисс,
		// axis = OY = 1 - получение по оси ординат,
		// axis = OZ = 3 - получение по оси аппликат)
		std::vector<std::vector<std::optional<T>>> GetPlane(LONG position, XYZaxis axis) const noexcept;

		// Функция заполнения пространства данными
		void Fill(T input) noexcept;
	};

	template<typename T>
	arr3d::Array3d<T>::Array3d()
	{
		size_ = { 0, 0, 0 };
	}

	template<typename T>
	arr3d::Array3d<T>::Array3d(Oxyz size)
	{
		size_ = size;

		for (auto i = 0; i != size_.x; i++)
		{
			std::vector<std::vector<T*>> column;
			for (auto j = 0; j != size_.y; j++)
			{
				std::vector<T*> row;
				for (auto k = 0; k != size_.z; k++)
					row.push_back(nullptr);
				column.push_back(std::move(row));
			}
			space_.push_back(column);
		}
	}

	template<typename T>
	arr3d::Array3d<T>::~Array3d()
	{
		for (auto i = 0; i != size_.x; i++)
			for (auto j = 0; j != size_.y; j++)
				for (auto k = 0; k != size_.z; k++)
					delete space_[i][j][k];
	}

	template<typename T>
	Oxyz arr3d::Array3d<T>::GetSize() const noexcept { return size_; }

	template<typename T>
	void arr3d::Array3d<T>::Print(void (*print_func)(T*)) const noexcept
	{
		for (auto& column : space_)
		{
			for (auto& row : column)
			{
				for (T* data : row)
					print_func(data);
				std::cout << '\n';
			}
			std::cout << "\n\n";
		}
	}

	template<typename T>
	void arr3d::Array3d<T>::Add(T input, Oxyz position) noexcept
	{
		if (position.x >= size_.x)
		{
			for (auto i = size_.x; i != (position.x + 1); i++)
			{
				std::vector<std::vector<T*>> column;
				for (auto j = 0; j != size_.y; j++)
					column.push_back(std::vector<T*>(size_.z, nullptr));
				space_.push_back(std::move(column));
			}
			size_.x = position.x + 1;
		}

		if (position.y >= size_.y)
		{
			for (auto i = 0; i != size_.x; i++)
			{
				for (auto j = size_.y; j != (position.y + 1); j++)
					space_[i].push_back(std::vector<T*>(size_.z, nullptr));
			}
			size_.y = position.y + 1;
		}

		if (position.z >= size_.z)
		{
			for (auto i = 0; i != size_.x; i++)
			{
				for (auto j = 0; j != size_.y; j++)
				{
					for (auto k = size_.z; k != (position.z + 1); k++)
						space_[i][j].push_back(nullptr);
				}
			}
			size_.z = position.z + 1;
		}

		space_[position.x][position.y][position.z] = new T(input);
	}

	template<typename T>
	T* arr3d::Array3d<T>::Get(Oxyz position) const noexcept
	{
		if ((position.x < size_.x) &&
			(position.y < size_.y) &&
			(position.z < size_.z))
		{
			return space_[position.x][position.y][position.z];
		}

		return nullptr;
	}

	template<typename T>
	void arr3d::Array3d<T>::AddLine(std::vector<T>& input_line, Oxy position, XYZplane plane) noexcept
	{
		if (plane == OXY)
		{
			for (auto k = 0; k != input_line.size(); k++)
				Add(input_line[k], { position.x, position.y, k });
		}
		else if (plane == OXZ)
		{
			for (auto j = 0; j != input_line.size(); j++)
				Add(input_line[j], { position.x, j, position.y });
		}
		else if (plane == OYZ)
		{
			for (auto i = 0; i != input_line.size(); i++)
				Add(input_line[i], { i, position.x, position.y });
		}
	}

	template<typename T>
	std::vector<std::optional<T>> arr3d::Array3d<T>::GetLine(Oxy position, XYZplane plane) const noexcept
	{
		std::vector<std::optional<T>> result;

		if (plane == OXY)
		{
			for (auto k = 0; k != size_.z; k++)
			{
				T* get_data = Get({ position.x, position.y, k });
				if (get_data != nullptr)
					result.push_back(*get_data);
				else
					result.push_back(std::nullopt);
			}
		}
		else if(plane == OXZ)
		{
			for (auto j = 0; j != size_.y; j++)
			{
				T* get_data = Get({ position.x, j, position.y });
				if (get_data != nullptr)
					result.push_back(*get_data);
				else
					result.push_back(std::nullopt);
			}
		}
		else if (plane == OYZ)
		{
			for (auto i = 0; i != size_.x; i++)
			{
				T* get_data = Get({ i, position.x, position.y });
				if (get_data != nullptr)
					result.push_back(*get_data);
				else
					result.push_back(std::nullopt);
			}
		}

		return result;
	}

	template<typename T>
	void arr3d::Array3d<T>::AddPlane(std::vector<std::vector<T>>& input_plane, LONG position, XYZaxis axis)
	{
		if (axis == OX)
		{
			for (auto j = 0; j != input_plane.size(); j++)
			{
				AddLine(input_plane[j], { position, j }, OXY);
			}
		}
		else if (axis == OY)
		{
			for (auto i = 0; i != input_plane.size(); i++)
			{
				AddLine(input_plane[i], { position, i }, OYZ);
			}
		}
		else if (axis == OZ)
		{
			for (auto k = 0; k != input_plane.size(); k++)
			{
				AddLine(input_plane[k], { k, position }, OXZ);
			}
		}
	}

	template<typename T>
	std::vector<std::vector<std::optional<T>>> arr3d::Array3d<T>::GetPlane(LONG position, XYZaxis axis) const noexcept
	{
		std::vector<std::vector<std::optional<T>>> result;

		if (axis == OX)
		{
			for (auto j = 0; j != size_.y; j++)
			{
				std::vector<std::optional<T>> row;
				for (auto k = 0; k != size_.z; k++)
				{
					T* get_data = Get({ position, j, k });
					if (get_data != nullptr)
						row.push_back(*get_data);
					else
						row.push_back(std::nullopt);
				}
				result.push_back(row);
			}
		}
		else if (axis == OY)
		{
			for (auto i = 0; i != size_.x; i++)
			{
				std::vector<std::optional<T>> row;
				for (auto k = 0; k != size_.z; k++)
				{
					T* get_data = Get({ i, position, k });
					if (get_data != nullptr)
						row.push_back(*get_data);
					else
						row.push_back(std::nullopt);
				}
				result.push_back(row);
			}
		}
		else if (axis == OZ)
		{
			for (auto i = 0; i != size_.x; i++)
			{
				std::vector<std::optional<T>> row;
				for (auto j = 0; j != size_.y; j++)
				{
					T* get_data = Get({ i, j, position });
					if (get_data != nullptr)
						row.push_back(*get_data);
					else
						row.push_back(std::nullopt);
				}
				result.push_back(row);
			}
		}

		return result;
	}

	template<typename T>
	void arr3d::Array3d<T>::Fill(T input) noexcept
	{
		for (auto i = 0; i != size_.x; i++)
			for (auto j = 0; j != size_.y; j++)
				for (auto k = 0; k != size_.z; k++)
				space_[i][j][k] = new T(input);
	}
}