#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> ReadBoardFile(std::string path_to_file){
    std::vector<std::vector<int>> b;
    std::ifstream my_file;
    my_file.open(path_to_file);
    if (my_file) {
        std::string line;
        while (std::getline(my_file, line)) {
            std::vector<int> b_{};
            while (line != "") {
                b_.push_back(stoi(line.substr(0, line.find(","))));
                line = line.substr(line.find(",") + 1, line.length());
            }
            b.push_back(b_);
        }
        my_file.close();
    }
    return b;
}

void PrintBoard(const std::vector<std::vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
    std::vector<std::vector<int>> board = ReadBoardFile("../src/files/1.board");
    PrintBoard(board);
}