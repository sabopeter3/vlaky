#include "Logika.h"


int main() {
	Logika logic;
	logic.NacitajZoSuboru("Trat.txt");
	logic.ZoradPodlaPolohy("Trat.txt");
	//logic.VypisNaKonzolu("Trat.txt");
	logic.VypisDoSuboru("UsporiadanyZoznam.txt");
}