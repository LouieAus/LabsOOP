#pragma once
#include <iostream>
#include <vector>
#include <thread>

namespace key
{
	typedef unsigned char UCHAR;

	// Базовый класс Command для команд
	class Command
	{
	public:
		virtual void Run() = 0;		// Запуск команды
		virtual void Undo() = 0;	// Отмена команды
	};

	// Команда TypeText печатает текст
	class TypeText : public Command
	{
	protected:
		std::string text_;
	public:
		void Run() override;
		void Undo() override;
	};

	// Команда RunWordpad запускает блокнот
	class RunWordpad : public Command
	{
	public:
		void Run() override;
		void Undo() override;
	};

	// Структура Action, содержащая информацию о действии
	struct Action
	{
		std::vector<UCHAR> keys;	// Комбинация клавиш
		Command* command;			// Действие
	};

	// Структура VirtualKeyboard, содержащая методы взаимодействия с кнопками
	class VirtualKeyboard
	{
	private:
		std::vector<Action*> actions_;	// Назначенные действия
		std::vector<Command*> history_;	// История выполненных команд
	public:
		~VirtualKeyboard();

		// Добавление нового действия или переназначение старого
		void AddCommand(Action* action);

		// Отмена последней команды
		void UndoLastCommand();

		// Имититация нажатия кнопки
		void PressKey(UCHAR key);

		// Нажатие комбинации кнопок
		void PressKeys(std::vector<UCHAR> keys);

		// Выполнение потока комбинаций клавиш
		void ExecuteWorkflow(std::vector<std::vector<UCHAR>> keys);
	};
}