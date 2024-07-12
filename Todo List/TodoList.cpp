#include <fstream>
#include <istream>
#include <sstream>
#include "TodoList.hpp"
#include "Task.hpp"

void TodoList::addingTask(const string &description)
{
    tasks.emplace_back(description);
    saveToFile();
}

void TodoList::changingTask(unsigned index, const string &newDescription)
{
    if(existenceIndex(index))
    {
        tasks[index].setTask(newDescription);
        saveToFile();
    }
    else
    {
        cout << "Неверный номер задачи!" << endl;
    }
    cout << "=================================================================" << endl;
}

void TodoList::deletingTask(unsigned index)
{
    if(existenceIndex(index))
    {
        tasks.erase(tasks.begin() + index);
        saveToFile();
    }
    else
    {
        cout << "Неверный номер задачи!" << endl << endl;
    }
}

void TodoList::completingTask(unsigned index)
{
    if(existenceIndex(index))
    {
        tasks[index].completeTask();
        saveToFile();
    }
    else
    {
        cout << "Неверный номер задачи!" << endl << endl;
    }
}

void TodoList::notCompletingTask(unsigned index)
{
    if(existenceIndex(index))
    {
        tasks[index].incompleteTask();
        saveToFile();
    }
    else
    {
        cout << "Неверный номер задачи!" << endl << endl;
    }
}

void TodoList::printTasks() const
{
    if(tasks.empty())
    {
        cout << "Список задач пуст" << endl << endl;
        return;
    }

    const size_t len = tasks.size();
    cout << "Список задач: " << endl;
    for(size_t i = 0; i != len; ++i)
    {
        cout << "ID: " << i + 1 << " | Описание: " << tasks[i].getTaskDescription() << " | Дата последнего изменения: " << tasks[i].getDate() << " | Статус выполнения: " << (tasks[i].isTaskCompleted() ? "Выполнена" : "Не выполнена") << endl;
    }

    cout << "=================================================================" << endl;
}

void TodoList::saveToFile() const
{
    std::ofstream file(filename);
    if(file.is_open())
    {
        for(size_t i = 0; i != tasks.size(); ++i)
        {
            file << "ID: " << i + 1 << " | Описание: " << tasks[i].getTaskDescription() << "| Дата создания: " << tasks[i].getDate() << " | Статус выполнения: " << (tasks[i].isTaskCompleted() ? "Выполнена" : "Не выполнена") << endl;
        }

        file.close();
    }
    else
    {
        cout << "Ошибка при открытии файла для записи!" << endl;
    }
}

void TodoList::loadFromFile()
{
    std::ifstream file(filename);
    if(file.is_open())
    {
        tasks.clear();
        string line;
        while(getline(file, line))
        {
            std::istringstream stream(line);
            string indexStr;
            string desc;
            string date;
            string status;

            getline(stream, indexStr, '.');
            stream.get();

            getline(stream, desc, '\t');

            getline(stream, status);

            Task task(desc);
            task.setCreationDate(date);
            if(status.find("Выполнена") != string::npos)
            {
                task.completeTask();
            }

            tasks.push_back(task);
        }
        file.close();
    }
    else
    {
        cout << "Ошибка открытия файла для чтения!" << endl;
    }
}