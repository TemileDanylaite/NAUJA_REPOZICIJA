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


void Stud::apskaiciuotiGalutinius() {
	if (ND.empty()) {
		cout << "Nd yra tuscias, negalima suskaiciuoti galutinio balo" << endl;
		GalutinisVid = 0.0;
		GalutinisMed = 0.0;
		return;
	}
	double vidutinis = 0.0;
	for (double nd : ND) {
		vidutinis += nd;
	}
	vidutinis /= ND.size();
	GalutinisVid = 0.4 * vidutinis + 0.6 * egz;

	double mediana = apskaiciuotiMediana(ND);
	GalutinisMed = 0.4 * mediana + 0.6 * egz;
}

void irasytiVargsiukusVector(const vector<Stud>& vargsiukai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;


		for (const auto& studentas : vargsiukai) {
			failas << setw(15) << left << studentas.getVardas()
				<< setw(15) << left << studentas.getPavarde()
				<< setw(20) << left << fixed << setprecision(2) << studentas.getGalutinisVid() << endl;

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
			failas << setw(15) << left << studentas.getVardas()
				<< setw(15) << left << studentas.getPavarde()
				<< setw(20) << left << fixed << setprecision(2) << studentas.getGalutinisVid() << endl;
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
			failas << setw(15) << left << studentas.getVardas()
				<< setw(15) << left << studentas.getPavarde()
				<< setw(20) << left << fixed << setprecision(2) << studentas.getGalutinisVid() << endl;

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
			failas << setw(15) << left << studentas.getVardas()
				<< setw(15) << left << studentas.getPavarde()
				<< setw(20) << left << fixed << setprecision(2) << studentas.getGalutinisVid() << endl;
		}
		failas.close();

	}
	else {
		cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
	}
}


void output(const Stud& Lok, bool isFromFile = false) {
	cout << setw(15) << left << Lok.getVardas() << setw(15) << left << Lok.getPavarde()
		<< setw(5) << right << fixed << setprecision(2) << Lok.getGalutinisVid();

	if (!isFromFile) {
		cout << setw(15) << right << fixed << setprecision(2) << Lok.getGalutinisMed();
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

		cout << "Pasirinkti strategija(1 - pirmoji, 2 - antroji, 3 - trecioji): ";
		int strategija;
		cin >> strategija;

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
			nuskaitytiIsFailo(Vec1, "studentai1000.txt");
			auto pabaigaNuskaitymui = std::chrono::high_resolution_clock::now();

			cout << "Failas uzdarytas" << endl;
			cout << "Failo is " << Vec1.size() << " irasu nuskaitymo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaNuskaitymui - pradziaNuskaitymui).count() << " s" << endl;

			for (auto& studentas : Vec1) {
				studentas.apskaiciuotiGalutinius();
			}

			auto pradziaRusiavimui = std::chrono::high_resolution_clock::now();

			if (rusiavimoKriterijus == 1) {
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();
					});
			}
			else if (rusiavimoKriterijus == 2) {
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getPavarde() < b.getPavarde();
					});
			}
			else if (rusiavimoKriterijus == 3) {
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getGalutinisVid() < b.getGalutinisVid();
					});
			}
			else {
				cout << "Netinkamas pasirinkimas. Rusiavimas pagal varda" << endl;
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();
					});
			}

			auto pabaigaRusiavimui = std::chrono::high_resolution_clock::now();
			cout << Vec1.size() << "irasu rusiavimas didejimo tvarka, su sort funkcija: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaRusiavimui - pradziaRusiavimui).count() << " s " << endl;

			vector<Stud> vargsiukai;
			vector<Stud> kietiakiai;

			auto pradziaDalijimui = std::chrono::high_resolution_clock::now();

			if (strategija == 1) {

				for (auto& studentas : Vec1) {
					if (studentas.getGalutinisVid() < 5.0) {
						vargsiukai.push_back(studentas);
					}
					else {
						kietiakiai.push_back(studentas);
					}
				}

			}
			else if (strategija == 2) {


				auto it = std::remove_if(Vec1.begin(), Vec1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;
					});

				vargsiukai.assign(it, Vec1.end());
				Vec1.erase(it, Vec1.end());

			}
			else if (strategija == 3) {


				auto it = std::partition(Vec1.begin(), Vec1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;
					});
				vargsiukai = vector<Stud>(it, Vec1.end());
				Vec1.erase(it, Vec1.end());
			}


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
				studentas.apskaiciuotiGalutinius();
			}

			auto pradziaRusiavimui = std::chrono::high_resolution_clock::now();

			if (rusiavimoKriterijus == 1) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();
					});
			}
			else if (rusiavimoKriterijus == 2) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getPavarde() < b.getPavarde();
					});
			}
			else if (rusiavimoKriterijus == 3) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getGalutinisVid() < b.getGalutinisVid();
					});
			}
			else {
				cout << "Netinkamas pasirinkimas. Rusiavimas pagal varda" << endl;
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();
					});
			}

			auto pabaigaRusiavimui = std::chrono::high_resolution_clock::now();
			cout << list1.size() << "irasu rusiavimas didejimo tvarka, su sort funkcija: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaRusiavimui - pradziaRusiavimui).count() << " s " << endl;



			auto pradziaDalijimui = std::chrono::high_resolution_clock::now();
			list<Stud> vargsiukai, kietiakiai;
			if (strategija == 1) {

				for (auto& studentas : list1) {
					if (studentas.getGalutinisVid() < 5.0) {
						vargsiukai.push_back(studentas);
					}
					else {
						kietiakiai.push_back(studentas);
					}
				}

			}
			else if (strategija == 2) {

				auto it = std::remove_if(list1.begin(), list1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;
					});

				vargsiukai.assign(it, list1.end());
				list1.erase(it, list1.end());

			}
			else if (strategija == 3) {

				auto it = std::partition(list1.begin(), list1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;
					});
				vargsiukai = list<Stud>(it, list1.end());
				list1.erase(it, list1.end());
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
				Temp.apskaiciuotiGalutinius();
				Vec1.push_back(Temp);
				val(Temp);

				cout << "Objekto saugojimo atmintyje adresas: " << &Vec1.back() << endl;
			}

			sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
				return a.getVardas() < b.getVardas();
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
				Temp.apskaiciuotiGalutinius();
				list1.push_back(Temp);
				val(Temp);

				cout << "Objekto saugojimo atmintyje adresas: " << &list1.back() << endl;
			}

			sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
				return a.getVardas() < b.getVardas();
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

