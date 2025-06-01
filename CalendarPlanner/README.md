# CalendarPlanner

**CalendarPlanner** is a lightweight desktop application designed to help users manage daily tasks using an interactive calendar.  
Built with **C++ and Qt6**, it offers a simple and responsive interface for adding, viewing, and checking off tasks by date.

---

## ✨ Features

- Interactive calendar with date selection
- Add tasks for a selected day
- Check off completed tasks (with automatic strikethrough)
- Delete selected tasks
- Highlight calendar dates that contain tasks
- Optional integration with a local Flask API via HTTP POST

---

## How to Run the Application

### 1. Clone the repository

```bash
git clone https://github.com/PenLi123/PenLi123.github.io.git
cd PenLi123.github.io/CalendarPlanner
```

### 2. Build with CMake

Make sure Qt6 and CMake (≥ 3.14) are installed.  
(On macOS with Homebrew: `brew install qt cmake`)

```bash
mkdir build
cd build
cmake ..
make
./CalendarPlanner
```

### 3. (Optional) Run the Flask API

To test the network integration, launch the Flask API backend:

```bash
cd ../TaskTrackAPI
python3 app.py
```

---

## 🛠 Technologies Used

- **C++17**
- **Qt 6** (Widgets, Calendar, Network)
- **CMake** (build system)
- **Flask** (minimal Python API)
