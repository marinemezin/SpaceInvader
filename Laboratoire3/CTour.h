#pragma once

#include <iostream>
#include "CJeu.h"

class CJeu;

class CTour
{
private:
	int numerotour;
	int monMissile;
	int Ligne;
	int Colonne;
	CJeu* monJeu;

public:
	CTour(int numtour, int positionX, int positionY, CJeu* jeu);
	~CTour();

	//Créé un thread pour lancer un missile
	void lancerMissile();

	CJeu* getMonJeu();
	void setMonMissileZero();
	void afficher();
};
