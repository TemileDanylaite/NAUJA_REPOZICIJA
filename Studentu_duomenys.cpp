/**
 * @file Studentu_duomenys.cpp
 * @brief Pagrindinis programos vykdymo failas.
 *
 * Šis failas sujungia visas reikalingas bibliotekas ir paleidžia programą,
 * koordinuodamas studentų duomenų apdorojimą. Jame atliekami veiksmai, tokie kaip
 * atsitiktinių studentų duomenų generavimas, studentų duomenų nuskaitymas iš failo,
 * jų apdorojimas ir galutinių įvertinimų apskaičiavimas.
 *
 * @details
 * Failas vykdo programos logiką, įskaitant šiuos pagrindinius veiksmus:
 * - Atsitiktinių studentų duomenų generavimas ir įrašymas į failą.
 * - Studentų duomenų nuskaitymas iš failo į atitinkamas duomenų struktūras.
 * - Studentų rezultatų apdorojimas, įskaitant galutinių įvertinimų (vidurkio ir medianos)
 *   apskaičiavimą.
 * - Studentų rezultatų klasifikavimas ir įrašymas į atskirus failus pagal jų pasiekimus.
 *
 * Šis failas taip pat valdys vartotojo sąsają, leidžiančią pasirinkti norimus veiksmus,
 * pavyzdžiui, generuoti duomenis, nuskaityti juos iš failo arba išvesti studentų
 * rezultatus į failą.
 * 
 * @details Failas naudoja „mylib“ biblioteką.
 */

#include "Mylib.h"
#include "Stud.h"

/**
 * @brief Apskaičiuoja studentų namų darbų mediana.
 *
 * Ši funkcija rūšiuoja namų darbų rezultatus ir grąžina medianą.
 * Jei yra lyginis namų darbų skaičius, grąžinama vidutinė vidurinių elementų reikšmė.
 * Jei nelyginis, grąžinamas vidurinysis elementas.
 *
 * @param nd Vektorius, kuriame saugomi studento namų darbų balai.
 * @return Grąžina mediana kaip double reikšmę.
 */
double apskaiciuotiMediana(std::vector<int>& nd) {
	std::sort(nd.begin(), nd.end());/**< Rūšiuojame namų darbų balus. */
	int n = nd.size();
	if (n % 2 == 0) {
		return(static_cast<double>(nd[n / 2 - 1]) + static_cast<double>(nd[n / 2])) / 2.0;
	}
	else {
		return static_cast<double>(nd[n / 2]);
	}
}

/**
 * @brief Apskaičiuoja galutinius balus pagal vidurkį ir medianą.
 *
 * Ši funkcija apskaičiuoja studento galutinį balą naudojant namų darbų vidurkį
 * ir mediana, pridedant egzaminų balą su nustatytais svoriais:
 * - 40% vidurkis arba mediana iš namų darbų
 * - 60% egzamino balas.
 */
void Stud::apskaiciuotiGalutinius() {
	if (ND.empty()) {
		cout << "Nd yra tuscias, negalima suskaiciuoti galutinio balo" << endl;
		GalutinisVid = 0.0;
		GalutinisMed = 0.0;
		return;
	}
	double vidutinis = 0.0;
	for (double nd : ND) {
		vidutinis += nd;/**< Skaičiuojame namų darbų vidurkį. */
	}
	vidutinis /= ND.size();
	GalutinisVid = 0.4 * vidutinis + 0.6 * egz;

	double mediana = apskaiciuotiMediana(ND);/**< Skaičiuojame namų darbų medianą. */
	GalutinisMed = 0.4 * mediana + 0.6 * egz;
}

/**
 * @brief Įrašo vargsiukų studentų duomenis į failą.
 *
 * Ši funkcija įrašo studentų, kurių galutiniai balai yra žemesni, duomenis į nurodytą failą.
 *
 * @param vargsiukai Vektorius studentų, kurių galutiniai balai yra žemesni.
 * @param failoPavadinimas Failo pavadinimas, į kurį bus įrašyti studentų duomenys.
 */
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

/**
 * @brief Įrašo kietiakiai studentų duomenis į failą.
 *
 * Ši funkcija įrašo studentų, kurių galutiniai balai yra aukšti, duomenis į nurodytą failą.
 *
 * @param kietiakiai Vektorius studentų, kurių galutiniai balai yra aukšti.
 * @param failoPavadinimas Failo pavadinimas, į kurį bus įrašyti studentų duomenys.
 */
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

