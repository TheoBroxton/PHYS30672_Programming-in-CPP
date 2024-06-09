#include<fstream>

std::ifstream my_input_file; // a file stream for reading only
std::ofstream my_output_file; // a file stream for writing only
std::fstream my_file; // a file stream for both reading and writing

my_file.open("data1.dat"); // open file called data1.dat

std::fstream myfile{"data1.dat"}; // open and attatch data1 to my_file

my_file.close(); // to close the file
