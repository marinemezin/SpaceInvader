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
M�thode collision faite
Remonter qu'il y a eu une collision � notre plateau de jeu pour qu'il fasse mourir le vaisseau concern�
Cad Le missile a d�j� �t� tu� reste � tuer le vaisseau
*/