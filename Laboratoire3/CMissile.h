#pragma once

#include <thread>
#include <mutex>

using namespace std;

class CMissile 
{
private:
	int Colonne;
	int Ligne;
	thread* LeThread;

	//Appeler dans le constructeur pour le faire monter direct
	void monter();
	
	static mutex Verrou;
public:
	CMissile(int Ligne, int Colonne);
	~CMissile();	
};