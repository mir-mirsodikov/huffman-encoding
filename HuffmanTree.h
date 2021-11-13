#pragma once
#include "HuffmanTreeNode.h"

class HuffmanTree {
private:
  HuffmanTreeNode* _root;  
  HuffmanTreeNode* insert(HuffmanTreeNode* node, char character, int frequency);
  void preOrder(const HuffmanTreeNode* node);
public:
  HuffmanTree();

  void insert(char character, int frequency); 
  void preOrder();
};