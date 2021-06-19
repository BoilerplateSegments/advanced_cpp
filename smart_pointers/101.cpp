#include <memory>
#include <iostream>


int main(){
    auto p = std::make_unique<int>(2);

    auto q = std::move(p);

}