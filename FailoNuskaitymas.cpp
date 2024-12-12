/**
 * @file FailoNuskaitymas.cpp
 * @brief Studentų duomenų nuskaitymas iš failo.
 *
 
 * Šiame faile apdorojamas tekstinio failo nuskaitymas, kuriame saugomi
 * studentų duomenys. Nuskaityti duomenys apdorojami ir įrašomi į atitinkamus
 * struktūrų konteinerius (pvz., vektorius arba sąrašus), kuriuose saugomi
 * studentų vardai, pavardės, namų darbų ir egzamino rezultatai.
 * 
 * @details Failas naudoja „mylib“ biblioteką.
 */

#include "Stud.h"
#include "Mylib.h"

 /**
  * @brief Nuskaityti studentų duomenis iš failo ir įkelti į vektorių.
  *
  * Ši funkcija atidaro nurodytą failą, nuskaito kiekvieną eilutę ir iš jos sukuria
  * studento objektą, kurio vardas, pavardė, namų darbai ir egzamino rezultatai yra įrašomi
  * ir perduodami į `std::vector`. Jeigu duomenų eilutėje yra klaida arba trūksta reikalingų
  * duomenų, studentas ignoruojamas.
  *
  * @param Vec1 Nuoroda į `std::vector`, kuriame bus saugomi nuskaityti studentų duomenys.
  * @param failoVardas Failo, iš kurio bus nuskaityti studentų duomenys, pavadinimas.
  */
void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas) {
    try {
        std::ifstream inFile(failoVardas); /**< Atidarome failą su nurodytu pavadinimu */
        if (!inFile) {
            throw runtime_error("Nepavyko atidaryti failo:" + failoVardas);
        }
        string line;
        while (getline(inFile, line)) {

            std::stringstream ss(line);
            Stud temp;
            temp.clearData(); // Išvalome ankstesnius duomenis 

            std::string vardas, pavardė;
            if (!(ss >> vardas >> pavardė)) {
                std::cerr << "Nepavyko nuskaityti studento vardo ir pavardės" << endl;
                continue; // Jei vardo ir pavardės nuskaityti nepavyko, pereiname prie kitos eilutės 
            }

            temp.setVardas(vardas);
            temp.setPavarde(pavardė);

            int nd;
            while (ss >> nd) {
                temp.addND(nd); // Pridedame namų darbų balus 
            }
            if (temp.getND().size() < 1) {
                continue; // Jei ND trūksta, ignoruojame studentą 
            }
            temp.setEgz(temp.getND().back()); // Paskutinį namų darbų balą priskiriame egzamino rezultatui 
            temp.getND().pop_back();  // Pašaliname paskutinį ND, kad liktų tik namų darbų rezultatai 

            Vec1.push_back(temp); // Pridedame studentą į vektorių
        }
        inFile.close(); // Uždaromas failas po nuskaitymo 

    }
    catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << endl; // Jei įvyko klaida, išvedame klaidos pranešimą 
    }
}

/**
 * @brief Nuskaityti studentų duomenis iš failo ir įkelti į sąrašą.
 *
 * Ši funkcija atidaro nurodytą failą, nuskaito kiekvieną eilutę ir iš jos sukuria
 * studento objektą, kurio vardas, pavardė, namų darbai ir egzamino rezultatai yra įrašomi
 * ir perduodami `std::list`. Jeigu duomenų eilutėje yra klaida arba trūksta reikalingų
 * duomenų, studentas ignoruojamas.
 *
 * @param list1 Nuoroda į `std::list`, kuriame bus saugomi nuskaityti studentų duomenys.
 * @param failoVardas Failo, iš kurio bus nuskaityti studentų duomenys, pavadinimas.
 */
void nuskaitytiIsfailo(std::list<Stud>& list1, const std::string& failoVardas) {
    try {
        std::ifstream inFile(failoVardas); // Atidarome failą su nurodytu pavadinimu 
        if (!inFile) {
            throw runtime_error("Nepavyko atidaryti failo:" + failoVardas);
        }
        string line;
        while (getline(inFile, line)) {

            std::stringstream ss(line);
            Stud temp;
            temp.clearData(); //Išvalome ankstesnius duomenis 

            std::string vardas, pavardė;
            if (!(ss >> vardas >> pavardė)) {
                std::cerr << "Nepavyko nuskaityti studento vardo ir pavardės" << endl;
                continue; // Jei vardo ir pavardės nuskaityti nepavyko, pereiname prie kitos eilutės 
            }
            temp.setVardas(vardas);
            temp.setPavarde(pavardė);

            int nd;
            while (ss >> nd) {
                temp.addND(nd); // Pridedame namų darbų balus 
            }
            if (temp.getND().size() < 1) {
                continue; // Jei ND trūksta, ignoruojame studentą 
            }
            temp.setEgz(temp.getND().back()); // Paskutinį namų darbų balą priskiriame egzamino rezultatui 
            temp.getND().pop_back();  // Pašaliname paskutinį ND, kad liktų tik namų darbų rezultatai 

            list1.push_back(temp); // Pridedame studentą į sąrašą 
        }
        inFile.close(); // Uždaromas failas po nuskaitymo 

    }
    catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << endl; // Jei įvyko klaida, išvedame klaidos pranešimą 
    }
}

