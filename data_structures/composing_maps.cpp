#include <iostream>
#include <map>
#include <string>
#include <string_view>

// map(COMPUTER map (CPU, GPU, RAM))
using comp_map=std::map<std::string, std::map<std::string,int>>;

// TODO: real recursive?
void
recursivePrintMap (comp_map& m){

  for (const auto & [key,map]:m){
      std::cout<<key << ":" <<std::endl;

      // Abuse scope rule
      for (const auto & [key,value]:map){
          std::cout<< "\t" << key << " = " << value << std::endl;
        }
    }

}

int
main (){
  comp_map composed_map
      {
        {"comp1",{{"CPU", 10},
                       {"GPU", 15},
                       {"RAM", 20}}},
       {"comp2",{{"CPU", 11},
                       {"GPU", 16},
                       {"RAM", 21}}}
      };

  recursivePrintMap (composed_map);

}

/*
=>
comp1:
	CPU = 10
	GPU = 15
	RAM = 20
comp2:
	CPU = 11
	GPU = 16
	RAM = 21
*/