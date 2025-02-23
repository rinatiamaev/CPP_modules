#include "FileReplacer.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << "<s1> <s2> <filename>" << std::endl;
        return (1);
    }

    FileReplacer replacer(argv[1], argv[2], argv[3]);
    if (!replacer.doWork()) {
        return (1);
    }

    std::cout << "Well done. Output: " << argv[3] << ".replace" << std::endl;
    return (0);
}
