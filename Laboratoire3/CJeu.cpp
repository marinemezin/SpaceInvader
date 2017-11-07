#include <iostream>
#include "CEcran.h"
#include "CJeu.h"

CJeu::CJeu()
{
	T1 = new CTour(1,28,20);
	T2 = new CTour(2,28,50);
	T3 = new CTour(3,28,80);
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