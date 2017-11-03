#pragma once

#include "CMissile.h"

class CTour
{
private:
	CMissile* monMissile;
	int PositionX;
	int PositionY;


public:
	CTour();
	~CTour();

	//Créé un thread pour lancer un missile
	void lancerMissile();
};
