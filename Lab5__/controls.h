#pragma once
#include <iostream>
#include <vector>

namespace ctrl
{
    typedef unsigned short USHRT;

    enum System { WINDOWS, LINUX, MACOS };

    struct Oxy
    {
        USHRT x, y;
    };

    // Базовый класс Control
    class Control {
    protected:
        USHRT x_, y_;
    public:
        virtual void SetPosition(USHRT x, USHRT y) = 0;
        virtual Oxy GetPosition() = 0;
    };

    // Контрол Form
    class Form : public Control {
    protected:
        std::vector<Control*> controls_;
    public:
        virtual void AddControl(Control* control) = 0;
    };

    // Контрол Label
    class Label : public Control {
    protected:
        std::string text_;
    public:
        virtual void        SetText(std::string text) = 0;
        virtual std::string GetText() = 0;
    };

    // Контрол TextBox
    class TextBox : public Control {
    protected:
        std::string text_;
    public:
        virtual void        SetText(std::string text) = 0;
        virtual std::string GetText() = 0;
        virtual void        OnValueChanged() = 0;
    };

    // Контрол ComboBox
    class ComboBox : public Control {
    protected:
        USHRT       index_;
        std::string items_;
    public:
        virtual void        SetSelectedIndex(USHRT index) = 0;
        virtual USHRT       GetSelectedIndex() = 0;
        virtual void        SetItems(std::string items) = 0;
        virtual std::string GetItems() = 0;
    };

    // Контрол Button
    class Button : public Control {
    protected:
        std::string text_;
    public:
        virtual void        SetText(std::string text) = 0;
        virtual std::string GetText() = 0;
        virtual void        Click() = 0;
    };
}