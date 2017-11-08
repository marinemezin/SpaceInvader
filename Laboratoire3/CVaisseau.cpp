#include <iostream>
#include "CVaisseau.h"
#include "CEcran.h"
#include "CJeu.h"
#include <thread>

using namespace std;


CVaisseau::CVaisseau()
{
	//D�finir al�atoirement s'il se d�placera de DG ou GD

	//GD Colonne d�part minimum 0 -> colonne = �l�ment du centre
	Colonne = 0;
	//Lignes entre 1 et 15
	Ligne = 15;
	LeThread = new thread(&CVaisseau::deplacerGD, this);
	//DG colonne d�part minimum 100

	//M�thode pour cr�er vaisseau
}

CVaisseau::~CVaisseau()
{
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
		CEcran::Gotoxy(0, 29);
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