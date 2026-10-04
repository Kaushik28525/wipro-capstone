# Stage 2 – Requirements & Development Plan

## 1. Project Title

**Linux System Resource Monitor with Custom Character Device Driver**

---

## 2. Purpose

The purpose of this project is to develop a C++ based Linux system monitoring application that collects and displays important system information.

The application will monitor CPU information, memory usage, system uptime, and running processes. A Linux character device driver will also be incorporated to demonstrate basic user-space and kernel-space communication.

---

## 3. Functional Requirements

The system shall:

1. Display CPU information.
2. Display the number of physical CPU cores.
3. Display the number of logical processors.
4. Display total system memory.
5. Display used memory.
6. Display available memory.
7. Display system uptime.
8. Count running processes.
9. Read system information using Linux interfaces such as `/proc`.
10. Refresh monitoring information periodically.
11. Handle errors when Linux system files cannot be accessed.
12. Provide a character device driver component.
13. Allow the user-space application to communicate with the character device.
14. Provide a terminal-based interface.
15. Maintain source code using Git version control.

---

## 4. Non-Functional Requirements

### 4.1 Performance

The application should collect and display system information efficiently without unnecessary resource consumption.

### 4.2 Reliability

The application should handle file-access and filesystem errors without unexpectedly terminating.

### 4.3 Portability

The application is designed for Linux systems and uses standard Linux system interfaces.

### 4.4 Maintainability

The source code should be divided into logical modules and documented clearly.

### 4.5 Usability

The monitoring information should be displayed in a clear and readable terminal format.

### 4.6 Security

The application should use appropriate permissions when interacting with Linux system resources and the device driver.

---

## 5. Project Modules

| Module | Responsibility |
|---|---|
| CPU Monitor | Collect CPU information |
| Memory Monitor | Collect memory information |
| Uptime Monitor | Calculate system uptime |
| Process Monitor | Count running processes |
| User Interface | Display monitoring information |
| Device Driver | Provide character-device functionality |
| Testing | Verify system functionality |
| Documentation | Maintain project and technical documentation |

---

## 6. Module Details

### 6.1 CPU Monitor

The CPU monitoring module reads `/proc/cpuinfo` and extracts information such as:

- CPU model
- Physical CPU cores
- Logical processors

### 6.2 Memory Monitor

The memory monitoring module reads `/proc/meminfo` and extracts:

- Total memory
- Available memory
- Used memory

### 6.3 Uptime Monitor

The uptime module reads `/proc/uptime` and converts the uptime value into:

- Days
- Hours
- Minutes
- Seconds

### 6.4 Process Monitor

The process monitor examines directories inside `/proc`.

Directories with numeric names represent process IDs. These directories are counted to determine the approximate number of currently running processes.

### 6.5 User Interface

The application provides a terminal dashboard that displays information collected by the monitoring modules.

The dashboard refreshes periodically so that the displayed information remains current.

### 6.6 Device Driver

The device-driver module will implement a Linux character device.

The driver will demonstrate:

- Kernel module initialization
- Kernel module cleanup
- Character device registration
- Device file creation
- File operations
- Communication between user space and kernel space

---

## 7. System Requirements

### Hardware Requirements

- x86-64 compatible computer
- Minimum 4 GB RAM
- Sufficient storage for Linux development tools

### Software Requirements

- Linux operating system
- GCC/G++
- Linux kernel development environment
- VS Code
- Git
- Make/build tools
- Linux terminal

---

## 8. Development Environment

The project is developed using:

- **Programming Language:** C++
- **Operating System:** Linux
- **Compiler:** G++
- **Editor:** Visual Studio Code
- **Version Control:** Git
- **Repository:** GitHub
- **System Interfaces:** Linux `/proc` filesystem
- **Kernel Component:** Linux character device driver

---

## 9. Development Plan

The project will be developed incrementally.

### Phase 1 – Project Setup

Tasks:

- Create project repository
- Create directory structure
- Configure Linux development environment
- Configure C++ compiler
- Initialize Git repository

Deliverable:

- Working project structure

---

### Phase 2 – CPU Monitoring

Tasks:

- Read `/proc/cpuinfo`
- Extract CPU model
- Extract physical core count
- Extract logical processor count
- Display CPU information

Deliverable:

- Working CPU monitoring module

---

### Phase 3 – Memory Monitoring

Tasks:

- Read `/proc/meminfo`
- Extract total memory
- Extract available memory
- Calculate used memory
- Display memory information

Deliverable:

- Working memory monitoring module

---

### Phase 4 – System Information

Tasks:

- Read `/proc/uptime`
- Calculate system uptime
- Read process directories
- Count running processes

Deliverable:

- Working uptime and process monitoring modules

---

### Phase 5 – Monitor Integration

Tasks:

- Combine monitoring modules
- Create terminal dashboard
- Add periodic refresh
- Add error handling
- Test integrated application

Deliverable:

- Working system-monitor prototype

---

### Phase 6 – Character Device Driver

Tasks:

- Prepare Linux kernel-module development environment
- Implement character device
- Register device number
- Create device class and device
- Implement file operations
- Create device file
- Test communication with user-space application

Deliverable:

- Working Linux character device driver

---

### Phase 7 – Testing and Improvement

Tasks:

- Perform unit testing
- Perform integration testing
- Test driver communication
- Test error conditions
- Debug problems
- Improve code quality
- Update documentation

Deliverable:

- Tested and improved application

---

### Phase 8 – Finalization

Tasks:

- Complete README
- Complete architecture documentation
- Add UML diagrams
- Document testing results
- Review Git history
- Upload final project to GitHub
- Prepare final demonstration

Deliverable:

- Final project and presentation-ready repository

---

## 10. Planned Deliverables

The project will contain:

- C++ source files
- Header files
- Linux device-driver source code
- Test files
- README
- Project introduction
- Requirements document
- Architecture documentation
- UML diagrams
- Testing documentation
- Git history
- GitHub repository

---

## 11. Development Repository Structure

The planned project structure is:

```text
wipro-capstone/
│
├── docs/
│   ├── PROJECT_INTRODUCTION.md
│   ├── REQUIREMENTS.md
│   ├── ARCHITECTURE.md
│   └── TESTING.md
│
├── driver/
│   └── character device driver files
│
├── include/
│   └── header files
│
├── src/
│   ├── main.cpp
│   ├── cpu_monitor.cpp
│   ├── memory_monitor.cpp
│   ├── uptime_monitor.cpp
│   └── process_monitor.cpp
│
├── tests/
│   └── test files
│
└── README.md
