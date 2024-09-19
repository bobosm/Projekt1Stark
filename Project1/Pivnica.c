#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "Pivnica.h"
#include "Konobarica.h"


void PovratakIzPivnicePoruka()
{
	printf("\n'Malo pricekaj, trebat ce vremena da se napravi.' Konobarica izgleda kao da bi radije da nisi nista narucio.\n");
	printf("Sada si uzeo nesta za jest, vracas se u srediste sela.\n");
}

void Pivnica() {
	system("cls");
	if (PRVI_POSJET_PIVNICI) {
		PRVI_POSJET_PIVNICI = false;
		printf("\n=========================\n");
		printf("Ulazis u obliznju pivnicu. Miris vlage i loseg alkohola brzo te okruzuje.\n");
		printf("Ipak nekoliko gostiju je prisutno no nijedan ne izgleda previse pristupacno.\n ");
		printf("Cak imaju osobine sumskih zivotinja, jedan gost ima lice kao divlja svinja,\na drugom izgleda kao da rastu rogovi kao na jelenu.\n");
		printf("Ali primjecujes jednog starijeg covjeka koji izgleda kao normalna osoba. Hoces li ga pitati za pomoc ili nastatviti prema konobarici?\n ");
		printf("=========================\n");

		while (1) {
			int odabirPivnica;
			printf("\n===== ODABERITE OPCIJU =======\n");
			printf("===== 1. STARIJI COVJEK ======\n");
			printf("===== 2. KONOBARICA ==========\n");
			if (scanf("%d", &odabirPivnica) != 1) {
				printf("Vas unos nije broj! Molim Vas ponovite izbor.");
				OcistiUnos();
			}
			else
			{
				switch (odabirPivnica) {
				case 1:
					StariCovjek();
					break;
				case 2:
					Konobarica();
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
	else {
		printf("\n=========================\n");
		printf("U pivnici si. Starog covjeka vise nema. Nadas se da je sve uredu s njime.\n");
		printf("U pivnici mozes kupiti hranu kako bi se oporavio. Takoder istu hranu mozes uzeti za ponjeti.\n");
		printf("Primjecujes da te Konobarica gleda. Trebao bi joj prici ako zelis nesta kupiti.\n");
		printf("=========================\n");

		while (1) {
			int odabirKonobarica;
			printf("\n===== ODABERITE OPCIJU =======\n");
			printf("===== 1. PRIDI KONOBARICI ====\n");
			printf("===== 2. POVRATAK U SELO =====\n");
			if (scanf("%d", &odabirKonobarica) != 1) {
				printf("Vas unos nije broj! Molim Vas ponovite izbor.");
				OcistiUnos();
			}
			else
			{
				switch (odabirKonobarica) {
				case 1:
					Konobarica();
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
}

void DodajHranu(HranaEnum tipHrane) {
	FILE* hranaTxt = fopen("hrana.txt", "a");
	if (hranaTxt == NULL) {
		perror("GRESKA!");
		return 1;
	}

	const char* hrana = EnumHranaToString(tipHrane);

	fprintf(hranaTxt, "%s\n", hrana);

	fclose(hranaTxt);
}

const char* EnumHranaToString(enum HranaEnum hrana) {
	switch (hrana) {
	case Gulas:
		return "Gulas";
	case CevapiLepinja:
		return "Cevapi s lepinjom";
	case JuhaPiletina:
		return "Juha s piletinom";
	default:
		return "Nepostojeca hrana";
	}
}