#include <iostream>
#include <assert.h>

// A simple generic function

template <class T>
T pick_max(T a, T b){
  return (a>b)?a:b;
}

int main(){

  assert( pick_max<int>(3,2)==3);

  return 0;
}