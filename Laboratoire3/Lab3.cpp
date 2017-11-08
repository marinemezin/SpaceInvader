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
Il faut verifie appuyer sur une touche pour le missile et verifier un missile par tour
Faire les vaisseau

*/