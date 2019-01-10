#pragma once

class Stanice
{

private:
	char typStanice;
	char *nazovStanice;
	double polohaStanice;

public:
	Stanice(char paTypStanice, char *paNazovStanice, double paPolohaStanice);
	~Stanice();
	char GetTypStanice() { return typStanice; };
	char *GetNazovStanice() { return nazovStanice; };
	double GetPolohaStanice() { return polohaStanice; };
};