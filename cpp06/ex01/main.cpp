#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data* ptr = new Data();
    std::cout << "original answer: " << ptr->answer << std::endl;

    uintptr_t serial = Serializer::serialize(ptr);
    std::cout << "serialized number: " << serial << std::endl;

    Data* deserialized = Serializer::deserialize(serial);
    std::cout << "Deserialized answer: " << deserialized->answer << std::endl;

    delete ptr;
}