/**
 * @brief Įrašo vargsiukų studentų duomenis į failą.
 *
 * Ši funkcija įrašo studentų, kurių galutiniai balai yra žemesni, duomenis į nurodytą failą.
 *
 * @param vargsiukai Sąrašas studentų, kurių galutiniai balai yra žemesni.
 * @param failoPavadinimas Failo pavadinimas, į kurį bus įrašyti studentų duomenys.
 */
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

/**
 * @brief Įrašo kietiakiai studentų duomenis į failą.
 *
 * Ši funkcija įrašo studentų, kurių galutiniai balai yra aukšti, duomenis į nurodytą failą.
 *
 * @param kietiakiai Sąrašas studentų, kurių galutiniai balai yra aukšti.
 * @param failoPavadinimas Failo pavadinimas, į kurį bus įrašyti studentų duomenys.
 */
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


/**
 * @brief Pagrindinė programa, skirta studentų duomenų nuskaitymui, apdorojimui ir rūšiavimui.
 *
 * Ši funkcija leidžia vartotojui nuskaityti studentų duomenis iš failo, suskirstyti juos į grupes ir rūšiuoti pagal pasirinkimus.
 * Vartotojas gali pasirinkti konteinerio tipą (vector arba list), rusiavimo kriterijų (pagal vardą, pavardę arba galutinį balą)
 * ir studentų dalijimo strategiją. Laikai matuojami kiekvienam etapui.
 *
 * @return 0 Jei programa baigiasi sėkmingai.
 */
