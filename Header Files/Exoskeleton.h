#ifndef _EXO_
#define _EXO_
#include "Stimulation.h"

namespace final{
	class Exoskeleton : public Stimulation{
		std::string name;
		int intensity;
		int duration;
	public:
		Exoskeleton(std::string, int, int);
		void display(std::ostream&);
		Stimulation* clone() const;
		std::string getName()const;
	};
}
#endif