// Buffer area before classification

#include <vector>
#include <iostream>

#define macro_sum(args...) sum(args)

// __Variadic__ templates and macros

int sum(){return 0;}


// Here we defined a list of args
template<typename T, typename... Ts>
T sum(T a, Ts... args){return a + sum(args...);}

int main(){

  std::cout<< sum(1,2,3)+sum(4.0,5.0,6.5)+macro_sum(7,8)<<std::endl;
//  => 36.5

  // Using pointer to modify list
  std::vector< int > numbers = {2, 3, 5, 7};
  for (auto& x : numbers)
    x *= 2;

  for (auto x : numbers)
    std::cout << x << std::endl;
}