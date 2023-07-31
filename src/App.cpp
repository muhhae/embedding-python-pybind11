#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>

#include "Pet/Pet.hpp"

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
}

