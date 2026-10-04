#include <iostream>
#include <filesystem>
#include <string>
#include <cctype>

namespace fs = std::filesystem;

bool isProcessDirectory(const std::string& name) {
    if (name.empty()) {
        return false;
    }

    for (char ch : name) {
        if (!std::isdigit(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    return true;
}

int main() {
    const std::string procPath = "/proc";

    int processCount = 0;

    try {
        for (const auto& entry : fs::directory_iterator(procPath)) {
            if (entry.is_directory()) {
                std::string directoryName = entry.path().filename().string();

                if (isProcessDirectory(directoryName)) {
                    processCount++;
                }
            }
        }
    }
    catch (const fs::filesystem_error& error) {
        std::cerr << "Error reading /proc: "
                  << error.what() << std::endl;
        return 1;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "          PROCESS INFORMATION" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "Running Processes : "
              << processCount << std::endl;

    std::cout << "========================================" << std::endl;

    return 0;
}
