#include "ARAIG_Sensors.h"

namespace final{
	ARAIG_Sensors::ARAIG_Sensors(){
		stimFname.clear();
		taskFname.clear();
		tempStimList.clear();
		tempTaskList.clear();
	}

	ARAIG_Sensors::ARAIG_Sensors(char* stim, char* tsk){
		
		std::ifstream stimfile(stim);
		std::string delimiter;
		std::string line;
		std::string temp;
		std::string nm;
		while (stimfile.good()){
			std::getline(stimfile, line);
			std::istringstream iss(line);
			std::getline(iss, temp, ',');
			int intens;
			float freq;
			int dur;
			std::string lo;
			Stimulation* stimulation;
			if (temp == "stim"){
				std::getline(iss, nm, ',');
				std::getline(iss, lo, ',');
				location l;
				if (lo == "abs"){
					l = abs;
				}
				else if (lo == "front"){
					l = front;
				}
				else if (lo == "back"){
					l = back;
				}
				else if (lo == "traps"){
					l = traps;
				}
				std::getline(iss, temp, ',');
				intens = std::stoi(temp);
				std::getline(iss, temp, ',');
				freq = std::stof(temp);
				std::getline(iss, temp, ',');
				dur = std::stoi(temp);
				tempStimList.push_back(new Stims(nm, l, intens, freq, dur));
			}
			else if (temp == "exoskeleton"){
				std::getline(iss, nm, ',');
				std::getline(iss, temp, ',');
				intens = std::stoi(temp);
				std::getline(iss, temp, ',');
				dur = std::stoi(temp);
				tempStimList.push_back(new Exoskeleton(nm, intens, dur));
			}
		}
		std::ifstream tskfile(tsk);
		std::getline(tskfile, temp, ',');
		if (temp == "TASK"){
			std::getline(tskfile, temp);
			while (tskfile.good()){
				std::size_t found = temp.find_last_not_of(" ");
				if (found != std::string::npos){
					temp.erase(found + 1);
				}
				nm = temp;
				taskNames.push_back(nm);
				tempTaskList.push_back(new Task(nm));
				while (temp.substr(0,4) != "TASK" && !tskfile.eof()){
					std::getline(tskfile, temp);
					if (temp != "TASK"){
						for (auto i = tempStimList.begin(); i != tempStimList.end(); i++){
							if (temp == (*i)->getName()){
								(*(tempTaskList.back())) += *i;
							}
						}
					}
				}
				if (!temp.empty()){
					temp = temp.substr(5, temp.npos);
				}
			}
		}
	}

	void ARAIG_Sensors::dump(std::ostream& os){
		for (auto i = tempTaskList.begin(); i != tempTaskList.end(); i++){
			(*i)->dump(os);
			(*i)->execute(os);
		}
		for (auto i = tempStimList.begin(); i != tempStimList.end(); i++){
			(*i)->display(os);
		}
	}

	Task& ARAIG_Sensors::getTask(std::string nm){
		bool exit = 0;
		int i;
		for (i = 0; exit != 1 && i < tempTaskList.size(); i++){
			if (nm == tempTaskList[i]->getName()){
				return *tempTaskList[i]; 
			}
		}
	}

	ARAIG_Sensors::~ARAIG_Sensors(){
		for (auto i = tempStimList.begin(); i != tempStimList.end(); i++){
			delete * i;
			i = tempStimList.erase(i);
		}
	}

	bool ARAIG_Sensors::check(std::string nom){
		bool returned = false;
		for (int i = 0; i < taskNames.size(); i++){
			if (nom == taskNames[i]){
				returned = true;
			}
		}
		return returned;
	}
}