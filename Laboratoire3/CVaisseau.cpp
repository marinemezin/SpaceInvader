#include <iostream>
#include "CVaisseau.h"
#include "CEcran.h"
#include "CJeu.h"
#include <thread>


using namespace std;

int CVaisseau::nbVaisseau = 0;

bool CVaisseau::premierVaisseau = false;
int CVaisseau::nbVaisseauACreer = 10;

CVaisseau::CVaisseau(int p, CJeu* jeu)
{
	place = p;
	doitMourir = false;
	monJeu = jeu;
	if (!premierVaisseau)
	{
		srand(time(NULL));
		CVaisseau::premierVaisseau = true;
	}
	nbVaisseau++;
	nbVaisseauACreer--;
	//Lignes entre 1 et 15
	Ligne = rand() % 15; //entre 2 et 15
	Ligne = Ligne + 2;
	int destin = rand() % 2;
	if (destin == 0) { //GD
		Colonne = 1;
		LeThread = new thread(&CVaisseau::deplacerGD, this);
	}
	else { //DG
		Colonne = 99;
		LeThread = new thread(&CVaisseau::deplacerDG, this);
	}
}

CVaisseau::~CVaisseau()
{
	nbVaisseau--;
	monJeu->setMonVaisseauZero(place);
	LeThread->detach();
	delete LeThread;
}

void CVaisseau::deplacerGD()
{
	while ((Colonne + 1 < 100) && (!doitMourir))
	{
		CJeu::VerrouJeu.lock();
		//On efface l'ancien vaisseau
		CEcran::Gotoxy(Colonne - 1, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne + 1, Ligne);
		cout << " ";
		//On place le nouveau vaisseau
		Colonne++;
		CEcran::Gotoxy(Colonne - 1, Ligne);
		cout << "<";
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "*";
		CEcran::Gotoxy(Colonne + 1, Ligne);
		cout << ">";
		CEcran::Gotoxy(0, 30);
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne - 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}

void CVaisseau::deplacerDG()
{
	while ((Colonne - 1 > 0) && (!doitMourir))
	{
		CJeu::VerrouJeu.lock();
		//On efface l'ancien vaisseau
		CEcran::Gotoxy(Colonne + 1, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		CEcran::Gotoxy(Colonne - 1, Ligne);
		cout << " ";
		//On place le nouveau vaisseau
		Colonne--;
		CEcran::Gotoxy(Colonne + 1, Ligne);
		cout << ">";
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "*";
		CEcran::Gotoxy(Colonne - 1, Ligne);
		cout << "<";
		CEcran::Gotoxy(0, 30);
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	if (doitMourir)
	{
		destructionAnimee();
	}
	else
	{
		destructionClassique();
	}
}

void CVaisseau::destructionClassique()
{
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne + 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne - 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}

void CVaisseau::destructionAnimee()
{
	CJeu::VerrouJeu.lock();
	destructionAnimeecarac("*", true);
	this_thread::sleep_for(chrono::milliseconds(150));
	destructionAnimeecarac(" ", false);
	CJeu::VerrouJeu.unlock();
	delete this;
}

void CVaisseau :: destructionAnimeecarac(string carac, bool temps)
{
	CEcran::Gotoxy(Colonne, Ligne);
	cout << carac;
	CEcran::Gotoxy(Colonne + 1, Ligne);
	cout << carac;
	CEcran::Gotoxy(Colonne - 1, Ligne);
	cout << carac;
	CEcran::Gotoxy(Colonne, Ligne + 1);
	cout << carac;
	CEcran::Gotoxy(Colonne, Ligne - 1);
	cout << carac;
	if (temps)
	{
		this_thread::sleep_for(chrono::milliseconds(300));
	}
	CEcran::Gotoxy(Colonne + 2, Ligne);
	cout << carac;
	CEcran::Gotoxy(Colonne - 2, Ligne);
	cout << carac;
	CEcran::Gotoxy(Colonne, Ligne + 2);
	cout << carac;
	CEcran::Gotoxy(Colonne, Ligne - 2);
	cout << carac;
	CEcran::Gotoxy(Colonne + 1, Ligne + 1);
	cout << carac;
	CEcran::Gotoxy(Colonne + 1, Ligne - 1);
	cout << carac;
	CEcran::Gotoxy(Colonne - 1, Ligne + 1);
	cout << carac;
	CEcran::Gotoxy(Colonne - 1, Ligne - 1);
	cout << carac;
	CEcran::Gotoxy(0, 0);
}

void CVaisseau::deleteCeVaisseau()
{
	monJeu->setScorePlus1();
	doitMourir = true;
}