#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

TaskManager::TaskManager() : nextId_(1) {}

void TaskManager::addTask(const std::string& title, const std::string& description) {
    tasks_.emplace_back(nextId_++, title, description);
    std::cout << "Task added: [" << (nextId_ - 1) << "] " << title << "\n";
}

void TaskManager::removeTask(int id) {
    auto it = std::remove_if(tasks_.begin(), tasks_.end(),
        [id](const Task& t) { return t.id == id; });
    if (it != tasks_.end()) {
        tasks_.erase(it, tasks_.end());
        std::cout << "Task #" << id << " removed.\n";
    }
    else {
        std::cout << "Task #" << id << " not found.\n";
    }
}

void TaskManager::updateStatus(int id, TaskStatus status) {
    Task* task = findById(id);
    if (task) {
        task->status = status;
        std::cout << "Task #" << id << " status updated to " << task->statusToString() << "\n";
    }
    else {
        std::cout << "Task #" << id << " not found.\n";
    }
}

void TaskManager::printTask(const Task& task) const {
    std::cout << "  [" << std::setw(3) << task.id << "] "
        << std::left << std::setw(30) << task.title
        << " | " << std::setw(10) << task.statusToString()
        << " | " << task.description << "\n";
}

void TaskManager::listTasks() const {
    if (tasks_.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }
    std::cout << "\n=== All Tasks ===\n";
    for (const auto& task : tasks_) {
        printTask(task);
    }
    std::cout << "Total: " << tasks_.size() << " task(s)\n\n";
}

void TaskManager::listByStatus(TaskStatus status) const {
    Task dummy(0, "", "");
    dummy.status = status;
    std::cout << "\n=== Tasks with status: " << dummy.statusToString() << " ===\n";
    int count = 0;
    for (const auto& task : tasks_) {
        if (task.status == status) {
            printTask(task);
            ++count;
        }
    }
    if (count == 0) std::cout << "  (none)\n";
    std::cout << "\n";
}

Task* TaskManager::findById(int id) {
    for (auto& task : tasks_) {
        if (task.id == id) return &task;
    }
    return nullptr;
}

bool TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    file << nextId_ << "\n";
    for (const auto& task : tasks_) {
        file << task.id << "|"
            << task.title << "|"
            << task.description << "|"
            << task.statusToString() << "\n";
    }
    std::cout << "Saved " << tasks_.size() << " task(s) to " << filename << "\n";
    return true;
}

bool TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    tasks_.clear();
    file >> nextId_;
    file.ignore();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string idStr, title, desc, statusStr;
        if (std::getline(ss, idStr, '|') &&
            std::getline(ss, title, '|') &&
            std::getline(ss, desc, '|') &&
            std::getline(ss, statusStr)) {
            Task task(std::stoi(idStr), title, desc);
            task.status = Task::statusFromString(statusStr);
            tasks_.push_back(task);
        }
    }
    std::cout << "Loaded " << tasks_.size() << " task(s) from " << filename << "\n";
    return true;
}