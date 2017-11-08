#include <iostream>

#include <thread>

#include "CMissile.h"
#include "CEcran.h"
#include "CJeu.h"

using namespace std;

CMissile::CMissile(int Lig, int Col, CTour* tour)
{
	Colonne = Col;
	Ligne = Lig;
	LeThread = new thread(&CMissile::monter, this);
	maTour = tour;
}

CMissile::~CMissile()
{
	maTour->setMonMissileZero();
	LeThread->detach();
	delete LeThread;
}

void CMissile::monter()
{
	while (Ligne > 0)
	{
		CJeu::VerrouJeu.lock();
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		Ligne--;
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "|";
		CEcran::Gotoxy(0, 30);
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}