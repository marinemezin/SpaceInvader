#pragma once
#include "CTour.h"
#include "CVaisseau.h"
#include "CMissile.h"
#include <thread>
#include <mutex>

using namespace std;

class CJeu
{
private : 
	CTour* mesTours[3];
	CVaisseau* mesVaisseaux[10];
	int score;
	thread* LeThread1;
	thread* LeThread2;

	void Afficher();
	void goVaisseau();
	
public: 
	CJeu();
	~CJeu();

	void jouer();
	
	static bool testCollision(CMissile* ceMissile);
	bool collision(CMissile* ceMissile);

	static mutex VerrouJeu;
};