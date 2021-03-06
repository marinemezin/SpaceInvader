#include <iostream>
#include "CEcran.h"
#include "CJeu.h"
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include "CTour.h"

using namespace std;

mutex CJeu::VerrouJeu;

CJeu::CJeu() {
	score = 0;
	for (int i = 0; i < 10; i++) {
		mesVaisseaux[i] = 0;
		listeVaisseaux[i] = 0;
	}
	mesTours[0] = new CTour(1, 28, 20, this);
	mesTours[1] = new CTour(2, 28, 50, this);
	mesTours[2] = new CTour(3, 28, 80, this);
	mesTours[0]->afficher();
	mesTours[1]->afficher();
	mesTours[2]->afficher();
	LeThread = new thread(&CJeu::goVaisseau, this);
	LeThreadScore = new thread(&CJeu::afficherScore, this);
}

CJeu::~CJeu() {
	LeThread->detach();
	delete LeThread;
	delete mesTours[0];
	delete mesTours[1];
	delete mesTours[2];
	delete mesTours;
	for (int i = 0; i < 10; i++) {
		delete mesVaisseaux[i];
	}
}

void CJeu::goVaisseau() {
	while (CVaisseau::nbVaisseauACreer != 0) {
		if (CVaisseau::nbVaisseau < 4) {
			CVaisseau* myV = new CVaisseau(10 - CVaisseau::nbVaisseauACreer, this);
			mesVaisseaux[9 - CVaisseau::nbVaisseauACreer] = myV;
			listeVaisseaux[9 - CVaisseau::nbVaisseauACreer] = 1;
		}
		this_thread::sleep_for(chrono::milliseconds(3200));
	}
}

int CJeu::getColV(int position) {
	bool col = 1;
	if (listeVaisseaux[position] != 0) {
		return mesVaisseaux[position]->getCol();
	}
	return -1;
}

int CJeu::getLigV(int position) {
	if (listeVaisseaux[position] != 0) {
		return mesVaisseaux[position]->getLig();
	}
	return -1;
}

void CJeu::setScorePlus1() {
	score = score + 1;
}

void CJeu::setMonVaisseauZero(int position) {
	listeVaisseaux[position] = 0;
}

void CJeu::tuerUnVaisseau(int position) {
	mesVaisseaux[position]->deleteCeVaisseau();
}

void CJeu::afficherScore() {
	int scoreInitial = score;
	while (CVaisseau::nbVaisseau != 0) {
		if (scoreInitial != score) {
			VerrouJeu.lock();
			CEcran::Gotoxy(0, 29);
			cout << "Score : ";
			CEcran::Gotoxy(9, 29);
			cout << score;
			VerrouJeu.unlock();
		}
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

void CJeu::jouer() {
	char monNumChar = _getch();
	int monNum = monNumChar - 48;
	while (CVaisseau::nbVaisseau != 0) {
		switch (monNum) {
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
		monNumChar = _getch();
		monNum = monNumChar - 48;
	}
}