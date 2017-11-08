#include <iostream>
#include "CJeu.h"
#include "CEcran.h"

using namespace std;

int main()
{
	CJeu *jeu = new CJeu();
	jeu->jouer();
	CEcran::Gotoxy(0, 30);
	system("PAUSE");
	return 0;
}

/*
Tant qu'il y a encore des vaisseaux qui sont vivants ou créés alors la partie continue :
Mettre un nombre max de vaisseau actuellement en vie et de vaisseaux restants à créer

Random pour ligne des vaisseaux à faire
Faire DG pour vaisseau
*/