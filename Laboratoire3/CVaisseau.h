#pragma once

#include <thread>

using namespace std;

class CVaisseau
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;

	void deplacerGD();
	void deplacerDG();

public:
	CVaisseau();
	~CVaisseau();

	static int nbVaisseau;
};