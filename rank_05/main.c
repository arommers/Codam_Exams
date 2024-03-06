// #include "infin_mult.h"
#include "test.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        write(1, "Usage: ./multiply_strings num1 num2\n", 36);
        return 1;
    }
    // multiply_strings(argv[1], argv[2]);
    infin_mult(argv[1], argv[2]);
    return 0;
}