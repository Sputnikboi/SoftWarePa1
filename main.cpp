#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Task
{
	public:
	std::string _description;
	bool completed = false;
	Task(std::string description){
		_description = description;
	}
	void complete()
	{
		completed = true;
	}
	void getStatus()
	{
		if(completed)
		{
			cout<<"Task is completed"<<endl;
		}
		else
		{
			cout<<"Task is not completed"<<endl;
		}
	}
};

class TodoList
{
	
	public:
	std::vector<Task> todolist;
	TodoList(){}
	
	
	void add_Todo(std::string description)
	{
		todolist.push_back(Task(description));
		cout<<"New task Added" << endl;
	};
};



int main() 
{
    std::string new_task;
    TodoList todo = TodoList();
    cout<<"Create a new task"<<endl;
    cin >> new_task;
    todo.add_Todo(new_task);
    cout<<todo.todolist.at(0)._description<<endl;
	todo.todolist.at(0).complete();
	todo.todolist.at(0).getStatus();

    return 0;
}
