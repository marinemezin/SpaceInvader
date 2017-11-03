#pragma once

#include <thread>
#include <mutex>

class CMissile 
{
private:
	int Colonne;
	int Ligne;
	std::thread* LeThread;

	//Appeler dans le constructeur pour le faire monter direct
	void monter();
	
	static int Verrou;
public:
	CMissile();
	~CMissile();	
};