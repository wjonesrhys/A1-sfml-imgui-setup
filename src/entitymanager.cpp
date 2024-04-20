#include <entitymanager.hpp>

EntityManager::EntityManager()
{
    std::cout << "entity manager created" << std::endl;
}

EntityManager::~EntityManager()
{
    std::cout << "entity manager destroyed" << std::endl;
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    // std::cout << "added entity" << std::endl;
    m_totalEntities++;
    auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities));
    m_entities.push_back(e);
    m_entityMap[tag].push_back(e);
    return e;
}

size_t EntityManager::getNumOfEntities() 
{
    return this->m_totalEntities;
}

EntityVec& EntityManager::getEntities()
{

    // std::cout << "got entities" << std::endl;
    return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
    // std::cout << "got entities by a label from the map" << std::endl;
    return m_entityMap[tag];
}