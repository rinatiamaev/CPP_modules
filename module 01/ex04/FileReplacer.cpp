#include <iostream>
#include <fstream>
#include <exception>
#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& s1, const std::string& s2, const std::string& filename)
    : s1(s1), s2(s2), filename(filename) {}

FileReplacer::~FileReplacer() {}

std::string FileReplacer::replaceSame(const std::string& line) const {
    std::string res;
    size_t pos = 0;
    size_t prev = 0;

    while ((pos = line.find(s1, prev)) != std::string::npos) {
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

    try {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw std::ios_base::failure("Error: Cannot open file '" + filename + "'.");
        }

        std::ofstream outputFile(filename + ".replace");
        if (!outputFile.is_open()) {
            throw std::ios_base::failure("Error: Cannot create output file.");
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            outputFile << replaceSame(line) << std::endl;
        }

        inputFile.close();
        outputFile.close();
    } catch (const std::ios_base::failure& e) { 
        std::cerr << e.what() << std::endl;
        return (false);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return (false);
    } catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
        return (false);
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
        return (false);
    }

    return (true);
}
