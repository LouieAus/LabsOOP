#include "property.h"

prop::Listener::Listener(ID id, void (*get_state_func)(bool))
{
	this->id = id;
	this->get_state = get_state_func;
}

prop::Listener::~Listener()
{
}

void prop::Button::NotifyListeners() const noexcept
{
	for (auto& listener : listeners_)
	{
		listener.get_state(pressed_);
	}
}

prop::Button::Button()
{
	pressed_ = false;
}

prop::Button::~Button()
{
}

bool prop::Button::GetState() const noexcept { return pressed_; }

void prop::Button::SetState(bool state) noexcept
{
	pressed_ = state;		// Если кнопка нажата/отжата, то
	NotifyListeners();		// уведомляем всех слушателей об этом
}

void prop::Button::AddNotifyNropertyChangedListener(Listener& listener)
{
	listeners_.push_back(listener);
}

void prop::Button::RemoveNotifyPropertyChangedListener(ID id)
{
	for (auto i = 0; i != listeners_.size(); i++)
	{
		listeners_.erase(listeners_.begin() + i);
		break;
	}
}