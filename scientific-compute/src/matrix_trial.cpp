#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

void hr(){
    std::cout<<std::endl;
}

int main()
{
    MatrixXd m = MatrixXd::Random(3,3);
    MatrixXd constone=MatrixXd::Constant(3,3,1);
    std::cout<<m+constone<<std::endl;
    VectorXd v(3);
    v<< 1,2,3;
    std::cout<< (m+constone)*v<<std::endl;

    hr();

    Matrix2f a;
    a << 1,2,
         3,4;
    Matrix2f b;
    b << 1,2,
         3,4;


    std::cout<<a*b<<std::endl;
//    7 10
//    15 22
//    7 = 1*1+2*3

    hr();


}
