#include <iostream>

#include <thread>
#include <mutex>

#include "CMissile.h"
#include "CEcran.h"
#include "CTour.h"

using namespace std;

mutex CMissile::Verrou;

CMissile::CMissile(int Lig, int Col)
{
	Colonne = Col;
	Ligne = Lig;
	LeThread = new thread(&CMissile::monter, this);
	//maTour = tour;
}

CMissile::~CMissile()
{
	//maTour->setMonMissileZero();
	LeThread->detach();
	delete LeThread;
}

void CMissile::monter()
{
	while (Ligne > 0)
	{
		Verrou.lock();
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		Ligne--;
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "|";
		CEcran::Gotoxy(0, 29);
		Verrou.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	Verrou.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	Verrou.unlock();
	delete this;
}