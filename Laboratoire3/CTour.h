#pragma once

#include <iostream>
#include "CJeu.h"



class CTour
{
private:
	int numerotour;
	int monMissile;
	int Ligne;
	int Colonne;
	CJeu* monJeu;

public:
	CTour(int num, int Lig, int Col, CJeu* jeu);
	~CTour();

	void lancerMissile();
	CJeu* getMonJeu();
	void setMonMissileZero();
	void afficher();
};
