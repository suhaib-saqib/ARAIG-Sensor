#ifndef _PROFILE_
#define _PROFILE_
#include "ARAIG_Sensors.h"

namespace final{
	struct calibration{
		int max;
		int min;
	};

	class Profile : public ARAIG_Sensors{
		std::vector<Task>ToRun;
		std::vector<Task>Completed;
		std::string sFname;
		std::string sLname;
		int sNumber;
		std::string iFname;
		std::string iLname;
		int eNumber;
		calibration cal;
		std::ostream& ostr;
	public:
		Profile();
		Profile(char*, std::ostream&, ARAIG_Sensors&);
		std::ostream& displayToRun(std::ostream&);
		std::ostream& displayCompleted(std::ostream&);
		std::ostream& displayNext(std::ostream&);
		std::ostream& displayLast(std::ostream&);
		void run();
	};
}
#endif