#include <functional>
#include <iostream>
#include <string>

#define PRINT(out) std::cout << out << std::endl
#define BREAK std::cout << "―――――――――――" << std::endl

// a function that return a function
std::function<int (int, int)>
higher_order (const std::string &expr)
{
  if ("+" == expr)
    {
      return [] (auto a, auto b) { return a + b; };
    }
  else if ("-" == expr)
    {
      return [] (auto a, auto b) { return a - b; };
    }
}

// a function that require a lambda
// Repeat a function certain times, a counter is passed to it.
// The second parameter takes a int and return void.
void
repeat (int times, const std::function<void (int)> &fn)
{
  for (int i = 0; i < times; ++i)
    {
      fn (i);
    }
}

int
main ()
{
  // generic lambda
  auto less = [] (auto a, auto b) { return a < b; };
  bool b = less (2, 1);
  PRINT (b); //  => 0

  PRINT (higher_order ("+") (1, 3));

  BREAK;

  repeat (4, [] (int i) { PRINT (i + 1); });

  BREAK;

  // Simple capture

  int ammo{ 10 }; // this is not array init like ammo[3] = {1,2,3}

  auto shoot{
    // capture by reference (which enable use to do some side-effects)
    [&ammo] (int x) { --ammo; }
  };

  auto shoot_auto{
    // `default capture` by reference.
    // If u want to capture by value, use [=] instead
    [&](int x) { --ammo; }
  };

  repeat (3, shoot);
  repeat (3, shoot_auto);

  PRINT (ammo); // => 4

  BREAK;

  return 0;
}
