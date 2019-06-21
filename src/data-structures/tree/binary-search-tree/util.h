#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

namespace FileUtils {
    bool readFile(const std::string &filename, std::vector<std::string> &words) {
        std::string line;
        std::string contents = "";
        std::ifstream file(filename);
        if (file.is_open()) {
            while (getline(file, line)) 
                contents += (line + "\n");
            file.close();
        } else {
            std::cout << "Failed to open " << filename << "!" << std::endl;
            return false;
        }

        for (int i = 0; i < contents.length(); i++)
            if (ispunct(contents[i]) || !isalpha(contents[i]))
                contents[i] = ' ';

        std::stringstream ss(contents);
        std::string word;
        while (ss >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.push_back(word);
        }

        return true;
    }
}