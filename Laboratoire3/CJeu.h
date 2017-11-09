#pragma once
#include "CTour.h"
#include "CVaisseau.h"
#include <mutex>

using namespace std;

class CJeu
{
private : 
	CTour* mesTours[3];
	CVaisseau* mesVaisseaux[10];
	int score;
	
public: 
	CJeu();
	~CJeu();

	void jouer();
	void goVaisseau();
	
	CVaisseau* getVaisseau(int i) { return mesVaisseaux[i]; }

	static mutex VerrouJeu;
};