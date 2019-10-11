#include "gtest/gtest.h"
#include <memory>

namespace test
{
namespace SmartPointer
{
class Foo
{
private:
    unsigned char value1{};
    int value2{};
    long long value3{};
};

class Holder
{
    Holder(const std::shared_ptr<Foo> _ptr):
    mMyPtr{_ptr}
    {}
private:
    std::shared_ptr<Foo> mMyPtr;
};

void foo1(const std::shared_ptr<Foo> _foo)
{

}

}
}

using test::SmartPointer::Foo;

TEST(TestSharedPtr, test)
{
 ASSERT_EQ(16, sizeof(Foo));
}

