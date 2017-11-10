#pragma once

#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string>

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
	bool doitMourir;

	void deplacerGD();
	void deplacerDG();

	static bool premierVaisseau;
	void destructionAnimee();
	void destructionClassique();
	void destructionAnimeecarac(string carac, bool temps);
	void mouvement(string carac, int lig, int col);

public:
	CVaisseau(int p, CJeu* jeu);
	~CVaisseau();
	static int nbVaisseau;
	static int nbVaisseauACreer;
	int getCol() { return Colonne; }
	int getLig() { return Ligne; }
	void deleteCeVaisseau();
};