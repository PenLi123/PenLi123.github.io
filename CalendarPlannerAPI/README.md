# CalendarPlannerAPI – Flask Backend

This is the backend API that complements the [CalendarPlanner](../CalendarPlanner/) desktop app, built in C++ with Qt.  
It provides basic RESTful endpoints to store and retrieve daily tasks by date.

---

## How it's different from the main CalendarPlanner project

- The main **CalendarPlanner** project is a desktop app built with **Qt/C++** that provides the user interface.
- This **CalendarPlannerAPI** project is a **Python Flask API** that handles task data storage and processing.
- They communicate via **HTTP requests**: when a user adds or deletes a task in the Qt app, it sends a request to this backend.

This separation reflects a real-world **frontend/backend architecture**.

---

## How to run the backend (macOS/Linux)

### 1. Clone the repository (or move into `CalendarPlannerAPI/`)

```bash
cd CalendarPlannerAPI
```

### 2. Set up a virtual environment

```bash
python3 -m venv venv
source venv/bin/activate
```

### 3. Install dependencies

```bash
pip install flask flask-cors
```

### 4. Run the server

```bash
python3 calendar_backend.py
```

You should see:
```
 * Running on http://127.0.0.1:5000/
```

The Qt frontend will now be able to send requests to this backend when launched.

## License

This project is open-source and distributed under the MIT license.
