//
// ФАЙЛ target.cpp
//
#include "target.hpp"

#include <iostream>

namespace tactical
{
Target::Target(IdType id, std::string_view name)
    : m_id{ id }
    , m_name{ name }
    , m_status{ Status::eActive }
{
    std::cout << "[" << TAG << "] Создана: " << m_name << "\n";
}

Target::~Target()
{
    std::cout << "[" << TAG << "] Уничтожена: " << m_name << "\n";
}

void Target::Destroy()
{
    if (m_status == Status::eDestroyed)
    {
        std::cout << "[" << TAG << "] Правило: цель \"" << m_name
                  << "\" уже уничтожена.\n";
        return;
    }
    m_status = Status::eDestroyed;
    std::cout << "[" << TAG << "] Действие: цель \"" << m_name
              << "\" уничтожена.\n";
}
} // namespace tactical