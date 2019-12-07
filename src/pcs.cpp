#include "include/pcs.hpp"
#include "include/property.hpp"

#include "include/positionProperty.hpp"
#include "include/positionLimitProperty.hpp"
#include "include/speedProperty.hpp"
#include "include/textureProperty.hpp"
#include "include/WASDAnimatorProperty.hpp"
#include "include/WASDControllerProperty.hpp"
#include "include/tilemapProperty.hpp"
#include "include/mouse.hpp"
#include "include/cameraProperty.hpp"

#include "include/exeptions.hpp"

#include <iostream>

void PropertyControlSystem::update()
{
    for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
    {
        if (properties[i])
        {
            properties[i]->update();
        }
    }
}

PropertyControlSystem::PropertyControlSystem(const PropertyControlSystem &cp)
{
    for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
    {
        if (properties[i])
        {
            properties[i] = cp.properties[i];
        }
    }
}

void PropertyControlSystem::draw()
{
    for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
    {
        if (properties[i])
        {
            properties[i]->draw();
        }
    }
}

property *PropertyControlSystem::addProperty(int id) //safity adding property
{
    if (!properties[id])
    {
        properties[id] = create(id);
    }
    return properties[id];
}

property *PropertyControlSystem::connectProperty(property *p) //unsafe
{
    int id = p->getID();
    if (properties[id])
    {
        throw new propertySwapping();
    }
    else
    {
        properties[id] = p;
    }
    return properties[id];
}

property *PropertyControlSystem::getProperty(int id)
{
    if (properties[id])
    {
    }
    else
    {
        std::cout << "[!] Property not created, creating new property " << std::endl;
        properties[id] = create(id);
    }
    return properties[id];
}

PropertyControlSystem::PropertyControlSystem(/* args */)
{
    for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
    {
        if (properties[i])
        {
            properties[i] = nullptr;
        }
    }
    std::cout << "[?] Has been created new property control system" << std::endl;
}

PropertyControlSystem::~PropertyControlSystem()
{
    for (size_t i = 0; i <= OVERAL_PROPERTIES; i++)
    {
        if (properties[i])
        {
            delete properties[i];
        }
    }
}

property *PropertyControlSystem::create(int id)
{
    switch (id)
    {
    case PROPERTY_POSITION:
        return new positionProperty(this);
        break;
    case PROPERTY_TEXTURE:
        return new textureProperty(this);
        break;
    case PROPERTY_SPEED:
        return new speedProperty(this);
        break;
    case PROPERTY_WASD_CONTROLLER:
        return new WASDControllerProperty(this);
        break;
    case PROPERTY_COLLIDER:
        return nullptr;
        break;
    case PROPERTY_TILEMAP:
        return new tilemap(this);
        break;
    case PROPERTY_GRAVITY:
        return new gravityProperty(this);
        break;
    case PROPERTY_CAMERA:
        return new camera(this);
        break;
    case PROPERTY_POSITION_LIMIT:
        return new positionLimitProperty(this);
        break;
    case PROPERTY_MOUSE:
        return new mouse(this);
        break;
    case PROPERY_WASD_ANIMATOR:
        return new WASDAnimatorProperty(this);
        break;
    default:
        return nullptr;
        break;
    }
    return nullptr;
}
