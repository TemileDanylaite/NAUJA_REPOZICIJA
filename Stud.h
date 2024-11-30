#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED
#include "Mylib.h"

class zmogus {
private:
	std::string vardas, pavarde;

public:
	zmogus(std::string v = "", std::string p = "")
		: vardas(v), pavarde(p) {}
	
	virtual ~zmogus() = default;

	std::string getVardas() const { return vardas; }
	std::string getPavarde() const { return pavarde; }

	virtual void setVardas(const std::string& v) { vardas = v; }
	virtual void setPavarde(const std::string& p) { vardas = p; }

	virtual void atvaizduoti() const = 0;
};

class Stud : public zmogus{
private:
	std::vector<int> ND;
	double egz;
	double GalutinisVid;
	double GalutinisMed;

public:
	Stud(std::string v = "", std::string p = "", std::vector<int> nd = {}, double e = 0.0)
		:zmogus(v,p), ND(nd), egz(e), GalutinisVid(0), GalutinisMed(0) {
		
	}

	Stud(const Stud& other) noexcept
		: zmogus(other.getVardas(), other.getPavarde()),
		ND (other.ND),
		egz (other.egz),
		GalutinisVid(other.GalutinisVid),
		GalutinisMed(other.GalutinisMed) {
		//cout << "Kopijavimo konstruktorius: " << vardas << " " << pavarde << endl;
	}
		

	Stud& operator = (const Stud& other) noexcept{
		if (this == &other) return *this;
		zmogus::operator = (other);
		ND = other.ND;
		egz = other.egz;
		GalutinisVid = other.GalutinisVid;
		GalutinisMed = other.GalutinisMed;

		//cout << "Priskyrimo operatorius: " << vardas << " " << pavarde << endl;
		return *this;
	}
	void addND(int nd) {
		ND.push_back(nd);
	}
	

	~Stud() {clearData();}

	void clearData() {
		ND.clear();
		egz = 0.0;
		GalutinisVid = 0.0;
		GalutinisMed = 0.0;
	}
	

	
	std::vector<int> getND() const { return ND; }
	double getEgz() const { return egz; }
	double getGalutinisVid() const { return GalutinisVid; }
	double getGalutinisMed() const { return GalutinisMed; }
	
	void setND(const std::vector<int>& nd) { ND = nd; }
	void setEgz(double e) { egz = e; }

	void apskaiciuotiGalutinius();

	void atvaizduoti() const override ;


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

#endif ZMOGUS_H_INCLUDED;