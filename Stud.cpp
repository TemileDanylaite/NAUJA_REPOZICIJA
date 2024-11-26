#include "Stud.h"
#include "Mylib.h"
void ived(Stud& Lok) {

	cout << "Ivesti varda ir pavarde: ";
	string vardas, pavarde;
	cin >> vardas >> pavarde;
	Lok.setVardas(vardas);
	Lok.setPavarde(pavarde);

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

		for (int i = 0; i < ndCount; ++i) {
			Lok.addND(dist(gen));
		}

		Lok.setEgz(dist(gen));
	}
	else {
		cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
		cin >> pasirinkimas;

		if (pasirinkimas == "taip") {
			int ndCount;
			cout << "Ivesti namu darbu skaiciu: ";
			cin >> ndCount;



			cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
			for (int i = 0; i < ndCount; ++i) {
				int nd;
				cin >> nd;
				Lok.addND(nd);

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
				Lok.addND(nd);
			}
		}


		cout << "Ivesti egzamino rezultata: ";
		double egz;
		cin >> egz;
		Lok.setEgz(egz);

	}

}


void output(const Stud& Lok)
{
	cout << setw(15) << left << Lok.getVardas() << setw(15) << left << Lok.getPavarde()
		<< setw(4) << right << fixed << setprecision(2) << Lok.getGalutinisVid()
		<< setw(16) << right << fixed << setprecision(2) << Lok.getGalutinisMed() << endl;

}

void val(Stud& Lok) {
	Lok.setVardas("");
	Lok.setPavarde("");
	Lok.setND({});
}