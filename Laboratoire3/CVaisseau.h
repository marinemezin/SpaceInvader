#pragma once

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class CVaisseau
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;

	void deplacerGD();
	void deplacerDG();

	static bool premierVaisseau;

public:
	CVaisseau();
	CVaisseau(int chiffre);
	~CVaisseau();
	static int nbVaisseau;
	static int nbVaisseauACreer;
	int getCol() { return Colonne; }
	int getLig() { return Ligne; }
	void deleteCeVaisseau();
};