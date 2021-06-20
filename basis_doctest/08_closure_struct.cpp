#include <iostream>
#include <cstddef>

using namespace std;


struct counter {
    // If we construct a counter, a private char x would be
    // live with object counter.
    // Just like a closure!
    explicit counter(char x) : x{x} {};

    size_t operator()(const char *str) const {

        size_t index{0}, result{0};
        while (str[index]) {
            index++;
            if (str[index] == x) {
                result++;
            }
        }
        return result;
    }

private:
    const char x;
};

int main() {

    // A counter that only count s
    counter s_counter('s');
    cout << s_counter("abcsssss123 ") << endl;


    counter a_counter('a');
    cout << a_counter("aaaa aaa") << endl;

    return 0;
}