# Stage 4 – Initial Implementation & Prototype

## 1. Project Title

**Linux System Resource Monitor with Custom Character Device Driver**

## 2. Implementation Overview

The initial implementation focuses on developing the core Linux system-monitoring functionality using C++.

The application reads information exposed by the Linux `/proc` filesystem and presents the information through a terminal-based interface.

The prototype currently includes CPU monitoring, memory monitoring, system uptime monitoring, and process monitoring.

The character device driver is planned as the next implementation component.

---

## 3. Development Environment

The application was developed using:

- Linux environment
- C++
- G++ compiler
- Visual Studio Code
- Linux terminal
- Git

The source code is maintained in a Git repository.

---

## 4. Project Structure

The current project structure is:

```text
wipro-capstone/
│
├── docs/
│   ├── PROJECT_INTRODUCTION.md
│   ├── REQUIREMENTS.md
│   ├── ARCHITECTURE.md
│   └── IMPLEMENTATION.md
│
├── driver/
│
├── include/
│
├── src/
│   ├── main.cpp
│   ├── cpu_monitor.cpp
│   ├── memory_monitor.cpp
│   ├── uptime_monitor.cpp
│   └── process_monitor.cpp
│
└── tests/
