#pragma once

#include <thread>
#include "CTour.h"

using namespace std;

class CMissile 
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;
	CTour* maTour;

	//Appeler dans le constructeur pour le faire monter direct
	void monter();

	bool attentionCollision();
	bool sousTestCollision(int colV, int ligV);

public:
	CMissile(int Lig, int Col, CTour* tour);
	~CMissile();
};