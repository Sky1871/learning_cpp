#include <iostream>
#include <string>

void swapstr(std::string &s1, std::string &s2) {
  std::string temp = s1;
  s1 = s2;
  s2 = temp;
}

void process_str(std::string &str) {
  std::string sign = " - processed";

  str += sign;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <swap> or <process>\n";
    return 1;
  }
  
  std::string cmd = argv[1];
  std::string s1 = "apple";
  std::string s2 = "banana";

  if (cmd == "swap") {
    std::cout << "original: " << s1 << " " << s2 << "\n";

    swapstr(s1, s2);

    std::cout << "swapped: " << s1 << " " << s2 << "\n";
  } else if (cmd == "process") {
    std::cout << "original: " << s1 << " " << s2 << "\n";

    process_str(s1);
    process_str(s2);

    std::cout << "processed: " << s1 << " " << s2 << "\n";
  } else {
    std::cout << "Usage: " << argv[0] << " <swap> or <process>\n";
    return 1;
  }
  return 0;
}
