#pragma once
#pragma once
#include "Task.h"
#include <vector>
#include <string>

class TaskManager {
public:
    TaskManager();

    void addTask(const std::string& title, const std::string& description);
    void removeTask(int id);
    void updateStatus(int id, TaskStatus status);
    void listTasks() const;
    void listByStatus(TaskStatus status) const;
    Task* findById(int id);

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);

private:
    std::vector<Task> tasks_;
    int nextId_;

    void printTask(const Task& task) const;
};