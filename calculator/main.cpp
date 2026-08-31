#include <iostream>
#include <string>
#include <stdexcept>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <num> <operator> <num>\n";
    return 1;
  }

  try {
    int s;
    std::string op = argv[2];
    int n1 = std::stoi(argv[1]);
    int n2 = std::stoi(argv[3]);

    if (op == "+") {
      s = n1 + n2;
    } else if (op == "-") {
      s = n1 - n2;
    } else if (op == "*") {
      s = n1 * n2;
    } else if (op == "/") {
      if (n2 == 0) {
        throw std::invalid_argument("Cannot divide by 0");
      }
      s = n1 / n2;
    } else {
      throw std::invalid_argument("Inavlid operator");
    }

    std::cout << s << "\n";
  } catch (const std::invalid_argument& e) {
    std::cerr <<  "Argument Error: " << e.what() << "\n";
    return 1;
  } catch (const std::out_of_range& e) {
    std::cerr << "Number too large: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
