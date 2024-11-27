#include "Stud.h"
#include "Mylib.h"


void sugeneruotiStudentoFaila(const string& fileName, int studentCount, int ndCount) {
	auto pradzia = std::chrono::high_resolution_clock::now();

	ofstream outFile(fileName);
	if (!outFile) {
		std::cerr << "Nepavyko sukurti failo: " << fileName << endl;
		return;
	}

	outFile << std::setw(25) << std::left << "Vardas"
		<< std::setw(25) << std::left << "Pavarde";

	for (int i = 1; i <= ndCount; i++) {
		outFile << std::setw(10) << std::right << "ND" + std::to_string(i);
	}
	outFile << std::setw(10) << std::right << "Egz." << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <> dist(1, 10);

	for (int i = 1; i <= studentCount; ++i) {
		Stud studentas("Vardas" + std::to_string(i), "Pavarde" + std::to_string(i));

		for (int j = 0; j < ndCount; ++j) {
			studentas.addND(dist(gen));

		}

		studentas.setEgz(dist(gen));

		outFile << studentas << endl;

	}

	outFile.close();
	cout << "Failas sukurtas: " << fileName << endl;

	auto pabaiga = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = pabaiga - pradzia;
	cout << "Failo kurimo trukme: " << fixed << setprecision(5) << elapsed.count() << " s" << endl;
}
