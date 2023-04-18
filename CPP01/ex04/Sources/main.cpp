
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {

    if (argc != 4) {
        std::cout << "Unvalid args" << std::endl;
        return (1);
    }
    
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile;
    std::string line;
    size_t found;
    std::string inputFileName = argv[1];
    std::string charToReplace = argv[2];
    std::string replaceChar = argv[3];

    if (inputFile.is_open()) {
        outputFile.open(inputFileName.append(".replace"));
        while (std::getline(inputFile, line)) {
            found = 0;
            found = line.find(charToReplace);
            if (found != std::string::npos) {
                line.erase(found, charToReplace.length());
                line.insert(found, replaceChar);
            }
            while (found != std::string::npos) {
                found = line.find(charToReplace, found + 1);
                if (found != std::string::npos) {
                    line.erase(found, charToReplace.length());
                    line.insert(found, replaceChar);
                }
            }
            outputFile << line << std::endl;
        }
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return (0);
}
