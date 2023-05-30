// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include  <string>

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string word;
  while (!file.eof()) {
    int ch = file.get();
    if (ch >= 65 && ch <= 90) {
      ch += 32;
      word += ch;
    } else if (ch >= 97 && ch <= 122) {
      word += ch;
    } else {
      tree.add(word);
      word = "";
    }
  }
  file.close();
  return tree;
}
