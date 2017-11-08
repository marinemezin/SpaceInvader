#include <iostream>
#include "CVaisseau.h"
#include "CEcran.h"
#include "CJeu.h"
#include <thread>

using namespace std;

int CVaisseau::nbVaisseau = 0;

bool CVaisseau::premierVaisseau = false;

CVaisseau::CVaisseau()
{
	if (!premierVaisseau)
	{
		srand(time(NULL));
		CVaisseau::premierVaisseau = true;
	}
	nbVaisseau++;
	//Lignes entre 1 et 15
	Ligne = rand() % 15;
	Ligne++;
	int destin = rand() % 2;
	if (destin == 0) { //GD
		Colonne = 0;
		LeThread = new thread(&CVaisseau::deplacerGD, this);
	}
	else { //DG
		Colonne = 100;
		LeThread = new thread(&CVaisseau::deplacerDG, this);
	}
}

CVaisseau::~CVaisseau()
{
	nbVaisseau--;
	LeThread->detach();
	delete LeThread;
}

void CVaisseau::deplacerGD()
{
	while (Colonne + 2 < 100)
	{
		CJeu::VerrouJeu.lock();
		//On efface l'ancien vaisseau
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne + 1, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne + 2, Ligne);
		cout << " ";
		//On place le nouveau vaisseau
		Colonne++;
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "<";
		CEcran::Gotoxy(Colonne + 1, Ligne);
		cout << "*";
		CEcran::Gotoxy(Colonne + 2, Ligne);
		cout << ">";
		CEcran::Gotoxy(0, 30);
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 2, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}

void CVaisseau::deplacerDG()
{
	while (Colonne - 2 > 0)
	{
		CJeu::VerrouJeu.lock();
		//On efface l'ancien vaisseau
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne - 1, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne - 2, Ligne);
		cout << " ";
		//On place le nouveau vaisseau
		Colonne--;
		CEcran::Gotoxy(Colonne, Ligne);
		cout << ">";
		CEcran::Gotoxy(Colonne - 1, Ligne);
		cout << "*";
		CEcran::Gotoxy(Colonne - 2, Ligne);
		cout << "<";
		CEcran::Gotoxy(0, 30);
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne - 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne - 2, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}