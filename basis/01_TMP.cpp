#include <iostream>


//=============================================================================

template <unsigned int n>
struct factorial{
  enum {value = n* factorial<n-1>::value};
};

template <>
struct factorial<0>{
  enum {value = 1};
};


//=============================================================================
// cons
struct Nil{};

template <int n, class T>
struct Cons{
  enum {item = n};
  typedef T next;
};


int main(){

  typedef Cons<1,Cons<2,Nil>> slb_cons;

  // [[ 2 ]]
  std::cout<< slb_cons::next::item << std::endl;

  // [[ 3628800 ]]
  std::cout<< factorial<10>().value <<std::endl;

  std::exit(0);
}