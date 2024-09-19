#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h> 
#include "Katakombe.h"
#include "Header.h"

/*1, 15, 4 */
/*1, 15, 8 */
/*1, 15, 12 */
/*1, 25, 20 */


void Katakombe() {
	system("cls");
	printf("\n=========================\n");
	printf("Kad si se provukao kroz mracni i vlazni prolaz ulazis u tamnu sobu.\n");
	printf("Ispunjava te osjecaj jeze.\n");
	printf("Soba se cini isklesana iz kamena, kao da je drevna.\n");
	printf("Sto god se nalazilo ovdje dolje dugo nije izaslo van.\n");
	printf("Ispred tebe je prolaz. Hoces li uci unutra?\n");
	printf("=========================\n");

	while (1) {
		int odabirKatakombe;
		printf("\n=========================\n");
		printf("===== 1. PRVI PROLAZ ====\n");
		printf("===== 2. POVRATAK NAZAD =\n");
		printf("=========================\n");
		if (scanf("%d", &odabirKatakombe) != 1) {
			printf("Vas unos nije broj! Molim vas ponovite odabir.");
			OcistiUnos();
		}
		else {
			switch (odabirKatakombe) {
			case 1:
				ProlazJedanSobaJedan();
				break;
			case 2:
				Predvorje();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}

void BorbaNeprijateljPrvi() {
	int tvojHealth = DohvatiHealth();
	int odabirOruzje;
	bool sljedeciDioKatakombi = false;

	if (NeprijateljPrvi.health < 0) {
		int odabirPrviProlaz;
		printf("\n=========================\n");
		prinf("===== VEC SI POBJEDIO NEPRIJATELJA ==\n");
		printf("===== 1. NASTAVI DALJE ==\n");
		printf("===== 2. POVRATAK U SELO =\n");
		printf("=========================\n");
		if (scanf("%d", &odabirPrviProlaz) != 1) {
			printf("Vas unos nije broj! Molim vas ponovite odabir.");
			OcistiUnos();
		}
		else {
			switch (odabirPrviProlaz) {
			case 1:
				ProlazDvaSobaJedan();
				break;
			case 2:
				Selo();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}

	if(NeprijateljPrvi.health > 0 && tvojHealth > 0) {
		bool rezultat = PotezNeprijatelj(1, 15, 4);

		if (rezultat) {
			printf("Neprijatelj vas odjednom napada. Vrijeme je za borbu!\n");
			printf("Izgubili ste 10 hp-a!\n");
			AzurirajHealth(-10);
			tvojHealth = DohvatiHealth();
		}
		else {
			printf("Neprijatelj vas odjednom napada. Vrijeme je za borbu!\n");
			printf("Neprijatelj je promasio!\n");
		}

		PrikaziOruzje();
		while (true) {
			tvojHealth = DohvatiHealth();

			if (NeprijateljPrvi.health > 0 && tvojHealth <= 0) {
				printf("\nMrtav si!!\n");
				Sleep(4500);
				exit(0);
			}
			else if (NeprijateljPrvi.health <= 0 && tvojHealth > 0) {
				printf("\nPobijedili ste neprijatelja!!\n");
				int stanjeRacuna = StanjeRacuna();
				stanjeRacuna += 10;
				AzurirajStanjeRacuna(stanjeRacuna);
				sljedeciDioKatakombi = true;
				Sleep(4500);
				break;
			}

			printf("Odaberite oruzje po broju:\n");
			if (scanf("%d", &odabirOruzje) != 1) {
				printf("Vas unos nije broj! Molim Vas ponovite izbor.");
				OcistiUnos();
			}
			else
			{
				bool imaOruzje = OruzjePostojiUTorbi(odabirOruzje);
				if (!imaOruzje) {
					printf("Nemas oruzje. Preporucio bih ti da pobjegnes!");
				}
				int akcija;
				int brojPoteza = 0;
				while (NeprijateljPrvi.health > 0 && tvojHealth > 0) {
					if (brojPoteza % 2 == 0) {
						printf("\n=========================\n");
						printf("Odaberi akciju:\n");
						printf("1. Napadni.\n");
						printf("2. Pobjegni.\n");
						printf("=========================\n");
						if (scanf("%d", &akcija) != 1) {
							printf("Vas unos nije broj! Molim Vas ponovite izbor.");
							OcistiUnos();
						}
						else {
							switch (akcija)
							{
							case 1:
								printf("E sada bijem ja!!!\n");
								if (imaOruzje) {
									bool upjesanUdarac = PotezJa(1, 15, 4);
									if (upjesanUdarac) {
										Oruzje mojeOruzje = DohvatiOruzjePoId(odabirOruzje);
										NeprijateljPrvi.health -= mojeOruzje.jacina;
										printf("Pogodili ste, neprijatelju je ostalo %dHP-a\n", NeprijateljPrvi.health);
									}
									else {
										printf("Fulao si ko kramaric u 95' protiv albanije...\n");
									}
								}
								else {
									printf("E jebiga sad, nemam s cim da bijem.\n");
								}
								break;
							case 2:
								Selo();
								break;
							default:
								printf("Vas unos nije tocan! Molim Vas ponovite izbor.");
								break;
							}
						}
					}
					else {
						printf("Neprijatelj napada!\n");
						if (PotezNeprijatelj(1, 15, 4)) {
							printf("Izgubili ste 10 hp-a!\n");
							AzurirajHealth(-10);
							tvojHealth = DohvatiHealth();
						}
						else {
							printf("Neprijatelj je promasio!\n");
						}
					}
					brojPoteza++;
				}
			}
		}

		if (sljedeciDioKatakombi) {
			int odabirPrviProlaz;
			printf("\n=========================\n");
			printf("===== 1. NASTAVI DALJE ==\n");
			printf("===== 2. POVRATAK U SELO =\n");
			printf("=========================\n");
			if (scanf("%d", &odabirPrviProlaz) != 1) {
				printf("Vas unos nije broj! Molim vas ponovite odabir.");
				OcistiUnos();
			}
			else {
				switch (odabirPrviProlaz) {
				case 1:
					ProlazDvaSobaJedan();
					break;
				case 2:
					Selo();
					break;
				default:
					printf("GRESKA! Krivo ste odabrali! Molim vas ponovite izbor.");
					break;
				}
			}
			NastavakPoruka();
			getchar();
		}
	}
}


void ProlazJedanSobaJedan() {
	system("cls");
	printf("\n=========================\n");
	printf("Prosao si kroz prvi prolaz.\n");
	printf("Kada si izasao iz prolaza docekala te mracna soba.\n");
	printf("Kada su ti se oci priviknule na nedostatak svjetlosti uspio si opaziti u kutu sobe nesto.\n");
	printf("Problem je sto je i tebe ta stvar primjetila!\n");
	printf("Priblizava ti se nesto sto je skoro nemoguce opisati, ali ipak zauvijek ces zapamtiti taj prizor.\n");
	printf("Cini se da ces se morati boriti s tim cudovistem.\n");
	printf("Nadam se da si ponio nekakvo oruzje.\n");
	printf("=========================\n");
	Sleep(3000);
	BorbaNeprijateljPrvi();
}

void BorbaNeprijateljDrugi() {
	int tvojHealth = DohvatiHealth();
	int odabirOruzje;
	bool sljedeciDioKatakombi = false;
	if (NeprijateljPrvi.health < 0) {
			int odabirPrviProlaz;
			printf("\n=========================\n");
			prinf("===== VEC SI POBJEDIO NEPRIJATELJA ==\n");
			printf("===== 1. NASTAVI DALJE ==\n");
			printf("===== 2. POVRATAK U SELO =\n");
			printf("=========================\n");
			if (scanf("%d", &odabirPrviProlaz) != 1) {
				printf("Vas unos nije broj! Molim vas ponovite odabir.");
				OcistiUnos();
			}
			else {
				switch (odabirPrviProlaz) {
				case 1:
					ProlazDvaSobaJedan();
					break;
				case 2:
					Selo();
					break;
				default:
					printf("GRESKA! Krivo ste odabrali! Molim vas ponovite izbor.");
					break;
				}
			}
			NastavakPoruka();
			getchar();
		}

	if (NeprijateljDrugi.health > 0 && tvojHealth > 0) {
		bool rezultat = PotezNeprijatelj(1, 15, 8);

		if (rezultat) {
			printf("Neprijatelj vas odjednom napada. Vrijeme je za borbu!\n");
			printf("Izgubili ste 15 hp-a!\n");
			AzurirajHealth(-15);
			tvojHealth = DohvatiHealth();
		}
		else {
			printf("Neprijatelj vas odjednom napada. Vrijeme je za borbu!\n");
			printf("Neprijatelj je promasio!\n");
		}

		PrikaziOruzje();
		while (true) {
			tvojHealth = DohvatiHealth();

			if (NeprijateljDrugi.health > 0 && tvojHealth <= 0) {
				printf("\nMrtav si!!\n");
				Sleep(4500);
				exit(0);
			}
			else if (NeprijateljDrugi.health <= 0 && tvojHealth > 0) {
				printf("\nPobijedili ste neprijatelja!!\n");
				int stanjeRacuna = StanjeRacuna();
				stanjeRacuna += 15;
				AzurirajStanjeRacuna(stanjeRacuna);
				sljedeciDioKatakombi = true;
				Sleep(4500);
				break;
			}

			printf("Odaberite oruzje po broju:\n");
			if (scanf("%d", &odabirOruzje) != 1) {
				printf("Vas unos nije broj! Molim Vas ponovite izbor.");
				OcistiUnos();
			}
			else
			{
				bool imaOruzje = OruzjePostojiUTorbi(odabirOruzje);
				if (!imaOruzje) {
					printf("Nemas oruzje. Preporucio bih ti da pobjegnes!");
				}
				int akcija;
				int brojPoteza = 0;
				while (NeprijateljDrugi.health > 0 && tvojHealth > 0) {
					if (brojPoteza % 2 == 0) {
						printf("\n=========================\n");
						printf("Odaberi akciju:\n");
						printf("1. Napadni.\n");
						printf("2. Pobjegni.\n");
						printf("=========================\n");
						if (scanf("%d", &akcija) != 1) {
							printf("Vas unos nije broj! Molim Vas ponovite izbor.");
							OcistiUnos();
						}
						else {
							switch (akcija)
							{
							case 1:
								printf("E sada bijem ja!!!");
								if (imaOruzje) {
									bool upjesanUdarac = PotezJa(1, 15, 8);
									if (upjesanUdarac) {
										Oruzje mojeOruzje = DohvatiOruzjePoId(odabirOruzje);
										NeprijateljDrugi.health -= mojeOruzje.jacina;
										printf("Pogodili ste, neprijatelju je ostalo %dHP-a", NeprijateljDrugi.health);
									}
									else {
										printf("Fulao si ko Lukaku 2022 protiv nas...");
									}
								}
								else {
									printf("E jebiga sad, nemam s cim da bijem.\n");
								}
								break;
							case 2:
								Selo();
								break;
							default:
								printf("Vas unos nije tocan! Molim Vas ponovite izbor.");
								break;
							}
						}
					}
					else {
						printf("Neprijatelj napada!\n");
						if (PotezNeprijatelj(1, 15, 8)) {
							printf("Izgubili ste 15 hp-a!\n");
							AzurirajHealth(-15);
							tvojHealth = DohvatiHealth();
						}
						else {
							printf("Neprijatelj je promasio!\n");
						}
					}
					brojPoteza++;
				}
			}
		}

		if (sljedeciDioKatakombi) {
			int odabirPrviProlaz;
			printf("\n=========================\n");
			printf("===== 1. NASTAVI DALJE ==\n");
			printf("===== 2. POVRATAK U SELO =\n");
			printf("=========================\n");
			if (scanf("%d", &odabirPrviProlaz) != 1) {
				printf("Vas unos nije broj! Molim vas ponovite odabir.");
				OcistiUnos();
			}
			else {
				switch (odabirPrviProlaz) {
				case 1:
					ProlazTriSobaJedan();
					break;
				case 2:
					Selo();
					break;
				default:
					printf("GRESKA! Krivo ste odabrali! Molim vas ponovite izbor.");
					break;
				}
			}
			NastavakPoruka();
			getchar();
		}
	}
}

void ProlazDvaSobaJedan() {
	system("cls");
	printf("\n=========================\n");
	printf("Prezivio si prvog neprijatelja i nastavio dalje.\n");
	printf("U sljedecoj sobi takoder je bilo mracno.\n");
	printf("Ovaj putu znao si sto te ocekuje, ali neprijatelj te docekuje u sredini sobe\n");
	printf("Priblizava ti se nesto sto izgleda kao covjek. Slicno kao seljani, ali sa puno ocitijim zivotinjskim djelovima.\n");
	printf("Vrijeme je za jos jednu borbu!\n");
	printf("=========================\n");
	Sleep(3000);
	BorbaNeprijateljDrugi();
}

void BorbaNeprijateljTreci() {
	int tvojHealth = DohvatiHealth();
	int odabirOruzje;
	bool sljedeciDioKatakombi = false;
	if (NeprijateljTreci.health > 0 && tvojHealth > 0) {
		bool rezultat = PotezNeprijatelj(1, 15, 10);

		if (rezultat) {
			printf("Neprijatelj vas odjednom napada. Vrijeme je za borbu!\n");
			printf("Ne znam kako te uspio iznenadit, mislim zadnja dva cudovista su te prva napala...\n");
			printf("Izgubili ste 20 hp-a!\n");
			AzurirajHealth(-20);
			tvojHealth = DohvatiHealth();
		}
		else {
			printf("Neprijatelj vas odjednom napada. Vrijeme je za borbu!\n");
			printf("Neprijatelj je promasio!\n");
		}

		PrikaziOruzje();
		while (true) {
			tvojHealth = DohvatiHealth();

			if (NeprijateljTreci.health > 0 && tvojHealth <= 0) {
				printf("\nMrtav si!!\n");
				Sleep(4500);
				exit(0);
			}
			else if (NeprijateljTreci.health <= 0 && tvojHealth > 0) {
				printf("\nPobijedili ste neprijatelja!!\n");
				sljedeciDioKatakombi = true;
				Sleep(4500);
				break;
			}

			printf("Odaberite oruzje po broju:\n");
			if (scanf("%d", &odabirOruzje) != 1) {
				printf("Vas unos nije broj! Molim Vas ponovite izbor.");
				OcistiUnos();
			}
			else
			{
				bool imaOruzje = OruzjePostojiUTorbi(odabirOruzje);
				if (!imaOruzje) {
					printf("Nemas oruzje. Preporucio bih ti da pobjegnes!");
				}
				int akcija;
				int brojPoteza = 0;
				while (NeprijateljTreci.health > 0 && tvojHealth > 0) {
					if (brojPoteza % 2 == 0) {
						printf("\n=========================\n");
						printf("Odaberi akciju:\n");
						printf("1. Napadni.\n");
						printf("2. Pobjegni.\n");
						printf("=========================\n");
						if (scanf("%d", &akcija) != 1) {
							printf("Vas unos nije broj! Molim Vas ponovite izbor.");
							OcistiUnos();
						}
						else {
							switch (akcija)
							{
							case 1:
								printf("E sada bijem ja!!!\n");
								if (imaOruzje) {
									bool upjesanUdarac = PotezJa(1, 15, 8);
									if (upjesanUdarac) {
										Oruzje mojeOruzje = DohvatiOruzjePoId(odabirOruzje);
										NeprijateljTreci.health -= mojeOruzje.jacina;
										printf("Pogodili ste, neprijatelju je ostalo %dHP-a", NeprijateljTreci.health);
									}
									else {
										printf("Fulao si ko Brazilci na penalima...");
									}
								}
								else {
									printf("E jebiga sad, nemam s cim da bijem.\n");
								}
								break;
							case 2:
								Selo();
								break;
							default:
								printf("Vas unos nije tocan! Molim Vas ponovite izbor.");
								break;
							}
						}
					}
					else {
						printf("\nNeprijatelj napada!\n");
						if (PotezNeprijatelj(1, 15, 10)) {
							printf("Izgubili ste 20 hp-a!\n");
							AzurirajHealth(-20);
							tvojHealth = DohvatiHealth();
						}
						else {
							printf("Neprijatelj je promasio!\n");
						}
					}
					brojPoteza++;
				}
			}
		}

		if (sljedeciDioKatakombi) {
			FunkcijaPobjeda();
		}
	}
}

void ProlazTriSobaJedan() {
	system("cls");
	printf("\n=========================\n");
	printf("Prezivio si drugog neprijatelja i nastavio dalje.\n");
	printf("Ovaj puta si ostao iznenaden. U ovoj sobi gori nekoliko svijeca.\n");
	printf("Pod slabim svijetlom ispred vrata koje vode u zadnju sobu docekuje te cudoviste.\n");
	printf("Izgleda slicno kao jelen, ali stoji na zadnjim nogama noge. Te takoder ima ljudske ruke.\n");
	printf("Ovako nesta nikad nisi vidio, nit si mogao ocekivati. Cini se da ce ovo biti najteza borba dosada!\n");
	printf("Ipak moras znati sto slijedi dalje. Ovaj puta ti prilazis neprijatelju.");
	printf("=========================\n");
	Sleep(3000);
	BorbaNeprijateljTreci();
}

static void FunkcijaPobjeda() {
	printf("\n=========================\n");
	printf("Pobjedivsi uzasavajuce bice pronalazis svoga oca iza njega.\n");
	printf("Unatoc tome sto je vidno oslabljen idalje moze pricati.\n");
	printf("No, mozda je ipak bolje ostaviti masti to sto se dogodilo ovih proteklih nekoliko mjeseci u ovome selu...\n");
	printf("\=====      KRAJ      =====\n");
	Sleep(18000);
	exit(0);
}

static bool PotezNeprijatelj(int dgNeprijatelj, int ggNeprijatelj, int jacinaNeprijatelja)
{
	int borbaBroj = dgNeprijatelj + (float)rand() / RAND_MAX * (ggNeprijatelj - dgNeprijatelj);

	if (borbaBroj <= jacinaNeprijatelja) {
		return true;
	}
	else {
		return false;
	}
}

static bool PotezJa(int dgNeprijatelj, int ggNeprijatelj, int jacinaNeprijatelja)
{
	int borbaBroj = dgNeprijatelj + (float)rand() / RAND_MAX * (ggNeprijatelj - dgNeprijatelj);

	if (borbaBroj > jacinaNeprijatelja) {
		return true;
	}
	else {
		return false;
	}
}


