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
Dans CJeu.cpp on poss�de une liste de tous les vaisseaux qui vont ou ont ou sont (�t�) lanc�s
Dans CMissile avant de faire monter le missile il faut v�rifier si un vaisseau de cette liste :
- vaisseau non �gale � 0
- ligne entre 1 et 15
- colonne entre 0 et 100
se trouve sur la m�me case que l� o� le missile veux aller (attention un vaisseau � 3 cases)

*/