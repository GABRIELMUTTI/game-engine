#include "EntityTest.hpp"

#include <iostream>

using namespace mtecs;
using namespace mtecs::test;

int main()
{
    int result;
    
    EntityTest entityTest;

    result = entityTest.test();
    std::cout << "EntityTest :: " << result << std::endl;
    
    return 0;
}
