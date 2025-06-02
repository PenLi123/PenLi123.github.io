from flask import Flask, request, jsonify
from flask_cors import CORS
from collections import defaultdict

app = Flask(__name__)
CORS(app)

# Stores tasks per date in memory: { "YYYY-MM-DD": [ { "text": ..., "done": ... }, ... ] }
task_storage = defaultdict(list)

# -------------------------------
# Retrieve all tasks for a date
# -------------------------------
@app.route('/tasks/<date>', methods=['GET'])
def fetch_tasks(date):
    return jsonify(task_storage[date])

# -------------------------------
# Add a new task to a specific date
# -------------------------------
@app.route('/tasks/<date>', methods=['POST'])
def create_task(date):
    payload = request.get_json()
    text = payload.get('text')

    if not text:
        return jsonify({'error': 'Task content is required.'}), 400

    task_storage[date].append({'text': text, 'done': False})
    return jsonify({'message': 'Task successfully added!'}), 201

# -------------------------------
# Update completion status of a task
# -------------------------------
@app.route('/tasks/<date>/<int:task_index>', methods=['PATCH'])
def mark_task_done(date, task_index):
    payload = request.get_json()
    done = payload.get('done')

    try:
        task_storage[date][task_index]['done'] = bool(done)
        return jsonify({'message': 'Task status updated.'})
    except IndexError:
        return jsonify({'error': 'Task index out of range.'}), 404

# -------------------------------
# Delete a task
# -------------------------------
@app.route('/tasks/<date>/<int:task_index>', methods=['DELETE'])
def remove_task(date, task_index):
    try:
        task_storage[date].pop(task_index)
        return jsonify({'message': 'Task successfully deleted.'})
    except IndexError:
        return jsonify({'error': 'Task index out of range.'}), 404

# -------------------------------
# Launch the Flask app
# -------------------------------
if __name__ == '__main__':
    app.run(debug=True)
