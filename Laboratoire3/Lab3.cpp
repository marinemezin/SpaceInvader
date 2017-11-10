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