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

public:
	CVaisseau();
	~CVaisseau();
};