#  Todo List Manager

Консольное приложение на C++ для управления задачами с сохранением данных в файл.

##  Возможности

-  Добавление задач с заголовком и описанием
-  Просмотр всех задач
-  Изменение статуса задачи (Proposed → Active → Resolved → Completed)
-  Удаление задач
-  Фильтрация задач по статусу
-  Автоматическое сохранение/загрузка из файла
-  Красивый консольный интерфейс

##  Технологии

- **C++17** - стандарт языка
- **CMake 3.16+** - система сборки
- **STL** — стандартная библиотека
- **Pre-commit hooks** - автоматическая проверка кода:
  - `clang-format` - форматирование (Google style)
  - `clang-tidy` - статический анализ
  - `trailing-whitespace` - проверка пробелов
  - `end-of-file-fixer` - корректные концы файлов

##  Структура проекта

```
todo-app/
├── include/
│ ├── Task.h # Структура задачи
│ └── TaskManager.h # Класс управления задачами
├── src/
│ ├── main.cpp # Точка входа и UI
│ ├── Task.cpp # Реализация Task
│ └── TaskManager.cpp # Реализация TaskManager
├── CMakeLists.txt # Конфигурация сборки
├── .pre-commit-config.yaml # Настройки pre-commit
└── README.md
```


##  Установка и запуск

### Требования

- CMake 3.16+
- C++17 компилятор (GCC, Clang, MSVC)
- Python 3 (для pre-commit)

### Сборка

```bash
# Клонирование репозитория
git clone https://github.com/yourusername/todo-app.git
cd todo-app

# Создание папки для сборки
mkdir build && cd build

# Генерация файлов сборки
cmake ..

# Компиляция
cmake --build . --config Release
```
### Использование
```bash
╔══════════════════════════════╗
║       TODO LIST MANAGER      ║
╠══════════════════════════════╣
║  1. Add task                 ║
║  2. List all tasks           ║
║  3. Update task status       ║
║  4. Remove task              ║
║  5. Filter by status         ║
║  6. Save to file             ║
║  7. Load from file           ║
║  0. Exit                     ║
╚══════════════════════════════╝
```
##  Статусы задач

| Статус | Описание |
|--------|----------|
| **Proposed** | Предложена, ещё не начата |
| **Active** | В работе |
| **Resolved** | Решена, ожидает проверки |
| **Completed** | Завершена |

### Разработка
## Установка pre-commit хуков
```bash
# Установка pre-commit
pip install pre-commit

# Установка хуков в репозиторий
pre-commit install

# Ручной запуск проверки всех файлов
pre-commit run --all-files
```

## Форматирование кода вручную
```bash
# Форматирование всех файлов в стиле Google
clang-format -i src/*.cpp include/*.h --style=Google
```
### Pre-commit

<img width="763" height="190" alt="{33B19460-DA44-415B-9364-424B6FEDB561}" src="https://github.com/user-attachments/assets/63af4a1e-dc6e-48b4-8c79-de30fb112f4b" />
