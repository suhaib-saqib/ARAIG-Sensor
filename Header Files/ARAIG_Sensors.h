#ifndef _ARAIG_
#define _ARAIG_
#include "Task.h"
#include <fstream>
#include <sstream>
#include<vector>
namespace final{
	class ARAIG_Sensors{
		std::string stimFname;
		std::string taskFname;
		std::vector<Stimulation*> tempStimList;
		std::vector<Task*> tempTaskList;
		std::vector<std::string> taskNames;
	public:
		ARAIG_Sensors();
		ARAIG_Sensors(char*, char*);
		void dump(std::ostream&);
		~ARAIG_Sensors();
		Task& getTask(std::string);
		bool check(std::string);
	};
}
#endif