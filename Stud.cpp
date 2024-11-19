#include "Stud.h"
#include "Mylib.h"


void ived(Stud& Lok) {
	cout << "Ivesti varda ir pavarde: ";
<<<<<<< HEAD
	string vardas, pavarde;
	cin >> vardas >> pavarde;
	Lok.setVardas(vardas);
	Lok.setPavarde(pavarde);
=======
	cin >> Lok.vardas >> Lok.pavarde;
>>>>>>> old-branch

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

<<<<<<< HEAD
		for (int i = 0; i < ndCount; ++i) {
			Lok.addND(dist(gen));
		}

		Lok.setEgz(dist(gen));
=======
		Lok.ND.resize(ndCount);
		for (int i = 0; i < ndCount; ++i) {
			Lok.ND[i] = dist(gen);

		}

		Lok.egz = dist(gen);
>>>>>>> old-branch
	}
	else {
		cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
		cin >> pasirinkimas;

		if (pasirinkimas == "taip") {
			int ndCount;
			cout << "Ivesti namu darbu skaiciu: ";
			cin >> ndCount;
<<<<<<< HEAD
			
=======
			Lok.ND.resize(ndCount);
>>>>>>> old-branch


			cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
			for (int i = 0; i < ndCount; ++i) {
<<<<<<< HEAD
				int nd;
				cin >> nd;
				Lok.addND(nd);
=======
				cin >> Lok.ND[i];
>>>>>>> old-branch
			
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
<<<<<<< HEAD
				Lok.addND(nd);
=======
				Lok.ND.push_back(nd);
>>>>>>> old-branch
			}
		}


		cout << "Ivesti egzamino rezultata: ";
<<<<<<< HEAD
		double egz;
		cin >> egz;
		Lok.setEgz(egz);
=======
		cin >> Lok.egz;
>>>>>>> old-branch
		
		}

	}


	void output(const Stud & Lok)
{
<<<<<<< HEAD
		cout << setw(15) << left << Lok.getVardas() << setw(15) << left << Lok.getPavarde()
		       <<setw(4) << right<< fixed << setprecision(2) << Lok.getGalutinisVid()
			   << setw(16) << right << fixed << setprecision(2) << Lok.getGalutinisMed() << endl;
=======
		cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde
		       <<setw(4) << right<< fixed << setprecision(2) << Lok.GalutinisVid
			   << setw(16) << right << fixed << setprecision(2) << Lok.GalutinisMed << endl;
>>>>>>> old-branch

}

void val(Stud& Lok) {
<<<<<<< HEAD
	Lok.setVardas("");
	Lok.setPavarde("");
	Lok.setND({});
=======
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
>>>>>>> old-branch
}