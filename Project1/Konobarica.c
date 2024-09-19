#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "HranaEnum.h"
#include "Pivnica.h"
#include "Konobarica.h"
#include "Header.h" 

void Konobarica() { //ubit cu se runda 2
	system("cls");
	if (PRVI_POSJET_KONOBARICA) {
		PRVI_POSJET_KONOBARICA = false;
		printf("\n=========================\n");
		printf("Prilazis konobarici. Kao i ostali gosti, osim starijeg covjeka, imala na licu obiljezja divljih zivotinja.\n");
		printf("Cinilo se kao da joj raste pticji kljun. Odlucio si to ignoritati i pitao si ju mozes li kupiti nesta.\n");
		printf("Iako se cinilo kao da bi doslovno radilo bilo sta drugo osim razgovarala s tobom ipak ti je rekla ponudu.\n");
		printf("Sto ces sljedece. Zelis li kupiti nesta za jest ili se vratiti u centar sela.\n");
		printf("=========================\n");
	}
	else {
		printf("\n=========================\n");
		printf("Prilazis konobarici. Izgleda kao da je razocarana sto te vidi.\n");
		printf("'Sto zelis kupiti?'\n");
		printf("=========================\n");
	}

	Meni();
}


void Meni()
{
	while (true) {
		int odabirAHrana;
		printf("\n====== ODABERITE OPCIJU =======\n");
		printf("===== 1. GULAS(HLT: 25) - 4 ZLATNIKA =======\n");
		printf("===== 2. PILECA JUHA(HLT: 14) - 2 ZLATNIKA =\n");
		printf("===== 3. CEVAPI S LEPINJOM(HLT: 30) - 7 ZLATNIKA ==\n");
		printf("===== 4. NE ZELIS NISTA, POVRATAK U SREDISTE SELA =\n");
		if (scanf("%d", &odabirAHrana) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else
		{
			int stanjeRacuna = StanjeRacuna();
			switch (odabirAHrana) {
			case 1:
				if (stanjeRacuna < (int)Gulas) {
					printf("Nemas dovoljno zlatnika!");
				}
				else {
					DodajHranu(Gulas);
					stanjeRacuna -= (int)Gulas;
					AzurirajStanjeRacuna(stanjeRacuna);
					AzurirajHealth(25);
					PovratakIzPivnicePoruka();
				}
				Selo();
				break;
			case 2:
				if (stanjeRacuna < (int)JuhaPiletina) {
					printf("Nemas dovoljno zlatnika!");
				}
				else {
					DodajHranu(JuhaPiletina);
					stanjeRacuna -= (int)JuhaPiletina;
					AzurirajStanjeRacuna(stanjeRacuna);
					AzurirajHealth(14);
					PovratakIzPivnicePoruka();
				}
				Selo();
				break;
			case 3:
				if (stanjeRacuna < (int)CevapiLepinja) {
					printf("Nemas dovoljno zlatnika!");
				}
				else {
					DodajHranu(CevapiLepinja);
					stanjeRacuna -= (int)CevapiLepinja;
					AzurirajStanjeRacuna(stanjeRacuna);
					AzurirajHealth(30);
					PovratakIzPivnicePoruka();
				}
				Selo();
				break;
			case 4:
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