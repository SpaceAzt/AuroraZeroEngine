#include "../include/AuroraVersion.h"

#include <iostream>

const char *AuroraVersion::GetVersion() {
	return "0.1.0-PreAlpha";
}

void AuroraVersion::Print() {
	std::cout << "=====================================\n";
	std::cout << "Aurora Zero Engine\n";
	std::cout << "Version : " << GetVersion() << "\n";
	std::cout << "=====================================\n";
}
