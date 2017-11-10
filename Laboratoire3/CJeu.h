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

	void goVaisseau();
	
public: 
	CJeu();
	~CJeu();

	void jouer();
	
	int getColV(int i);
	int getLigV(int i);
	void setMonVaisseauZero(int position);
	void tuerUnVaisseau(int position); //appeler par un missile

	static mutex VerrouJeu;
};