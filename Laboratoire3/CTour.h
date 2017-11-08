#pragma once

#include "CMissile.h"


class CTour
{
private:
	int numerotour;
	CMissile* monMissile;
	int Ligne;
	int Colonne;

public:
	CTour(int numtour, int positionX, int positionY);
	~CTour();

	//Créé un thread pour lancer un missile
	void lancerMissile();

	void setMonMissileZero();
	void afficher();
};
