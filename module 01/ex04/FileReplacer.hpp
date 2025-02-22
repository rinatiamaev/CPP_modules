#ifndef FILEREPLACER_HPP 
#define FILEREPLACER_HPP

#include <iostream>
#include <fstream>
#include <string>

class FileReplacer{
    private:
        std::string s1;
        std::string s2;
        std::string filename;
        std::string replaceSame(const std::string& line) const;
    
    public:
        FileReplacer(const std::string& s1, const std::string& s2, const std::string& filename);
        ~FileReplacer();

    bool doWork();
    
};

#endif