#include "Stud.h"
#include "Mylib.h"


/**
 * @brief Nuskaityti student? duomenis i� failo ir ?kelti ? vektori?.
 *
 * �i funkcija atidaro nurodyt? fail?, nuskaityti kiekvien? eilut? ir i� jos sukuria
 * studento objekt?, kurio vardas, pavard?, nam? darb? ir egzamino rezultatai yra ?ra�omi
 * ? perduot? `std::vector`. Jeigu duomen? eilut?je yra klaida arba tr?ksta reikaling?
 * duomen?, studentas ignoruojamas.
 *
 * @param Vec1 Nuoroda ? `std::vector`, kuriame bus saugomi nuskaityti student? duomenys.
 * @param failoVardas Failo, i� kurio bus nuskaityti student? duomenys, pavadinimas.
 */
void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas) {
	try {
		std::ifstream inFile(failoVardas); /**< Atidarome fail? su nurodytu pavadinimu */
		if (!inFile) {
			throw runtime_error("Nepavyko atdiaryti failo:" + failoVardas);
		}
		string line;
		while (getline(inFile, line)) {

			std::stringstream ss(line);
			Stud temp;
			temp.clearData();/**< I�valome ankstesnius duomenis */

			std::string vardas, pavarde;
			if (!(ss >> vardas >> pavarde)) {
				std::cerr << "Nepavyko nuskaityti studento vardo ir pavardes" << endl;
				continue; /**< Jei vardo ir pavard?s nuskaityti nepavyko, pereiname prie kitos eilut?s */
			}

			temp.setVardas(vardas);
			temp.setPavarde(pavarde);

			int nd;
			while (ss >> nd) {
				temp.addND(nd); /**< Pridedame nam? darb? balus */
			}
			if (temp.getND().size() < 1) {
				continue;/**< Jei ND tr?ksta, ignoruojame student? */
			}
			temp.setEgz(temp.getND().back()); /**< Paskutin? nam? darb? bal? priskiriame egzamino rezultatui */
			temp.getND().pop_back();  /**< Pa�aliname paskutin? ND, kad likt? tik nam? darb? rezultatai */

			Vec1.push_back(temp);/**< Pridedame student? ? vektori? */
		}
		inFile.close(); /**< U�daromas failas po nuskaitymo */

	}
	catch (const std::exception& e) {
		std::cerr << "Klaida: " << e.what() << endl;/**< Jei ?vyko klaida, i�vedame klaidos prane�im? */
	}

}

/**
 * @brief Nuskaityti student? duomenis i� failo ir ?kelti ? s?ra�?.
 *
 * �i funkcija atidaro nurodyt? fail?, nuskaityti kiekvien? eilut? ir i� jos sukuria
 * studento objekt?, kurio vardas, pavard?, nam? darb? ir egzamino rezultatai yra ?ra�omi
 * ? perduot? `std::list`. Jeigu duomen? eilut?je yra klaida arba tr?ksta reikaling?
 * duomen?, studentas ignoruojamas.
 *
 * @param list1 Nuoroda ? `std::list`, kuriame bus saugomi nuskaityti student? duomenys.
 * @param failoVardas Failo, i� kurio bus nuskaityti student? duomenys, pavadinimas.
 */
void nuskaitytiIsfailo(std::list<Stud>& list1, const std::string& failoVardas) {
	try {
		std::ifstream inFile(failoVardas);/**< Atidarome fail? su nurodytu pavadinimu */
		if (!inFile) {
			throw runtime_error("Nepavyko atidaryti failo:" + failoVardas);
		}
		string line;
		while (getline(inFile, line)) {

			std::stringstream ss(line);
			Stud temp;
			temp.clearData();/**< I�valome ankstesnius duomenis */

			std::string vardas, pavarde;
			if (!(ss >> vardas >> pavarde)) {
				std::cerr << "Nepavyko nuskaityti studento vardo ir pavardes" << endl;
				continue;/**< Jei vardo ir pavard?s nuskaityti nepavyko, pereiname prie kitos eilut?s */
			}
			temp.setVardas(vardas);
			temp.setPavarde(pavarde);

			int nd;
			while (ss >> nd) {
				temp.addND(nd);/**< Pridedame nam? darb? balus */
			}
			if (temp.getND().size() < 1) {
				continue;/**< Jei ND tr?ksta, ignoruojame student? */
			}
			temp.setEgz(temp.getND().back()); /**< Paskutin? nam? darb? bal? priskiriame egzamino rezultatui */
			temp.getND().pop_back();  /**< Pa�aliname paskutin? ND, kad likt? tik nam? darb? rezultatai */


			list1.push_back(temp);/**< Pridedame student? ? s?ra�? */
		}
		inFile.close(); /**< U�daromas failas po nuskaitymo */

	}
	catch (const std::exception& e) {
		std::cerr << "Klaida: " << e.what() << endl;/**< Jei ?vyko klaida, i�vedame klaidos prane�im? */
	}

}