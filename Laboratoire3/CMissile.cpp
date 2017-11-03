#include <iostream>

#include <thread>
#include <mutex>

#include "CMissile.h"
#include "CEcran.h"

using namespace std;

mutex CMissile::Verrou;

CMissile::CMissile(int Lig, int Col)
{
	Colonne = Col;
	Ligne = Lig;
	LeThread = new thread(&CMissile::monter, this);
}

CMissile::~CMissile()
{
	LeThread->detach();
	delete LeThread;
}

void CMissile::monter()
{
	while (Ligne >= 0)
	{
		Verrou.lock();
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		Ligne--;
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "|";
		CEcran::Gotoxy(79, 24);
		Verrou.unlock();

		this_thread::sleep_for(chrono::milliseconds(50));
	}
	Verrou.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " " << flush;
	CEcran::Gotoxy(0, 0);
	Verrou.unlock();
	delete this;
}