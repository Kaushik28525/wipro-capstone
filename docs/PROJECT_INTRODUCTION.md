# Stage 1 – Project Introduction

## Project Title

**Linux System Resource Monitor with Custom Character Device Driver**

## 1. Project Overview

The Linux System Resource Monitor is a C++ based system-monitoring application designed to run on Linux.

The project collects and displays important system information using Linux system interfaces such as `/proc`. The application monitors CPU information, memory usage, system uptime, and running processes.

A custom Linux character device driver is also planned as part of the project to demonstrate communication between user-space applications and the Linux kernel.

The project combines C++ programming, Linux system programming, operating-system concepts, computer architecture, hardware/software interaction, and device-driver concepts.

---

## 2. Problem Statement

Linux provides system information through different interfaces, but users normally need to execute separate commands or inspect different files to obtain CPU, memory, process, and system information.

The objective of this project is to develop a single C++ application that collects important system information and presents it in a simple and organized interface.

The project also demonstrates how a user-space application can communicate with a Linux character device driver.

---

## 3. Project Objective

The main objectives of the project are:

- Develop a Linux-based system monitoring application using C++.
- Collect CPU information from the Linux `/proc` filesystem.
- Monitor system memory information.
- Display system uptime.
- Count currently running processes.
- Provide a simple terminal-based monitoring interface.
- Understand Linux system interfaces and filesystem-based system information.
- Implement a Linux character device driver.
- Demonstrate user-space and kernel-space communication.
- Apply Linux, C++, operating-system, and computer-architecture concepts.
- Maintain the complete project using Git and GitHub.

---

## 4. Scope of the Project

The project focuses on monitoring the basic resources of a Linux system.

### Included in the scope

- CPU information
- Physical CPU cores
- Logical processors
- Memory information
- Used and available memory
- System uptime
- Running process count
- Linux `/proc` filesystem
- Linux character device driver
- User-space and kernel-space communication
- C++ system programming
- Error handling
- Testing and debugging
- Git version control
- Project documentation

### Outside the current scope

- Graphical user interface
- Remote system monitoring
- Network monitoring
- Cloud-based monitoring
- Advanced performance profiling
- Hardware control

---

## 5. Main Modules

The project is divided into the following modules:

### 5.1 CPU Monitoring Module

Reads CPU information from `/proc/cpuinfo`.

The module collects information such as:

- CPU model
- Physical CPU cores
- Logical processors

### 5.2 Memory Monitoring Module

Reads memory information from `/proc/meminfo`.

The module collects:

- Total memory
- Used memory
- Available memory

### 5.3 System Uptime Module

Reads `/proc/uptime` to determine how long the Linux system has been running.

### 5.4 Process Monitoring Module

Reads the `/proc` filesystem and identifies directories whose names are numeric.

Numeric directories represent process IDs, allowing the application to determine the number of running processes.

### 5.5 User Interface Module

Displays the collected information in a terminal-based monitoring dashboard.

The monitor periodically refreshes the displayed information.

### 5.6 Character Device Driver Module

A Linux character device driver is planned for the project.

The driver will demonstrate:

- Linux kernel module concepts
- Character device registration
- Device file creation
- File operations
- User-space and kernel-space communication

---

## 6. Expected Outcome

The final application is expected to provide a terminal interface similar to:

```text
==============================================
       LINUX SYSTEM RESOURCE MONITOR
==============================================

[ CPU INFORMATION ]
CPU Model          : 12th Gen Intel(R) Core(TM) i7-12650H
Physical CPU Cores : 8
Logical Processors : 16

[ MEMORY INFORMATION ]
Total Memory       : XXXX MB
Used Memory        : XXXX MB
Available Memory   : XXXX MB

[ SYSTEM INFORMATION ]
System Uptime      : XX days, XX hours, XX minutes, XX seconds

[ PROCESS INFORMATION ]
Running Processes  : XX

[ DEVICE DRIVER ]
Driver Status      : ...

==============================================
Press Ctrl+C to exit
==============================================
