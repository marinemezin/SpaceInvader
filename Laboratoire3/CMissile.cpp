#include <iostream>

#include <thread>

#include "CMissile.h"
#include "CEcran.h"
#include "CJeu.h"

using namespace std;

CMissile::CMissile(int Lig, int Col, CTour* tour, CJeu* jeu)
{
	Colonne = Col;
	Ligne = Lig;
	LeThread = new thread(&CMissile::monter, this);
	maTour = tour;
	monJeu = jeu;
}

CMissile::~CMissile()
{
	maTour->setMonMissileZero();
	LeThread->detach();
	delete LeThread;
}

void CMissile::monter()
{
	bool collision = false;
	while (Ligne > 0)
	{
		CJeu::VerrouJeu.lock();
		//Collision ? 
		collision = attentionCollision();
		if (!collision) {
			CEcran::Gotoxy(Colonne, Ligne);
			cout << " ";
			Ligne--;
			CEcran::Gotoxy(Colonne, Ligne);
			cout << "|";
			CEcran::Gotoxy(0, 30);
		}
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}

bool CMissile::sousTestCollision(int colV, int ligV)
{
	if (Colonne == colV) {
		if (Ligne - 1 == ligV) {
			return true;
		}
	}
	return false;
}

bool CMissile::attentionCollision()
{
	bool collision = false;
	for (int i = 0; i < 10; i++) {
		if (monJeu->getColV(i) != -1) {
			int colV = monJeu->getColV(i);
			int ligV = monJeu->getLigV(i);
			//S'il touche le bout droit
			bool test1 = sousTestCollision(colV - 1, ligV);
			//S'il touche le milieu
			bool test2 = sousTestCollision(colV, ligV);
			//S'il touche le bout gauche
			bool test3 = sousTestCollision(colV + 1, ligV);
			if (test1 || test2 || test3) {
				collision = true;
				if (test1) { monJeu->tuerUnVaisseau(i); }
				if(test2) { monJeu->tuerUnVaisseau(i); }
				if(test3) { monJeu->tuerUnVaisseau(i); }
			}
		}
	}
	return collision;
}