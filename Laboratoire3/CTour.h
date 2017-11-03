#pragma once

#include "CMissile.h"

class CTour
{
private:
	CMissile* monMissile;
	int PositionX;
	int PositionY;


public:
	CTour(int positionX, int positionY);
	~CTour();

	//Créé un thread pour lancer un missile
	void lancerMissile();
};
