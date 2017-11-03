#include <iostream>
#include "CEcran.h"
#include "CJeu.h"

CJeu::CJeu()
{
	T1 = new CTour(20,26);
	T2 = new CTour(50,26);
	T3 = new CTour(80,26);
	score = 0;
}

CJeu::~CJeu()
{

}

void CJeu::Afficher()
{
	T1->afficher();
	T2->afficher();
	T3->afficher();
	T1->lancerMissile();
}
//Gotoxy(COLONNE,LIGNE)