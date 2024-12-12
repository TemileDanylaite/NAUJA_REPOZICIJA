/**
 * @file FailoGeneravimas.cpp
 * @brief Studentų duomenų generavimas į failą.
 *
 * Šiame faile įgyvendinamas atsitiktinių studentų duomenų
 * generavimas ir išsaugojimas į tekstinį failą.
 *
 * @details Failas naudoja „mylib“ biblioteką ir susijusius metodus
 * efektyviam duomenų rašymui.
 */

#include "Stud.h"
#include "Mylib.h"


/**
 * @brief Sugeneruoja studentų duomenų failą.
 *
 * Ši funkcija sukuria failą su studentų vardais, pavardėmis, jų namų darbų (ND) rezultatais
 * ir egzamino rezultatais. Kiekvienam studentui sugeneruojami atsitiktiniai ND ir egzaminų
 * balai, kurie įrašomi į nurodytą failą.
 *
 * @param fileName Failo pavadinimas, kuriame bus išsaugoti studentų duomenys.
 * @param studentCount Kiek studentų duomenų turi būti sugeneruota.
 * @param ndCount Kiek namų darbų rezultatų turi būti sugeneruota kiekvienam studentui.
 */
void sugeneruotiStudentoFaila(const string& fileName, int studentCount, int ndCount) {
    auto pradzia = std::chrono::high_resolution_clock::now();  ///< Laiko pradžia

    
    ofstream outFile(fileName); /**< Sukuriame failą su nurodytu pavadinimu */
    if (!outFile) {
        std::cerr << "Nepavyko sukurti failo: " << fileName << endl;
        return;
    }

    /** Pirmos eilutės su antraštėmis įrašymas į failą */
    outFile << setw(25) << left << "Vardas"
        << setw(25) << left << "Pavarde";

    /** Generuojame ND antraštes */
    for (int i = 1; i <= ndCount; i++) {
        outFile << setw(10) << right << "ND" + std::to_string(i);
    }
    outFile << setw(10) << right << "Egz." << endl;



    /** Atsitiktinių skaičių generatorius(1 - 10 balai). */
    random_device rd;  /**< Atsitiktinių skaičių generatorius. */
    mt19937 gen(rd());  /**< Inicializuojame generatorių. */
    uniform_int_distribution<> dist(1, 10);  /**< Skaičių intervalas nuo 1 iki 10 */

    /** Generuojame duomenis kiekvienam studentui */
    for (int i = 1; i <= studentCount; ++i) {

        /** Sukuriame studentą su vardu ir pavarde */
        Stud studentas("Vardas" + std::to_string(i), "Pavarde" + std::to_string(i));

        /** Generuojame ND balus */
        for (int j = 0; j < ndCount; ++j) {
            studentas.addND(dist(gen)); /**< Pridedame atsitiktinį ND balą */
        }

        /** Generuojame egzamino balą */
        studentas.setEgz(dist(gen));

        /** Įrašome studento duomenis į failą */
        outFile << setw(25) << left << studentas.getVardas()
            << setw(25) << left << studentas.getPavarde();

        /** Įrašome ND rezultatus */
        for (int nd : studentas.getND()) {
            outFile << setw(10) << right << nd;
        }

        /** Įrašome egzamino rezultatą */
        outFile << setw(10) << right << studentas.getEgz() << endl;
    }

    /** Uždaromas failas */
    outFile.close();
    cout << "Failas sukurtas: " << fileName << endl;

    /** Apskaičiuojame ir išvedame failo kūrimo trukmę */
    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = pabaiga - pradzia;
    cout << "Failo kurimo trukme: " << fixed << setprecision(5) << elapsed.count() << " s" << endl;
}
