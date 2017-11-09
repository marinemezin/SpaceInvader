#pragma once

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class CJeu;

class CVaisseau
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;
	int place;
	CJeu* monJeu;

	void deplacerGD();
	void deplacerDG();

	static bool premierVaisseau;

public:
	CVaisseau(int p, CJeu* jeu);
	//CVaisseau(int chiffre);
	~CVaisseau();
	static int nbVaisseau;
	static int nbVaisseauACreer;
	int getCol() { return Colonne; }
	int getLig() { return Ligne; }
	void deleteCeVaisseau();
};