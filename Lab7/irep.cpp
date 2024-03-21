#include "irep.h"

namespace irep
{
    int User::GetId() const noexcept            { return m_id_; }
    void User::SetId(int id) noexcept                       { m_id_ = id; }

    std::string User::GetName() const noexcept  { return m_name_; }
    void User::SetName(const std::string& name) noexcept    { m_name_ = name; }

    std::string User::GetEmail() const noexcept { return m_email_; }
    void User::SetEmail(const std::string& email) noexcept  { m_email_ = email; }

    std::string User::GetPhone() const noexcept { return m_phone_; }
    void User::SetPhone(const std::string& phone) noexcept  { m_phone_ = phone; }

    std::string User::GetCity() const noexcept  { return m_city_; }
    void User::SetCity(const std::string& city) noexcept    { m_city_ = city; }

    Gender User::GetGender() const noexcept     { return m_gender_; }
    void User::SetGender(Gender gender) noexcept            { m_gender_ = gender; }

    User* MemoryUserRepository::GetById (int id)
    {
        for (auto& user : m_items_)
        {
            if (user->GetId() == id)
            {
                return user;
            }
        }
        return nullptr;
    }

    std::vector<User*> MemoryUserRepository::GetByName(const std::string& name)
    {
        std::vector<User*> res;
        for (auto& user : m_items_)
        {
            if (user->GetName() == name)
            {
                res.push_back(user);
            }
        }
        return res;
    }

    User* MemoryUserRepository::GetByEmail(const std::string& email)
    {
        for (auto& user : m_items_)
        {
            if (user->GetEmail() == email)
            {
                return user;
            }
        }
        return nullptr;
    }

    std::vector<User*> MemoryUserRepository::GetByCity(const std::string& city)
    {
        std::vector<User*> res;
        for (auto& user : m_items_) 
        {
            if (user->GetCity() == city)
            {
                res.push_back(user);
            }
        }
        return res;
    }

    std::vector<User*> MemoryUserRepository::GetByGender(Gender gender)
    {
        std::vector<User*> res;
        for (auto& user : m_items_)
        {
            if (user->GetGender() == gender)
            {
                res.push_back(user);
            }
        }
        return res;
    }
}