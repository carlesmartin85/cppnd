#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

//import <iostream>;

//import mainmodule;

int main(){

    std::string line;
    std::ifstream myfile ("../src/files/1.board");
    if (myfile.is_open()){
        while ( std::getline (myfile,line) ){
            std::cout << line << '\n';
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file";
    } 

    /*

    std::ifstream my_file;
    my_file.open("../src/files/1.board", std::ios::out);
    if (my_file) {
        std::cout << "The file stream has been created!" << "\n";

        std::ofstream myfile;
  myfile.open ("../src/files/example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;

  */

    //mainmodule::printboard(board);

  return 0;
  
}