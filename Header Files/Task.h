#ifndef _TASK_
#define _TASK_

#include "Stims.h"
#include "Exoskeleton.h"
#include <list>
#include <string>
#include <iterator>

namespace final{
	class Task{
		std::list<Stimulation*> stimList;
		std::string name;
	public:
		Task(std::string);
		Task();
		Task(const Task&);
		Task& operator=(Task&);
		Task(Task&&);
		Task& operator+=(Stimulation*&);
		Stimulation* operator[](int);
		Stimulation* operator[](std::list<Stimulation*>::iterator);
		void remove(std::string);
		void dump(std::ostream&);
		void execute(std::ostream&);
		std::string getName();
		~Task();
	};
}
#endif