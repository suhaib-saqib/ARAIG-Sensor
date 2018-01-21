#include "Profile.h"

namespace final{
	Profile::Profile() : ostr(std::cout){
		ToRun.clear();
		Completed.clear();
		sFname.clear();
		sLname.clear();
		sNumber = 0;
		iFname.clear();
		iLname.clear();
		eNumber = 0;
		cal.max = 0;
		cal.min = 0;
	}

	Profile::Profile(char* fn, std::ostream& os, ARAIG_Sensors& AS) : ostr(os){
		std::ifstream f(fn);
		std::string temp;
		std::getline(f, temp, ',');
		sFname = temp;
		std::getline(f, temp, ',');
		sLname = temp;
		std::getline(f, temp);
		sNumber = std::stoi(temp);
		std::getline(f, temp, ',');
		iFname = temp;
		std::getline(f, temp, ',');
		iLname = temp;
		std::getline(f, temp);
		eNumber = std::stoi(temp);
		std::getline(f, temp, ',');
		cal.max = std::stoi(temp);
		std::getline(f, temp);
		cal.min = std::stoi(temp);
		while (!f.eof()){
			std::getline(f, temp);
			if (AS.check(temp)){
				ToRun.push_back(*new Task(AS.getTask(temp)));
			}
		}
		//std::cout << "hello" << std::endl;
		std::reverse(ToRun.begin(), ToRun.end());
	}

	std::ostream& Profile::displayToRun(std::ostream& os){
		os << "Tasks to run:" << std::endl;
		for (std::vector<Task>::reverse_iterator i = ToRun.rbegin(); i != ToRun.rend(); i++){
			os << (*i).getName() << std::endl;
		}
		return os;
	}

	std::ostream& Profile::displayCompleted(std::ostream& os){
		os << "Tasks completed:" << std::endl;
		for (auto i = Completed.begin(); i != Completed.end(); i++){
			os << i->getName() << std::endl;
		}
		return os;
	}

	std::ostream& Profile::displayNext(std::ostream& os){
		os << "Next Task: " << ToRun.back().getName() << std::endl;
		return os;
	}

	std::ostream& Profile::displayLast(std::ostream& os){
		os << "Last Task: " << Completed.back().getName() << std::endl;
		return os;
	}

	void Profile::run(){
		ostr << "Student: " << sFname << " " << sLname << " - " << sNumber << std::endl;
		ostr << "Instructor: " << iFname << " " << iLname << " - " << eNumber << std::endl;
		ostr << "Student Calibration:" << std::endl;
		ostr << "MAX = " << cal.max << std::endl;
		ostr << "MIN = " << cal.min << std::endl;
		while (ToRun.begin() != ToRun.end()){
			displayNext(std::cout);
			std::string uin;
			std::cout << "Enter 'y' to execute next task: " << std::endl;
			std::cin >> uin;
			if (uin == "y" || uin == "Y"){
				ToRun.back().dump(ostr);
				ToRun.back().execute(ostr);
				Completed.push_back(std::move(ToRun.back()));
				ToRun.pop_back();
			}
		}
	}
}