// Implementations of a set of higher order functions

#include<iostream>

// Recursive sum
// constexpr means this will be expanded at compile times
template<typename T>
constexpr T rec_sum(T car){
  return car;
}

template<typename T, typename...Args>
constexpr T rec_sum(T car, Args... cdr){
  return car + rec_sum (cdr...);
}

int main(){
  std::cout<<rec_sum(1,2,3)<<std::endl;
}