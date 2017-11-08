#include <iostream>

#include <thread>
#include <mutex>

using namespace std;

#include "CVaisseau.h"
#include "CEcran.h"

mutex CVaisseau::Verrou;

CVaisseau::CVaisseau()
{
	//Définir aléatoirement s'il se déplacera de DG ou GD

	//GD Colonne départ minimum 0 -> colonne = élément du centre
	Colonne = 0;
	Ligne = 10;
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
		Verrou.lock();
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
		Verrou.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	Verrou.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 1, Ligne);
	cout << " ";
	CEcran::Gotoxy(Colonne + 2, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	Verrou.unlock();
	delete this;
}