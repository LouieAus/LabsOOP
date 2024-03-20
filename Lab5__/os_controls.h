#pragma once
#include "controls.h"

// Здесь представлены реализации контролов в зависимости от системы
// В конце файла находится фабрика

namespace ctrl
{
    // ===================== FORM =====================

    class WindowsForm : public Form {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла WindowsForm\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла WindowsForm\n";
            return { x_, y_ };
        }
        void AddControl(Control* control) override {
            std::cout << "Вызван метод AddControl у контролла WindowsForm\n";
            controls_.push_back(control);
        }
        ~WindowsForm() {
            for (auto i = 0; i != controls_.size(); i++)
                delete controls_[i];
        }
    };

    class LinuxForm : public Form {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла LinuxForm\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла LinuxForm\n";
            return { x_, y_ };
        }
        void AddControl(Control* control) override {
            std::cout << "Вызван метод AddControl у контролла LinuxForm\n";
            controls_.push_back(control);
        }
        ~LinuxForm() {
            for (auto i = 0; i != controls_.size(); i++)
                delete controls_[i];
        }
    };

    class MacOSForm : public Form {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла MacOSForm\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла MacOSForm\n";
            return { x_, y_ };
        }
        void AddControl(Control* control) override {
            std::cout << "Вызван метод AddControl у контролла MacOSForm\n";
            controls_.push_back(control);
        }
        ~MacOSForm() {
            for (auto i = 0; i != controls_.size(); i++)
                delete controls_[i];
        }
    };
    

    // ===================== LABEL =====================

    class WindowsLabel : public Label {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла WindowsLabel\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла WindowsLabel\n";
            return { x_, y_ };
        }
        void SetText(std::string text) override {
            std::cout << "Вызван метод SetText у контролла WindowsLabel\n";
        }
        std::string GetText() override {
            std::cout << "Вызван метод GetText у контролла WindowsLabel\n";
            return text_;
        }
    };

    class LinuxLabel : public Label {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла LinuxLabel\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла LinuxLabel\n";
            return { x_, y_ };
        }
        void SetText(std::string text) override {
            std::cout << "Вызван метод SetText у контролла LinuxLabel\n";
        }
        std::string GetText() override {
            std::cout << "Вызван метод GetText у контролла LinuxLabel\n";
            return text_;
        }
    };

    class MacOSLabel : public Label {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла MacOSLabel\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла MacOSLabel\n";
            return { x_, y_ };
        }
        void SetText(std::string text) override {
            std::cout << "Вызван метод SetText у контролла MacOSLabel\n";
        }
        std::string GetText() override {
            std::cout << "Вызван метод GetText у контролла MacOSLabel\n";
            return text_;
        }
    };


    // ===================== TEXTBOX =====================

    class WindowsTextBox : public TextBox {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла WindowsTextBox\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла WindowsTextBox\n";
            return { x_, y_ };
        }
        void SetText(std::string text) {
            std::cout << "Вызван метод SetText у контролла WindowsTextBox\n";
        }
        std::string GetText() {
            std::cout << "Вызван метод GetText у контролла WindowsTextBox\n";
            return text_;
        }
        void OnValueChanged() {
            std::cout << "Вызван метод OnValueChanged у контролла WindowsTextBox\n";
        }
    };

    class LinuxTextBox : public TextBox {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла LinuxTextBox\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла LinuxTextBox\n";
            return { x_, y_ };
        }
        void SetText(std::string text) {
            std::cout << "Вызван метод SetText у контролла LinuxTextBox\n";
        }
        std::string GetText() {
            std::cout << "Вызван метод GetText у контролла LinuxTextBox\n";
            return text_;
        }
        void OnValueChanged() {
            std::cout << "Вызван метод OnValueChanged у контролла LinuxTextBox\n";
        }
    };

    class MacOSTextBox : public TextBox {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла MacOSTextBox\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла MacOSTextBox\n";
            return { x_, y_ };
        }
        void SetText(std::string text) {
            std::cout << "Вызван метод SetText у контролла MacOSTextBox\n";
        }
        std::string GetText() {
            std::cout << "Вызван метод GetText у контролла MacOSTextBox\n";
            return text_;
        }
        void OnValueChanged() {
            std::cout << "Вызван метод OnValueChanged у контролла MacOSTextBox\n";
        }
    };


    // ===================== COMBOBOX =====================

    class WindowsComboBox : public ComboBox {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла WindowsComboBox\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла WindowsComboBox\n";
            return { x_, y_ };
        }
        void SetSelectedIndex(USHRT index) {
            std::cout << "Вызван метод SetSelectedIndex у контролла WindowsComboBox\n";
        }
        USHRT GetSelectedIndex() {
            std::cout << "Вызван метод GetSelectedIndex у контролла WindowsComboBox\n";
            return index_;
        }
        void SetItems(std::string items) {
            std::cout << "Вызван метод SetItems у контролла WindowsComboBox\n";
        }
        std::string GetItems() {
            std::cout << "Вызван метод GetItems у контролла WindowsComboBox\n";
            return items_;
        }
    };

    class LinuxComboBox : public ComboBox {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла LinuxComboBox\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла LinuxComboBox\n";
            return { x_, y_ };
        }
        void SetSelectedIndex(USHRT index) {
            std::cout << "Вызван метод SetSelectedIndex у контролла LinuxComboBox\n";
        }
        USHRT GetSelectedIndex() {
            std::cout << "Вызван метод GetSelectedIndex у контролла LinuxComboBox\n";
            return index_;
        }
        void SetItems(std::string items) {
            std::cout << "Вызван метод SetItems у контролла LinuxComboBox\n";
        }
        std::string GetItems() {
            std::cout << "Вызван метод GetItems у контролла LinuxComboBox\n";
            return items_;
        }
    };

    class MacOSComboBox : public ComboBox {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла MacOSComboBox\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла MacOSComboBox\n";
            return { x_, y_ };
        }
        void SetSelectedIndex(USHRT index) {
            std::cout << "Вызван метод SetSelectedIndex у контролла MacOSComboBox\n";
        }
        USHRT GetSelectedIndex() {
            std::cout << "Вызван метод GetSelectedIndex у контролла MacOSComboBox\n";
            return index_;
        }
        void SetItems(std::string items) {
            std::cout << "Вызван метод SetItems у контролла MacOSComboBox\n";
        }
        std::string GetItems() {
            std::cout << "Вызван метод GetItems у контролла MacOSComboBox\n";
            return items_;
        }
    };


    // ===================== BUTTON =====================

    class WindowsButton : public Button {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла WindowsButton\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла WindowsButton\n";
            return { x_, y_ };
        }
        void SetText(std::string text) {
            std::cout << "Вызван метод SetText у контролла WindowsButton\n";
        }
        std::string GetText() {
            std::cout << "Вызван метод GetText у контролла WindowsButton\n";
            return text_;
        }
        void Click() {
            std::cout << "Вызван метод Click у контролла WindowsButton\n";
        }
    };

    class LinuxButton : public Button {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла LinuxButton\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла LinuxButton\n";
            return { x_, y_ };
        }
        void SetText(std::string text) {
            std::cout << "Вызван метод SetText у контролла LinuxButton\n";
        }
        std::string GetText() {
            std::cout << "Вызван метод GetText у контролла LinuxButton\n";
            return text_;
        }
        void Click() {
            std::cout << "Вызван метод Click у контролла LinuxButton\n";
        }
    };

    class MacOSButton : public Button {
    public:
        void SetPosition(USHRT x, USHRT y) override {
            std::cout << "Вызван метод SetPosition у контролла MacOSButton\n";
            x_ = x;
            y_ = y;
        }
        Oxy GetPosition() override {
            std::cout << "Вызван метод GetPosition у контролла MacOSButton\n";
            return { x_, y_ };
        }
        void SetText(std::string text) {
            std::cout << "Вызван метод SetText у контролла MacOSButton\n";
        }
        std::string GetText() {
            std::cout << "Вызван метод GetText у контролла MacOSButton\n";
            return text_;
        }
        void Click() {
            std::cout << "Вызван метод Click у контролла MacOSButton\n";
        }
    };

    // Фабрика, создающая контрол в зависимости от параметра sys, отвечающий за систему
    // Параметр form - форма, в которую надо добавить любой контрол (кроме формы)
    template <typename T>
    T* CreateControl(System sys, Form* form)
    {
        T* return_control = nullptr;
        if (sys == WINDOWS)
        {
            if (typeid(T) == typeid(Form))      return_control = (T*)(new WindowsForm());
            if (typeid(T) == typeid(Label))     return_control = (T*)(new WindowsLabel());
            if (typeid(T) == typeid(TextBox))   return_control = (T*)(new WindowsTextBox());
            if (typeid(T) == typeid(ComboBox))  return_control = (T*)(new WindowsComboBox());
            if (typeid(T) == typeid(Button))    return_control = (T*)(new WindowsButton());
        }
        if (sys == LINUX)
        {
            if (typeid(T) == typeid(Form))      return_control = (T*)(new LinuxForm());
            if (typeid(T) == typeid(Label))     return_control = (T*)(new LinuxLabel());
            if (typeid(T) == typeid(TextBox))   return_control = (T*)(new LinuxTextBox());
            if (typeid(T) == typeid(ComboBox))  return_control = (T*)(new LinuxComboBox());
            if (typeid(T) == typeid(Button))    return_control = (T*)(new LinuxButton());
        }
        if (sys == MACOS)
        {
            if (typeid(T) == typeid(Form))      return_control = (T*)(new MacOSForm());
            if (typeid(T) == typeid(Label))     return_control = (T*)(new MacOSLabel());
            if (typeid(T) == typeid(TextBox))   return_control = (T*)(new MacOSTextBox());
            if (typeid(T) == typeid(ComboBox))  return_control = (T*)(new MacOSComboBox());
            if (typeid(T) == typeid(Button))    return_control = (T*)(new MacOSButton());
        }

        if (form != nullptr)
            form->AddControl((Control*)return_control);

        return return_control;
    }
}