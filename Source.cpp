#include "Header.h"

int main()
{
	string tiret;
	t_biblio bibliotheque;
	bibliotheque.nbibli = 0;
	string titre;
	int choix, ind, E;
	tiret = " ---------------------------------------------------------------------";
	do
	{
		system("CLS");
		cout << tiret << endl;
		cout << " |1- Afficher l'ensemble des livres de la bibliotheque.              |\n";
		cout << " |2- Ajouter un nouveau livre.                                       |\n";
		cout << " |3- Supprimer un livre.                                             |\n";
		cout << " |4- Rechercher un livre.                                            |\n";
		cout << " |5- Verifier que la bibliotheque est un ensemble.                   |\n";
		cout << " |6- Quitter.                                                        |\n";
		cout << tiret << endl;
		cout << "		Quel est votre choix ? ";

		cin >> choix;

		system("CLS");
		switch (choix)
		{
			case 1: affichage(bibliotheque);
				break;
			case 2: ajout(bibliotheque);
				break;
			case 3: suppression(bibliotheque);
				break;
			case 4: cout<< "Saisir le titre du livre que vous recherchez: ";
			cin>> titre;
			ind = recherche(bibliotheque, titre);
			if (ind < 0)
			{
				cout << "Desole mais nous ne sommes pas en possession de ce livre.";
			}
			else
			{
				// FAIRE LA MEME CHOSE MAIS AVEC UN TABLEAU POUR SI LE LIVRE EXISTE EN PLUSIEURS EXEMPLAIRES
				cout << endl <<"Nous possedons ce livre, il se trouve en position numero " << ind+1 << endl;
			}
			system("PAUSE");
			break;
			case 5:	E=verif(bibliotheque);
				if (E==false)
				{
					cout << "Ce n'est pas un ensemble" << endl;
				}
				else
				{
					cout << "C'est une ensemble" << endl;
				}
				system("PAUSE"); 
				break;
			case 6: "Au revoir ! ";
				break;
		}
	}while (choix != 6);
}

