#include "Task.h"

Task::Task(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description), status(TaskStatus::Proposed) {
}

std::string Task::statusToString() const {
    switch (status) {
    case TaskStatus::Proposed:  return "Proposed";
    case TaskStatus::Active:    return "Active";
    case TaskStatus::Resolved:  return "Resolved";
    case TaskStatus::Completed: return "Completed";
    }
    return "Unknown";
}

TaskStatus Task::statusFromString(const std::string& s) {
    if (s == "Active")    return TaskStatus::Active;
    if (s == "Resolved")  return TaskStatus::Resolved;
    if (s == "Completed") return TaskStatus::Completed;
    return TaskStatus::Proposed;
}