#ifndef ALGORITHMS_TODOLIST_HPP
#define ALGORITHMS_TODOLIST_HPP

#include "Task.hpp"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class TodoList
{
private:
    vector<Task> tasks;
    [[nodiscard]] bool existenceIndex(int64_t index) const
    {
        return index >= 0 && index < tasks.size();
    }

    const string filename = "../tasks.txt";

public:
    void addingTask(const string &description);
    void changingTask(unsigned index, const string &newDescription);
    void deletingTask(unsigned index);
    void completingTask(unsigned index);
    void notCompletingTask(unsigned index);
    void printTasks() const;
    void saveToFile() const;
    void loadFromFile();
};

#endif //ALGORITHMS_TODOLIST_HPP