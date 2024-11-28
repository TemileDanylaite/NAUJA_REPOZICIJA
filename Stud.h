#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

class Stud {
private:
	std::string vardas, pavarde;
	std::vector<int> ND;
	double egz;
	double GalutinisVid;
	double GalutinisMed;

public:
	Stud(std::string v = "", std::string p = "", std::vector<int> nd = {}, double e = 0.0)
		:vardas(v), pavarde(p), ND(nd), egz(e), GalutinisVid(0), GalutinisMed(0) {
		
	}

	Stud(const Stud& other) noexcept
		:vardas (other.vardas),
		pavarde (other.pavarde),
		ND (other.ND),
		egz (other.egz),
		GalutinisVid(other.GalutinisVid),
		GalutinisMed(other.GalutinisMed) {
		cout << "Kopijavimo konstruktorius: " << vardas << " " << pavarde << endl;
	}
		

	Stud& operator = (const Stud& other) noexcept{
		if (this == &other) return *this;
		vardas = other.vardas;
		pavarde = other.pavarde;
		ND = other.ND;
		egz = other.egz;
		GalutinisVid = other.GalutinisVid;
		GalutinisMed = other.GalutinisMed;

		cout << "Priskyrimo operatorius: " << vardas << " " << pavarde << endl;
		return *this;
	}


	void addND(int nd) {
		ND.push_back(nd);
	}

	void clearData() {
		vardas = "";
		pavarde = "";
		ND.clear();
		egz = 0.0;
		GalutinisVid = 0.0;
		GalutinisMed = 0.0;
	}
	

	std::string getVardas() const { return vardas; }
	std::string getPavarde() const { return pavarde; }
	std::vector<int> getND() const { return ND; }
	double getEgz() const { return egz; }
	double getGalutinisVid() const { return GalutinisVid; }
	double getGalutinisMed() const { return GalutinisMed; }

	void setVardas(const std::string& v) { vardas = v; }
	void setPavarde(const std::string& p) { pavarde = p; }
	void setND(const std::vector<int>& nd) { ND = nd; }
	void setEgz(double e) { egz = e; }

	void apskaiciuotiGalutinius();

	~Stud() {
		
		clearData();
	}


	friend std::istream& operator>>(std::istream& is, Stud& stud);
	friend std::ostream& operator<<(std::ostream& os, const Stud& stud);



};

//void ived(Stud& Lok);
//void output(const Stud& Lok);
//void val(Stud& Lok);

void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas);
void nuskaitytiIsfailo(std::list<Stud>& Vec1, const std::string& failoVardas);
void sugeneruotiStudentoFaila(const string& fileName, int studentCount, int ndCount);
void irasytiVargsiukusVector(const vector<Stud>& vargsiukai, const string& failoPavadinimas);
void irasytivargsiukusList(const list<Stud>& vargsiukai, const string& failoPavadinimas);
void irasytikietiakiaiList(const list<Stud>& kietiakiai, const string& failoPavadinimas);
void irasytiKietiakiaiVector(const vector<Stud>& kietiakiai, const string& failoPavadinimas);

#endif STUD_H_INCLUDED