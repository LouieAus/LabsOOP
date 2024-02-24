#pragma once
#include <vector>
#include <string>

namespace prop
{
	typedef unsigned short ID;
	
	// (реализация всех методов находится в файле property.cpp)

	// Структура слушатель
	struct Listener
	{
		ID id;						// id слушателя
		void (*get_state)(bool);	// функция, вызываемая при изменении состояния объекта

		Listener() = delete;
		Listener(ID id, void (*get_state_func)(bool));
		~Listener();
	};

	// Интерфейс добавления и удаления слушателей
	class INotifyPropertyChanged
	{
	public:
		virtual ~INotifyPropertyChanged() = default;

		virtual void AddNotifyNropertyChangedListener(Listener& listener) = 0;
		virtual void RemoveNotifyPropertyChangedListener(ID id) = 0;
	};

	// Класс кнопки
	class Button : public INotifyPropertyChanged
	{
	private:
		bool pressed_;						// Состояние кнопки
		std::vector<Listener> listeners_;	// Массив слушателей состояния кнопки
		
		// Метод уведомления слушателей об изменении состояния кнопки
		void NotifyListeners() const noexcept;
	public:
		Button();
		~Button();

		// Геттеры, сеттеры
		bool GetState() const noexcept;
		void SetState(bool state) noexcept;

		void AddNotifyNropertyChangedListener(Listener& listener) override;
		void RemoveNotifyPropertyChangedListener(ID id) override;
	};
}