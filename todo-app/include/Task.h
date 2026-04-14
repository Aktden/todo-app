#pragma once
#pragma once
#include <string>

enum class TaskStatus {
    Proposed,
    Active,
    Resolved,
    Completed
};

struct Task {
    int id;
    std::string title;
    std::string description;
    TaskStatus status;

    Task(int id, const std::string& title, const std::string& description);

    std::string statusToString() const;
    static TaskStatus statusFromString(const std::string& s);
};