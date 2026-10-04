#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream uptimeFile("/proc/uptime");

    if (!uptimeFile.is_open()) {
        std::cerr << "Error: Could not open /proc/uptime" << std::endl;
        return 1;
    }

    double uptimeSeconds;
    double idleSeconds;

    uptimeFile >> uptimeSeconds >> idleSeconds;
    uptimeFile.close();

    long long totalSeconds = static_cast<long long>(uptimeSeconds);

    long long days = totalSeconds / 86400;
    totalSeconds %= 86400;

    long long hours = totalSeconds / 3600;
    totalSeconds %= 3600;

    long long minutes = totalSeconds / 60;
    long long seconds = totalSeconds % 60;

    std::cout << "========================================" << std::endl;
    std::cout << "          SYSTEM UPTIME INFORMATION" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "System Uptime : "
              << days << " days, "
              << hours << " hours, "
              << minutes << " minutes, "
              << seconds << " seconds"
              << std::endl;

    std::cout << "Idle Time     : "
              << std::fixed << std::setprecision(2)
              << idleSeconds << " seconds"
              << std::endl;

    std::cout << "========================================" << std::endl;

    return 0;
}
