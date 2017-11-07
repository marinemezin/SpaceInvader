#include <iostream>
using namespace std;
#include "CJeu.h";
#include "CEcran.h";


int main()
{
	CJeu *jeu = new CJeu();
	jeu->Afficher();
	CEcran::Gotoxy(0, 29);
	system("PAUSE");
	return 0;
}

/*
Il faut verifie appuyer sur une touche pour le missile et verifier un missile par tour
Faire les vaisseau

*/