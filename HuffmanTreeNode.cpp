#include "HuffmanTreeNode.h"

HuffmanTreeNode::HuffmanTreeNode(char character, int frequency) :
  character{ character }, frequency{frequency}, left{ nullptr }, right{ nullptr } {}
