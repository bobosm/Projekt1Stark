#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Header.h"
#include "Pivnica.h"
#include "OruzjeEnum.h"

#define MAX_HEALTH 100
#define MAX_GOLD 30
#define POCETNI_BROJ_ZLATNIKA 7
bool PRVI_POSJET_PIVNICI = true;
bool PRVI_POSJET_KONOBARICA = true;

Neprijatelj NeprijateljPrvi = {
	.rbr = 1,
	.health = 50
};

Neprijatelj NeprijateljDrugi = {
	.rbr = 2,
	.health = 75
};

Neprijatelj NeprijateljTreci = {
	.rbr = 3,
	.health = 100
};

Oruzje oruzje[6] = {
	{1, "Drvosjeca sjekira(ATT: 4)", 4, 5, true},
	{2, "Rabljeni mac(ATT: 8)", 8, 4, true},
	{3, "Novi mac(ATT: 12)", 12, 10, true},
	{4, "Vitezov Mac(ATT: 17)", 17, 15, true},
	{5, "Drevni mac(ATT: 25)", 25, 30, true},    
	{6, "Djedina sjekira(ATT: 6)", 6, 0, true}
};

Oruzje mojeOruzje[3] = { 0 };


inline void OcistiUnos() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

static void IzbornikUlaz() {
	printf("\n===========================\n");
	printf("===== 1. NOVA IGRA ========\n");
	printf("===== 2. IZLAZ ============\n");
	printf("===== ODABERIITE OPCIJU: ==\n");
}

