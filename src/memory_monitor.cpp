#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {

    std::ifstream memoryFile("/proc/meminfo");

    if (!memoryFile.is_open()) {
        std::cerr << "Error: Could not open /proc/meminfo" << std::endl;
        return 1;
    }

    std::string line;

    long long totalMemory = 0;
    long long freeMemory = 0;
    long long availableMemory = 0;

    while (std::getline(memoryFile, line)) {

        std::stringstream ss(line);

        std::string key;
        long long value;
        std::string unit;

        ss >> key >> value >> unit;

        if (key == "MemTotal:") {
            totalMemory = value;
        }
        else if (key == "MemFree:") {
            freeMemory = value;
        }
        else if (key == "MemAvailable:") {
            availableMemory = value;
        }
    }

    memoryFile.close();

    long long usedMemory = totalMemory - freeMemory;

    std::cout << "========================================" << std::endl;
    std::cout << "          MEMORY INFORMATION" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "Total Memory     : "
              << totalMemory / 1024 << " MB" << std::endl;

    std::cout << "Free Memory      : "
              << freeMemory / 1024 << " MB" << std::endl;

    std::cout << "Available Memory : "
              << availableMemory / 1024 << " MB" << std::endl;

    std::cout << "Used Memory      : "
              << usedMemory / 1024 << " MB" << std::endl;

    std::cout << "========================================" << std::endl;

    return 0;
}