int main()
{
	

	cout << "Ar norite sugeneruoti studentu failus?(taip/ne): ";
	string generuotiFailoPasirinkima; /**< Kintamasis vartotojo atsakymui saugoti */
	cin >> generuotiFailoPasirinkima;/**< Vartotojo atsakymo įvedimas */

	if (generuotiFailoPasirinkima == "taip") {/**< Jei vartotojas pasirinko "taip", generuojami failai */
		sugeneruotiStudentoFaila("studentai1000.txt", 1000, 5);
		sugeneruotiStudentoFaila("studentai10000.txt", 10000, 7);
		sugeneruotiStudentoFaila("studentai100000.txt", 100000, 6);
		sugeneruotiStudentoFaila("studentai1000000.txt", 1000000, 8);
		sugeneruotiStudentoFaila("studentai10000000.txt", 10000000, 4);
		cout << "Failai sugeneruoti!" << endl;/**< Informacija apie failų sugeneravimą */
	}

	vector<Stud> Vec1;/**< Vektorius studentų saugojimui */
	Stud Temp;/**< Laikinas studento objektas */

	cout << "Ar norite ivesti studentu duomenis ar nuskaityti is failo?(ivesti/nuskaityti): ";
	string pasirinkimas;/**< Kintamasis vartotojo pasirinkimui saugoti */
	cin >> pasirinkimas;/**< Vartotojo atsakymo įvedimas */



	if (pasirinkimas == "nuskaityti") {/**< Jei pasirinktas duomenų nuskaitymas iš failo */

		cout << "Pasirinkti strategija(1 - pirmoji, 2 - antroji, 3 - trecioji): "; /**< Klausimas apie strategiją */
		int strategija;/**< Kintamasis strategijai saugoti */
		cin >> strategija;/**< Vartotojo pasirinkimo įvedimas */

		cout << "Pasirinkite konteinerio tipa? (1 - vector, 2 - list): "; /**< Klausimas apie konteinerio tipą */
		int konteinerioTipas;/**< Kintamasis konteinerio tipui saugoti */
		cin >> konteinerioTipas;/**< Vartotojo pasirinkimo įvedimas */


		if (konteinerioTipas == 1) {/**< Jei pasirenkamas vektorius */
			vector<Stud> Vec1;/**< Studentų vektorius */
			cout << "Naudojamas vector." << endl;

			cout << "Pasirinkite rusiavimo kriteriju(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala: ";/**< Klausimas apie rūšiavimą */
			int rusiavimoKriterijus;/**< Kintamasis rūšiavimo kriterijui saugoti */
			cin >> rusiavimoKriterijus;/**< Vartotojo pasirinkimo įvedimas */

			auto pradziaNuskaitymui = std::chrono::high_resolution_clock::now();/**< Laiko pradžia nuskaitymui */
			nuskaitytiIsFailo(Vec1, "studentai1000.txt");
			auto pabaigaNuskaitymui = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga nuskaitymui */

			cout << "Failas uzdarytas" << endl;/**< Informacija, kad failas uždarytas */
			cout << "Failo is " << Vec1.size() << " irasu nuskaitymo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaNuskaitymui - pradziaNuskaitymui).count() << " s" << endl;

			for (auto& studentas : Vec1) {/**< Iteracija per studentus */
				studentas.apskaiciuotiGalutinius();/**< Galutinio balo skaičiavimas kiekvienam studentui */
			}

			auto pradziaRusiavimui = std::chrono::high_resolution_clock::now();/**< Laiko pradžia rūšiavimui */

			if (rusiavimoKriterijus == 1) {/**< Rūšiavimas pagal vardą */
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();
					});
			}
			else if (rusiavimoKriterijus == 2) {/**< Rūšiavimas pagal pavardę */
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getPavarde() < b.getPavarde();
					});
			}
			else if (rusiavimoKriterijus == 3) {/**< Rūšiavimas pagal galutinį balą */
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getGalutinisVid() < b.getGalutinisVid();
					});
			}
			else {
				cout << "Netinkamas pasirinkimas. Rusiavimas pagal varda" << endl;/**< Klaida,netinkamas pasirinkimas */
				sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();/**< Numatytoji rūšiavimo funkcija pagal vardą */
					});
			}

			auto pabaigaRusiavimui = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga rūšiavimui */
			cout << Vec1.size() << "irasu rusiavimas didejimo tvarka, su sort funkcija: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaRusiavimui - pradziaRusiavimui).count() << " s " << endl;

			vector<Stud> vargsiukai; /**< Sukuriamas vektorius vargsiukams saugoti */
			vector<Stud> kietiakiai; /**< Sukuriamas vektorius kietiakams saugoti */

			auto pradziaDalijimui = std::chrono::high_resolution_clock::now();/**< Laiko pradžia dalijimui į grupes */

			if (strategija == 1) {/**< Patikrinama, ar pasirinkta pirmoji dalijimo strategija */

				for (auto& studentas : Vec1) {/**< Pereinama per visus studentus */
					if (studentas.getGalutinisVid() < 5.0) {
						vargsiukai.push_back(studentas);/**< Jei galutinis vidurkis mažesnis už 5, pridedama į vargsiukus */
					}
					else {
						kietiakiai.push_back(studentas);/**< Jei galutinis vidurkis didesnis arba lygus 5, pridedama į kietiakiai */
					}
				}

			}
			else if (strategija == 2) {/**< Patikrinama, ar pasirinkta antroji dalijimo strategija */

				auto it = std::remove_if(Vec1.begin(), Vec1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;/**< Pašalinami studentai, kurių galutinis vidurkis yra 5 ar didesnis */
					});

				vargsiukai.assign(it, Vec1.end()); /**< Vargsiukai priskiriami tiems, kurių vidurkis mažesnis nei 5 */
				Vec1.erase(it, Vec1.end()); /**< Pašalinami studentai, kurių vidurkis 5 ar didesnis */

			}
			else if (strategija == 3) {/**< Patikrinama, ar pasirinkta trečioji dalijimo strategija */


				auto it = std::partition(Vec1.begin(), Vec1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;/**< Padalinama pagal tai, ar galutinis vidurkis yra didesnis arba lygus 5 */
					});
				vargsiukai = vector<Stud>(it, Vec1.end()); /**< Vargsiukai priskiriami tiems, kurių vidurkis mažesnis nei 5 */
				Vec1.erase(it, Vec1.end()); /**< Pašalinami studentai, kurių vidurkis 5 ar didesnis */
			}


			auto pabaigaDalijimui = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga dalijimui į grupes */
			cout << Vec1.size() << " irasu dalijimo i dvi grupes laikas, panaikinant pradini Vektor: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaDalijimui - pradziaDalijimui).count() << " s" << endl;

			auto pradziaVargsiukams = std::chrono::high_resolution_clock::now(); /**< Laiko pradžia vargsiukų įrašymui į failą */
			irasytiVargsiukusVector(vargsiukai, "vargsiukai.txt");
			auto pabaigaVargsiukams = std::chrono::high_resolution_clock::now(); /**< Laiko pabaiga vargsiukų įrašymui į failą */
			cout << vargsiukai.size() << " irasu  vargsiuku irasymo i faila laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaVargsiukams - pradziaVargsiukams).count() << " s" << endl;

			auto pabaigaTesto = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga testui */
			cout << endl << Vec1.size() << " irasu testo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaTesto - pradziaNuskaitymui).count() << " s" << endl;


		}
		else if (konteinerioTipas == 2) {/**< Patikrinama, ar pasirinktas konteinerio tipas yra 'list' */
			list<Stud> list1; /**< Sukuriama 'list' konteinerio struktūra */
			cout << "Naudojamas list." << endl;

			cout << "Pasirinkite rusiavimo kriteriju(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini bala: ";
			int rusiavimoKriterijus;
			cin >> rusiavimoKriterijus; /**< Vartotojas pasirenka rusiavimo kriterijų */

			auto pradziaNuskaitymui = std::chrono::high_resolution_clock::now();/**< Laiko pradžia failo nuskaitymui */
			nuskaitytiIsfailo(list1, "studentai1000.txt");
			auto pabaigaNuskaitymui = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga failo nuskaitymui */

			cout << "Failas uzdarytas" << endl;
			cout << "Failo is " << list1.size() << " irasu nuskaitymo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaNuskaitymui - pradziaNuskaitymui).count() << " s" << endl;

			for (auto& studentas : list1) { /**< Apskaičiuojama kiekvieno studento galutinė vidurkio reikšmė */
				studentas.apskaiciuotiGalutinius();
			}

			auto pradziaRusiavimui = std::chrono::high_resolution_clock::now();/**< Laiko pradžia rūšiavimui */

			if (rusiavimoKriterijus == 1) { /**< Patikrinama, pagal kokį kriterijų rūšiuoti */
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();/**< Rūšiuojama pagal vardą */
					});
			}
			else if (rusiavimoKriterijus == 2) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getPavarde() < b.getPavarde();/**< Rūšiuojama pagal pavardę */
					});
			}
			else if (rusiavimoKriterijus == 3) {
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getGalutinisVid() < b.getGalutinisVid();/**< Rūšiuojama pagal galutinį vidurkį */
					});
			}
			else {
				cout << "Netinkamas pasirinkimas. Rusiavimas pagal varda" << endl;
				list1.sort([](const Stud& a, const Stud& b) {
					return a.getVardas() < b.getVardas();/**< Jei pasirinktas netinkamas kriterijus, rūšiuojama pagal vardą */
					});
			}

			auto pabaigaRusiavimui = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga rūšiavimui */
			cout << list1.size() << "irasu rusiavimas didejimo tvarka, su sort funkcija: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaRusiavimui - pradziaRusiavimui).count() << " s " << endl;



			auto pradziaDalijimui = std::chrono::high_resolution_clock::now();/**< Laiko pradžia dalijimui į grupes */
			list<Stud> vargsiukai, kietiakiai;/**< Sukuriami du sąrašai vargsiukams ir kietiakams */
			if (strategija == 1) {

				for (auto& studentas : list1) {/**< Pereinama per visus studentus sąraše */
					if (studentas.getGalutinisVid() < 5.0) {
						vargsiukai.push_back(studentas);/**< Jei galutinis vidurkis mažesnis už 5, pridedama į vargsiukus */
					}
					else {
						kietiakiai.push_back(studentas); /**< Jei galutinis vidurkis didesnis arba lygus 5, pridedama į kietiakiai */
					}
				}

			}
			else if (strategija == 2) { /**< Patikrinama, ar pasirinkta antroji dalijimo strategija */

				auto it = std::remove_if(list1.begin(), list1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0; /**< Pašalinami studentai, kurių galutinis vidurkis yra 5 ar didesnis */
					});

				vargsiukai.assign(it, list1.end()); /**< Vargsiukai priskiriami tiems, kurių vidurkis mažesnis nei 5 */
				list1.erase(it, list1.end()); /**< Pašalinami studentai, kurių vidurkis 5 ar didesnis */
			}
			else if (strategija == 3) {/**< Patikrinama, ar pasirinkta trečioji dalijimo strategija */

				auto it = std::partition(list1.begin(), list1.end(), [](const Stud& studentas) {
					return studentas.getGalutinisVid() >= 5.0;/**< Padalinama pagal tai, ar galutinis vidurkis yra didesnis arba lygus 5 */
					});
				vargsiukai = list<Stud>(it, list1.end()); /**< Vargsiukai priskiriami tiems, kurių vidurkis mažesnis nei 5 */
				list1.erase(it, list1.end()); /**< Pašalinami studentai, kurių vidurkis 5 ar didesnis */
			}

			auto pabaigaDalijimui = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga dalijimui į grupes */
			cout << list1.size() << " irasu dalijimo i dvi grupes laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaDalijimui - pradziaDalijimui).count() << " s" << endl;

			auto pradziaVargsiukams = std::chrono::high_resolution_clock::now(); /**< Laiko pradžia vargsiukų įrašymui į failą */
			irasytivargsiukusList(vargsiukai, "vargsiukai.txt");
			auto pabaigaVargsiukams = std::chrono::high_resolution_clock::now(); /**< Laiko pabaiga vargsiukų įrašymui į failą */
			cout << vargsiukai.size() << " irasu  vargsiuku irasymo i faila laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaVargsiukams - pradziaVargsiukams).count() << " s" << endl;



			auto pabaigaTesto = std::chrono::high_resolution_clock::now();/**< Laiko pabaiga testui */
			cout << endl << list1.size() << " irasu testo laikas: "
				<< fixed << setprecision(5) << std::chrono::duration<double>(pabaigaTesto - pradziaNuskaitymui).count() << " s" << endl;

		}


	}
	else {

		/**< Klausiama vartotojo, kiek studentų norima įvesti */
		cout << "Kiek yra studentu ?";
		int n;/**< Studentų skaičius */
		cin >> n;

		/**< Prašoma vartotojo pasirinkti konteinerį (vector/list) */
		cout << "Pasirinkite konteineri(vector/list): ";
		string konteineris;/**< Konteinerio pasirinkimas */
		cin >> konteineris;

		
		vector<Stud> Vec1; /**< Vektorius studentams, jei pasirenkamas "vector" */
		list<Stud> list1; /**< Sąrašas studentams, jei pasirenkamas "list" */

		if (konteineris == "vector") {/**< Jei pasirinktas vektorius */

			for (int i = 0; i < n; i++) {
				Stud Temp;/**< Laikinas studento objektas */
				cout << "Please input user data: " << endl;
				cin >> Temp;
				Temp.apskaiciuotiGalutinius();/**< Apskaičiuojami galutiniai balai */

				Vec1.push_back(Temp); /**< Studentas pridedamas į vektorių */
				
			}

			sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
				return a.getVardas() < b.getVardas(); /**< Rūšiuoja studentus pagal vardą */
				});

			/**< Spausdina stulpelius su studentų informacija */
			cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
				<< setw(5) << right << "Galutinis(Vid.)"
				<< setw(5) << right << " Galutinis(Med.)" << endl;

			cout << string(60, '-') << endl;

			for (const auto& studentas : Vec1) {
				cout << studentas << endl;/**< Spausdina studentų informaciją */
			}

		}
		else if (konteineris == "list") {/**< Jei pasirinktas sąrašas */

			/**< Įveda studentų duomenis ir prideda juos į sąrašą */
			for (int i = 0; i < n; i++) {
				Stud Temp; /**< Laikinas studento objektas */
				cout << "Please input user data: " << endl;
				cin >> Temp;
				Temp.apskaiciuotiGalutinius(); /**< Apskaičiuojami galutiniai balai */
				list1.push_back(Temp);/**< Studentas pridedamas į sąrašą */
				
			}

			list1.sort([](const Stud& a, const Stud& b) {
				return a.getVardas() < b.getVardas();/**< Rūšiuoja studentus pagal vardą */
				});

			/**< Spausdina stulpelius su studentų informacija */
			cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
				<< setw(5) << right << "Galutinis(Vid.)"
				<< setw(5) << right << " Galutinis(Med.)" << endl;

			cout << string(60, '-') << endl;

			
			for (const auto& studentas : list1) {
				cout << studentas << endl; /**< Spausdina studentų informaciją */
			}
		}
		else {
			cout << "Neteisingas konteinerio pasirinkimas." << endl;
		}
		

		cout << "Programos pabaiga, sunaikinami visi objektai" << endl;/**< Pabaiga: programos pabaiga ir objektų sunaikinimas */
	
		return 0;/**< Programos pabaiga */

	}
}

