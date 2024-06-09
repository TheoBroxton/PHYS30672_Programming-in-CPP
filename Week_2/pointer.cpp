#include<iostream>
int main()
{
    double a{3.2}; //a is an ordinary int variable, initialised to 3
    double* ptr; //declared a pointer
    ptr=&a; //initialised pointer with address of a
    
    std::cout<<"Value of a is "<<a<<std::endl;
    std::cout<<"Address of a is "<<ptr<<std::endl;
    std::cout<<"Value of a (*ptr) is "<<*ptr<<std::endl; //Use * as dereferncing operator to get the value of a

    return 0;
}