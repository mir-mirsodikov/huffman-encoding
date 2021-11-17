#pragma once
#include <map>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <locale>
#include <iostream>
#include "HuffmanTreeNode.h"

class HuffmanTree {
private:
  std::map<wchar_t, int> readFile(const std::string fileName);
  HuffmanTreeNode* buildHuffmanTree(const std::string fileName);
  std::map<wchar_t, std::string> getHuffmanCodes(HuffmanTreeNode* node, std::string prefix, std::map<wchar_t, std::string>& output);
  void writeFile(std::string fileName, std::map<wchar_t, std::string> encodingScheme);
public:
  HuffmanTree() = default;

  void compress(const std::string fileName);
};