#include "Stanice.h"


Stanice::Stanice(char paTypStanice, char *paNazovStanice, double paPolohaStanice) :
	typStanice(paTypStanice),
	nazovStanice(paNazovStanice),
	polohaStanice(paPolohaStanice)
{
}


Stanice::~Stanice()
{
	delete nazovStanice;
}