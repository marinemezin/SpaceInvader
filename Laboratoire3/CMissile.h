#pragma once

#include "CTour.h"
#include <thread>
#include <mutex>

using namespace std;

class CMissile 
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;
	//CTour maTour;

	//Appeler dans le constructeur pour le faire monter direct
	void monter();
	
	static mutex Verrou;
public:
	CMissile(int Lig, int Col);
	~CMissile();
};