#ifndef p09_H
#define p09_H
#include <string_view>
#include <string>
#include <vector>

// check if a word is same when read backward and forward.
bool is_palindrome(const std::string_view& s);

int simple_accumulate(const std::vector<int>& v);

// add a dash line to a set of string items
std::string dashed_string(const std::vector<std::string>& s);
#endif
