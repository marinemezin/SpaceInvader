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
CVaisseau* CJeu::getVaisseau(int i)
{
if (mesVaisseaux[i]->getCol() != -1)
{
return mesVaisseaux[i];
}
return 0;
}

Cette m�thode beug
Il me dit que le tableau est vide alors que je le rempli
Je pense que le probl�me viens d'un probl�me de synchronisation des threads

En mode debug tout fonctionne mais quand je lance �a ne fonctionne plus 
*/