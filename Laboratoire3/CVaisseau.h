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
	~CVaisseau();
	static int nbVaisseau;
	static int nbVaisseauACreer;
	int getCol();
	int getLig();
};