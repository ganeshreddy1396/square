#include <iostream>
#include "math_functions.h"

int main() {
    int num = 5;
    int square_result = square(num);

    std::cout << "Square of " << num << " is: " << square_result << std::endl;

    return 0;
}
