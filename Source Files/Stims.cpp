#include "Stims.h"

namespace final{
	Stims::Stims(std::string n, location l, int in, float frq, int dur){
		if (in >= 0 && in <= 100 && l >= 0 && l <= 3){
			name = n;
			loc = l;
			intensity = in;
			frequency = frq;
			duration = dur;
		}
	}

	void Stims::display(std::ostream& os){
		os << "Stims Name: " << name << std::endl;
		os << "Location: " << loc << std::endl;
		os << "Intensity: " << intensity << std::endl;
		os << "Frequency: " << frequency << std::endl;
		os << "Duration: " << duration << std::endl << std::endl;
	}

	Stimulation* Stims::clone() const{
		return new Stims(*this);
	}

	std::string Stims::getName()const{
		return name;
	}
}