# Stage 5 – Testing, Integration & Improvement

## 1. Project Title

**Linux System Resource Monitor with Custom Character Device Driver**

## 2. Testing Objective

The objective of testing is to verify that each monitoring module works correctly, that the modules work together as an integrated application, and that errors are handled appropriately.

Testing is performed incrementally so that problems can be identified and corrected during development.

---

## 3. Testing Environment

The monitoring application is tested in a Linux environment using:

- C++
- G++ compiler
- Linux terminal
- Visual Studio Code
- Git

The character-device driver will require a Linux kernel development environment with matching kernel headers.

---

## 4. Unit Testing

Each monitoring component is tested independently before integration.

### 4.1 CPU Monitor Test

**Input:**

```text
/proc/cpuinfo
