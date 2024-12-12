/**
 * @file Stud.cpp
 * @brief Studentų objektų realizacija.
 *
 * Šiame faile įgyvendinamos studento duomenų struktūros ir metodai,
 * leidžiantys apdoroti studentų informaciją. Tai apima tokius veiksmus,
 * kaip duomenų įvedimas, išvedimas, skaičiavimai, taip pat vidurkių ir
 * medianų apskaičiavimas pagal studentų namų darbų ir egzamino rezultatus.
 *
 * @details
 * Failas įgyvendina funkcijas, kurios leidžia nustatyti studento duomenis,
 * pavyzdžiui, vardą, pavardę, namų darbų rezultatus ir egzamino rezultatą,
 * bei atlikti atitinkamus skaičiavimus, tokius kaip galutinio įvertinimo
 * apskaičiavimas (vidurkis ir mediana). Taip pat realizuoti įvedimo ir
 * išvedimo metodai, kurie leidžia vartotojui bendrauti su studentų objektais.
 * 
 * @details Failas naudoja „mylib“ biblioteką.
 */


#include "Stud.h"
#include "Mylib.h"


/**
 * @brief Atvaizduoja studento informaciją į srautą.
 *
 * Ši funkcija išveda studento vardą, pavardę, galutinį vidurkį ir galutinį mediana į srautą.
 *
 * @param os Išvesties srautas, į kurį bus rašoma informacija apie studentą.
 */
void Stud::atvaizduoti(std::ostream& os) const {// Išvedame studento vardą, pavardę, galutinį vidurkį ir galutinę medianą į išvesties srautą
	os << "Vardas:" << getVardas() << ", Pavarde:" << getPavarde() << ", GalutinisVid:" << GalutinisVid
		<< ", GalutinisMed:" << GalutinisMed << endl;
};


/**
 * @brief Nuskaitymo operatorius studento duomenims įvesti iš srauto.
 *
 * Šis operatorius leidžia įvesti studento duomenis, tokius kaip vardas, pavardė, namų darbų rezultatai ir egzamino rezultatas.
 * Duomenys gali būti įvedami tiek atsitiktinai, tiek rankiniu būdu.
 *
 * @param is Įvesties srautas, iš kurio bus nuskaityti duomenys.
 * @param stud Objektas, į kurį bus saugomi nuskaityti duomenys.
 * @return std::istream& Nuoroda į įvesties srautą.
 */
