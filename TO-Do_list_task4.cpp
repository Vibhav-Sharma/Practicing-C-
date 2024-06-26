#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

class Task {
public:
    Task() : completed(false) {}
    void setTask(const string& task) {
        this->task = task;
        this->completed = false;
    }

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getTask() const {
        return task;
    }
    string task;
    bool completed;
};

class TodoListManager {
public:
    TodoListManager() : taskCount(0) {}

    void addTask(const string& task) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].setTask(task);
            taskCount++;
        } else {
            cout << "No more tasks can be added." << endl;
        }
    }

    void viewTasks() const {
        if (taskCount == 0) {
            cout << "No tasks are therein the list." << endl;
            return;
        }
        for (int i = 0; i < taskCount; i++) {
            string status = tasks[i].isCompleted() ? "Completed" : "Pending";
            cout << i + 1 << ". " << tasks[i].getTask() << " - " << status << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index > 0 && index <= taskCount) {
            tasks[index - 1].markCompleted();
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(int index) {
        if (index > 0 && index <= taskCount) {
            for (int i = index - 1; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
    Task tasks[MAX_TASKS];
    int taskCount;
};

int main() {
    TodoListManager manager;
    int choice;
    string task;
    int taskIndex;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Task\n";
        cout << "3. Mark as Completed\n";
        cout << "4. Remove the Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            manager.addTask(task);
        } 
        
        else if (choice == 2) {
            manager.viewTasks();
        } 
        
        else if (choice == 3) {
            cout << "Enter task number to be marked as completed: ";
            cin >> taskIndex;
            manager.markTaskCompleted(taskIndex);
        } 
        
        else if (choice == 4) {
            cout << "Enter task number to remove: ";
            cin >> taskIndex;
            manager.removeTask(taskIndex);
        }
        
        else if (choice == 5) {
            cout << "Exitting" << endl;
            return 0;
        } 
        
        else {
            cout << "Please try again." << endl;
        }
    }

    return 0;
}
