#include "keyboard.h"

namespace help
{
	template <typename T>
	bool areVecsSimilar(std::vector<T>& vec_1, std::vector<T>& vec_2)
	{
		if (vec_1.size() == vec_2.size())
		{
			for (auto i = 0; i != vec_1.size(); i++)
			{
				if (vec_1[i] != vec_2[i])
					return false;
			}
			return true;
		}
		return false;
	}
}

namespace key
{
	void TypeText::Run()
	{
		std::cout << "Command 'TypeText' was executed\n";
	}

	void TypeText::Undo()
	{
		std::cout << "Undo command 'TypeText'\n";
	}

	void RunWordpad::Run()
	{
		std::cout << "Command 'RunWordpad' was executed\n";
	}

	void RunWordpad::Undo()
	{
		std::cout << "Undo command 'RunWordpad'\n";
	}

	VirtualKeyboard::~VirtualKeyboard()
	{
		for (auto i = 0; i != actions_.size(); i++)
		{
			if (actions_[i] != nullptr)
			{
				if (actions_[i]->command != nullptr)
					delete actions_[i]->command;
				delete actions_[i];
			}
		}
	}

	void VirtualKeyboard::AddCommand(Action* action)
	{
		for (auto i = 0; i != actions_.size(); i++)
		{
			if (help::areVecsSimilar(actions_[i]->keys, action->keys))
			{
				delete actions_[i];
				actions_[i] = action;
				return;
			}
		}
		actions_.push_back(action);
	}

	void VirtualKeyboard::UndoLastCommand()
	{
		if (history_.size() != 0)
		{
			history_[history_.size() - 1]->Undo();
			history_.pop_back();
		}
	}

	void VirtualKeyboard::PressKey(UCHAR key)
	{
		std::cout << "Key with code " << (int)key << " was pressed\n";
	}

	void VirtualKeyboard::PressKeys(std::vector<UCHAR> keys)
	{
		for (auto i = 0; i != actions_.size(); i++)
		{
			if (help::areVecsSimilar(actions_[i]->keys, keys))
			{
				for (auto k = 0; k != actions_[i]->keys.size(); k++)
				{
					PressKey(actions_[i]->keys[k]);
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}

				actions_[i]->command->Run();
				history_.push_back(actions_[i]->command);
				return;
			}
		}
		std::cout << "No command was found\n";
	}

	void VirtualKeyboard::ExecuteWorkflow(std::vector<std::vector<UCHAR>> keys)
	{
		for (auto i = 0; i != keys.size(); i++)
			PressKeys(keys[i]);
	}
}
