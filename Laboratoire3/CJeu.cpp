#include <iostream>
#include "CEcran.h"
#include "CJeu.h"
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

mutex CJeu::VerrouJeu;

CJeu::CJeu()
{
	T1 = new CTour(1,28,20);
	T2 = new CTour(2,28,50);
	T3 = new CTour(3,28,80);
	score = 0;
	LeThread = new thread(&CJeu::Afficher, this);
}

CJeu::~CJeu()
{

}

void CJeu::Afficher()
{
	T1->afficher();
	T2->afficher();
	T3->afficher();
	//T1->lancerMissile();
}

void CJeu::jouer()
{
	char monNumChar = _getch();
	int monNum = monNumChar - 48;
	while (monNum != 4)
	{
		switch (monNum)
		{
		case 1:
			T1->lancerMissile();
			break;
		case 2:
			T2->lancerMissile();
			break;
		case 3:
			T3->lancerMissile();
			break;
		default:
			break;
		}
		//On demande un nouveau numéro
		monNumChar = _getch();
		monNum = monNumChar - 48;
	}
}
/**
void CTour::lancement()
{
	while (monMissile == 0)
	{
		Verrou.lock();
		char monNum = _getch();
		if (monNum == numerotour)
		{
			lancerMissile();
		}
		Verrou.unlock();
	}
}/**/
//Gotoxy(COLONNE,LIGNE)