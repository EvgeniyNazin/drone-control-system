//
// ФАЙЛ mission.cpp
//
#include "mission.hpp"
#include "drone.hpp"
#include "target.hpp"

#include <iostream>

namespace tactical
{
Mission::Mission(IdType id, std::string_view name)
    : m_id{ id }
    , m_name{ name }
{
    std::cout << "[" << TAG << "] Создана: " << m_name << "\n";
}

Mission::~Mission()
{
    std::cout << "[" << TAG << "] Уничтожена: " << m_name
              << " (Цели также уничтожаются)\n";
    
    // Композиция: Mission владеет целями и удаляет их
    for (auto* target : m_targets)
    {
        delete target;
    }
    m_targets.clear();
}

void Mission::AddTarget(IdType targetId, std::string_view targetName)
{
    auto* target = new Target(targetId, targetName);
    m_targets.push_back(target);
}

void Mission::AssignDrone(Drone* drone)
{
    if (drone == nullptr)
    {
        std::cout << "[" << TAG << "] Ошибка: передан nullptr дрона.\n";
        return;
    }
    m_drones.push_back(drone);
    std::cout << "[" << TAG << "] Действие: дрон \""
              << drone->GetName() << "\" назначен на миссию \""
              << m_name << "\".\n";
}

void Mission::ExecuteStrike(std::size_t targetIdx, std::size_t droneIdx)
{
    if (targetIdx >= m_targets.size())
    {
        std::cout << "[" << TAG << "] Ошибка: индекс цели вне диапазона.\n";
        return;
    }
    if (droneIdx >= m_drones.size())
    {
        std::cout << "[" << TAG << "] Ошибка: индекс дрона вне диапазона.\n";
        return;
    }

    std::cout << "--- Выполнение удара ---\n";
    m_drones[droneIdx]->Attack(*m_targets[targetIdx]);
    std::cout << "------------------------\n";
}
} // namespace tactical