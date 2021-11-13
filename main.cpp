/**
 * Mirmukhammad Mirsodikov
 * CS400
 * Homework 7
  1. Define a struct for Huffman tree node. This struct contains links to left/right child nodes, a character,
      and its frequency.
  2. Define a function for file reading operation. This function should take in a filename (string type) as
      parameter and return a proper data structure object that contains characters and their frequencies
      that will be used to generate Huffman tree nodes.
  3. The construction of Huffman tree requires taking two nodes with smallest frequencies. Select a
      proper data structure to support this operation. Note this data structure object could be different to
      the object from Step (2).
  4. Design a function that takes in the root of Huffman coding tree, prints, and returns the encoding
      scheme in a data structure object.
  5. Design a function that takes in the encoding scheme and filename (string type), output encoded
      content (bit-string) to a file named pride.huff 
 * November 6
 */

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include <queue>
#include "HuffmanTree.h"
using namespace std;

map<wchar_t, int> readFile(string fileName);

map<wchar_t, int> readFile(string fileName) {
  wifstream fileRead;
  fileRead.imbue(locale("zh_CN.UTF-8"));
  map<wchar_t, int> characterFrequencyCounter;

  wchar_t fileCharacter;

  fileRead.open(fileName);
  if (fileRead.is_open()) {
    while (!fileRead.eof()) {
      fileRead.get(fileCharacter);
      if (fileRead.gcount() < 1) break;
      if (characterFrequencyCounter.count(fileCharacter) != 0) {
        characterFrequencyCounter.at(fileCharacter) += 1;
      }
      else {
        characterFrequencyCounter.insert(pair<wchar_t, int>(fileCharacter, 1));
      }
    }
  }
  return characterFrequencyCounter;
}

int main() {
  map<wchar_t, int> characterFrequencyCounter = readFile("Pride_and_Prejudice.txt");
  wcout.imbue(locale("zh_CN.UTF-8"));
  // for (auto const &pair : characterFrequencyCounter) {
  //   wcout << pair.first << " " << pair.second << endl;
  // }

  HuffmanTree myTree;

  myTree.insert('a', 5);
  myTree.insert('b', 1);
  myTree.insert('T', 45);
  myTree.insert('y', 7);
  myTree.insert('/', 2);
  
  myTree.preOrder();
}