#include <iostream>
#include <vector>

#include "src/segy_file.h"

using namespace segystack;

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
	std::cout << '[';

	if (vec.size() > 0) {
		std::cout << vec[0];
		for (size_t i = 1; i < vec.size(); i++) {
			std::cout << ", " << vec[i];
		}
	}

	return out << ']';
}

int main() {
	SegyFile segy("data.segy");
	segy.open();

	SegyFile::TextHeader text_header = segy.getTextHeader();
	SegyFile::BinaryHeader binary_header = segy.getBinaryHeader();

	SegyFile::Trace trace;
	segy.read(trace);

	std::cout << "Cabecera de Texto: " << text_header << std::endl;
	std::cout << "Cabecera Binaria: ";
	binary_header.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Primera traza (Cabecera): ";
	trace.header().print(std::cout);
	std::cout << std::endl;

	std::cout << "Primera traza (samples): " << trace.samples() << std::endl;

	return 0;
}
