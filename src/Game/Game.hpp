#pragma once

#include <memory>
#include <map>
#include <unordered_map>

#include "Entity/Entity.hpp"

class Game
{
    private:
        std::unordered_map<std::string, std::shared_ptr<nty::Entity>> m_entities;
        
    public:
        void addEntity(std::string name, nty::Entity* entity)
        {
            m_entities[name] = std::make_shared<nty::Entity>(*entity);
        }

        std::reference_wrapper<nty::Entity> getEntity(std::string name)
        {
            return *m_entities[name];
        }
        

};