#include "Mylib.h"
#include "Stud.h"


double apskaiciuotiMediana(std::vector<int>& nd) {
	std::sort(nd.begin(), nd.end());
	int n = nd.size();
	if (n % 2 == 0) {
		return(static_cast<double>(nd[n / 2 - 1]) + static_cast<double>(nd[n / 2])) / 2.0;
	}
	else {
		return static_cast<double>(nd[n / 2]);
	}
}


void apskaiciuotiGalutinius(Stud& Lok) {
	if (Lok.ND.empty()) {
		cout << "Nd yra tuscias, negalima suskaiciuoti galutinio balo" << endl;
		Lok.GalutinisVid = 0.0;
		Lok.GalutinisMed = 0.0;
		return;
	}
	double vidutinis = 0.0;
	for (double nd : Lok.ND) {
		vidutinis += nd;
	}
	vidutinis /= Lok.ND.size();
    Lok.GalutinisVid = 0.4 * vidutinis + 0.6 * Lok.egz;

	double mediana = apskaiciuotiMediana(Lok.ND);
	Lok.GalutinisMed = 0.4 * mediana + 0.6 * Lok.egz;
}

void irasytiVargsiukusVector(const vector<Stud>& vargsiukai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;


		for (const auto& studentas : vargsiukai) {
			failas << setw(15) << left << studentas.vardas
				<< setw(15) << left << studentas.pavarde
				<< setw(20) << left << fixed << setprecision(2) << studentas.GalutinisVid << endl;
	
		}
		failas.close();
		
	}
	else {
		cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
	}
}
void irasytiKietiakiaiVector(const vector<Stud>& kietiakiai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;

		for (const auto& studentas : kietiakiai) {
			failas << setw(15) << left << studentas.vardas
				<< setw(15) << left << studentas.pavarde
				<< setw(20) << left << fixed << setprecision(2) << studentas.GalutinisVid << endl;
		}
		failas.close();

	}
	else {
		cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
	}
}

void irasytivargsiukusList(const list<Stud>& vargsiukai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;


		for (const auto& studentas : vargsiukai) {
			failas << setw(15) << left << studentas.vardas
				<< setw(15) << left << studentas.pavarde
				<< setw(20) << left << fixed << setprecision(2) << studentas.GalutinisVid << endl;

		}
		failas.close();

	}
	else {
		cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
	}
}

void irasytikietiakiaiList(const list<Stud>& kietiakiai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;

		for (const auto& studentas : kietiakiai) {
			failas << setw(15) << left << studentas.vardas
				<< setw(15) << left << studentas.pavarde
				<< setw(20) << left << fixed << setprecision(2) << studentas.GalutinisVid << endl;
		}
		failas.close();

	}
	else {
		cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
	}
}


void output(const Stud& Lok, bool isFromFile = false) {
	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde
		<< setw(5) << right << fixed << setprecision(2) << Lok.GalutinisVid;

	if (!isFromFile) {
		cout << setw(15) << right << fixed << setprecision(2) << Lok.GalutinisMed;
	}
	cout << endl;
}

