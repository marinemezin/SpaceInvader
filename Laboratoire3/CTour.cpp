#include <iostream>
#include "CTour.h"

CTour::CTour(int Lig, int Col)
{
	monMissile = 0;
	Ligne = Lig;
	Colonne = Col; 
}

CTour::~CTour()
{

}

void CTour::lancerMissile()
{
	if (monMissile != 0)
	{
		monMissile = new CMissile(Ligne + 1, Colonne);
		this_thread::sleep_for(chrono::milliseconds(50));

	}
}

