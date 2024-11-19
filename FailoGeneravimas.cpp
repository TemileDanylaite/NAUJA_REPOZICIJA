#include "Stud.h"
#include "Mylib.h"


void sugeneruotiStudentoFaila(const string& fileName, int studentCount, int ndCount) {
	auto pradzia = std::chrono::high_resolution_clock::now();
	
	ofstream outFile(fileName);
	if (!outFile) {
		std::cerr << "Nepavyko sukurti failo: " << fileName << endl;
		return;
	}

	outFile << setw(25) << left << "Vardas"
		<< setw(25) << left << "Pavarde";

	for (int i = 1; i <= ndCount; i++) {
		outFile << setw(10) << right << "ND" + std::to_string(i);
	}
	outFile << setw(10) << right << "Egz." << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <> dist(1, 10);

	for (int i = 1; i <= studentCount; ++i) {

<<<<<<< HEAD
		Stud studentas("Vardas" + std::to_string(i), "Pavarde" + std::to_string(i));

		for (int j = 0; j < ndCount; ++j) {
			studentas.addND(dist(gen));
			
		}

		studentas.setEgz(dist(gen));

		outFile << setw(25) << left << studentas.getVardas()
			<< setw(25) << left << studentas.getPavarde();

		for (int nd : studentas.getND()) {
			outFile << setw(10) << right << nd;
		}

		outFile << setw(10) << right << studentas.getEgz() << endl;

		
=======
		string vardas = "Vardas" + std::to_string(i);
		string pavarde = "Pavarde" + std::to_string(i);

		outFile << setw(25) << left << vardas
			<< setw(25) << left << pavarde;

		for (int j = 0; j < ndCount; ++j) {
			outFile << setw(10) << right << dist(gen);
		}

		outFile << setw(10) << right << dist(gen) << endl;
>>>>>>> old-branch
	}

	outFile.close();
	cout << "Failas sukurtas: " << fileName << endl;

	auto pabaiga = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = pabaiga - pradzia;
	cout << "Failo kurimo trukme: " <<fixed << setprecision(5) << elapsed.count() << " s" << endl;
}