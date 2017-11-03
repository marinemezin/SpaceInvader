#include <iostream>
#include "CEcran.h"
#include "CJeu.h"

CJeu::CJeu()
{
	T1 = new CTour(20,30);
	T2 = new CTour(50,30);
	T3 = new CTour(80,30);
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
}
//Gotoxy(COLONNE,LIGNE)