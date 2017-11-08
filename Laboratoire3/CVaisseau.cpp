#include <iostream>

#include <thread>
#include <mutex>

using namespace std;

#include "CVaisseau.h"
#include "CEcran.h"

mutex CVaisseau::Verrou;

CVaisseau::CVaisseau()
{
	//D�finir al�atoirement s'il se d�placera de DG ou GD

	//GD Colonne d�part minimum 0 -> colonne = �l�ment du centre
	Colonne = 0;
	Ligne = 10;
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