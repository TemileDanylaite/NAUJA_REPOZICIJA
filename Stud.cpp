#include "Stud.h"
#include "Mylib.h"



std::istream& operator>>(std::istream& is, Stud& stud) {
	cout << "Ivesti varda ir pavarde: ";
	string vardas, pavarde;
	is >> vardas >> pavarde;

	stud.setVardas(vardas);
	stud.setPavarde(pavarde);

	cout << "Konstruktoriu: Objekto " << vardas << " " << pavarde << " sukurimas" << endl;

	string pasirinkimas;
	cout << "Ar reikia namu darbu ir egzamino rezultatus generuoti atsitiktinai?(taip/ne) ";
	is >> pasirinkimas;

	if (pasirinkimas == "taip") {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		int ndCount;
		cout << "Ivesti namu darbu skaiciu: ";
		is >> ndCount;

		for (int i = 0; i < ndCount; ++i) {
			stud.addND(dist(gen));
		}

		stud.setEgz(dist(gen));
		stud.apskaiciuotiGalutinius();
	}
	else {
		cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
		is >> pasirinkimas;

		if (pasirinkimas == "taip") {
			int ndCount;
			cout << "Ivesti namu darbu skaiciu: ";
			is >> ndCount;



			cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
			for (int i = 0; i < ndCount; ++i) {
				int nd;
				is >> nd;
				stud.addND(nd);

			}
		}
		else if (pasirinkimas == "ne") {
			double nd;
			cout << "Ivesti namu darbu rezultatus(ivesti '-1',kad baigti):" << endl;
			while (true) {
				is >> nd;
				if (nd == -1) {
					break;
				}
				stud.addND(nd);
			}
		}


		cout << "Ivesti egzamino rezultata: ";
		double egz;
		is >> egz;
		stud.setEgz(egz);


	}

	return is;

}

std::ostream& operator<<(std::ostream& os, const Stud& stud) {
	os << setw(15) << left << stud.getVardas()
		<< setw(15) << left << stud.getPavarde()
		<< setw(4) << right << fixed << setprecision(2) << stud.getGalutinisVid()
		<< setw(16) << right << fixed << setprecision(2) << stud.getGalutinisMed() << endl;
	return os;
}

void output(const Stud& Lok){
	cout << Lok;
}

void val(Stud& Lok) {
	Lok.setVardas("");
	Lok.setPavarde("");
	Lok.setND({});
}