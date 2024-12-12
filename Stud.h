/**
 * @file stud.h
 * @brief Studentų klasės antraštinis failas.
 *
 * Šiame faile aprašoma studentų duomenų struktūra, jos
 * kintamieji ir pagrindiniai metodai, kurie bus naudojami
 * „stud.cpp“ faile.
 *
 * Šiame faile aprašomos dvi pagrindinės klasės:
 * - **Abstrakti klasė `zmogus`**, kuri aprašo žmogaus duomenis, įskaitant vardą ir pavardę.
 * - **Išvestinė klasė `Stud`**, kuri paveldi klasę `zmogus` ir praplečia ją pridėdama studentų specifinius duomenis ir metodus, tokius kaip namų darbų rezultatai, egzaminas ir galutiniai įvertinimai.
 *
 * **`zmogus` klasė**:
 * - Tai **abstrakti klasė**, nes ji turi **grynąją virtualią funkciją** `atvaizduoti()`, kuri nėra įgyvendinta šioje klasėje ir turi būti įgyvendinta išvestinėse klasėse.
 * - Ši klasė aprašo bendrą žmogaus informaciją, tokią kaip vardas ir pavardė, ir pateikia metodus jų nustatymui bei gavimui.
 * - Klasė `zmogus` negali būti tiesiogiai instancijuojama, tačiau ji suteikia pagrindą kitoms klasėms, pvz., `Stud`, paveldėti ir įgyvendinti savo specifinius metodus.
 * - Naudojami operatoriai, leidžiantys lengvai įvesti ir išvesti žmogaus duomenis į/iš srauto.
 *
 * **`Stud` klasė**:
 * - Tai **išvestinė klasė**, paveldinti klasę `zmogus`. Ji prideda papildomus duomenis ir funkcijas, susijusias su studentų rezultatais.
 * - Klasė turi metodus, skirtus apdoroti studentų namų darbų rezultatus (`addND()`), apskaičiuoti galutinius įvertinimus (vidurkį ir medianą), taip pat atvaizduoti studento informaciją (`atvaizduoti()`).
 * - `Stud` klasė įgyvendina grynąją virtualią funkciją `atvaizduoti()` iš bazinės klasės `zmogus`, todėl ši funkcija tampa specifinė studentui.
 * - Pateikiami operatoriai, leidžiantys įvesti ir išvesti studentų duomenis į/iš srauto.
 * - Klasė turi ir papildomas funkcijas, kaip duomenų kopijavimas, destruktorius, skirtas duomenų valymui, bei papildomos funkcijos studentų duomenims apdoroti.
 *
 * @details Failas naudoja „mylib“ biblioteką.
 */



#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED
#include "Mylib.h"

/**
 * @class zmogus
 * @brief Klasė, kuri aprašo žmogų su vardu ir pavarde.
 *
 * Ši klasė suteikia pagrindines funkcijas, leidžiančias nustatyti ir gauti žmogaus vardą ir pavardę.
 */
class zmogus {
private:
    std::string vardas, pavarde;// Privatus kintamasis vardui ir pavardei saugoti

public:
    /**
     * @brief Konstruktorius, kuriame nustatomi vardas ir pavardė.
     * @param v Žmogaus vardas (numatytasis tuščias).
     * @param p Žmogaus pavardė (numatytasis tuščias).
     */
    zmogus(std::string v = "", std::string p = "")// Konstruktorius su numatytomis reikšmėmis
        : vardas(v), pavarde(p) {}

    /**
     * @brief Virtualus destruktorius (default).
     */
    virtual ~zmogus() = default;// Numatytoji destrukcija

    /**
     * @brief Grąžina žmogaus vardą.
     * @return Žmogaus vardas.
     */
    std::string getVardas() const { return vardas; }// Vardo grąžinimo funkcija

    /**
     * @brief Grąžina žmogaus pavardę.
     * @return Žmogaus pavardė.
     */
    std::string getPavarde() const { return pavarde; }// Pavardės grąžinimo funkcija

    /**
     * @brief Nustato žmogaus vardą.
     * @param v Žmogaus vardas.
     */
    virtual void setVardas(const std::string& v) { vardas = v; }// Vardo nustatymo funkcija


    /**
     * @brief Nustato žmogaus pavardę.
     * @param p Žmogaus pavardė.
     */
    virtual void setPavarde(const std::string& p) { pavarde = p; } // Pavardės nustatymo funkcija