int main(void) {
	AzurirajHealth(100);
	SetBrojZlatnika();

	srand((unsigned)time(NULL));

	for (int i = 0; i < 3; ++i) {
		mojeOruzje[i].validno = false;
	}

	while (true) {
		system("cls");
		int odabirUvod;
		IzbornikUlaz();
		if (scanf("%d", &odabirUvod) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else
		{
			switch (odabirUvod)
			{
			case 1:
				Uvod();
				break;
			case 2:
				printf("Izlaz iz programa.\n");
				exit(0);
				break;
			default:
				printf("Greska! Ne mozete to odabrati! Ponovite odabir.");
				break;
			}
		}

		NastavakPoruka();
		getchar();
	}

	return 0;
}

void NastavakPoruka()
{
	printf("\nZa nastavak pritisni Enter");
}

int StanjeRacuna() {
	FILE* stanjeRacunaFile;
	char brojZlatnikaStr[30];
	stanjeRacunaFile = fopen("brojZlatnika.txt", "r");
	if (stanjeRacunaFile == NULL) {
		printf("GRESKA! Otvaranje dokumenta.");
		return -1;
	}

	if (fgets(brojZlatnikaStr, sizeof(brojZlatnikaStr), stanjeRacunaFile) == NULL) {
		printf("GRESKA! Vrijednost u dokumentu ne postoji ili greska u citanju.\n");
		fclose(stanjeRacunaFile);
		return -1;
	}

	fclose(stanjeRacunaFile);

	int brojZlatnika = atoi(brojZlatnikaStr);

	return brojZlatnika;
}

void AzurirajStanjeRacuna(int brojZlatnika) {
	if (brojZlatnika > MAX_GOLD) {
		brojZlatnika = MAX_GOLD;
	}

	FILE* brojZlantikaFile;
	brojZlantikaFile = fopen("brojZlatnika.txt", "w");

	if (brojZlantikaFile == NULL) {
		perror("Greska! Dokument ne postoji!");
		return;
	}

	fprintf(brojZlantikaFile, "%d", brojZlatnika);

	fclose(brojZlantikaFile);
}

void AzurirajHealth(int health) {
	FILE* healthFile = fopen("health.txt", "r+");
	if (healthFile == NULL) {
		perror("Greška pri otvaranju datoteke!");
		return;
	}

	char healthStr[4];
	if (fgets(healthStr, sizeof(healthStr), healthFile) == NULL) {
		perror("Greška pri čitanju datoteke!");
		fclose(healthFile);
		return;
	}

	int noviHealth = atoi(healthStr);

	noviHealth += health;

	if (noviHealth > MAX_HEALTH) {
		noviHealth = MAX_HEALTH;
	}
	if (noviHealth < 0) {
		noviHealth = 0;
	}

	rewind(healthFile);

	fprintf(healthFile, "%d", noviHealth);

	long int pos = ftell(healthFile);
	if (pos < sizeof(healthStr)) {
		for (int i = pos; i < sizeof(healthStr); i++) {
			fputc(' ', healthFile);
		}
	}

	fclose(healthFile);
}

int SetBrojZlatnika() {
	FILE* stanjeRacunaFile;
	char brojZlatnikaStr[30];
	stanjeRacunaFile = fopen("brojZlatnika.txt", "r");
	if (stanjeRacunaFile == NULL) {
		printf("GRESKA! Otvaranje dokumenta.");
		return -1;
	}

	if (fgets(brojZlatnikaStr, sizeof(brojZlatnikaStr), stanjeRacunaFile) == NULL) {
		printf("GRESKA! Vrijednost u dokumentu ne postoji ili greska u citanju.\n");
		fclose(stanjeRacunaFile);
		return -1;
	}
	int brojZlatnika;

	brojZlatnika = atoi(brojZlatnikaStr);
	
	if (brojZlatnika != POCETNI_BROJ_ZLATNIKA) {
		stanjeRacunaFile = fopen("brojZlatnika.txt", "w");
		if (stanjeRacunaFile == NULL) {
			printf("GRESKA! Otvaranje dokumenta za pisanje.\n");
			return;
		}

		fprintf(stanjeRacunaFile, "%d", POCETNI_BROJ_ZLATNIKA);
		fclose(stanjeRacunaFile);
	}

}

int DohvatiHealth() {
	FILE* healthFile = fopen("health.txt", "r");
	if (healthFile == NULL) {
		perror("Greška pri otvaranju datoteke!");
		return -1;
	}

	char healthStr[3];
	if (fgets(healthStr, sizeof(healthStr), healthFile) == NULL) {
		perror("Greška pri čitanju datoteke!");
		fclose(healthFile);
		return -1;
	}

	fclose(healthFile);

	int noviHealth = atoi(healthStr);

	return noviHealth;
}

int LinearnoPretrazivanje(int niz[], int velicina, int trazeniElement) {
	for (int i = 0; i < velicina; i++) {
		if (niz[i] == trazeniElement) {
			return i; 
		}
	}
	return -1; 
}


Oruzje DohvatiOruzjePoId(int oruzjeId) {
	for (int i = 0; i < ARRAY_SIZE(oruzje); i++) {
		if (oruzje[i].id == oruzjeId) {
			return oruzje[i];
		}
	}
	return;
}

void DodajOruzjePoId(int oruzjeId) {
	if (OruzjePostojiUTorbi(oruzjeId)) {
		printf("Oruzje postoji u torbi.");
		return;
	}

	Oruzje oruzje = DohvatiOruzjePoId(oruzjeId);
	bool torbaPuna = true;
	for (int i = 0; i < ARRAY_SIZE(mojeOruzje); i++) {
		if (!mojeOruzje[i].validno) {
			mojeOruzje[i] = oruzje;
			torbaPuna = false;
			break;
		}
	}

	if (torbaPuna) {
		printf("Torba je puna, nije moguce dodati novo.");
	}
}

void DodajOruzje(Oruzje oruzje) {
	if (OruzjePostojiUTorbi(oruzje.id)) {
		printf("Oruzje postoji u torbi.");
		return;
	}

	bool torbaPuna = true;
	for (int i = 0; i < ARRAY_SIZE(mojeOruzje); i++) {
		if (!mojeOruzje[i].validno) {
			mojeOruzje[i] = oruzje;
			torbaPuna = false;
			break;
		}
	}

	if (torbaPuna) {
		printf("Torba je puna, nije moguce dodati novo.");
	}
}



bool OruzjePostojiUTorbi(int oruzjeId) {

	for (int i = 0; i < 5; ++i) {
		if (mojeOruzje[i].id == oruzjeId) {
			return true;
		}
	}
	return false;
}

void OruzarnicaMain() { 
	system("cls");
	printf("\n=========================\n");
	printf("Ulazis u oruzarnicu. U oruzarnici vidis covjeka u srednjim godinama. Kada te ugledao nasmjesio se.\n ");
	printf("Za razliku od ostatka sela oruzarnica izgleda lijepo. Kao da je u potpuno drugom selu.\n");
	printf("'Pozdrav! Sto trebas?'\n");
	printf("Na ponudi ima mnogo stvari, ostalo ti je 7 zlatnika od puta. Mozda bi trebao uzeti oruzje.");
	printf("=========================\n");

	while (1) {
		int odabirOruzarnica;
		printf("\n===== ODABERI STO ZELIS KUPITI =======\n");
		printf("===== 1. DRVOSJECEVA SJEKIRA(ATT: 4) - 5 ZLATNIKA==\n");
		printf("===== 2. RABLJENI MAC(ATT: 8) - 4 ZLATNIKA ========\n");
		printf("===== 3. NOVI MAC(ATT: 12) - 10 ZLATNIKA ===========\n");
		printf("===== 4. MAC VITEZA(ATT: 17) - 15 ZLATNIKA ========\n");
		printf("===== 5. DREVNI MAC(ATT: 25) - 20 ZLATNIKA ========\n");
		printf("===== 6. NE ZELIS NISTA, POVRATAK U SREDISTE SELA =\n");
		if (scanf("%d", &odabirOruzarnica) != 1) {
			printf("Vas unos nije broj! Molim Vas ponovite izbor.");
			OcistiUnos();
		}
		else {
			int stanjeRacuna = StanjeRacuna();
			switch (odabirOruzarnica) {
			case 1:
				if (stanjeRacuna < (int)DrvosjecaSjekira) {
					printf("Nemas dovoljno Zlatnika!");
				}
				else {
					PorukaOruzarnica();
					DodajOruzjePoId(1);
					stanjeRacuna -= (int)DrvosjecaSjekira;
					AzurirajStanjeRacuna(stanjeRacuna);

				}
				Selo();
				break;
			case 2:
				if (stanjeRacuna < (int)RabljeniMac) {
					printf("Nemas dovoljno Zlatnika!");
				}
				else {
					PorukaOruzarnica();
					DodajOruzjePoId(2);
					stanjeRacuna -= (int)RabljeniMac;
					AzurirajStanjeRacuna(stanjeRacuna);

				}
				Selo();
				break;
			case 3:
				if (stanjeRacuna < (int)NoviMac) {
					printf("Nemas dovoljno Zlatnika!");
				}
				else {
					PorukaOruzarnica();
					DodajOruzjePoId(3);
					stanjeRacuna -= (int)NoviMac;
					AzurirajStanjeRacuna(stanjeRacuna);

				}
				Selo();
				break;
			case 4:
				if (stanjeRacuna < (int)VitezMac) {
					printf("Nemas dovoljno Zlatnika!");
				}
				else {
					PorukaOruzarnica();
					DodajOruzjePoId(4);
					stanjeRacuna -= (int)VitezMac;
					AzurirajStanjeRacuna(stanjeRacuna);

				}
				Selo();
				break;
			case 5:
				if (stanjeRacuna < (int)DrevniMac) {
					printf("Nemas dovoljno Zlatnika!");
				}
				else {
					PorukaOruzarnica();
					DodajOruzjePoId(5);
					stanjeRacuna -= (int)DrevniMac;
					AzurirajStanjeRacuna(stanjeRacuna);

				}
				Selo();
				break;
			case 6:
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

void PorukaOruzarnica()
{
	printf("\n'Dobar odabir! S tim ces sigurno biti zadovoljan.'\n");
	printf("Sada se barem malo sigurnije osjecas. Vracas se u srediste sela.\n");
}

void PrikaziOruzje() {
	bool torbaJePrazna = true;
	QuickSort(mojeOruzje, 0, ARRAY_SIZE(mojeOruzje) - 1);

	printf("\n===== POPIS ORUZJA ==\n");
	for (int i = 0; i < ARRAY_SIZE(mojeOruzje); ++i) {
		if (mojeOruzje[i].validno) {
			printf("\n%d. %s\n", mojeOruzje[i].id, mojeOruzje[i].naziv);
			torbaJePrazna = false;
		}
	}

	if (torbaJePrazna) {
		printf("\nTorba je prazna.");
	}
}

void Swap(Oruzje* a, Oruzje* b) {
	Oruzje temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(Oruzje array[], int low, int high) {
	int pivot = array[high].id;
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (array[j].id < pivot) {
			i++;
			Swap(&array[i], &array[j]);
		}
	}
	Swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void QuickSort(Oruzje array[], int low, int high) {
	if (low < high) {
		int pi = Partition(array, low, high);
		QuickSort(array, low, pi - 1);
		QuickSort(array, pi + 1, high);
	}
}