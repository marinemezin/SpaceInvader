#pragma once

#include <thread>
#include <mutex>

class CVaisseau
{
private:
	int Colonne;
	int Ligne;
	std::thread* LeThread;

	void deplacer();

	static int Verrou;
public:
	CVaisseau();
	~CVaisseau();
};