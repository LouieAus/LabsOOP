// ========= Лабораторная работа №6 =========
// Условие:
// Создать виртуальную клавиатуру с переназначаемыми
// действиями для клавиш и комбинаций клавиш, с возможностью
// отката действий назад. Симулировать нажатия клавиш путем
// вывода значения в консоль и задержкой между нажатиями.

#include <iostream>
#include "keyboard.h"

int main()
{
	key::VirtualKeyboard Keyboard;

	// Примеры создания действий:
	// command_1 - при нажатии комбинации клавиш с кодами 7 и 125 пишется текст
	key::Action* command_1 = new key::Action{ std::vector<key::UCHAR> { 7, 125 }, new key::TypeText() };
	// command_2 - при нажатии одной клавиши с кодом 55 открывается блокнот
	key::Action* command_2 = new key::Action{ std::vector<key::UCHAR> { 55 }, new key::RunWordpad() };

	// Добавление команд
	Keyboard.AddCommand(command_1);
	Keyboard.AddCommand(command_2);

	// Нажатие одной клавиши
	Keyboard.PressKeys({ 7, 125 });

	// Нажатие нескольких комбинаций клавиш
	Keyboard.ExecuteWorkflow({ {55}, {25, 13}, {14, 58} });

	// Отмена последней команды
	Keyboard.UndoLastCommand();

	// Создаем новое действие и переназначаем клавишу с кодом 55
	key::Action* command_3 = new key::Action{ std::vector<key::UCHAR> { 55 }, new key::TypeText() };
	Keyboard.AddCommand(command_3);

	// Снова выполняем нажатие комбинаций клавиш (в данном случае одной - с кодом 55)
	Keyboard.ExecuteWorkflow({ { 55 } });
}