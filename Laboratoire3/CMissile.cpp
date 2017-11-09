#include <iostream>

#include <thread>

#include "CMissile.h"
#include "CEcran.h"
#include "CJeu.h"

using namespace std;

CMissile::CMissile(int Lig, int Col, CTour* tour/*, CJeu* jeu*/)
{
	Colonne = Col;
	Ligne = Lig;
	LeThread = new thread(&CMissile::monter, this);
	maTour = tour;
	//monJeu = jeu;
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
		//vérifier ici s'il y a collision ou non
		//Si non on bouge le missile normalement
		CEcran::Gotoxy(Colonne, Ligne);
		cout << " ";
		Ligne--;
		CEcran::Gotoxy(Colonne, Ligne);
		cout << "|";
		CEcran::Gotoxy(0, 30);
		CJeu::VerrouJeu.unlock();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	CJeu::VerrouJeu.lock();
	CEcran::Gotoxy(Colonne, Ligne);
	cout << " ";
	CEcran::Gotoxy(0, 0);
	CJeu::VerrouJeu.unlock();
	delete this;
}

bool CMissile::sousTestCollision(int colM, int ligM, int colV, int ligV)
{
	if (colM == colV)
	{
		if (ligM - 1 == ligV)
		{
			return true;
		}
	}
	return false;
}

bool CMissile::collision()
{
	bool collision = false;
	for (int i = 0; i < 10; i++)
	{
		//S'il touche le bout droit
		/*if (Colonne == mesVaisseaux[i]->getCol() - 1)
		{
			if (Ligne - 1 == mesVaisseaux[i]->getLig())
			{
				collision = true;
			}
		}*/
		//S'il touche le milieu
		/*if (Colonne == mesVaisseaux[i]->getCol())
		{
			if (Ligne - 1 == mesVaisseaux[i]->getLig())
			{
				collision = true;
			}
		}*/
		//S'il touche le bout gauche
		/*if (Colonne == mesVaisseaux[i]->getCol() + 1)
		{
			if (Ligne - 1 == mesVaisseaux[i]->getLig())
			{
				collision = true;
			}
		}*/
	}
	return collision;
}