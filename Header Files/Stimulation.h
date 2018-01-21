#ifndef _STIMULATION_
#define _STIMULATION_
#include <string.h>
#include <iostream>
#include <string>

namespace final{
	class Stimulation{
	protected:
		std::string name;
	public:
		virtual void display(std::ostream& os) = 0;
		virtual Stimulation* clone() const = 0;
		virtual std::string getName() const = 0;
	};
}
#endif