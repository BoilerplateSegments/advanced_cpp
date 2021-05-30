#include <vector>
#include <iostream>

// aka iterator invalidation

int main(){

    std::vector<int> v {2,3,4,5};
    int *vptr = &v[1]; // Aliasing v[1] with another name
    std::cout<<*vptr<<std::endl;

    v.push_back(6);
    // If there is no more space for additional element
    // A new buffer is allocated and existing elements are moved over
    std::cout<<*vptr;
    //          ^ this value will be random
    // vptr is now dangling ptr
}

//TODO: memory alignment of vector?