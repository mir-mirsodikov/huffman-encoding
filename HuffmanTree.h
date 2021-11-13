#pragma once
#include "HuffmanTreeNode.h"

class HuffmanTree {
private:
  HuffmanTreeNode* _root;  
  HuffmanTreeNode* insert(HuffmanTreeNode* node, wchar_t character, int frequency);
  void preOrder(const HuffmanTreeNode* node);
public:
  HuffmanTree();

  void insert(wchar_t character, int frequency); 
  void preOrder();
};