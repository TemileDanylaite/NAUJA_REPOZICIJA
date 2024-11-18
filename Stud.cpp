#include "Stud.h"
#include "Mylib.h"


void ived(Stud& Lok) {
	cout << "Ivesti varda ir pavarde: ";
	cin >> Lok.vardas >> Lok.pavarde;

	string pasirinkimas;
	cout << "Ar reikia namu darbu ir egzamino rezultatus generuoti atsitiktinai?(taip/ne) ";
	cin >> pasirinkimas;

	if (pasirinkimas == "taip") {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		int ndCount;
		cout << "Ivesti namu darbu skaiciu: ";
		cin >> ndCount;

		Lok.ND.resize(ndCount);
		for (int i = 0; i < ndCount; ++i) {
			Lok.ND[i] = dist(gen);

		}

		Lok.egz = dist(gen);
	}
	else {
		cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
		cin >> pasirinkimas;

		if (pasirinkimas == "taip") {
			int ndCount;
			cout << "Ivesti namu darbu skaiciu: ";
			cin >> ndCount;
			Lok.ND.resize(ndCount);


			cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
			for (int i = 0; i < ndCount; ++i) {
				cin >> Lok.ND[i];
			
			}
		}
		else if (pasirinkimas == "ne") {
			double nd;
			cout << "Ivesti namu darbu rezultatus(ivesti '-1',kad baigti):" << endl;
			while (true) {
				cin >> nd;
				if (nd == -1) {
					break;
				}
				Lok.ND.push_back(nd);
			}
		}


		cout << "Ivesti egzamino rezultata: ";
		cin >> Lok.egz;
		
		}

	}


	void output(const Stud & Lok)
{
		cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde
		       <<setw(4) << right<< fixed << setprecision(2) << Lok.GalutinisVid
			   << setw(16) << right << fixed << setprecision(2) << Lok.GalutinisMed << endl;

}

void val(Stud& Lok) {
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
}