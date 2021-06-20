#include <fmt/core.h>
#include <fmt/format.h>

// C++20 perview
// none-std fmt lib that implemented c++ 20 format

int main() {
    fmt::print("Hello, world!\n");

    fmt::memory_buffer out;
    fmt::format_to(out,"The answer is {}.\n", 42);
    fmt::print(to_string(out));

    fmt::print("{:^+30.3f}\n",-123456789.123456789);
    // : ^       +         30     .  3                      f
    // :[center][add sign][width][.][three floating points][FP]
    fmt::print(
    "┌{0:─^{2}}┐\n"
              "│{1: ^{2}}│\n"
              "└{0:─^{2}}┘\n", "", "Hello, world!", 20);

}