#include "os_controls.h"

int main()
{
	setlocale(LC_ALL, "rus");

	ctrl::System current_system = ctrl::WINDOWS;


	// Пример создания контролов: ctrl::CreateControl<Тип контрола>(система, форма);

	ctrl::Form* form			= ctrl::CreateControl<ctrl::Form>(current_system, nullptr);
	ctrl::Label* label			= ctrl::CreateControl<ctrl::Label>(current_system, form);
	ctrl::TextBox* textbox		= ctrl::CreateControl<ctrl::TextBox>(current_system, form);
	ctrl::ComboBox* combobox	= ctrl::CreateControl<ctrl::ComboBox>(current_system, form);
	ctrl::Button* button		= ctrl::CreateControl<ctrl::Button>(current_system, form);


	// Примеры вызова методов котролов

	label->SetText("Hello");
	
	textbox->OnValueChanged();

	combobox->SetItems("items: 1, 2, 3");

	button->Click();
}