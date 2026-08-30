#include <iostream>
#include <cstdio>

class FileWrapper {
private:
  FILE* m_file;

public:
  FileWrapper(const char* filename) {
    m_file = std::fopen(filename, "r");
    if (m_file) {
      std::cout << "Opened file: " << filename << "\n";
    } else {
      std::cout << "Failed to open file\n";
    }
  }
  ~FileWrapper() {
    if (m_file) {
      std::fclose(m_file);
      std::cout << "Closed file\n";
    }
  }
};

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <file>\n";
    return 1;
  }

  std::cout << "---Starting program---\n";

  {
    std::cout << "Entering local scope... \n";
    FileWrapper file(argv[1]);
  }

  std::cout << "Exited local scope\n";
  std::cout << "---Ending program---\n";

  return 0;
}
