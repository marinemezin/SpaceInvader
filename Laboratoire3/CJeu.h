#pragma once
#include "CVaisseau.h"
#include <thread>
#include <mutex>

using namespace std;

class CTour;

class CJeu
{
private : 
	CTour* mesTours[3];
	CVaisseau* mesVaisseaux[10];
	int listeVaisseaux[10];
	int vaisseauATuer[2];
	int score;
	thread* LeThread;
	thread* LeThreadScore;

	void goVaisseau();
	void afficherScore();
	
public: 
	CJeu();
	~CJeu();

	void jouer();
	
	int getColV(int i);
	int getLigV(int i);
	void setScorePlus1();
	void setMonVaisseauZero(int position);
	void tuerUnVaisseau(int position);

	static mutex VerrouJeu;
};