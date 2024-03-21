// ========= Лабораторная работа №7 =========
// Условие:
// Задание паттерн Repository

#include "irep.h"

int main()
{
    // Создание репозитория
    irep::MemoryUserRepository repos;

    // Создание нового пользователя
    irep::User user_1;
    user_1.SetId(98782);
    user_1.SetName("Ilya");
    user_1.SetEmail("LouieAus@outlook.com");
    user_1.SetPhone("89062478844");
    user_1.SetCity("Kaliningrad");
    user_1.SetGender(irep::Gender::MALE);

    // Добавление пользователя
    repos.MemoryRepository<irep::User>::AddItem(&user_1);

    // Изменение данных пользователя
    user_1.SetId(789897);
    user_1.SetName("Ilya Lvov");
    repos.MemoryRepository<irep::User>::Update(&user_1);

    // Получение пользователя по каким-то данным (в данном случае по id)
    irep::User* get_user = repos.GetById(789897);

    // Удаление пользователя
    repos.MemoryRepository<irep::User>::Delete(get_user);

    // Получение списка всех пользователей
    std::vector<irep::User*> users = repos.MemoryRepository<irep::User>::GetItems();
}