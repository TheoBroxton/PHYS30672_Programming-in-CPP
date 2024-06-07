// Example: checking for valid input
#include<iostream>
int main()
{
    int any_year;
    std::cout<<"Enter a year: ";
    std::cin>>any_year;
    // Check input is valid
    while(std::cin.fail())
    {
        std::cout<<"Sorry, your input was not valid, please enter a year: ";
        //Clear fail bit and ignore bad input
        std::cin.clear();
        std::cin.ignore();
        std::cin>>any_year;
    }
    std::cout<<"C++ is the best programming language in "<<any_year<<"!"<<std::endl;
}