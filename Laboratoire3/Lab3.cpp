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
Beug sur methode getColV
Problème de lecture
Me dit que la listeVaisseau est vide alors que j'initialise tout à 0 au début dans le constructeur
*/