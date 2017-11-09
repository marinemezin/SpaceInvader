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
	mesTours[0] = new CTour(1,28,20, this);
	mesTours[1] = new CTour(2,28,50, this);
	mesTours[2] = new CTour(3,28,80, this);
	mesTours[0]->afficher();
	mesTours[1]->afficher();
	mesTours[2]->afficher();
	score = 0;
	for (int i = 0; i < 10; i++) {
		mesVaisseaux[i] = 0;
		listeVaisseaux[i] = 0;
	}
	LeThread = new thread(&CJeu::goVaisseau, this);
}

CJeu::~CJeu()
{
	LeThread->detach();
	delete LeThread;
	delete mesTours[0];
	delete mesTours[1];
	delete mesTours[2];
	delete mesTours;
	for (int i = 0; i < 10; i++)
	{
		delete mesVaisseaux[i];
	}
}

void CJeu::goVaisseau()
{
	while (CVaisseau::nbVaisseauACreer != 0)
	{
		if (CVaisseau::nbVaisseau < 4) { //pas + de 4 vaisseau en meme temps sur le jeu
			mesVaisseaux[9 - CVaisseau::nbVaisseauACreer] = new CVaisseau(9 - CVaisseau::nbVaisseauACreer, this);
			listeVaisseaux[9 - CVaisseau::nbVaisseauACreer] = 1;
		}
		this_thread::sleep_for(chrono::milliseconds(3200));
	}
}

int CJeu::getColV(int i)
{
	if (listeVaisseaux[i] != 0)
	{
		return mesVaisseaux[i]->getCol();
	}
	return -1;
}
int CJeu::getLigV(int i)
{
	if (listeVaisseaux[i] != 0)
	{
		return mesVaisseaux[i]->getLig();
	}
	return -1;
}

void CJeu::setMonVaisseauZero(int position)
{
	listeVaisseaux[position] = 0;
}

//modifier pour obtenir direct l'indice du vaisseau à killer
void CJeu::tuerUnVaisseau(int position)
{
	mesVaisseaux[position]->deleteCeVaisseau();
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
			mesTours[0]->lancerMissile();
			break;
		case 2:
			mesTours[1]->lancerMissile();
			break;
		case 3:
			mesTours[2]->lancerMissile();
			break;
		default:
			break;
		}
		//On demande un nouveau numéro
		monNumChar = _getch();
		monNum = monNumChar - 48;
	}
}
//Gotoxy(COLONNE,LIGNE)