int main()
{

	cout << "Ar norite sugeneruoti studentu failus?(taip/ne): ";
	string generuotiFailoPasirinkima;
	cin >> generuotiFailoPasirinkima;

	if (generuotiFailoPasirinkima == "taip") {
		sugeneruotiStudentoFaila("studentai1000.txt", 1000, 5);
		sugeneruotiStudentoFaila("studentai10000.txt", 10000, 7);
		sugeneruotiStudentoFaila("studentai100000.txt", 100000, 6);
		sugeneruotiStudentoFaila("studentai1000000.txt", 1000000, 8);
		sugeneruotiStudentoFaila("studentai10000000.txt", 10000000, 4);
		cout << "Failai sugeneruoti!" << endl;
	}

	vector<Stud> Vec1;
	Stud Temp;

	cout << "Ar norite ivesti studentu duomenis ar nuskaityti is failo?(ivesti/nuskaityti): ";
	string pasirinkimas;
	cin >> pasirinkimas;


	if (pasirinkimas == "nuskaityti") {

		cout << "Pasirinkite konteinerio tipa? (1 - vector, 2 - list): ";
		int konteinerioTipas;
		cin >> konteinerioTipas;


		if (konteinerioTipas == 1) {
			vector<Stud> Vec1;
			cout << "Naudojamas vector." << endl;

			cout << "Pasirinkite rusiavimo kriteriju(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala: ";
			int rusiavimoKriterijus;
			cin >> rusiavimoKriterijus;

			auto pradziaNuskaitymui = std::chrono::high_resolution_clock::now();
			nuskaitytiIsFailo(Vec1, "studentai10000000.txt");
			auto pabaigaNuskaitymui = std::chrono::high_resolution_clock::now();

			cout << "Failas uzdarytas" << endl;
			cout << "Failo is " << Vec1.size() << " irasu nuskaitymo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaNuskaitymui - pradziaNuskaitymui).count() << " s" << endl;

			for (auto& studentas : Vec1) {
				apskaiciuotiGalutinius(studentas);
			}

			auto pradziaRusiavimui = std::chrono::high_resolution_clock::now();

			if (rusiavimoKriterijus == 1) {
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.vardas < b.vardas;
					});
			}
			else if (rusiavimoKriterijus == 2) {
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.pavarde < b.pavarde;
					});
			}
			else if (rusiavimoKriterijus == 3) {
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.GalutinisVid < b.GalutinisVid;
					});
			}
			else {
				cout << "Netinkamas pasirinkimas. Rusiavimas pagal varda" << endl;
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.vardas < b.vardas;
					});
			}

			auto pabaigaRusiavimui = std::chrono::high_resolution_clock::now();
			cout << Vec1.size() << "irasu rusiavimas didejimo tvarka, su sort funkcija: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaRusiavimui - pradziaRusiavimui).count() << " s " << endl;



			vector<Stud> vargsiukai;
			std::copy_if(Vec1.begin(), Vec1.end(), std::back_inserter(vargsiukai), [](const Stud& studentas) {
				return studentas.GalutinisVid < 5.0
				});

			
			
			auto pabaigaDalijimui = std::chrono::high_resolution_clock::now();
			cout << Vec1.size() << " irasu dalijimo i dvi grupes laikas, panaikinant pradini Vektor: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaDalijimui - pradziaDalijimui).count() << " s" << endl;

			auto pradziaVargsiukams = std::chrono::high_resolution_clock::now();
			irasytiVargsiukusVector(vargsiukai, "vargsiukai.txt");
			auto pabaigaVargsiukams = std::chrono::high_resolution_clock::now();
			cout << vargsiukai.size() << " irasu  vargsiuku irasymo i faila laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaVargsiukams - pradziaVargsiukams).count() << " s" << endl;

		

			auto pabaigaTesto = std::chrono::high_resolution_clock::now();
			cout << endl << Vec1.size() << " irasu testo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaTesto - pradziaNuskaitymui).count() << " s" << endl;


		}
		else if (konteinerioTipas == 2) {
			list<Stud> list1;
			cout << "Naudojamas list." << endl;

			cout << "Pasirinkite rusiavimo kriteriju(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala: ";
			int rusiavimoKriterijus;
			cin >> rusiavimoKriterijus;

			auto pradziaNuskaitymui = std::chrono::high_resolution_clock::now();
			nuskaitytiIsfailo(list1, "studentai1000.txt");
			auto pabaigaNuskaitymui = std::chrono::high_resolution_clock::now();

			cout << "Failas uzdarytas" << endl;
			cout << "Failo is " << list1.size() << " irasu nuskaitymo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaNuskaitymui - pradziaNuskaitymui).count() << " s" << endl;

			for (auto& studentas : list1) {
				apskaiciuotiGalutinius(studentas);
			}

			auto pradziaRusiavimui = std::chrono::high_resolution_clock::now();

			if (rusiavimoKriterijus == 1) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.vardas < b.vardas;
					});
			}
			else if (rusiavimoKriterijus == 2) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.pavarde < b.pavarde;
					});
			}
			else if (rusiavimoKriterijus == 3) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.GalutinisVid < b.GalutinisVid;
					});
			}
			else {
				cout << "Netinkamas pasirinkimas. Rusiavimas pagal varda" << endl;
				list1.sort([](const Stud& a, const Stud& b) {
					return a.vardas < b.vardas;
					});
			}

			auto pabaigaRusiavimui = std::chrono::high_resolution_clock::now();
			cout << list1.size() << "irasu rusiavimas didejimo tvarka, su sort funkcija: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaRusiavimui - pradziaRusiavimui).count() << " s " << endl;



			list<Stud> vargsiukai;
			auto pradziaDalijimui = std::chrono::high_resolution_clock::now();
			
			for (auto it = list1.begin(); it != list1.end();) {
				if (it->GalutinisVid < 5.0) {
					vargsiukai.push_back(*it);
					it = list1.erase(it);
				}
				else {
					++it;
				}
			}


			auto pabaigaDalijimui = std::chrono::high_resolution_clock::now();
			cout << list1.size() << " irasu dalijimo i dvi grupes laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaDalijimui - pradziaDalijimui).count() << " s" << endl;

			auto pradziaVargsiukams = std::chrono::high_resolution_clock::now();
			irasytivargsiukusList(vargsiukai, "vargsiukai.txt");
			auto pabaigaVargsiukams = std::chrono::high_resolution_clock::now();
			cout << vargsiukai.size() << " irasu  vargsiuku irasymo i faila laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaVargsiukams - pradziaVargsiukams).count() << " s" << endl;

	

			auto pabaigaTesto = std::chrono::high_resolution_clock::now();
			cout << endl << list1.size() << " irasu testo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaTesto - pradziaNuskaitymui).count() << " s" << endl;


		}


	}
	else {
		cout << "Kiek yra studentu ?";
		int n;
		cin >> n;

		cout << "Pasirinkite konteineri(vector/list): ";
		string konteineris;
		cin >> konteineris;

		vector<Stud> Vec1;
		list<Stud> list1;

		if (konteineris == "vector") {

			for (int i = 0; i < n; i++) {
				cout << "Please input user data: " << endl;
				ived(Temp);

				apskaiciuotiGalutinius(Temp);
				Vec1.push_back(Temp);
				val(Temp);

				cout << "Objekto saugojimo atmintyje adresas: " << &Vec1.back() << endl;
			}

			sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
				return a.vardas < b.vardas;
				});

			cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
				<< setw(5) << right << "Galutinis(Vid.)"
				<< setw(5) << right << " Galutinis(Med.)" << endl;

			cout << string(60, '-') << endl;

			for (const auto& studentas : Vec1) {
				output(studentas, false);
			}

		}
		else if (konteineris == "list") {
			list<Stud> list1;

			for (int i = 0; i < n; i++) {
				cout << "Please input user data: " << endl;
				ived(Temp);

				apskaiciuotiGalutinius(Temp);
				list1.push_back(Temp);
				val(Temp);

				cout << "Objekto saugojimo atmintyje adresas: " << &list1.back() << endl;
			}

			sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
				return a.vardas < b.vardas;
				});

			cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
				<< setw(5) << right << "Galutinis(Vid.)"
				<< setw(5) << right << " Galutinis(Med.)" << endl;

			cout << string(60, '-') << endl;

			for (const auto& studentas : list1) {
				output(studentas, false);
			}
		}
		else {
			cout << "Neteisingas konteinerio pasirinkimas." << endl;
		}

		system("pause");
		return 0;
	}
}

		

	
