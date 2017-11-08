#pragma once

#include <iostream>


class CTour
{
private:
	int numerotour;
	int monMissile;
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
