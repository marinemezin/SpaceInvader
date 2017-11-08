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
	LeThread1 = new thread(&CJeu::Afficher, this);
	LeThread2 = new thread(&CJeu::goVaisseau, this);
}

CJeu::~CJeu()
{
	LeThread1->detach();
	delete LeThread1;
	LeThread2->detach();
	delete LeThread2;
}

void CJeu::Afficher()
{
	T1->afficher();
	T2->afficher();
	T3->afficher();
	//T1->lancerMissile();
}

void CJeu::goVaisseau()
{
	while (CVaisseau::nbVaisseauACreer != 0)
	{
		if (CVaisseau::nbVaisseau < 4) { //pas + de 4 vaisseau en meme temps sur le jeu
			//des fois �a marche pas et 5 vaisseaux sont en meme temps
			new CVaisseau();
		}
		this_thread::sleep_for(chrono::milliseconds(3200));
	}
}

void CJeu::jouer()
{
	char monNumChar = _getch();
	int monNum = monNumChar - 48;
	while (CVaisseau::nbVaisseau != 0)
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
		//On demande un nouveau num�ro
		monNumChar = _getch();
		monNum = monNumChar - 48;
	}
}
//Gotoxy(COLONNE,LIGNE)