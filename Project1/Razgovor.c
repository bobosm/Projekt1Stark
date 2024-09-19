#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"
#include "HranaEnum.h"
#include "Pivnica.h"
#include "Konobarica.h"
#include "Katakombe.h"

/*PROFESORE SMILUJTE SE*/


void Uvod() { 
	system("cls");
	printf("\n==============================\n");
	printf("Jednog jutra dobio si pismo od svog otuđenog oca. Isprva nisi mnogo mislio o tome, ali nesto ti je govorilo da ga trebas otvoriti.\n");
	printf("Kada si procitao pismo ostao si iznenaden. Tvoj otac ostavlja ti veliku imovinu u selu koje se nalazi nekoliko dana putovanja dalje od tvog.\n");
	printf("Nisi mogao to vjerovati. Tvoj otac i ti niste se razgovarili dugi niz godina. Otkako je kupio to imanje zapravo.\n");
	printf("Odlucujes provjeriti o cemu se radi te odlazis na dugo putovanje. Nakon nekoliko dana dolazis u zapusteno Selo.\n");
	printf("U centru sela ne pronalazis nikoga. Velika vila koja je na imanju tvoga oca nadgleda Selo.\n");
	printf("Ipak mozda bi se trebao prvo zaputiti u obliznju pivnicu raspitati se o tvome ocu i selu. Vjerojatno bi trebao jesti nesta. Ipak si dugo na putu.\n");
	printf("==============================\n");

	while (true) {
		int odabirSelo;
		printf("\n===== ODABERITE OPCIJU =======\n");
		printf("===== 1. ODLAZAK U PIVNICU ===\n");
		printf("===== 2. ODLAZAK U VILU ======\n");
		if (scanf("%d", &odabirSelo) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else
		{
			switch (odabirSelo) {
			case 1:
				Pivnica();
				break;
			case 2:
				Vila();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}


void StariCovjek() {
	system("cls");
	printf("\n=========================\n");
	printf("Prvo sto si primjetio kada si prisao covjeku su silni ozuljci koje je covjek imao po rukama i po licu.\n");
	printf("Nisi bio siguran sto ga prvo pitati, ali ima si srece on je tebe prvi nesto pitao.\n'Ne izgledas kao da si odavdje.'\n");
	printf("'Otac mi je rekao da dodem. Mozete li mi reci sto se dogada u ovom selu?' Po licu covbjeku primjetio si da ovo vjerojatno nije dobro prvo pitanje.\n");
	printf("'Sto tocno zelis znati? Ako je tvoj otac zivio u onoj vili onda se njemu nista dobro nije dogodilo. A otkako je covjek iz te vile nestao svi u selu su se promjenili'\n");
	printf("'Kako mislite promjenilo?' Ali kako misli nestao. Ako tvoga oca nema tko je onda napisao ono pismo?\n");
	printf("'Pa zar ne vidis kako izgledaju ljudi oko tebe' Rekao je tiho\n'Ja zivim malo van sela i dolazim ovdje samo jesti i prodavati.'\n");
	printf("Primjetio si da je covjek nervozan, ali i da ostali gosti gledaju u tvom smjeru. Mozda bi trebao napustiti ovo mjesto.\n");
	printf("Ali tvoja znatizelja bila je jaca od straha.\n'Gdje su ostali stanovnici? Selo je pusto, a vila izvana izgleda zapusteno.'\n");
	printf("'Kada je vlasnik vile nestao ljudi su se zabrinuli. Svakih nekoliko dana ljudi su otisli u vilu provjeriti sto se dogada.'\n");
	printf("'Ali ti ljudi koji su odlazili u vilu ponekad se ne bi vratili, a ovi koji su se vratili bi izgledali drugacije. Ljudi su se poceli bojati vile.'");
	printf("'Nakon nekog vremena nacelnik sela je s nekoliko ljudi oruzan otisao u vilu. Takoder se nije vratio. Tada je nastala panika i ljudi koji nisu bili promjenjeni su pobjegli.'\n");
	printf("'Nadam se da si sad cuo sve sto te zanimalo jer bi ti preporucio da otides odavdje. Cini se da si privukao paznju krivih ljudi.'\n");
	printf("Nisi primjetio do sada, ali svi gosti su buljili u tebe. Stvarno je vrijeme da odes.\n");
	printf("Zahvalio si se covjeku i pozdravio ga. U sredistu sela si, sto ces sljedece?\n");
	printf("=========================\n");


	while (1) {
		int odabirSelo;
		printf("\n===== ODABIRETI OPCIJU =======\n");
		printf("===== 1. VILA ================\n");
		printf("===== 2. PIVNICA =============\n");
		printf("===== 3. ORUŽARNICA ==========\n");
		if (scanf("%d", &odabirSelo) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else {
			switch (odabirSelo) {
			case 1:
				Vila();
				break;
			case 2:
				Pivnica();
				break;
			case 3:
				OruzarnicaMain();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();

	}
}


void Vila() {
	system("cls");
	printf("\n=========================\n");
	printf("Vec dok prilazis vili obuzima te jeza, ali tvoja znatizelja je jaca. Zbog te vile si i dosao u ovo cudno Selo.\n");
	printf("Otvorivsi vrata ulazis u predvorje vile. Prvo sto primjecujes je kolicina prasine na podu i na namjestaju. Ocito ovdje nije nitko bio dugo.\n");
	printf("Crvena vrata u kutu velikog predvorja ti bude znatizelju. Dok si prilazio vratima obuzeo te los osjecaj. Mozda bi ipak prvo trebao pregledati ostatak kuce. Mozda pronades nesta korisno.\n");
	printf("=========================\n");

	while (1) {
		int odabirVila;
		printf("\n===== ODABERITE OPCIJE =======\n");
		printf("===== 1. ULAZ U PODRUM =======\n");
		printf("===== 2. PREGLEDAJ OSTATAK VILE ==\n");
		if (scanf("%d", &odabirVila) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else {
			switch (odabirVila) {
			case 1:
				Podrum();
				break;
			case 2:
				OstatakVile();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}

void Podrum() {
	system("cls");
	printf("\n=========================\n");
	printf("Ulaskom u podrum obuzima te miris vlage i smrti. Osjetis da ovdje ne bi trebao biti.\n");
	printf("Pred tobom se nalazi crni prolaz koji prije nije bio u ovom podrumu. Mozes proci kroz njega.\n");
	printf("=========================\n");

	while (1) {
		int odabirPodrum;
		printf("\n===== ODABERITE OPCIJU =======\n");
		printf("===== 1. ULAZ U KATAKOMBE ========\n");
		printf("===== 2. POVRATAK U PREDVORJE ====\n");
		if (scanf("%d", &odabirPodrum) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else {
			switch (odabirPodrum) {
			case 1:
				Katakombe();
				break;
			case 2:
				Predvorje();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}

void OstatakVile() {
	system("cls");
	printf("\n=========================\n");
	printf("Odabrao si provjeriti ostatak vile. To je ipak bila pametnija ideja.\n");
	printf("Prolazivši kroz razne sobe vile ne pronalaziš mnogo. Vidi se da ovdje dugo nitko nije živio.\n");
	printf("Razmisljas zasto je pismo tvoga oca tek sada stiglo. Mozda si se ipak trebao prvo raspitati u selu.\n");
	printf("Obilazak vile nije bio pretjerano uzbudljiv. Ostala ti je još jedna soba. Oceva soba.\n");
	printf("Kada si usao u sobu prvo sto si primjetio je velika sjekira na zidu. Sjecas se kako ju je tvoj djed koristio.\n");
	printf("Nije ti jasno zasto ju je tvoj otac drzao u sobi. Mozda bi ju trebao pokupiti. Ili ces zavrsiti obilazak i vratitit se u predvorje.\n");
	printf("==========================\n");

	while (1) { 
		int odabirSoba;
		printf("\n=========================\n");
		printf("===== 1. POKUPI SJEKIRU(ATT: 6) ==\n");
		printf("===== 2. VRATI SE U PREDVORJE ====\n");
		if (scanf("%d", &odabirSoba) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else {
			switch (odabirSoba) {
			case 1:
				printf("\nOdabrao si uzeti sjekiru. U torbi imas mjesta za još dva oruzja.\n");
				printf("Dok si stavljao sjekiru u torbu primjetio si kako se nesto sjaji ispod kreveta.\n");
				printf("Na tvoju srecu to su bila jos 4 zlatnika. Odlucio si ih uzeti. Od viska glava ne boli.");
				printf("Prosao si cijelu vilu i vracas se u predvorje.\n");
				printf("=========================\n");

				Oruzje novoOruzje = { 6, "Djedina sjekira(ATT: 6)", 5, 0, true };
				DodajOruzje(novoOruzje);
				int stanjeRacuna = StanjeRacuna();
				stanjeRacuna += 4;
				AzurirajStanjeRacuna(stanjeRacuna);

				Predvorje();
				break;
			case 2:
				Predvorje();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}

void Predvorje() {
	printf("\n=========================\n");
	printf("Vracas se u predvorje vile. Sto sada?\n");
	printf("=========================\n");

	while (1) {
		int odabirPredvorje;
		printf("\n===== ODABERITE OPCIJU =======\n");
		printf("===== 1. ULAZ U PODRUM =======\n");
		printf("===== 2. POVRATAK U SELU =====\n");
		if (scanf("%d", &odabirPredvorje) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else {
			switch (odabirPredvorje) {
			case 1:
				Podrum();
				break;
			case 2:
				Selo();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}

void Selo() {
	printf("\n=========================\n");
	printf("Ponovo su u središtu sela.\nŠto ces napraviti sljedece?\n");
	printf("=========================\n");

	while (1) {
		int odabirSelo;
		printf("\n===== ODABIRETI OPCIJU =======\n");
		printf("===== 1. VILA ================\n");
		printf("===== 2. PIVNICA =============\n");
		printf("===== 3. ORUŽARNICA ==========\n");
		if (scanf("%d", &odabirSelo) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else
		{
			switch (odabirSelo) {
			case 1:
				Vila();
				break;
			case 2:
				Pivnica();
				break;
			case 3:
				OruzarnicaMain();
				break;
			default:
				printf("GRESKA! Krivo ste odabrali! Molim Vas ponovite izbor.");
				break;
			}
		}
		NastavakPoruka();
		getchar();
	}
}