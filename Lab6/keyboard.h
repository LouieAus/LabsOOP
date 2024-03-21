#pragma once
#include <iostream>
#include <vector>
#include <thread>

namespace key
{
	typedef unsigned char UCHAR;

	// ������� ����� Command ��� ������
	class Command
	{
	public:
		virtual void Run() = 0;		// ������ �������
		virtual void Undo() = 0;	// ������ �������
	};

	// ������� TypeText �������� �����
	class TypeText : public Command
	{
	protected:
		std::string text_;
	public:
		void Run() override;
		void Undo() override;
	};

	// ������� RunWordpad ��������� �������
	class RunWordpad : public Command
	{
	public:
		void Run() override;
		void Undo() override;
	};

	// ��������� Action, ���������� ���������� � ��������
	struct Action
	{
		std::vector<UCHAR> keys;	// ���������� ������
		Command* command;			// ��������
	};

	// ��������� VirtualKeyboard, ���������� ������ �������������� � ��������
	class VirtualKeyboard
	{
	private:
		std::vector<Action*> actions_;	// ����������� ��������
		std::vector<Command*> history_;	// ������� ����������� ������
	public:
		~VirtualKeyboard();

		// ���������� ������ �������� ��� �������������� �������
		void AddCommand(Action* action);

		// ������ ��������� �������
		void UndoLastCommand();

		// ���������� ������� ������
		void PressKey(UCHAR key);

		// ������� ���������� ������
		void PressKeys(std::vector<UCHAR> keys);

		// ���������� ������ ���������� ������
		void ExecuteWorkflow(std::vector<std::vector<UCHAR>> keys);
	};
}