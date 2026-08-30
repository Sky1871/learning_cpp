#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <filename>\n";
    return 1;
  }
  
  std::string word;
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << argv[1] << "\n";
  }
  std::map<std::string, int> wordCount;

  while (file >> word) {
    word.erase(
      std::remove_if(word.begin(), word.end(), [](unsigned char c){ return std::ispunct(c); }),
      word.end()
    );

    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

    if (!word.empty()) {
      wordCount[word]++;
    }
  }
  
  for (const auto& [key, val] : wordCount)
    std::cout << key << " = " << val << '\n';
  return 0;
}
