#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

/**
 * @file Mylib.h
 * @brief Ši biblioteka apima pagrindines C++ standartines bibliotekas ir prideda aliasus.
 *
 * Ši antraštė suteikia naudotojui prieigą prie populiarių C++ funkcionalumų, tokių kaip įvesties/išvesties srautai, konteineriai (pvz., std::vector), atsitiktinių skaičių generavimas ir failų įvedimas/istrynimas.
 *
 * Tai supaprastina kodo rašymą ir leidžia naudoti dažnai pasikartojančias funkcijas be papildomų kvalifikatorių.
 */


#include <iostream>   /**< Apima įvesties/išvesties funkcionalumus. */
#include <iomanip>    /**< Apima funkcijas, susijusias su formatavimu (pvz., nustatyti skaitmenų tikslumą). */
#include <string>     /**< Apima klasę std::string ir funkcijas dirbti su tekstu. */
#include <vector>     /**< Apima std::vector konteinerį (dinamiškai valdomus masyvus). */
#include <algorithm>  /**< Apima algoritmus, tokius kaip sort, find, ir kt. */
#include <random>     /**< Apima atsitiktinių skaičių generavimo funkcijas. */
#include <fstream>    /**< Apima failų įvesties/išvesties funkcijas. */
#include <sstream>    /**< Apima srautų klasę, skirtą dirbti su eilutėmis. */
#include <chrono>     /**< Apima laikrodžio funkcijas ir laiką. */
#include <list>       /**< Apima std::list konteinerį (dviašius sąrašus). */

 //Pagrindinių funkcijų naudojimo paprastinimas:
using std::endl;              /**< Aliasas į std::endl. */
using std::cout;              /**< Aliasas į std::cout (standartinis išvesties srautas). */
using std::cin;               /**< Aliasas į std::cin (standartinis įvesties srautas). */
using std::left;              /**< Aliasas į std::left (kairiojo lygiavimo manipuliatorius). */
using std::right;             /**< Aliasas į std::right (dešiniojo lygiavimo manipuliatorius). */
using std::setw;              /**< Aliasas į std::setw (išvesties pločio nustatymas). */
using std::setprecision;      /**< Aliasas į std::setprecision (tikslumo nustatymas skaičiams). */
using std::fixed;             /**< Aliasas į std::fixed (formatavimas, kad skaičiai būtų rodomi fiksuotu taškų tikslumu). */
using std::string;            /**< Aliasas į std::string (standartinė eilutės klasė). */
using std::vector;            /**< Aliasas į std::vector (dinaminis masyvas). */
using std::random_device;     /**< Aliasas į std::random_device (atsitiktinių skaičių generatorius). */
using std::mt19937;           /**< Aliasas į std::mt19937 (atsitiktinių skaičių generatorius). */
using std::uniform_int_distribution; /**< Aliasas į std::uniform_int_distribution (atsitiktinių sveikųjų skaičių paskirstymas). */
using std::fstream;           /**< Aliasas į std::fstream (failų srautai). */
using std::sort;              /**< Aliasas į std::sort (rūšiavimo funkcija). */
using std::runtime_error;     /**< Aliasas į std::runtime_error (klaidos tipas). */
using std::ofstream;          /**< Aliasas į std::ofstream (išvesties failo srautas). */
using std::list;              /**< Aliasas į std::list (dviašiai sąrašai). */
using std::remove_if;         /**< Aliasas į std::remove_if (elementų pašalinimas pagal sąlygą). */
using std::partition;         /**< Aliasas į std::partition (konteinerių dalijimas pagal sąlygą). */
using std::stable_partition;  /**< Aliasas į std::stable_partition (stabilus konteinerių dalijimas). */


#endif // MYLIB_H_INCLUDED