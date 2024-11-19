#include "Stud.h"
#include "Mylib.h"

void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas) {
	try {
		std::ifstream inFile(failoVardas);
		if (!inFile) {
			throw runtime_error("Nepavyko atdiaryti failo:" + failoVardas);
		}
		string line;
		while(getline(inFile, line)) {

			std::stringstream ss(line);
			Stud temp;
			temp.clearData();

			std::string vardas, pavarde;
			if (!(ss >> vardas >> pavarde)) {
				std::cerr << "Nepavyko nuskaityti studento vardo ir pavardes" << endl;
				continue;
			}
			temp.setVardas(vardas);
			temp.setPavarde(pavarde);

			int nd;
			while (ss >> nd) {
				temp.addND(nd);
			}
			if (temp.getND().size() < 1) {
				continue;
			}
			temp.setEgz(temp.getND().back());
			temp.getND().pop_back();


			Vec1.push_back(temp);
		}
		inFile.close();

	}catch (const std::exception& e) {
		std::cerr << "Klaida: " << e.what() << endl;
	}

}
void nuskaitytiIsfailo(std::list<Stud>& list1, const std::string& failoVardas) {
	try {
		std::ifstream inFile(failoVardas);
		if (!inFile) {
			throw runtime_error("Nepavyko atidaryti failo:" + failoVardas);
		}
		string line;
		while (getline(inFile, line)) {

			std::stringstream ss(line);
			Stud temp;
			temp.clearData();

			std::string vardas, pavarde;
			if (!(ss >> vardas >> pavarde)) {
				std::cerr << "Nepavyko nuskaityti studento vardo ir pavardes" << endl;
				continue;
			}
			temp.setVardas(vardas);
			temp.setPavarde(pavarde);

			int nd;
			while (ss >> nd) {
				temp.addND(nd);
			}
			if (temp.getND().size() < 1) {
				continue;
			}
			temp.setEgz(temp.getND().back());
			temp.getND().pop_back();


			list1.push_back(temp);
		}
		inFile.close();

	}
	catch (const std::exception& e) {
		std::cerr << "Klaida: " << e.what() << endl;
	}

}