#pragma once


#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stddef.h>

extern const int MAX_HEALTH;
extern const int MAX_GOLD;
extern bool PRVI_POSJET_PIVNICI;
extern bool PRVI_POSJET_KONOBARICA;

typedef struct Oruzje {
	int id;
	char naziv[30];
	int jacina;
	int cijena;
	bool validno;
} Oruzje;

Oruzje oruzje[6];
Oruzje mojeOruzje[3];

typedef struct {
	int rbr;
	int health;
} Neprijatelj;

extern Neprijatelj NeprijateljPrvi;
extern Neprijatelj NeprijateljDrugi;
extern Neprijatelj NeprijateljTreci;

void Uvod();
void OcistiUnos();
void NastavakPoruka();
void StariCovjek();
void PorukaOruzarnica();
void Vila();
void Podrum();
void OstatakVile();
void Predvorje();
void Selo();
int StanjeRacuna();
void AzurirajStanjeRacuna(int brojZlatnika);
int SetBrojZlatnika();
void AzurirajHealth(int health);
int LinearnoPretrazivanje(int niz[], int velicina, int trazeniElement);
int DohvatiHealth();
void OruzarnicaMain();
void PorukaOruzarnica();

void PrikaziOruzje();
void DodajOruzje(Oruzje oruzje);
void DodajOruzjePoId(int oruzjeId);
Oruzje DohvatiOruzjePoId(int oruzjeId);
bool OruzjePostojiUTorbi(int oruzjeId);

//quick sort funkcije
void QuickSort(Oruzje array[], int low, int high);
int Partition(Oruzje array[], int low, int high);
void Swap(Oruzje* a, Oruzje* b);
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif