#include <iostream>

using namespace std;

int main()
{
    struct alignas(4) Info2 {
        uint8_t a;
        uint16_t b;
        uint8_t c;
    };
    
    std::cout << sizeof(Info2::b) << std::endl; // 8 4 + 4
    std::cout << alignof(Info2) << std::endl;
    return 0;
}