    /**
     * @brief Grynoji virtuali funkcija, kuri turi būti implementuota paveldėtojų klasėse.
     * @param os Išvesties srautas.
     */
    virtual void atvaizduoti(std::ostream& os) const = 0;// Grynoji virtuali funkcija, kurią turi implementuoti paveldėtos klasės

    /**
     * @brief Draugiškas operatorius, kuris išveda žmogų į srautą.
     * @param os Išvesties srautas.
     * @param zmog Žmogaus objektas.
     * @return Išvesties srautas su žmogaus duomenimis.
     */
    friend std::ostream& operator <<(std::ostream& os, const zmogus& zmog) {
        zmog.atvaizduoti(os);// Kvieciama atvaizduoti funkcija
        return os;// Grąžina išvesties srautą su žmogaus duomenimis
    }
};

/**
 * @class Stud
 * @brief Klasė, kuri aprašo studentą, paveldintį iš žmogaus.
 *
 * Ši klasė praplečia klasės `zmogus` funkcionalumą, kad apimtų studento pažymius, egzaminą ir galutinį įvertinimą.
 */
class Stud : public zmogus {
private:
    std::vector<int> ND; // Namų darbų rezultatai.
    double egz; // Egzamino rezultatas.
    double GalutinisVid; // Galutinis įvertinimas (vidurkis).
    double GalutinisMed; // Galutinis įvertinimas (mediana).

public:
    /**
     * @brief Konstruktorius, kuriame nustatomi studento vardas, pavardė, namų darbai ir egzaminas.
     * @param v Vardas.
     * @param p Pavardė.
     * @param nd Namų darbų rezultatai.
     * @param e Egzamino rezultatas.
     */
    Stud(std::string v = "", std::string p = "", std::vector<int> nd = {}, double e = 0.0)// Konstruktorius su parametrais
        : zmogus(v, p), ND(nd), egz(e), GalutinisVid(0), GalutinisMed(0) {}

    /**
     * @brief Kopijavimo konstruktorius.
     * @param other Kitas studentas, kurio duomenys bus nukopijuoti.
     */
    Stud(const Stud& other) noexcept
        : zmogus(other.getVardas(), other.getPavarde()),// Kopijavimo inicializacija iš zmogus klasės
        ND(other.ND),
        egz(other.egz),
        GalutinisVid(other.GalutinisVid),
        GalutinisMed(other.GalutinisMed) {}

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param other Kitas studentas, kurio duomenys bus priskiriami.
     * @return Nuoroda į šį objektą.
     */
    Stud& operator = (const Stud& other) noexcept {
        if (this == &other) return *this;// Patikrinimas, kad neatsitiktų savitarpio priskyrimas
        zmogus::operator = (other);// Kviečiamas paveldėtas operatorius
        ND = other.ND;// Priskiriame namų darbų rezultatus
        egz = other.egz;// Priskiriame egzamino rezultatą
        GalutinisVid = other.GalutinisVid;// Priskiriame galutinį vidurkį
        GalutinisMed = other.GalutinisMed; // Priskiriame galutinę medianą
        return *this;// Grąžiname šį objektą
    }

    /**
     * @brief Pridėti naują namų darbų rezultatą.
     * @param nd Namų darbų rezultatas.
     */
    void addND(int nd) {// Pridedame naują namų darbų rezultatą į vektorių
        ND.push_back(nd);
    }

    /**
     * @brief Destruktorius, kuris išvalo duomenis.
     */
    ~Stud() { clearData(); }// Destruktorius, kuris išvalo studento duomenis

    /**
     * @brief Išvalo studento duomenis.
     */
    void clearData() {
        ND.clear();// Išvalome namų darbų rezultatus
        egz = 0.0; // Nustatome egzamino rezultatą į 0
        GalutinisVid = 0.0; // Nustatome galutinį vidurkį į 0
        GalutinisMed = 0.0; // Nustatome galutinę medianą į 0
    }

    /**
     * @brief Grąžina namų darbų rezultatus.
     * @return Namų darbų rezultatai.
     */
    std::vector<int> getND() const { return ND; }

    /**
     * @brief Grąžina egzamino rezultatą.
     * @return Egzamino rezultatas.
     */
    double getEgz() const { return egz; }

    /**
     * @brief Grąžina galutinį įvertinimą (vidurkį).
     * @return Galutinis įvertinimas (vidurkis).
     */
    double getGalutinisVid() const { return GalutinisVid; }

