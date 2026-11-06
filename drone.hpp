//
// ФАЙЛ drone.hpp
//
#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace tactical
{
class Target; // forward declaration

class Drone
{
public:
    using IdType = std::int32_t;

private:
    static constexpr auto TAG       = "drone";
    static constexpr auto BASE_NAME = "noname";
    static constexpr auto MAX_AMMO  = 10;

protected:
    IdType m_id{};
    std::string m_name{ BASE_NAME };
    std::int32_t m_ammo{ 0 };
    std::int32_t m_battery{ 0 };

public:
    Drone(IdType id, std::string_view name, std::int32_t ammo, std::int32_t battery);

    Drone()                          = delete;
    Drone(const Drone&)              = delete;
    Drone(Drone&&)                   = delete;
    Drone& operator=(const Drone&)   = delete;
    Drone& operator=(Drone&&)        = delete;
    ~Drone();

    [[nodiscard]] auto GetId() const
    {
        return m_id;
    }

    [[nodiscard]] auto GetName() const -> std::string_view
    {
        return m_name;
    }

    [[nodiscard]] auto GetAmmo() const
    {
        return m_ammo;
    }

    [[nodiscard]] auto GetBattery() const
    {
        return m_battery;
    }

    auto Attack(Target& target) -> bool;
    void Recharge();
};
} // namespace tactical