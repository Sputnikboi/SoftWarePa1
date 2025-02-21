#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Task
{
	public:
	std::string _description;
	bool _completed;
	
	Task(std::string description){
		_description = description;
		_completed = false;
	}
	void complete()
	{
		_completed = 1;
		cout<<"Task completed"<<endl;
		cout<<_completed<<endl;
	}
	void getStatus()
	{
		if(_completed)
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

	Task& getTask(int index)
	{
		return todolist.at(index);
	}
};



int main() 
{
	int choice;
	std::string task;
	TodoList todo;
	while(1)
	{
		cout<<"1. Add a new task"<<endl;
		cout<<"2. Complete a task"<<endl;
		cout<<"3. Display all tasks"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the task description"<<endl;
				cin>>task;
				todo.add_Todo(task);
				break;
			case 2:
				cout<<"Enter the task number to complete"<<endl;
				cin>>task;
				todo.getTask(stoi(task)-1).complete();
				break;
			case 3:
				if (todo.todolist.size() == 0)
				{
					cout<<""<<endl;
					cout<<"No tasks to display"<<endl;
					cout<<""<<endl;
					break;
				}
				cout<<""<<endl;
				for(int i=0;i<todo.todolist.size();i++)
				{
					cout<<i+1<<". "<<todo.getTask(i)._description<<endl;
					cout<<"Status: ";
					todo.getTask(i).getStatus();
				}
				cout<<""<<endl;
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
	}
    return 0;
}
