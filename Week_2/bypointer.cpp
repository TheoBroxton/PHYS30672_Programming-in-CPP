// PL2/bypointer.cpp
// Call by value using pointer (PHYS30762)
// Source: Prof. Niels Walet's code repository
#include<iostream> 
void double_value(double* ptr_double) //Function of a pointer
{
  (*ptr_double)*=2; //Use dereferencing operator to get value of variable that is being pointed to
}
int main() 
{ 
  double number{4.}; 
  std::cout<<number<<std::endl; 
  double_value(&number); //Use address of variable when calling function
  std::cout<<number<<std::endl; 
  return 0; 
}
