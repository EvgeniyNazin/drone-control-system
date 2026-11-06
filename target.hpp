//
// ФАЙЛ target.hpp
//
#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace tactical
{
class Target
{
public:
    using IdType = std::int32_t;

    enum class Status
    {
        eActive = 0,
        eDestroyed = 1
    };

private:
    static constexpr auto TAG       = "target";
    static constexpr auto BASE_NAME = "noname";

protected:
    IdType m_id{};
    std::string m_name{ BASE_NAME };
    Status m_status{ Status::eActive };

public:
    Target(IdType id, std::string_view name);

    Target()                          = delete;
    Target(const Target&)             = delete;
    Target(Target&&)                  = delete;
    Target& operator=(const Target&)  = delete;
    Target& operator=(Target&&)       = delete;
    ~Target();

    [[nodiscard]] auto GetId() const
    {
        return m_id;
    }

    [[nodiscard]] auto GetName() const -> std::string_view
    {
        return m_name;
    }

    [[nodiscard]] auto GetStatus() const
    {
        return m_status;
    }

    [[nodiscard]] auto IsDestroyed() const -> bool
    {
        return m_status == Status::eDestroyed;
    }

    void Destroy();
};
} // namespace tactical