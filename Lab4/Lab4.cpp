// ========= Лабораторная работа №4 =========
// Условие:
// Создать интерфейсный класс Inotifypropertychanged.
// Добавить метод addnotifypropertychanged и функцию
// removenotifypropertychangedlistener. Реализовать этот
// интерфейс и информировать слушателей об изменении
// состоянии объекта

#include <iostream>
#include "property.h"

int main()
{
	// Создаем слушателей, например, окно программы, пользователь и
	// библиотека, получающая информацию о графическом интферейсе программы
	prop::Listener Window(1, [](bool button_state)
		{
			std::cout << "Listener Window got button state: " << button_state << '\n';
		});

	prop::Listener User(2, [](bool button_state)
		{
			std::cout << "Listener User got button state: " << button_state << '\n';
		});

	prop::Listener LibDataTransfer(3, [](bool button_state)
		{
			std::cout << "Listener LibDataTransfer got button state: " << button_state << '\n';
		});

	// Создаем элемент графического интерфейса (например, кнопку "ОК")
	prop::Button button_OK;

	// Добавляем слушателей
	button_OK.AddNotifyNropertyChangedListener(Window);
	button_OK.AddNotifyNropertyChangedListener(User);
	button_OK.AddNotifyNropertyChangedListener(LibDataTransfer);

	// Имитируем нажатие кнопки
	button_OK.SetState(true);
	button_OK.SetState(false);

	// При необхдимости можно удалить слушателя
	button_OK.RemoveNotifyPropertyChangedListener(2);
}