#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <cctype>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

void showCPU() {
    std::ifstream cpuFile("/proc/cpuinfo");

    if (!cpuFile.is_open()) {
        std::cout << "CPU Information : Unable to read\n";
        return;
    }

    std::string line;
    std::string modelName;
    std::string cpuCores;
    std::string siblings;

    while (std::getline(cpuFile, line)) {
        if (line.find("model name") == 0 && modelName.empty()) {
            modelName = line.substr(line.find(":") + 2);
        }
        else if (line.find("cpu cores") == 0 && cpuCores.empty()) {
            cpuCores = line.substr(line.find(":") + 2);
        }
        else if (line.find("siblings") == 0 && siblings.empty()) {
            siblings = line.substr(line.find(":") + 2);
        }
    }

    std::cout << "CPU Model          : " << modelName << '\n';
    std::cout << "Physical CPU Cores : " << cpuCores << '\n';
    std::cout << "Logical Processors : " << siblings << '\n';
}

void showMemory() {
    std::ifstream memoryFile("/proc/meminfo");

    if (!memoryFile.is_open()) {
        std::cout << "Memory Information : Unable to read\n";
        return;
    }

    std::string line;
    long long totalMemory = 0;
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
        else if (key == "MemAvailable:") {
            availableMemory = value;
        }
    }

    long long usedMemory = totalMemory - availableMemory;

    std::cout << "Total Memory      : "
              << totalMemory / 1024 << " MB\n";

    std::cout << "Used Memory       : "
              << usedMemory / 1024 << " MB\n";

    std::cout << "Available Memory  : "
              << availableMemory / 1024 << " MB\n";
}

void showUptime() {
    std::ifstream uptimeFile("/proc/uptime");

    if (!uptimeFile.is_open()) {
        std::cout << "System Uptime     : Unable to read\n";
        return;
    }

    double uptimeSeconds;
    double idleSeconds;

    uptimeFile >> uptimeSeconds >> idleSeconds;

    long long totalSeconds =
        static_cast<long long>(uptimeSeconds);

    long long days = totalSeconds / 86400;
    totalSeconds %= 86400;

    long long hours = totalSeconds / 3600;
    totalSeconds %= 3600;

    long long minutes = totalSeconds / 60;
    long long seconds = totalSeconds % 60;

    std::cout << "System Uptime     : "
              << days << " days, "
              << hours << " hours, "
              << minutes << " minutes, "
              << seconds << " seconds\n";
}

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

void showProcesses() {
    int processCount = 0;

    try {
        for (const auto& entry :
             fs::directory_iterator("/proc")) {

            if (entry.is_directory()) {

                std::string name =
                    entry.path().filename().string();

                if (isProcessDirectory(name)) {
                    processCount++;
                }
            }
        }
    }
    catch (const fs::filesystem_error& error) {
        std::cout << "Running Processes : Error\n";
        return;
    }

    std::cout << "Running Processes : "
              << processCount << '\n';
}

void showDriverStatus() {
    std::cout << "Driver Status     : Not installed\n";
}

void displayMonitor() {
    std::cout << "\033[2J\033[H";

    std::cout << "==============================================\n";
    std::cout << "       LINUX SYSTEM RESOURCE MONITOR\n";
    std::cout << "==============================================\n\n";

    std::cout << "[ CPU INFORMATION ]\n";
    showCPU();

    std::cout << "\n[ MEMORY INFORMATION ]\n";
    showMemory();

    std::cout << "\n[ SYSTEM INFORMATION ]\n";
    showUptime();

    std::cout << "\n[ PROCESS INFORMATION ]\n";
    showProcesses();

    std::cout << "\n[ DEVICE DRIVER ]\n";
    showDriverStatus();

    std::cout << "\n==============================================\n";
    std::cout << "Press Ctrl+C to exit\n";
    std::cout << "==============================================\n";
}

int main() {

    while (true) {

        displayMonitor();

        std::this_thread::sleep_for(
            std::chrono::seconds(2)
        );
    }

    return 0;
}
