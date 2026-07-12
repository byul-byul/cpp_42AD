#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data original;
    original.id = 42;
    original.label = "answer";
    original.value = 3.14;

    uintptr_t raw = Serializer::serialize(&original);
    Data *restored = Serializer::deserialize(raw);

    std::cout << "original address:  " << &original << std::endl;
    std::cout << "serialized raw:    " << raw << std::endl;
    std::cout << "restored address:  " << restored << std::endl;
    std::cout << "pointers match:    " << (restored == &original ? "yes" : "no") << std::endl;
    std::cout << "restored->id:      " << restored->id << std::endl;
    std::cout << "restored->label:   " << restored->label << std::endl;
    std::cout << "restored->value:   " << restored->value << std::endl;

    return 0;
}
