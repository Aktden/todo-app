#include "TaskManager.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\n╔══════════════════════════════╗\n";
    std::cout << "║       TODO LIST MANAGER      ║\n";
    std::cout << "╠══════════════════════════════╣\n";
    std::cout << "║  1. Add task                 ║\n";
    std::cout << "║  2. List all tasks           ║\n";
    std::cout << "║  3. Update task status       ║\n";
    std::cout << "║  4. Remove task              ║\n";
    std::cout << "║  5. Filter by status         ║\n";
    std::cout << "║  6. Save to file             ║\n";
    std::cout << "║  7. Load from file           ║\n";
    std::cout << "║  0. Exit                     ║\n";
    std::cout << "╚══════════════════════════════╝\n";
    std::cout << "Choice: ";
}

void printStatusMenu() {
    std::cout << "  1. Proposed\n  2. Active\n  3. Resolved\n  4. Completed\nChoice: ";
}

TaskStatus chooseStatus() {
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 2: return TaskStatus::Active;
    case 3: return TaskStatus::Resolved;
    case 4: return TaskStatus::Completed;
    default: return TaskStatus::Proposed;
    }
}

int main() {
    TaskManager manager;
    const std::string dataFile = "tasks.dat";

    // Try to load existing tasks on startup
    manager.loadFromFile(dataFile);

    int choice;
    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) {
            manager.saveToFile(dataFile);
            std::cout << "Goodbye!\n";
            break;
        }

        switch (choice) {
        case 1: {
            std::string title, desc;
            std::cout << "Title: ";
            std::getline(std::cin, title);
            std::cout << "Description: ";
            std::getline(std::cin, desc);
            manager.addTask(title, desc);
            break;
        }
        case 2:
            manager.listTasks();
            break;
        case 3: {
            int id;
            std::cout << "Task ID: ";
            std::cin >> id;
            std::cin.ignore();
            printStatusMenu();
            TaskStatus s = chooseStatus();
            manager.updateStatus(id, s);
            break;
        }
        case 4: {
            int id;
            std::cout << "Task ID to remove: ";
            std::cin >> id;
            std::cin.ignore();
            manager.removeTask(id);
            break;
        }
        case 5:
            printStatusMenu();
            manager.listByStatus(chooseStatus());
            break;
        case 6:
            manager.saveToFile(dataFile);
            break;
        case 7:
            manager.loadFromFile(dataFile);
            break;
        default:
            std::cout << "Invalid option.\n";
        }
    }
    return 0;
}