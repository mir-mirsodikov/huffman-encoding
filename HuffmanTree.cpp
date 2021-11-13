#include "HuffmanTree.h"
#include "iostream"

HuffmanTree::HuffmanTree() : _root{ nullptr } {}

void HuffmanTree::insert(char character, int frequency) {
  insert(_root, character, frequency);
}

void HuffmanTree::insert(HuffmanTreeNode* node, char character, int frequency) {
  if (!node) {
    node = new HuffmanTreeNode(character, frequency);
    _root = node;
  }
  else {
    if (frequency < node->frequency) {
      if (!node->left) {
        HuffmanTreeNode* temp = new HuffmanTreeNode(character, frequency);
        node->left = temp;
      }
      else {
        insert(node->right, character, frequency);
      }
    }
    else {
      if (!node->right) {
        HuffmanTreeNode* temp = new HuffmanTreeNode(character, frequency);
        node->right = temp;
      }
      else {
        insert(node, character, frequency);
      }
    }
  }
}

void HuffmanTree::preOrder() {
  preOrder(_root);
}


void HuffmanTree::preOrder(const HuffmanTreeNode* node) {
  if (node) {
		std::cout << node->character << " " << node->frequency; 
		preOrder(node->left); 
		preOrder(node->right); 
	}
}