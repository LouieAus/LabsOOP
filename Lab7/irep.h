#pragma once
#include <iostream>
#include <vector>

namespace irep
{
    enum Gender { MALE, FEMALE };

    // Интерфейс IRepository
    template<typename T>
    class IRepository
    {
    public:
        void Add(T* item) {};
        void Update(T* item) {};
        void Delete(T* item) {};
        std::vector<T*> Get(const std::string& path, const std::string& order_by) {};
    };

    // Класс User, содержащий информацию о пользователе
    class User
    {
    private:
        int         m_id_;
        std::string m_name_;
        std::string m_email_;
        std::string m_phone_;
        std::string m_city_;
        Gender      m_gender_;

    public:
        int GetId() const noexcept;
        void SetId(int id) noexcept;

        std::string GetName() const noexcept;
        void SetName(const std::string& name) noexcept;

        std::string GetEmail() const noexcept;
        void SetEmail(const std::string& email) noexcept;

        std::string GetPhone() const noexcept;
        void SetPhone(const std::string& phone) noexcept;

        std::string GetCity() const noexcept;
        void SetCity(const std::string& city) noexcept;

        Gender GetGender() const noexcept;
        void SetGender(Gender gender) noexcept;
    };
    
    // Интерфейс с методами, позволяющими получить информацию о пользователе
    class IUserRepository : public IRepository<User>
    {
    public:
        virtual User*               GetById(int id) = 0;
        virtual std::vector<User*>  GetByName(const std::string& name) = 0;
        virtual User*               GetByEmail(const std::string& email) = 0;
        virtual std::vector<User*>  GetByCity(const std::string& city) = 0;
        virtual std::vector<User*>  GetByGender(Gender gender) = 0;
    };

    // Класс с методами, позволяющими изменять информацию о пользователе
    template<typename T>
    class MemoryRepository : public IRepository<T>
    {
    protected:
        std::vector<T*> m_items_;
    public:
        void AddItem (T* item) noexcept;
        void UpdateItem (T* item) noexcept;
        void DeleteItem (T* item) noexcept;
        std::vector<T*> GetItems() noexcept;
    };

    template<typename T>
    void MemoryRepository<T>::AddItem(T* item) noexcept
    {
        m_items_.push_back(item);
    }

    template<typename T>
    void MemoryRepository<T>::UpdateItem(T* item) noexcept
    {
        for (auto i = 0; i != m_items_.size(); i++)
        {
            if (*m_items_[i] == *item)
            {
                *m_items_[i] = *item;
                break;
            }
        }
    }

    template<typename T>
    void MemoryRepository<T>::DeleteItem(T* item) noexcept
    {
        m_items_.erase(std::remove(m_items_.begin(), m_items_.end(), item), m_items_.end());
    }

    template<typename T>
    std::vector<T*> MemoryRepository<T>::GetItems() noexcept
    {
        return m_items_;
    }

    // Класс MemoryUserRepository, реализующий интерфейсы IUserRepository
    class MemoryUserRepository : public IUserRepository, public MemoryRepository<User>
    {
    public:
        User*               GetById (int id) override;
        std::vector<User*>  GetByName (const std::string& name) override;
        User*               GetByEmail (const std::string& email) override;
        std::vector<User*>  GetByCity (const std::string& city) override;
        std::vector<User*>  GetByGender (Gender gender) override;
    };
}