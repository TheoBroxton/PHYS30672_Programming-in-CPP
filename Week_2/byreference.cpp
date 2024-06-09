// PL2/byreference.cpp (PHYS30762)
// Call by value using reference in function definition 
// Source: Prof. Niels Walet's code repository
#include<iostream>
void double_value(double& reference) //Pass a reference (address denoted by &)
{
  reference*=2;
}
int main() 
{ 
  double number{4.}; 
  std::cout<<number<<std::endl; 
  double_value(number); 
  std::cout<<number<<std::endl; 
  return 0; 
}
