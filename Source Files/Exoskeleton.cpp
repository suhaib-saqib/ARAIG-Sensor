#include "Exoskeleton.h"

namespace final{
	Exoskeleton::Exoskeleton(std::string n, int in, int dur){
		if (in >= 0 && in <= 100){
			name = n;
			intensity = in;
			duration = dur;
		}
	}

	void Exoskeleton::display(std::ostream& os){
		os << "Exoskeleton Name: " << name << std::endl;
		os << "Intensity: " << intensity << std::endl;
		os << "Duration: " << duration << std::endl << std::endl;
	}

	Stimulation* Exoskeleton::clone() const{
		return new Exoskeleton(*this);
	}

	std::string Exoskeleton::getName()const{
		return name;
	}
}