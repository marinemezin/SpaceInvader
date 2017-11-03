#include <iostream>
#include "CEcran.h"
#include "CJeu.h"

CJeu::CJeu()
{
	T1 = new CTour(30,20);
	T2 = new CTour(30,40);
	T3 = new CTour(30,60);
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