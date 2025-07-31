# driver-monitoring-system
A C++ project that showcases a driver monitoring system using biometric data input and visual console feedback. 
# 🚗 Driver Monitoring System

A C++ console application that simulates a biometric-based **driver state monitoring system**.  
This project analyzes heart rate, blink rate, and stress level to classify the driver’s mental condition and trigger safety actions accordingly.

> ✅ Built by **Navi Jha** – aspiring Software Engineer & system thinker 😤✨

---

## 🧠 Features

- 🩺 **Biometric simulation**: Randomized or manually entered heart rate, blink rate, and stress scale
- 🧠 **State classification**: Detects driver status as:
  - 😁 HAPPY
  - 😐 NEUTRAL
  - 😴 DROWSY
  - 🚨 STRESSED!
  - 🆘 EMERGENCY
- 🎨 **Color-coded console**: Terminal output uses ANSI colors for visibility
- ✍️ **Manual mode**: Enter your own biometric values to test the system
- 🗂️ **Logging**: All states saved to `driver_log.txt`


## 💻 How to Run
g++ vibes.cpp -o vibes
./vibes

Optional: Clear old logs
rm driver_log.txt

File Structure
📦 driver-monitoring-system
├── vibes.cpp        → Main program
├── vibes            → Compiled binary
├── driver_log.txt   → State logs
└── README.md        → This file ✨

Technologies
Language: C++
Concepts: object-oriented logic, console UI, input validation, file I/O

Author
Navangana (Navi) Jha
Student @UGA - Computer Systems Engineering
---

## 📸 Sample Output

```bash
===============================
 VIBE: Driver Status Console
===============================

Heart Rate: 112 BPM
Blink Rate: 23 /min
Stress Level: 9/10
Status: 🚨 STRESSED!
System Action: Playing calming music, lowering AC...