    /**
     * @brief Grąžina galutinį įvertinimą (medianą).
     * @return Galutinis įvertinimas (mediana).
     */
    double getGalutinisMed() const { return GalutinisMed; }

    /**
     * @brief Nustato namų darbų rezultatus.
     * @param nd Namų darbų rezultatai.
     */
    void setND(const std::vector<int>& nd) { ND = nd; }

    /**
     * @brief Nustato egzamino rezultatą.
     * @param e Egzamino rezultatas.
     */
    void setEgz(double e) { egz = e; }

    /**
     * @brief Apskaičiuoja galutinius įvertinimus (vidurkį ir medianą).
     */
    void apskaiciuotiGalutinius();// Apskaičiuoja galutinį įvertinimą (vidurkį ir medianą)

    /**
     * @brief Atvaizduoja studento duomenis.
     * @param os Išvesties srautas.
     */
    void atvaizduoti(std::ostream& os) const;// Atvaizduoja studento duomenis

    /**
     * @brief Draugiškas operatorius, kuris įveda studentą iš srauto.
     * @param is Įvesties srautas.
     * @param stud Studentas.
     * @return Įvesties srautas su studento duomenimis.
     */
    friend std::istream& operator>>(std::istream& is, Stud& stud);// Draugiškas operatorius įvedimui

    /**
     * @brief Draugiškas operatorius, kuris išveda studentą į srautą.
     * @param os Išvesties srautas.
     * @param stud Studentas.
     * @return Išvesties srautas su studento duomenimis.
     */
    friend std::ostream& operator<<(std::ostream& os, const Stud& stud);// Draugiškas operatorius išvedimui
};

/**
 * @brief Nuskaityti studentus iš failo ir įrašyti juos į vektorių.
 * @param Vec1 Vektorius, kuriame bus saugomi studentai.
 * @param failoVardas Failo pavadinimas.
 */
void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas);// Nuskaityti studentus iš failo į vektorių

/**
 * @brief Nuskaityti studentus iš failo ir įrašyti juos į sąrašą.
 * @param Vec1 Sąrašas, kuriame bus saugomi studentai.
 * @param failoVardas Failo pavadinimas.
 */
void nuskaitytiIsfailo(std::list<Stud>& list1, const std::string& failoVardas);// Nuskaityti studentus iš failo į sąrašą

/**
 * @brief Sugeneruoti studentų failą su atsitiktiniais duomenimis.
 * @param fileName Failo pavadinimas.
 * @param studentCount Kiek studentų bus sugeneruota.
 * @param ndCount Kiek namų darbų bus sugeneruota kiekvienam studentui.
 */
void sugeneruotiStudentoFaila(const std::string& fileName, int studentCount, int ndCount); // Sugeneruoti studentų failą su atsitiktiniais duomenimis

/**
 * @brief Įrašyti "vargsiukus" į failą iš vektoriaus.
 * @param vargsiukai Vargsiukai (studentai).
 * @param failoPavadinimas Failo pavadinimas.
 */
void irasytiVargsiukusVector(const std::vector<Stud>& vargsiukai, const std::string& failoPavadinimas); // Įrašyti "vargsiukus" į failą iš vektoriaus

/**
 * @brief Įrašyti "vargsiukus" į failą iš sąrašo.
 * @param vargsiukai Vargsiukai (studentai).
 * @param failoPavadinimas Failo pavadinimas.
 */
void irasytivargsiukusList(const std::list<Stud>& vargsiukai, const std::string& failoPavadinimas); // Įrašyti "vargsiukus" į failą iš sąrašo

/**
 * @brief Įrašyti "kietiakiai" į failą iš sąrašo.
 * @param kietiakiai Kietiakiai (studentai).
 * @param failoPavadinimas Failo pavadinimas.
 */
void irasytikietiakiaiList(const std::list<Stud>& kietiakiai, const std::string& failoPavadinimas); // Įrašyti "kietiakiai" į failą iš sąrašo

/**
 * @brief Įrašyti "kietiakiai" į failą iš vektoriaus.
 * @param kietiakiai Kietiakiai (studentai).
 * @param failoPavadinimas Failo pavadinimas.
 */
void irasytiKietiakiaiVector(const std::vector<Stud>& kietiakiai, const std::string& failoPavadinimas);// Įrašyti "kietiakiai" į failą iš vektoriaus

#endif // ZMOGUS_H_INCLUDED;
