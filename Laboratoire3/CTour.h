#pragma once

#include "CMissile.h"

class CTour
{
private:
	CMissile* monMissile;
	int Ligne;
	int Colonne;


public:
	CTour(int positionX, int positionY);
	~CTour();

	//Cr�� un thread pour lancer un missile
	void lancerMissile();
};
