#pragma once

#include <thread>
#include <mutex>

using namespace std;

class CVaisseau
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;

	void deplacer();

	static mutex Verrou;
public:
	CVaisseau();
	~CVaisseau();
};