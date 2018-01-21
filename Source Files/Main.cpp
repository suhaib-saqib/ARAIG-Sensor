#include "Profile.h"


	int main(int argc, char** argv) {
		if (argc != 5) {
			std::cerr << argv[0] << ": incorrect number of arguments\n";
			std::cerr << "Usage: " << argv[0] << " file_name\n";
			return 1;
		}
		else{
			final::ARAIG_Sensors araig(argv[2], argv[3]);
			std::ofstream of;
			of.open(argv[4], std::ofstream::out | std::ofstream::trunc);
			final::Profile profile(argv[1], of, araig);
			profile.run();
		}

		system("pause");
	}
