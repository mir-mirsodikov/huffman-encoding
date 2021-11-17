#include "HuffmanTree.h"
using namespace std;

/**
 * Custom class used for comparing HuffmanNodes in the priority queue.
 */ 
class Compare {
public:
  bool operator() (HuffmanTreeNode* node1, HuffmanTreeNode* node2) {
    return node1->frequency > node2->frequency; 
  }
};

/**
 * Entry function of the class that performs the whole compression
 * process.
 * 
 */ 
void HuffmanTree::compress(const std::string fileName) {
  HuffmanTreeNode* root = buildHuffmanTree(fileName);

  std::map<wchar_t, std::string> output;
  std::map<wchar_t, std::string> huffmanCodes = getHuffmanCodes(root, "", output);

  writeFile(fileName, huffmanCodes); 
}

/**
 * Writes the bit strings to the desired file ("pride.huff")
 * 
 * @param fileName        Name of the file to read
 * @param encodingScheme  Huffman bit string encoding scheme for each character  
 */ 
void HuffmanTree::writeFile(string fileName, map<wchar_t, string> encodingScheme) {
  ofstream fileWrite;
  wifstream fileRead;
  fileRead.imbue(locale("zh_CN.UTF-8"));
  fileWrite.imbue(locale("zh_CN.UTF-8"));
  fileRead.open(fileName);

  if (fileRead.is_open()) {
    wchar_t fileCharacter;
    fileWrite.open("pride.huff");
    while (!fileRead.eof()) {
      fileRead.get(fileCharacter);
      if (fileRead.gcount() < 1) break;
      fileWrite << encodingScheme[fileCharacter];
    }
  }
}

/**
 * Read the provided text file and count the frequencies of characters. 
 * 
 * @param fileName  Name of the file to read
 * 
 * @return A map of the characters in the file as the key and 
 * their frequencies as values.
 */ 
map<wchar_t, int> HuffmanTree::readFile(const string fileName) {
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
        characterFrequencyCounter[fileCharacter] += 1;
      }
      else {
        characterFrequencyCounter.insert(pair<wchar_t, int>(fileCharacter, 1));
      }
    }
  }
  return characterFrequencyCounter;
}

/**
 * Build a Huffman tree by comparing the nodes' frequencies
 * 
 * @param fileName  Name of the file to read and generate the frequencies from
 * 
 * @return A tree of huffman nodes 
 */ 
HuffmanTreeNode* HuffmanTree::buildHuffmanTree(const std::string fileName) {
  map<wchar_t, int> characterFrequencyCounter = readFile(fileName);
  priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> characterQueue;
  
  // Push all key-value pairs in the map to the priority queue as a HuffmanNodeObject
  for (auto const &pair : characterFrequencyCounter) {
    characterQueue.push(new HuffmanTreeNode(pair.first, pair.second));
  }

  // Two at a time, remove the top nodes, which are the lowest frequencies
  // Add the frequencies together
  // Push a new node to the queue with the total frequency and left/right children
  while (characterQueue.size() > 1) {
    HuffmanTreeNode* left = characterQueue.top();
    characterQueue.pop();
    HuffmanTreeNode* right = characterQueue.top();
    characterQueue.pop();

    int frequencySum = left->frequency + right->frequency;
    characterQueue.push(new HuffmanTreeNode(frequencySum, left, right));
  }

  // At the end of the top loop, there should only be one node left in the queue
  // This is the root node
  return characterQueue.top();
}

/**
 * Create the Huffman encoding scheme characters in the tree
 * 
 * @param node    Root of the Huffman tree
 * @param prefix  The bit string value being kept track of and assigned to a leaf
 * @param output  Map of the characters and their encoding thus far
 * 
 * @return  Map of the encoding scheme.
 */ 
std::map<wchar_t, std::string> HuffmanTree::getHuffmanCodes(HuffmanTreeNode* node, std::string prefix, std::map<wchar_t, std::string>& output) {
  wcout.imbue(locale("zh_CN.UTF-8"));
  if (node->isLeaf()) {
    output[node->character] = prefix;
    wcout << node->character << ": ";
    cout << prefix << endl;
  }
  else {
    getHuffmanCodes(node->left, prefix + "0", output);
    getHuffmanCodes(node->right, prefix + "1", output);
  }
  return output;
}