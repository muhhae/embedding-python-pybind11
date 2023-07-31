#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>

#include "Pet/Pet.hpp"
#include "Entity/Entity.hpp"
#include "Component/Transform.hpp"

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(App, m) {
    m.doc() = "pybind11 App plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");
    m.attr("the_answer") = 42;

    py::class_<Pet>(m, "Pet", py::dynamic_attr())
        .def(py::init<std::string>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("setAge", &Pet::setAge)
        .def("getAge", &Pet::getAge)
        .def("sayHello", &Pet::sayHello)
        .def("__repr__", [](const Pet &a) {
            return "<Pet named '" + a.getName() + "'>";
        });

    m.def("getPet", &getPet);
    m.attr("Tes") = Pet("DOGGY");

    py::class_<PetStore>(m, "PetStore")
        .def(py::init<>())
        .def("addPet", &PetStore::addPet)
        .def("getPets", &PetStore::getPets);

    py::class_<Transform>(m, "Transform")
        .def(py::init<>())
        .def_readwrite("x", &Transform::x)
        .def_readwrite("y", &Transform::y)
        .def_readwrite("z", &Transform::z)
        .def("__repr__", [](const Transform &a) {
            return "<Transform x: " + std::to_string(a.x) + ", y: " + std::to_string(a.y) + ", z: " + std::to_string(a.z) + ">";
        });

    py::class_<Color>(m, "Color")
        .def(py::init<>())
        .def_readwrite("name", &Color::name)
        .def("__repr__", [](const Color &a) {
            return "<Color name: " + a.name + ">";
        });

    py::class_<ClassColor>(m, "ClassColor")
        .def(py::init<>())
        .def("print", &ClassColor::print)
        .def("setColor", &ClassColor::setColor);

    py::class_<nty::Entity>(m, "Entity")
        .def(py::init<>())
        .def("getTransform", &nty::Entity::get<Transform>)
        .def("getColor", &nty::Entity::get<Color>)
        .def("getClassColor", &nty::Entity::get<ClassColor>)
        .def("addTransform", &nty::Entity::add<Transform>)
        .def("addColor", &nty::Entity::add<Color>)
        .def("addClassColor", &nty::Entity::add<ClassColor>)
        .def("existTransform", &nty::Entity::exist<Transform>)
        .def("existColor", &nty::Entity::exist<Color>)
        .def("existClassColor", &nty::Entity::exist<ClassColor>);
}

