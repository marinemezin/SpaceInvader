#include <iostream>

#include <thread>
#include <mutex>

using namespace std;

#include "CVaisseau.h"
#include "CEcran.h"

mutex CVaisseau::VerrouVaisseau;

CVaisseau::CVaisseau()
{
	//Définir aléatoirement s'il se déplacera de DG ou GD

	//GD Colonne départ minimum 0 -> colonne = élément du centre
	Colonne = 0;
	//Lignes entre 1 et 15
	Ligne = 15;
	LeThread = new thread(&CVaisseau::deplacerGD, this);
	//DG colonne départ minimum 100

	//Méthode pour créer vaisseau
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
		VerrouVaisseau.lock();
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
		VerrouVaisseau.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	VerrouVaisseau.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 2, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	VerrouVaisseau.unlock();
	delete this;
}