#pragma once

#include <thread>
#include <mutex>

class CMissile 
{
private:
	int Colonne;
	int Ligne;
	std::thread* LeThread;

	void monter();
	
	static int Verrou;
public:
	CMissile();
	~CMissile();	
};