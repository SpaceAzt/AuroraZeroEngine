#include "../include/AuroraLogger.h"

#include <iostream>

void AuroraLogger::Info(const std::string &message) {
	std::cout << "[INFO] " << message << std::endl;
}

void AuroraLogger::Warning(const std::string &message) {
	std::cout << "[WARNING] " << message << std::endl;
}

void AuroraLogger::Error(const std::string &message) {
	std::cout << "[ERROR] " << message << std::endl;
}

void AuroraLogger::Success(const std::string &message) {
	std::cout << "[SUCCESS] " << message << std::endl;
}

void AuroraLogger::Section(const std::string &title) {
	std::cout << std::endl;

	std::cout << "========================================"
			  << std::endl;

	std::cout << "  " << title
			  << std::endl;

	std::cout << "========================================"
			  << std::endl;
}
