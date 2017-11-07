#pragma once

#include "CMissile.h"
#include <thread>
#include <mutex>

class CTour
{
private:
	int numerotour;
	CMissile* monMissile;
	int Ligne;
	int Colonne;
	thread* LeThread;

	static mutex Verroulancement;

public:
	CTour(int numtour, int positionX, int positionY);
	~CTour();

	//Créé un thread pour lancer un missile
	void lancerMissile();

	void afficher();

	void lancement();
};
