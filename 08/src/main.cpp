#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string line){
    vector<int> b_{};
    istringstream my_stream(line);
    char c;
    int n;
    while (my_stream >> n >> c) {
      b_.push_back(n);
    }
    return b_;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<int>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      board.push_back(ParseLine(line));
    }
  } else {
    std::cout << "File could not be opened" << "\n";
  }
  return board;
}

void PrintBoard(const vector<vector<int>> board) {
  cout << "{";
  for (int i = 0; i < board.size(); i++) {
    if (i == 0) {
      cout << "{";
    }else{
      cout << " {";
    }
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
      if (j+1 == board[i].size()) {
        cout << "}";
      }else{
        cout << ", ";
      }
    }

    if (i+1 == board.size()) {
      cout << "}\n";
    }else{
      cout << ",\n";
    }}
}
//#include "test.cpp"
int main() {
  vector<vector<int>> board = ReadBoardFile("../src/files/1.board");
  PrintBoard(board);
  //TestParseLine();
}