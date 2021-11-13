#include "HuffmanTreeNode.h"

HuffmanTreeNode::HuffmanTreeNode(wchar_t character, int frequency) :
  character{ character }, frequency{frequency}, left{ nullptr }, right{ nullptr } {}

HuffmanTreeNode::HuffmanTreeNode(int frequency, HuffmanTreeNode* left, HuffmanTreeNode* right) : 
  frequency{ frequency }, left { left }, right { right } {
}

bool HuffmanTreeNode::isLeaf() {
  return !(this->left || this->right);
}