// Testing conversion between variable types
#include<iostream>
int main()
{
    double r{-1.5};   // When we use -1.5 we get -1, but when we use 1.5 we get 1
    int i;
    r=static_cast<int>(r);
    std::cout<<"The value of r is: "<<r<<std::endl;
    return 0;
}
