#ifndef TESTING_MYSTRUCT_H
#define TESTING_MYSTRUCT_H

#include <iostream>
namespace test
{
struct MyStruct
{
public:
    MyStruct()
    {
        std::cout << this << " Ctor" << std::endl;
    }
    ~MyStruct()
    {
        std::cout << this << " Dtor" << std::endl;
    }
};
}

#endif //TESTING_MYSTRUCT_H
