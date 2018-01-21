#include "Task.h"

namespace final{
	Task::Task(){
		name.clear();
		stimList.clear();
	}

	Task::Task(std::string nm){
		name = nm;
		stimList.clear();
	}

	Task::Task(const Task& tsk){
		name = tsk.name;
		for (auto i = tsk.stimList.begin(); i != tsk.stimList.end(); i++){
			stimList.push_back(*i);
		}
	}

	Task& Task::operator=(Task& tsk){
		if (this != &tsk){
			name = tsk.name;
			for (auto i = tsk.stimList.begin(); i != tsk.stimList.end(); i++){
				stimList.push_back(*i);
			}
		}
		return *this;
	}

	Task::Task(Task&& tsk){
		name = tsk.name;
		for (auto i = tsk.stimList.begin(); i != tsk.stimList.end(); i++){
			stimList.push_back(*i);
		}
		for (auto i = tsk.stimList.begin(); i != tsk.stimList.end(); i++){

		}

		tsk.name.clear();
	}

	Task& Task::operator+=(Stimulation*& sim){
		stimList.push_back(sim);
		return *this;
	}

	Stimulation* Task::operator[](int c){
		std::list<Stimulation*>::iterator it = stimList.begin();
		std::advance(it, c);
		return *it;
	}

	Stimulation* Task::operator[](std::list<Stimulation*>::iterator c){
		return *c;
	}

	void Task::remove(std::string nm){
		for (auto i = stimList.begin(); i != stimList.end(); i++){
			if (nm == (*i)->getName()){
				stimList.erase(i);
			}
		}
	}

	void Task::dump(std::ostream& os){
		os << "Task Name: " << name << std::endl;
	}

	void Task::execute(std::ostream& os){
		for (auto i = stimList.begin(); i != stimList.end(); i++){
			(*i)->display(os);
		}
	}

	std::string Task::getName(){
		return name;
	}

	Task::~Task(){
		for (auto i = stimList.begin(); i != stimList.end(); i++){
			*i = nullptr;
		}
	}
}