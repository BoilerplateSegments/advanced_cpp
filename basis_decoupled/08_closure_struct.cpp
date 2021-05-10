#include <iostream>
#include <cstddef>

using namespace std;

int newslbplus(int x, int y) {
  cout<<"nce";
  return x+y; }

struct counter{
  // If we construct a counter, a private char x would be
  // live with object counter.
  // Just like a closure!
  explicit counter(char x):x { x }{};

  size_t operator() (const char* str) const{

    size_t index{},result{};
    while(str[index]){
        if(str[index] == x) result++;
        index++;
      }
    return result;
  }

private:
  const char x;
};

//int main(){
//
//  // A counter that only count s
//  counter s_counter('s');
//  cout<<s_counter("abcsssss123 ")<<endl;
//
//  return 0;
//}