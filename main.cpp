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
#include <vector>
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

class Compare {
public:
  bool operator() (HuffmanTreeNode* node1, HuffmanTreeNode* node2) {
    return node1->frequency > node2->frequency; 
  }
};

HuffmanTreeNode* buildHuffmanTree(const string fileName) {
  map<wchar_t, int> characterFrequencyCounter = readFile(fileName);
  priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> characterQueue;
        
  for (auto const &pair : characterFrequencyCounter) {
    characterQueue.push(new HuffmanTreeNode(pair.first, pair.second));
  }

  while (characterQueue.size() > 1) {
    HuffmanTreeNode* left = characterQueue.top();
    characterQueue.pop();
    HuffmanTreeNode* right = characterQueue.top();
    characterQueue.pop();

    int frequencySum = left->frequency + right->frequency;
    characterQueue.push(new HuffmanTreeNode(frequencySum, left, right));
  }
  return characterQueue.top();
}

map<wchar_t, string> getHuffmanCodes(HuffmanTreeNode* node, string prefix, map<wchar_t, string>& output) {
  if (node->isLeaf()) {
    output[node->character] = prefix;
  }
  else {
    getHuffmanCodes(node->left, prefix + "0", output);
    getHuffmanCodes(node->right, prefix + "1", output);
  }
  return output;
}

int main() {
  HuffmanTreeNode* root = buildHuffmanTree("Pride_and_Prejudice.txt");
  string prefix = "";
  map<wchar_t, string> output;
  map<wchar_t, string> huffmanCodes = getHuffmanCodes(root, prefix, output);

  wcout.imbue(locale("zh_CN.UTF-8"));
  for (auto const &pair : huffmanCodes) {
    wcout << pair.first << " : ";
    cout << pair.second << endl;
  }
}