#include <iostream>
#include "CTour.h"
#include "CEcran.h"


CTour::CTour(int num,int Lig, int Col)
{
	numerotour = num;
	monMissile = 0;
	Ligne = Lig;
	Colonne = Col; 
}

CTour::~CTour()
{

}

void CTour::lancerMissile()
{
	if (monMissile == 0)
	{
		monMissile = new CMissile(Ligne - 1, Colonne);
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}

void CTour::setMonMissileZero()
{
	monMissile = 0;
}

void CTour::afficher()
{
	CEcran::Gotoxy(Colonne, Ligne);
	cout << "O";
}
