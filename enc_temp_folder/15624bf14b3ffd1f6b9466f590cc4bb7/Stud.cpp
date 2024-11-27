#include "Stud.h"
#include "Mylib.h"
void ived(Stud& Lok) {

	cout << "Ivesti varda ir pavarde: ";
	cin >> Lok;

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
	cout << Lok;
}

void val(Stud& Lok) {
	Lok.setVardas("");
	Lok.setPavarde("");
	Lok.setND({});
}

std::ostream& operator<<(std::ostream& os, const Stud& stud) {
	os << setw(15) << left << stud.getVardas()
		<< setw(15) << left << stud.getPavarde();

	for (int i = 0 < stud.getND().size(); ++i;) {
		os << setw(10) << right << stud.getND()[i];
	}
	os << setw(10) << right << stud.getEgz() << endl;
	return os;
		
}
std::istream& operator>>(std::istream& is, Stud& stud) {
	is >> stud.vardas >> stud.pavarde >> stud.GalutinisVid >> stud.GalutinisMed;

	return is;

}