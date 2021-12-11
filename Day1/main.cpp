#include <iostream>
#include "Helper.cpp"
static std::vector<int> CreateArrayFromFile(std::string file) {
    std::ifstream fileStream;
    fileStream.open(file);
    std::vector<int> output;
    std::string line;
    char *end;
    while (std::getline(fileStream, line)) {
        output.push_back(strtol(line.c_str(), &end, 10));
    };
    return output;
}
static int DetectChanges(std::vector<int> measurements) {
    int numberOfChanges = 0;
    for (int index = 1; index < measurements.size(); index++) {
        if (measurements[index] > measurements[index - 1]) {
            ++numberOfChanges;
        }

    }
    return numberOfChanges;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    Helper helper;
    std::vector<int> input = CreateArrayFromFile("D:\\AdventOfCode2021\\Day1\\day1input.txt");
    for(int nos : input){
        std::cout << nos;
    }
    int result = DetectChanges(input);
    return result;
}