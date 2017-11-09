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
Méthode collision faite
Remonter qu'il y a eu une collision à notre plateau de jeu pour qu'il fasse mourir le vaisseau concerné
Cad Le missile a déjà été tué reste à tuer le vaisseau
*/