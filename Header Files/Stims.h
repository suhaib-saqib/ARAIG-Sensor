#ifndef _STIMS_
#define _STIMS_
#include "Stimulation.h"

namespace final{
	enum location{ abs, front, back, traps };
	class Stims : public Stimulation{
	private:
		std::string name;
		location loc;
		int intensity;
		float frequency;
		int duration;
	public:
		Stims(std::string, location, int, float, int);
		void display(std::ostream& os);
		Stimulation* clone() const;
		std::string getName()const;
	};
}
#endif