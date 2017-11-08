#pragma once
#include "CTour.h"
#include "CVaisseau.h"
#include <thread>
#include <mutex>

using namespace std;

class CJeu
{
private : 
	CTour *T1;
	CTour *T2;
	CTour *T3;
	int score;
	thread* LeThread1;
	thread* LeThread2;

	void Afficher();
	void goVaisseau();
	
public: 
	CJeu();
	~CJeu();

	void jouer();

	static mutex VerrouJeu;
};