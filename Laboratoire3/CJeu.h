#pragma once
#include "CVaisseau.h"
#include "CTour.h"
#include <thread>
#include <mutex>

using namespace std;

class CJeu
{
private : 
	CTour* mesTours[3];
	CVaisseau* mesVaisseaux[10];
	int vaisseauATuer[2];
	int score;
	thread* LeThread;

	void goVaisseau();
	
public: 
	CJeu();
	~CJeu();

	void jouer();
	
	CVaisseau* getVaisseau(int i);
	void setMonVaisseauZero(int colV, int ligV);
	void tuerUnVaisseau(int col, int lig);

	static mutex VerrouJeu;
};