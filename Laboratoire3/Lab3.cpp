#include <iostream>
#include "CJeu.h"
#include "CEcran.h"

using namespace std;

int main()
{
	CJeu *jeu = new CJeu();
	jeu->jouer();
	CEcran::Gotoxy(0, 29);
	system("PAUSE");
	return 0;
}

/*
Problème avec les lock
Les vaisseaux et missiles s'effacent mal et des parties restent bloquer comme la neige du prof avant le lock
*/