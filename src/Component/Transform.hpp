#pragma once

#include <iostream>

struct Transform
{
    float x, y, z;
    void set(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct Color
{
    std::string name;
    void set(std::string name)
    {
        this->name = name;
    }
};

class ClassColor
{
    public :
        void print()
        {
            std::cout << m_color.name << std::endl;
        }
        void setColor(Color color) 
        {
            m_color = color;
        }
    private :
        Color m_color = {"red"};
};