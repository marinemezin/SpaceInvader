#ifndef CECRAN_H
#define CECRAN_H
//#define LINUX
/**
* Cette classe fournis des services de gestion d'�cran en utilisant ansi.
*/
class CEcran
{
public:
	/**
	* Efface l'�cran au complet.
	*/
	static void ClrScr();

	/**
	* DessineCasement � la position x, y.
	* x Positon en x entre 1 et 80.
	* y Positon en y entre 1 et 25.
	*/
	static void Gotoxy(int x, int y);

	/**
	* Changer la couleur de fond et d'�criture.
	* f La couleur de fond.
	* l La couleur d'�criture.
	*/
	static void setCouleur(int f, int l);
};

#endif