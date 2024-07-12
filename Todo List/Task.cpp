#include "Task.hpp"

bool Task::isTaskCompleted() const
{
    return isDone;
}

string Task::getTaskDescription() const
{
    return taskDescription;
}

string Task::getDate() const
{
    return Date;
}

void Task::setTask(const string &newTaskDescription)
{
    taskDescription = newTaskDescription;
}

void Task::completeTask()
{
    isDone = true;
}

void Task::incompleteTask()
{
    isDone = false;
}

void Task::setCreationDate(const string &date)
{
    Date = date;
}