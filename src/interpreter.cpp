#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <iostream>

#include "Pet/Pet.hpp"
#include "Game/Game.hpp"
#include "Entity/Entity.hpp"
#include "Component/Transform.hpp"

namespace py = pybind11;

using namespace py::literals;

Pet getTesPet()
{
    return Pet("DOGGY");
}

void basicValueModification()
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
}

void gameSystem()
{
    try 
    {
        py::scoped_interpreter guard{};

        Game game = Game();

        game.addEntity("Player", new nty::Entity());

        py::module_ playerScript = py::module_::import("player");
        auto playerController = playerScript.attr("PlayerController")(std::ref(game));

        std::cout << "CPP : playerExistColor : " << game.getEntity("Player").get().exist<Color>() << std::endl;
        std::cout << "CPP : playerExistTransform : " << game.getEntity("Player").get().exist<Transform>() << std::endl;

        playerController.attr("OnUpdate")();

        std::cout << "CPP : playerExistColor : " << game.getEntity("Player").get().exist<Color>() << std::endl;
        std::cout << "CPP : playerExistTransform : " << game.getEntity("Player").get().exist<Transform>() << std::endl;

        std::cout << "size:" << game.getEntity("Player").get().getList<Transform>().get().size() << std::endl;

        std::cout << "END" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr<< e.what() << std::endl;
    }
}

int main()
{
    // basicValueModification();
    gameSystem();
    // enttGameSystem();
    
    return 0;
}