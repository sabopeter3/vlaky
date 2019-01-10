#include <iostream>
#include "stdio.h"
#include "Logika.h"

using namespace std;

int pocet = 0;

Logika::Logika()
{
}


Logika::~Logika()
{
	delete[] zoznamStanic;
}

int Logika::ZistiPocetStanic(const char * nazovSuboru)
{
	if (nazovSuboru && *nazovSuboru)
	{
		FILE *subor = fopen(nazovSuboru, "r");
		if (subor)
		{
			int vstup = 0;
			char znak = ' ';
			while (vstup >= 0)
			{
				vstup = fscanf(subor, "%c", &znak);
				if (znak == '\n') pocet++;
			}
			fclose(subor);
			pocet++;
		}
	}
	return pocet;
}

void Logika::NacitajZoSuboru(const char * nazovSuboru)
{
	if (nazovSuboru && *nazovSuboru)
	{
		int pocet(ZistiPocetStanic(nazovSuboru));
		FILE *subor = fopen(nazovSuboru, "r");
		if (subor)
		{
			if (pocet > 0)
			{
				zoznamStanic = new (nothrow) Stanice*[pocet];
				for (int i = 0; i < pocet; i++)
				{
					char typStanice;
					char *nazovStanice = new (nothrow) char[50];
					double polohaStanice;
					fscanf(subor, "%c ", &typStanice);
					fscanf(subor, "%s ", nazovStanice);
					fscanf(subor, "%.3lf", polohaStanice);

					Stanice *stanica = new Stanice(typStanice, nazovStanice, polohaStanice);
					zoznamStanic[i] = stanica;
				}
			}
			fclose(subor);
		}
	}
}

void Logika::NacitajZKonzoly()
{
	
}

void Logika::ZoradPodlaPolohy(const char * nazovSuboru)
{
	printf("**************************************************\nVysledky podla polohy\n**************************************************\n");

	for (int i = 0; i < pocet; i++)
	{
		for (int j = 0; j < pocet - 1; j++)
		{
			if (zoznamStanic[j]->GetPolohaStanice() > zoznamStanic[j + 1]->GetPolohaStanice())
			{
				Stanice *p(zoznamStanic[j]);
				zoznamStanic[j] = zoznamStanic[j + 1];
				zoznamStanic[j + 1] = p;
			}
		}
	}
}


void Logika::VypisNaKonzolu(const char * nazovSuboru)
{
	
}


void Logika::VypisDoSuboru(const char * nazovSuboru)
{
	if (nazovSuboru && *nazovSuboru)
	{
		FILE *subor = fopen(nazovSuboru, "w");
		if (subor)
		{
			for (int i = 0; i < pocet; i++)
			{
				fprintf(subor, "%.7f: %s\n", zoznamStanic[i]->GetPolohaStanice(), zoznamStanic[i]->GetNazovStanice());
			}
			fclose(subor);
		}
	}
}