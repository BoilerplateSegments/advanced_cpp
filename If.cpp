// Doesn't work yet
// Trial to do something as dynamic as:
// https://github.com/mappum/if/blob/master/index.js

#include <cstdarg>
#include <functional>



template<typename F>
void handler(F f){
  f();
}
template <typename F>
class Step{
public:
  Step(F handler);
  virtual void handler(F f);

};

template <typename F>
class then:Step{
  public:
    then(F Handler);
    void Then(F f);
};

template <typename F>
void
then<F>::Then (F f)
{
  f();
}

Step If(bool cond){
   if (cond){
       return then<int>();
     }
}


int main(){



  return 0;
}