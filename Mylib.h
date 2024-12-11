#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

/**
 * @file Mylib.h
 * @brief Ši biblioteka apima pagrindines C++ standartines bibliotekas ir prideda aliasus.
 *
 * Ši antrašt? suteikia naudotojui prieig? prie populiari? C++ funkcionalum?, toki? kaip ?vesties/išvesties srautai, konteineriai (pvz., std::vector), atsitiktini? skai?i? generavimas ir fail? ?vedimas/istrynimas.
 *
 * Tai supaprastina kodo rašym? ir leidžia naudoti dažnai pasikartojan?ias funkcijas be papildom? kvalifikatori?.
 */

#include <iostream>   /**< Apima ?vesties/išvesties funkcionalumus. */
#include <iomanip>    /**< Apima funkcijas, susijusias su formatavimu (pvz., nustatyti skaitmen? tikslum?). */
#include <string>     /**< Apima klas? std::string ir funkcijas dirbti su tekstu. */
#include <vector>     /**< Apima std::vector konteiner? (dinamiškai valdomus masyvus). */
#include <algorithm>  /**< Apima algoritmus, tokius kaip sort, find, ir kt. */
#include <random>     /**< Apima atsitiktini? skai?i? generavimo funkcijas. */
#include <fstream>    /**< Apima fail? ?vesties/išvesties funkcijas. */
#include <sstream>    /**< Apima sraut? klas?, skirt? dirbti su eilut?mis. */
#include <chrono>     /**< Apima laikrodžio funkcijas ir laik?. */
#include <list>       /**< Apima std::list konteiner? (dviašius s?rašus). */

  //Pagrindini? funkcij? naudojimo paprastinimas:
using std::endl;              /**< Aliasas ? std::endl. */
using std::cout;              /**< Aliasas ? std::cout (standartinis išvesties srautas). */
using std::cin;               /**< Aliasas ? std::cin (standartinis ?vesties srautas). */
using std::left;              /**< Aliasas ? std::left (kairiojo lygiavimo manipuliatorius). */
using std::right;             /**< Aliasas ? std::right (dešiniojo lygiavimo manipuliatorius). */
using std::setw;              /**< Aliasas ? std::setw (išvesties plo?io nustatymas). */
using std::setprecision;      /**< Aliasas ? std::setprecision (tikslumo nustatymas skai?iams). */
using std::fixed;             /**< Aliasas ? std::fixed (formatavimas, kad skai?iai b?t? rodomi fiksuotu tašk? tikslumu). */
using std::string;            /**< Aliasas ? std::string (standartin? eilut?s klas?). */
using std::vector;            /**< Aliasas ? std::vector (dinaminis masyvas). */
using std::random_device;     /**< Aliasas ? std::random_device (atsitiktini? skai?i? generatorius). */
using std::mt19937;           /**< Aliasas ? std::mt19937 (atsitiktini? skai?i? generatorius). */
using std::uniform_int_distribution; /**< Aliasas ? std::uniform_int_distribution (atsitiktini? sveik?j? skai?i? paskirstymas). */
using std::fstream;           /**< Aliasas ? std::fstream (fail? srautai). */
using std::sort;              /**< Aliasas ? std::sort (r?šiavimo funkcija). */
using std::runtime_error;     /**< Aliasas ? std::runtime_error (klaidos tipas). */
using std::ofstream;          /**< Aliasas ? std::ofstream (išvesties failo srautas). */
using std::list;              /**< Aliasas ? std::list (dviašiai s?rašai). */
using std::remove_if;         /**< Aliasas ? std::remove_if (element? pašalinimas pagal s?lyg?). */
using std::partition;         /**< Aliasas ? std::partition (konteineri? dalijimas pagal s?lyg?). */
using std::stable_partition;  /**< Aliasas ? std::stable_partition (stabilus konteineri? dalijimas). */

#endif // MYLIB_H_INCLUDED








