#include <iostream>
#include "CTour.h"
#include "CEcran.h"
#include "conio.h"

mutex CTour::Verroulancement;

CTour::CTour(int num,int Lig, int Col)
{
	numerotour = num;
	monMissile = 0;
	Ligne = Lig;
	Colonne = Col; 
	LeThread = new thread(&CTour::lancement, this);
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

void CTour::afficher()
{
	CEcran::Gotoxy(Colonne, Ligne);
	cout << "O";
}

void CTour::lancement()
{
	while (true)
	{
		Verroulancement.lock();
		if (_getch() != numerotour)
		{
			lancerMissile();
		}
		Verroulancement.unlock();
	}
}
