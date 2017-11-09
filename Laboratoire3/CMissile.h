#pragma once

#include <thread>
#include "CTour.h"

using namespace std;

class CJeu;

class CMissile 
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;
	CTour* maTour;
	CJeu* monJeu;

	//Appeler dans le constructeur pour le faire monter direct
	void monter();

	bool attentionCollision();
	bool sousTestCollision(int colV, int ligV);

public:
	CMissile(int Lig, int Col, CTour* tour, CJeu* jeu);
	~CMissile();
};