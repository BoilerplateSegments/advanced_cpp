#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

/*
a string_view consists of only a pointer and a length,
 identifying a section of character data that is not owned by the string_view
 and cannot be modified by the view.
 Consequently, making a copy of a string_view is a shallow operation:
 no string data is copied.

// C Convention
void TakesCharStar(const char* s);

// Old Standard C++ convention
void TakesString(const std::string& s);

// string_view C++ conventions
void TakesStringView(std::string_view s);     // C++17
*/

void echoStringView(std::string_view s){
  std::cout<<s<<std::endl;
}

size_t countAlphaBet(std::string_view s,char c)  {
  return std::count(s.begin(),s.end(),c);
}

// Repeat two string concated
std::string shuffleStr(std::string_view s1, std::string_view s2, int n){
  std::ostringstream strStream;
  for(int i=0;i<n;i++){
      strStream<< s1 << s2;
    };
  return strStream.str();
}

int main(){

  const std::string stdStr="C++ version of string";
  const char* plainStr="C version of string";

  // Same way to invoke with no duplicated allocation !
  // [[ C++ version of string ]]
  echoStringView (stdStr);
  // [[ C version of string ]]
  echoStringView (plainStr);

  // [[ 4 ]]
  std::cout<<countAlphaBet ("AABBCCCC",'C')<<std::endl;

  // [[ ABABAB ]]
  std::cout<< shuffleStr("A","B",3)<<std::endl;

  std::exit (0);
}