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

// Python String splitter

template <typename S>
void single_char_split(const std::string_view s,char delim, S result){

  // FIXME: C++ Quirk
  std::istringstream stream(std::string(s), std::ios_base::in);

  std::string item;
  while (std::getline(stream,item, delim)){
      *result++ = item;
    }
}

std::vector<std::string>
single_char_split(std::string_view s, char delim){
  std::vector<std::string> elems;
  single_char_split (s, delim, std::back_inserter (elems));
  return elems;
}

// echo
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

  auto SplitedStr= single_char_split ("A:B:C",':');

  // [[ B ]]
  std::cout<< SplitedStr[1]<<std::endl;


  std::exit (0);
}