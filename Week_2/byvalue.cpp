#include<iostream>
void double_value(double value)
{
    value*=2;

}
int main()
{
    double number{4.};
    std::cout<<number<<std::endl;
    double_value(number);
    std::cout<<number<<std::endl; //I get the same value printed twice because number is only locally doubled
    return 0;
}