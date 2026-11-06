//
// ФАЙЛ mission.hpp
//
#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace tactical
{
class Drone;
class Target;

class Mission
{
public:
    using IdType = std::int32_t;

private:
    static constexpr auto TAG       = "mission";
    static constexpr auto BASE_NAME = "noname";

protected:
    IdType m_id{};
    std::string m_name{ BASE_NAME };
    std::vector<Target*> m_targets{};  // сырые указатели, но Mission владеет ими
    std::vector<Drone*> m_drones{};

public:
    Mission(IdType id, std::string_view name);

    Mission()                            = delete;
    Mission(const Mission&)              = delete;
    Mission(Mission&&)                   = delete;
    Mission& operator=(const Mission&)   = delete;
    Mission& operator=(Mission&&)        = delete;
    ~Mission();

    [[nodiscard]] auto GetId() const
    {
        return m_id;
    }

    [[nodiscard]] auto GetName() const -> std::string_view
    {
        return m_name;
    }

    void AddTarget(IdType targetId, std::string_view targetName);
    void AssignDrone(Drone* drone);
    void ExecuteStrike(std::size_t targetIdx, std::size_t droneIdx);
};
} // namespace tactical