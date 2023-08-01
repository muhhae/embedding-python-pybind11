#pragma once

#include <iostream>
#include <vector>

struct Pet
{
    std::string p_name;
    int p_age;

    Pet(std::string name) : p_name(name) {}

    void setName(std::string name) { p_name = name; }
    const std::string getName() const { return p_name; }

    void setAge(int age) { p_age = age; }
    int getAge() { return p_age; }

    std::string sayHello() const { return "Hello, my name is " + p_name; }
};

class PetStore
{
    private:
        std::vector<Pet> m_pets;
    public:
        void addPet(Pet pet) { m_pets.push_back(pet); }
        const std::vector<Pet> getPets() const { return m_pets; }
};

Pet getPet() {
    return Pet("Molly");
}