#pragma once

#include "entt.hpp"
#include "Component/Transform.hpp"

class enttGame
{
    public:
        enttGame();
        ~enttGame();

    private:
        entt::registry m_registry;

};