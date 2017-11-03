#include <iostream>
using namespace std;
#include "CJeu.h";
#include "CEcran.h";


int main()
{
	CJeu *jeu = new CJeu();
	jeu->Afficher();
	CEcran::Gotoxy(0, 31);
	system("PAUSE");
	return 0;
}