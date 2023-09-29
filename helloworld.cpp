#include <iostream>
// import iostream
// python program starts here

// a = 0
// int a = 0;
int64_t a = 0;

// 8 bits, 1 byte, int8_t
// 32 bits, 4 bytes, int32_t
// 64 bits, 8 bytes, int64_t

int main(void)
{
    // C++ program starts here

    std::cout << "Hello my World!" << std::endl;

    std::cout << "Hello my World!" << std::endl;

    std::cout << "Sizes: " << sizeof(a) << " " << sizeof(int) << " " << sizeof(int64_t) << std::endl;

    a = a + 1;

    std::cout << "a: " << a << std::endl;
    // print("a:", a)

    return 0;
}
