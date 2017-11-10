#include <iostream>
#include <thread>
#include "CMissile.h"
#include "CEcran.h"
#include "CJeu.h"

using namespace std;

CMissile::CMissile(int Lig, int Col, CTour* tour) {
	Colonne = Col;
	Ligne = Lig;
	maTour = tour;
	LeThread = new thread(&CMissile::monter, this);
}

CMissile::~CMissile() {
	maTour->setMonMissileZero();
	LeThread->detach();
	delete LeThread;
}

void CMissile::monter() {
	bool collision = false;
	while ((Ligne > 0) && (!collision)) {
		CJeu::VerrouJeu.lock();
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

bool CMissile::sousTestCollision(int colV, int ligV) {
	if (Colonne == colV) {
		if (Ligne - 1 == ligV) {
			return true;
		}
	}
	return false;
}

bool CMissile::attentionCollision() {
	bool collision = false;
	for (int i = 0; i < 10; i++) {
		if (maTour->getMonJeu()->getColV(i) != -1) {
			int colV = maTour->getMonJeu()->getColV(i);
			int ligV = maTour->getMonJeu()->getLigV(i);
			//S'il touche le bout droit
			bool test1 = sousTestCollision(colV - 1, ligV);
			//S'il touche le milieu
			bool test2 = sousTestCollision(colV, ligV);
			//S'il touche le bout gauche
			bool test3 = sousTestCollision(colV + 1, ligV);
			if (test1 || test2 || test3) {
				collision = true;
				if (test1) { maTour->getMonJeu()->tuerUnVaisseau(i); }
				if(test2) { maTour->getMonJeu()->tuerUnVaisseau(i); }
				if(test3) { maTour->getMonJeu()->tuerUnVaisseau(i); }
			}
		}
	}
	return collision;
}