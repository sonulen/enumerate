#include <array>
#include <enumerate.hpp>
#include <iostream>

using mtl::enumerate;

int main(int argc, const char* argv[]) {
    std::array<double, 10> array{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (const auto& [i, v] : enumerate(array)) {
        std::cout << "Index : " << i << " with value: " << v << std::endl;
    }
    return 0;
}