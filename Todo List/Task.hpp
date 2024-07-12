#ifndef ALGORITHMS_TASK_HPP
#define ALGORITHMS_TASK_HPP

#include <string>
#include <utility>
#include <cmath>
#include <ctime>
using std::string;

class Task
{
private:
    string taskDescription; // описание задачи
    bool isDone; // выполнено / не выполнено
    string Date; // дата создания задачи

public:
    explicit Task(string description) : taskDescription(std::move(description)), isDone(false) // конструктор по умолчанию
    {
        time_t now = time(nullptr);
        char *dt = ctime(&now);
        Date = string(dt).substr(0, 24);
    }

    [[nodiscard]] bool isTaskCompleted() const; // статус задачи
    [[nodiscard]] string getTaskDescription() const; // геттеры = получить
    [[nodiscard]] string getDate() const; // получить дату
    void setTask(const string &newTaskDescription); // сеттеры = задавать
    void completeTask(); // задача выполнена
    void incompleteTask(); // задача не выполнена
    void setCreationDate(const string &date); // задать дату
};

#endif //ALGORITHMS_TASK_HPP