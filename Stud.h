#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

struct Stud {
	std::string vardas, pavarde;
	std::vector<int> ND;
	double egz;
	double GalutinisVid;
	double GalutinisMed;

};

void ived(Stud& Lok);
void output(const Stud& Lok);
void val(Stud& Lok);

void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas);
void nuskaitytiIsfailo(std::list<Stud>& Vec1, const std::string& failoVardas);
void sugeneruotiStudentoFaila(const string& fileName, int studentCount, int ndCount);
void apskaiciuotiGalutinius(Stud& Lok);
void irasytiVargsiukusVector(const vector<Stud>& vargsiukai, const string& failoPavadinimas);
void irasytivargsiukusList(const list<Stud>& vargsiukai, const string& failoPavadinimas);

#endif STUD_H_INCLUDED