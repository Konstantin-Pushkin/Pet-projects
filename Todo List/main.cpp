#include "TodoList.hpp"
#include <limits>
using std::cin;

int main()
{
    TodoList todoList;
    todoList.loadFromFile();
    unsigned item;
    string description;
    unsigned index;

    while(true)
    {
        cout << "1. Просмотр всех задач" << endl;
        cout << "2. Создание новой задачи" << endl;
        cout << "3. Изменение задачи из списка всех задач" << endl;
        cout << "4. Удаление задачи из списка задач" << endl;
        cout << "5. Пометить выполнение задачи из списка задач" << endl;
        cout << "6. Пометить невыполнение задачи из списка задач" << endl;
        cout << "7. Выйти и сохранить изменения в файл" << endl;
        cout << endl << "Введите цифру - ";
        cin >> item;
        cout << "=================================================================" << endl;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Неверный ввод. Введите цифру от 1 до 6" << endl;
            continue;
        }

        switch(item)
        {
            case 1:
                todoList.printTasks();
                break;
            case 2:
                cout << "Введите текст новой задачи: ";
                cin.ignore();
                getline(cin, description);
                todoList.addingTask(description);
                cout << endl;
                break;
            case 3:
                cout << "Введите номер задачи для изменения: ";
                cin >> index;
                cout << "Введите новый текст задачи: ";
                cin.ignore();
                getline(cin, description);
                todoList.changingTask(index - 1, description);
                break;
            case 4:
                cout << "Введите номер задачи для удаления: ";
                cin >> index;
                todoList.deletingTask(index - 1);
                break;
            case 5:
                cout << "Введите номер задачи для отметки выполнения: ";
                cin >> index;
                todoList.completingTask(index - 1);
                break;
            case 6:
                cout << "Введите номер задачи для отметки невыполнения: ";
                cin >> index;
                todoList.notCompletingTask(index - 1);
                break;
            case 7:
                return EXIT_SUCCESS;
            default:
                cout << "Неверный ввод. Введите цифру от 1 до 6" << endl;
        }

        todoList.saveToFile();
        cout << "=================================================================" << endl;
    }
}