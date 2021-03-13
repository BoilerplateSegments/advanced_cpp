#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

using std::cin;
using std::cout;
using std::endl;


int main(){

  // constructing
  std::filesystem::path cur_path=std::filesystem::current_path();

  //concatenate paths
  cur_path+="/nice.data";

  cout<<cur_path<<endl;

  is_directory(cur_path)?cout<<"Y":cout<<"N";
  cout<<endl;

  std::ofstream out(cur_path);

  if (out.fail()){
      cout<<"cannot open out"<<endl;
      return 0;
  }

  out<<"Hello\t\nOMG\tYSE"<<endl;
  out.close();

  std::ifstream in;
  in.open (cur_path);

  if (!in.is_open()){
      cout<<"cannot read"<<endl;
      return 0;
  }

  std::string line;
  while (getline (in,line))
  {
    cout<<line<<endl;
  }

  return 0;
}