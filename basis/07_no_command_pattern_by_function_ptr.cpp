#include<cstdio>

// Since we can dynamically rebind `function` pointer
// to any function, we dont need command pattern at all!
//
// opt can be replaced by add & subtract.
using opt = double(*)(double,int);

double add(double a, int b) {
  return a + b;
}
double subtract(double a, int b) {
  return a - b;
}


int main(){

  opt myopt = nullptr;
    printf ("%p\n",myopt);

  myopt = &add;
    printf ("%p\n",myopt);
    printf ("%f\n",myopt(1.2,3));

  myopt = &subtract;
    printf ("%p\n",myopt);
    printf ("%f\n",myopt(1.2,3));

}