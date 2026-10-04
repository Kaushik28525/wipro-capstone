#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ifstream cpuFile("/proc/cpuinfo");

    if (!cpuFile.is_open()) {
        std::cerr << "Error: Could not open /proc/cpuinfo" << std::endl;
        return 1;
    }

    std::string line;

    std::string modelName;
    std::string cpuMHz;
    std::string cacheSize;
    std::string cpuCores;
    std::string siblings;

    while (std::getline(cpuFile, line)) {

        if (line.find("model name") == 0 && modelName.empty()) {
            modelName = line.substr(line.find(":") + 2);
        }

        else if (line.find("cpu MHz") == 0 && cpuMHz.empty()) {
            cpuMHz = line.substr(line.find(":") + 2);
        }

        else if (line.find("cache size") == 0 && cacheSize.empty()) {
            cacheSize = line.substr(line.find(":") + 2);
        }

        else if (line.find("cpu cores") == 0 && cpuCores.empty()) {
            cpuCores = line.substr(line.find(":") + 2);
        }

        else if (line.find("siblings") == 0 && siblings.empty()) {
            siblings = line.substr(line.find(":") + 2);
        }
    }

    cpuFile.close();

    std::cout << "========================================" << std::endl;
    std::cout << "           CPU INFORMATION" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "CPU Model          : " << modelName << std::endl;
    std::cout << "Physical CPU Cores : " << cpuCores << std::endl;
    std::cout << "Logical Processors : " << siblings << std::endl;
    std::cout << "CPU Frequency      : " << cpuMHz << " MHz" << std::endl;
    std::cout << "Cache Size         : " << cacheSize << std::endl;

    std::cout << "========================================" << std::endl;

    return 0;
}