std::istream& operator>>(std::istream& is, Stud& stud) {

	/**
	* @brief Paprašo vartotojo įvesti vardą ir pavardę.
	* Šie duomenys priskiriami studento objektui.
	*/
	cout << "Ivesti varda ir pavarde: ";// Prašome vartotojo įvesti vardą ir pavardę
	string vardas, pavarde;
	is >> vardas >> pavarde;// Nuskaitomas vardas ir pavarde

	/**
	 * @brief Nustato įvestą vardą ir pavardę studento objektui.
	 */
	 // Nustatomas įvestas vardas ir pavarde studento objektui
	stud.setVardas(vardas);
	stud.setPavarde(pavarde);

	cout << "Konstruktoriu: Objekto " << vardas << " " << pavarde << " sukurimas" << endl;

	string pasirinkimas;

	/**
	 * @brief Patikrina, ar rezultatai turėtų būti generuojami atsitiktinai.
	 */
	cout << "Ar reikia namu darbu ir egzamino rezultatus generuoti atsitiktinai?(taip/ne) ";// Patikriname, ar rezultatai turi būti generuojami atsitiktinai
	is >> pasirinkimas;

	if (pasirinkimas == "taip") {

		/**
		 * @brief Inicijuojamas atsitiktinių skaičių generatorius.
		 * Naudojamas sugeneruoti namų darbų ir egzamino balams.
		 */
		 // Inicijuojamas atsitiktinių skaičių generatorius
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		int ndCount;
		cout << "Ivesti namu darbu skaiciu: ";
		is >> ndCount;// Nuskaityti namų darbų skaičių

		/**
		 * @brief Generuoja nurodyto dydžio atsitiktinius namų darbų balus.
		 * Balai priskiriami studento objektui.
		 */
		 // Sugeneruojame nurodyto dydžio atsitiktinius namų darbų balus
		for (int i = 0; i < ndCount; ++i) {
			stud.addND(dist(gen));// Sugeneruojame ir pridedame atsitiktinį namų darbų balą
		}

		/**
		* @brief Sugeneruojamas atsitiktinis egzamino balas ir priskiriamas studentui.
		*/
		// Sugeneruojamas atsitiktinis egzamino balas ir priskiriamas studentui
		stud.setEgz(dist(gen));
		stud.apskaiciuotiGalutinius();// Apskaičiuojamas galutinis įvertinimas
	
	}
	else {
		cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
		is >> pasirinkimas;

		if (pasirinkimas == "taip") {

			/**
			 * @brief Vartotojas įveda konkrečių namų darbų skaičių ir rezultatus.
			 * Visi rezultatai pridedami prie studento objekto
			 */
			 // Vartotojas įveda konkrečių namų darbų skaičių ir rezultatus
			int ndCount;
			cout << "Ivesti namu darbu skaiciu: ";
			is >> ndCount;



			cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
			for (int i = 0; i < ndCount; ++i) {
				int nd;
				is >> nd;// Vartotojas įveda kiekvieną namų darbų rezultatą
				stud.addND(nd);// Pridedamas rezultatas prie studento objekto

			}
		}
		else if (pasirinkimas == "ne") {

			/**
			* @brief Naudotojas įveda dinamiškai namų darbų rezultatus.
			* Įvedimas baigiamas įvedus -1.
			* Kiekvienas rezultatas pridedamas prie studento objekto
			*/
			// Naudotojas įveda dinamiškai namų darbų rezultatus
			double nd;
			cout << "Ivesti namu darbu rezultatus(ivesti '-1',kad baigti):" << endl;
			while (true) {
				is >> nd;// Vartotojas įveda kiekvieną namų darbų rezultatą
				if (nd == -1) {// Baigiasi įvedimas, jei įvedama -1
					break;
				}
				stud.addND(nd);// Pridedamas rezultatas prie studento objekto
			}
		}

		// Naudotojas įveda egzamino rezultatą ir priskiria jį studento objektui.
		cout << "Ivesti egzamino rezultata: ";
		double egz;
		is >> egz; // Vartotojas įveda egzamino rezultatą
		stud.setEgz(egz);// Priskiriamas egzamino rezultatas studentui


	}

	return is;// Grąžinamas įvesties srautas

}

/**
 * @brief Išvesties operatorius studento duomenims atvaizduoti.
 *
 * Ši funkcija leidžia atvaizduoti visus studento duomenis naudojant `<<` operatorių.
 *
 * @param os Išvesties srautas, į kurį bus rašoma informacija apie studentą.
 * @param stud Studentas, kurio informacija bus atvaizduota.
 * @return std::ostream& Nuoroda į išvesties srautą.
 */
std::ostream& operator<<(std::ostream& os, const Stud& stud) {
	stud.atvaizduoti(os);// Kviečiama funkciją, kuri atvaizduoja studento duomenis
	return os;// Grąžinamas išvesties srautas

}


/**
 * @brief Nustato studento duomenis į pradinius (tuščius) reikšmes.
 *
 * @param Lok Studentas, kurio duomenys bus nustatyti į pradinius.
 */
void val(Stud& Lok) {
	Lok.setVardas("");// Nustatome vardą į tuščią
	Lok.setPavarde("");// Nustatome pavardę į tuščią
	Lok.setND({});// Nustatome namų darbų rezultatus į tuščią vektorių
}