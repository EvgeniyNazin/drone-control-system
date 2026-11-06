//
// ФАЙЛ main.cpp
//
#include "drone.hpp"
#include "mission.hpp"

#include <iostream>

int main()
{
    std::cout << "=== Начало программы ===\n\n";

    tactical::Drone scoutDrone{ 1, "Разведчик-01", 0, 100 };
    tactical::Drone strikeDrone{ 2, "Ударный-01", 2, 100 };

    std::cout << "\n--- Блок 1: Демонстрация композиции и агрегации ---\n";
    {
        tactical::Mission missionAlpha{ 100, "Удар Альфа" };

        missionAlpha.AddTarget(1, "Вражеский радар");
        missionAlpha.AddTarget(2, "Склад боеприпасов");

        missionAlpha.AssignDrone(&scoutDrone);
        missionAlpha.AssignDrone(&strikeDrone);

        missionAlpha.ExecuteStrike(0, 1);
        missionAlpha.ExecuteStrike(1, 0);

        std::cout << "\n[Инфо] Выход из блока. Миссия будет уничтожена.\n";
    }

    std::cout << "\n--- Блок 2: Демонстрация динамической памяти ---\n";

    std::cout << "Создание динамического массива дронов...\n";
    auto* droneArray = new tactical::Drone[2]{
        tactical::Drone{ 3, "Динамический-1", 5, 50 },
        tactical::Drone{ 4, "Динамический-2", 5, 50 }
    };

    std::cout << "Создание массива указателей на миссии...\n";
    auto** missionPtrs = new tactical::Mission*[2];
    missionPtrs[0] = new tactical::Mission{ 200, "Динамическая миссия 1" };
    missionPtrs[1] = new tactical::Mission{ 201, "Динамическая миссия 2" };

    missionPtrs[0]->AddTarget(10, "Мост");
    missionPtrs[0]->AssignDrone(&droneArray[0]);
    missionPtrs[0]->ExecuteStrike(0, 0);

    std::cout << "\n[Инфо] Очистка динамической памяти...\n";
    delete missionPtrs[0];
    delete missionPtrs[1];
    delete[] missionPtrs;

    delete[] droneArray;

    std::cout << "\n=== Конец программы ===\n";
    return 0;
}