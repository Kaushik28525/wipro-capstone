# Stage 3 – System Design & Architecture

## 1. Project Title

**Linux System Resource Monitor with Custom Character Device Driver**

---

## 2. System Overview

The Linux System Resource Monitor is divided into two main parts:

1. User-space C++ monitoring application
2. Linux kernel-space character device driver

The user-space application collects system information from Linux system interfaces such as `/proc`.

The character device driver provides a communication interface between the user-space application and the Linux kernel.

---

## 3. High-Level Architecture

```text
+------------------------------------------------------+
|                    USER / OPERATOR                   |
+----------------------------+-------------------------+
                             |
                             v
+------------------------------------------------------+
|          C++ Linux System Resource Monitor           |
|                                                      |
|  +-------------+  +-------------+  +-------------+  |
|  | CPU Monitor |  |Memory Monitor| |Uptime Monitor| |
|  +-------------+  +-------------+  +-------------+  |
|                                                      |
|  +----------------+  +-----------------------------+ |
|  |Process Monitor |  | Terminal User Interface     | |
|  +----------------+  +-----------------------------+ |
+----------------------------+-------------------------+
                             |
              +--------------+--------------+
              |                             |
              v                             v
+---------------------------+   +----------------------+
|       Linux /proc         |   | Character Device     |
|                           |   | Driver               |
| /proc/cpuinfo             |   |                      |
| /proc/meminfo             |   | Linux Kernel Space   |
| /proc/uptime              |   |                      |
| /proc/<PID>               |   | /dev/lsrm            |
+---------------------------+   +----------------------+
                                          |
                                          v
                              +----------------------+
                              | Linux Kernel         |
                              | Character Device    |
                              | Subsystem            |
                              +----------------------+
