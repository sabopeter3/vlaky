#pragma once
#include "Stanice.h"

class Logika
{

private:
	Stanice **zoznamStanic;
	int ZistiPocetStanic(const char * nazovSuboru);

public:
	Logika();
	~Logika();
	void ZoradPodlaPolohy(const char * nazovSuboru);
	void NacitajZoSuboru(const char * nazovSuboru);
	void NacitajZKonzoly();
	void VypisNaKonzolu(const char * nazovSuboru);
	void VypisDoSuboru(const char * nazovSuboru);
};