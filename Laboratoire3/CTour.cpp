#include <iostream>
#include "CTour.h"
#include "CEcran.h"
#include "CMissile.h"


CTour::CTour(int num,int Lig, int Col, CJeu* jeu)
{
	numerotour = num;
	monMissile = 0;
	Ligne = Lig;
	Colonne = Col; 
	monJeu = jeu;
}

CTour::~CTour()
{

}

void CTour::lancerMissile()
{
	if (monMissile == 0)
	{
		new CMissile(Ligne - 1, Colonne, this);
		monMissile++;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}

void CTour::setMonMissileZero()
{
	monMissile = 0;
}

CJeu* CTour::getMonJeu()
{
	return monJeu;
}

void CTour::afficher()
{
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << "O";
	CJeu::VerrouJeu.unlock();
}
