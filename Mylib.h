#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

/** @file Mylib.h
* @brief Ši biblioteka apima pagrindines C++ standartines bibliotekas ir prideda aliasus.
*
 *Ši antraštė suteikia naudotojui prieigą prie populiarių C++ funkcionalumų, tokių kaip įvesties/išvesties srautai, konteineriai (pvz., std::vector), atsitiktinių skaičių generavimas ir failų įvedimas/istrynimas.
 */

#include <iostream>   // Apima įvesties/išvesties funkcionalumus. 
#include <iomanip>    // Apima funkcijas, susijusias su formatavimu (pvz., nustatyti skaitmenų tikslumą).
#include <string>     // Apima klasę std::string ir funkcijas dirbti su tekstu.
#include <vector>     // Apima std::vector konteinerį (dinamiškai valdomus masyvus).
#include <algorithm>  // Apima algoritmus, tokius kaip sort, find, ir kt.
#include <random>     // Apima atsitiktinių skaičių generavimo funkcijas.
#include <fstream>    // Apima failų įvesties/išvesties funkcijas.
#include <sstream>    // Apima srautų klasę, skirtą dirbti su eilutėmis.
#include <chrono>     // Apima laikrodžio funkcijas ir laiką.
#include <list>       // Apima std::list konteinerį (dviašius sąrašus).

 // Pagrindinių funkcijų naudojimo paprastinimas:
using std::endl;              // Leidžia naudoti std::endl.
using std::cout;              // Leidžia naudoti std::cout (standartinis išvesties srautas).
using std::cin;               // Leidžia naudoti std::cin (standartinis įvesties srautas).
using std::left;              // Leidžia naudoti std::left (kairiojo lygiavimo manipuliatorius).
using std::right;             // Leidžia naudoti std::right (dešiniojo lygiavimo manipuliatorius).
using std::setw;              // Leidžia naudoti std::setw (išvesties pločio nustatymas).
using std::setprecision;      // Leidžia naudoti std::setprecision (tikslumo nustatymas skaičiams).
using std::fixed;             // Leidžia naudoti std::fixed (formatavimas, kad skaičiai būtų rodomi fiksuotu taškų tikslumu).
using std::string;            // Leidžia naudoti std::string (standartinė eilutės klasė).
using std::vector;            // Leidžia naudoti std::vector (dinaminis masyvas).
using std::random_device;     // Leidžia naudoti std::random_device (atsitiktinių skaičių generatorius).
using std::mt19937;           // Leidžia naudoti std::mt19937 (atsitiktinių skaičių generatorius).
using std::uniform_int_distribution; // Leidžia naudoti std::uniform_int_distribution (atsitiktinių sveikųjų skaičių paskirstymas).
using std::fstream;           // Leidžia naudoti std::fstream (failų srautai).
using std::sort;              // Leidžia naudoti std::sort (rūšiavimo funkcija).
using std::runtime_error;     // Leidžia naudoti std::runtime_error (klaidos tipas).
using std::ofstream;          // Leidžia naudoti std::ofstream (išvesties failo srautas).
using std::list;              // Leidžia naudoti std::list (dviašiai sąrašai).
using std::remove_if;         // Leidžia naudoti std::remove_if (elementų pašalinimas pagal sąlygą).
using std::partition;         // Leidžia naudoti std::partition (konteinerių dalijimas pagal sąlygą).
using std::stable_partition;  // Leidžia naudoti std::stable_partition (stabilus konteinerių dalijimas).


#endif // MYLIB_H_INCLUDED