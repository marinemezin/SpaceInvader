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
Dans CJeu.cpp on possède une liste de tous les vaisseaux qui vont ou ont ou sont (été) lancés
Dans CMissile avant de faire monter le missile il faut vérifier si un vaisseau de cette liste :
- vaisseau non égale à 0
- ligne entre 1 et 15
- colonne entre 0 et 100
se trouve sur la même case que là où le missile veux aller (attention un vaisseau à 3 cases)

*/