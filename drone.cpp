//
// ФАЙЛ drone.cpp
//
#include "drone.hpp"
#include "target.hpp"

#include <iostream>

namespace tactical
{
Drone::Drone(IdType id, std::string_view name, std::int32_t ammo, std::int32_t battery)
    : m_id{ id }
    , m_name{ name }
    , m_ammo{ ammo }
    , m_battery{ battery }
{
    std::cout << "[" << TAG << "] Создан: " << m_name
              << " (Боекомплект: " << m_ammo << ")\n";
}

Drone::~Drone()
{
    std::cout << "[" << TAG << "] Уничтожен: " << m_name << "\n";
}

auto Drone::Attack(Target& target) -> bool
{
    if (m_ammo <= 0)
    {
        std::cout << "[" << TAG << "] Нарушение правила: дрон \""
                  << m_name << "\" не имеет боекомплекта! Атака отменена.\n";
        return false;
    }
    if (target.IsDestroyed())
    {
        std::cout << "[" << TAG << "] Правило: цель уже уничтожена, атака не требуется.\n";
        return false;
    }

    --m_ammo;
    std::cout << "[" << TAG << "] Действие: дрон \"" << m_name
              << "\" атакует \"" << target.GetName()
              << "\". Осталось боекомплекта: " << m_ammo << "\n";
    target.Destroy();
    return true;
}

void Drone::Recharge()
{
    m_ammo = MAX_AMMO;
    std::cout << "[" << TAG << "] Действие: дрон \"" << m_name
              << "\" перезаряжен. Боекомплект: " << m_ammo << "\n";
}
} // namespace tactical