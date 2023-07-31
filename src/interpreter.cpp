#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <iostream>

#include "Pet/Pet.hpp"

namespace py = pybind11;

using namespace py::literals;

Pet getTesPet()
{
    return Pet("DOGGY");
}

int main()
{
    py::scoped_interpreter guard{};

    try 
    {
        py::module_ app = py::module_::import("App");
        py::module_ tes = py::module_::import("tes");

        auto update = tes.attr("Update");

        Pet pet = Pet("Kitty");

        update(std::ref(pet));

        std::cout << "Pet name: " << pet.getName() << std::endl;
        std::cout << "Pet sayHello: " << pet.sayHello() << std::endl;
        std::cout << "Pet age: " << pet.getAge() << std::endl;

        std::cout << "end" << std::endl;
        std::cout << "Test Pet Store" << std::endl;

        PetStore petStore;

        petStore.addPet(Pet("Kitty"));
        tes.attr("PopulatePetStore")(std::ref(petStore));

        std::cout << "PetStore size: " << petStore.getPets().size() << std::endl;
        for (const auto& pet : petStore.getPets())
        {
            std::cout << "Pet name: " << pet.getName() << std::endl;
        }

        std::cout << "end" << std::endl;
        std::cout << "Test Class Populator" << std::endl;

        PetStore petStore2;

        py::object classPopulator = tes.attr("Populator")(std::ref(petStore2));

        classPopulator.attr("populate")();

        std::cout << "PetStore size: " << petStore2.getPets().size() << std::endl;

        for (const auto& pet : petStore2.getPets())
        {
            std::cout << "Pet name: " << pet.getName() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}