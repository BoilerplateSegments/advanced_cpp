#include <iostream>
#include <functional>
#include <string>

struct animal{
  std::string name = "animal";
  virtual void bark() const{
    std::cout<<this->name<<"Generic sound"<<std::endl;
  };
  animal(){
    std::cout<<"animal init"<<std::endl;
  };
};

struct dog:animal{
  void bark() const override{
    std::cout<<this->name<<" WoWoWo!"<<std::endl;
  }
  std::string name = "dog";
  dog(){
    std::cout<<"dog init"<<std::endl;
  }
};

int main(){

  dog mydog;
  mydog.bark();
  // Output:
  //  animal init => Parent class's constructor
  //  dog init
  //  dog WoWoWo!


  return 0;
}