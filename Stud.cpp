#include "Stud.h"
#include "Mylib.h"


/**
 * @brief Atvaizduoja studento informaciją į srautą.
 *
 * Ši funkcija išveda studento vardą, pavardę, galutinį vidurkį ir galutinį mediana į srautą.
 *
 * @param os Išvesties srautas, į kurį bus rašoma informacija apie studentą.
 */
void Stud::atvaizduoti(std::ostream& os) const {
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
	cout << "Ivesti varda ir pavarde: ";
	string vardas, pavarde;
	is >> vardas >> pavarde;

	/**
	 * @brief Nustato įvestą vardą ir pavardę studento objektui.
	 */
	stud.setVardas(vardas);
	stud.setPavarde(pavarde);

	cout << "Konstruktoriu: Objekto " << vardas << " " << pavarde << " sukurimas" << endl;

	string pasirinkimas;

	/**
	 * @brief Patikrina, ar rezultatai turėtų būti generuojami atsitiktinai.
	 */
	cout << "Ar reikia namu darbu ir egzamino rezultatus generuoti atsitiktinai?(taip/ne) ";
	is >> pasirinkimas;

	if (pasirinkimas == "taip") {

		/**
		 * @brief Inicijuojamas atsitiktinių skaičių generatorius.
		 * Naudojamas sugeneruoti namų darbų ir egzamino balams.
		 */
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		int ndCount;
		cout << "Ivesti namu darbu skaiciu: ";
		is >> ndCount;

		/**
		 * @brief Generuoja nurodyto dydžio atsitiktinius namų darbų balus.
		 * Balai priskiriami studento objektui.
		 */
		for (int i = 0; i < ndCount; ++i) {
			stud.addND(dist(gen));
		}

		/**
		* @brief Sugeneruojamas atsitiktinis egzamino balas ir priskiriamas studentui.
		*/
		stud.setEgz(dist(gen));
		stud.apskaiciuotiGalutinius();
	
	}
	else {
		cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
		is >> pasirinkimas;

		if (pasirinkimas == "taip") {

			/**
			 * @brief Vartotojas įveda konkrečių namų darbų skaičių ir rezultatus.
			 * Visi rezultatai pridedami prie studento objekto
			 */
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

			/**
			* @brief Naudotojas įveda dinamiškai namų darbų rezultatus.
			* Įvedimas baigiamas įvedus -1.
			* Kiekvienas rezultatas pridedamas prie studento objekto
			*/
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

		/**
		* @brief Naudotojas įveda egzamino rezultatą ir priskiria jį studento objektui.
		*/
		cout << "Ivesti egzamino rezultata: ";
		double egz;
		is >> egz;
		stud.setEgz(egz);


	}

	return is;

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
	stud.atvaizduoti(os);
	return os;

}


/**
 * @brief Nustato studento duomenis į pradinius (tuščius) reikšmes.
 *
 * @param Lok Studentas, kurio duomenys bus nustatyti į pradinius.
 */
void val(Stud& Lok) {
	Lok.setVardas("");
	Lok.setPavarde("");
	Lok.setND({});
}