#pragma once

#include "CMissile.h"
#include <thread>
#include <mutex>

class CTour
{
private:
	CMissile* monMissile;
	int Ligne;
	int Colonne;
	thread* LeThread;


public:
	CTour(int positionX, int positionY);
	~CTour();

	//Créé un thread pour lancer un missile
	void lancerMissile();

	void afficher();

	void lancement();
};
