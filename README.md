# Linux System Resource Monitor with Custom Character Device Driver

## 1. Project Overview

The **Linux System Resource Monitor** is a C++ based Linux system-monitoring project.

The application collects important system information using Linux system interfaces such as the `/proc` filesystem and displays the information through a terminal-based dashboard.

The project also includes a planned Linux character device driver component to demonstrate communication between user-space software and the Linux kernel.

---

## 2. Objectives

The main objectives are:

- Monitor CPU information.
- Monitor system memory.
- Display system uptime.
- Count running processes.
- Provide a terminal-based monitoring dashboard.
- Understand Linux system interfaces.
- Demonstrate C++ system programming.
- Implement and integrate a Linux character device driver.
- Apply operating-system and computer-architecture concepts.
- Maintain the project using Git and GitHub.

---

## 3. Features

### Currently Implemented

- CPU information monitoring
- Physical CPU core detection
- Logical processor detection
- Memory monitoring
- System uptime monitoring
- Running process counting
- Terminal dashboard
- Periodic refresh
- Basic error handling

### Planned

- Linux character device driver
- Device file communication
- User-space/kernel-space communication
- Driver integration with the monitoring application

---

## 4. System Architecture

```text
                    USER
                     |
                     v
       +---------------------------+
       | C++ System Resource       |
       | Monitor Application       |
       +-------------+-------------+
                     |
          +----------+----------+
          |                     |
          v                     v
      Linux /proc           /dev/lsrm
          |                     |
          v                     v
   System Information     Character Driver
                                |
                                v
                         Linux Kernel
