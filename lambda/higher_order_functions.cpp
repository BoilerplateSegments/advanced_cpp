/*
 * Classic higher order functions
 * Each part should have a counterpart that can be found on Lisp/Scheme/OCaml
 *
 * TODO: rewrite macros with generic or templates?
 */

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

// View and reset
#define RESET_PRINT(S, VEC)                                                   \
  std::cout << S << ": \n";                                                   \
  for (auto i : VEC)                                                          \
    {                                                                         \
      std::cout << i << " ";                                                  \
    }                                                                         \
  std::cout << std::endl << std::endl;                                        \
  vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };                                    \
  //std::iota(std::begin(VEC), std::end(VEC), 0);\

#define VIEW(S) RESET_PRINT (S, vec)


int
main ()
{

  std::vector<int> vec (10);
  // roughly equivalent of range from python.
  // iota is Greek letter for i

  RESET_PRINT ("init", vec)
  // === Map ===

  std::transform (vec.begin (), vec.end (), vec.begin (),
                  [&] (int i) { return i * i; });

  VIEW ("map")

  // === Filter ===

  auto isEven{ [] (int i) { return ((i % 2) == 0); } };

  std::erase_if (vec, isEven);

  VIEW ("filter")

  // == Fold ==
  // In OCaml, we call it as fold_left

  auto multiply{ [] (auto a, auto b) { return a * b; } };

  // C++
  std::cout<<"Fold -> 1*2*3*4*5*6*7*8*9*10\n"
      <<std::accumulate (vec.begin (), vec.end (), 1, multiply);

  return 0;
}