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

	void editTask(std::string description)
	{
		_description = description;
		cout<<"Task edited"<<endl;
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

	void delete_Todo(int index)
	{
		todolist.erase(todolist.begin()+index);
		cout<<"Task removed" << endl;
	}

	Task& getTask(int index)
	{
		return todolist.at(index);
	}
};



int main() 
{
	int choice;
	std::string task;
	std::string temp;
	TodoList todo;
	while(1)
	{
		cout<<"1. Add a new task"<<endl;
		cout<<"2. Complete a task"<<endl;
		cout<<"3. Remove tasks"<<endl;
		cout<<"4. Display all tasks"<<endl;
		cout<<"5. Edit a task"<<endl;
		cout<<"6. Exit"<<endl;
		cin>>choice;
		cin.ignore();
		cout<<""<<endl;
		switch(choice)
		{
			case 1:
				cout<<"Enter the task description"<<endl;
				getline(cin, task);
				todo.add_Todo(task);
				break;
			case 2:
				cout<<"Enter the task number to complete"<<endl;
				cin>>task;
				todo.getTask(stoi(task)-1).complete();
				break;
			case 3:
				cout<<"Enter task number to be removed"<<endl;
				cin>>task;
				todo.delete_Todo(stoi(task)-1);
				break;
			case 4:
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
			case 5:
				cout<<"Enter task number to be edited"<<endl;
				cin>>task;
				cin.ignore();
				cout<<"Enter new task description"<<endl;
				getline(cin, temp);
				todo.getTask(stoi(task)-1).editTask(temp);
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
	}
    return 0;
}

