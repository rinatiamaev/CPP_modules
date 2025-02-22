#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& s1, const std::string& s2, const std::string& filename): s1(s1), s2(s2), filename(filename) {};
FileReplacer::~FileReplacer(){};

std::string FileReplacer::replaceSame(const std::string& line) const {
    std::string res;
    size_t pos = 0;
    size_t prev = 0;

    while ((pos = line.find(s1, prev)) != std::string::npos)
    {
        res.append(line, prev, pos - prev);
        res.append(s2);
        prev = pos + s1.length();
    }
    res.append(line, prev, std::string::npos);
    return (res);
}

bool FileReplacer::doWork() {
    if (s1.empty() || s2.empty() || filename.empty()) {
        std::cerr << "Error: Invalid parameters." << std::endl;
        return (false);
    }
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cant open file '" << filename << "'." << std::endl;
        return (false);
    }
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cant create file." << std::endl;
        inputFile.close();
        return (false);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceSame(line) << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return (true);
}