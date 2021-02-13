#include "Header.h"

void affichage(t_biblio& bibliotheque)
{
	int i;
	string dièse;
	dièse = "#####################################################################";

	if (bibliotheque.nbibli == 0)
	{
		cout << "La bibliotheque ne comporte actuellement aucun livre.\n" << endl;
	}
	else
	{
		for (i = 0; i < bibliotheque.nbibli; i++)
		{
			cout << dièse << endl << endl;
			cout << "Titre: " << bibliotheque.livre[i].titre << endl;
			cout << "Auteur: " << bibliotheque.livre[i].nom << endl;
			cout << "Annee de parution: " << bibliotheque.livre[i].annee << endl;
			cout << "Nombre de pages: " << bibliotheque.livre[i].pages << endl << endl;
		}
		cout << dièse << endl;
	}
	system("PAUSE");
}

void ajout(t_biblio& bibliotheque)
{
	int i;
	int att;
	if (bibliotheque.nbibli < 100)
	{
		cout << "Saisir le titre du livre: ";
		cin >> bibliotheque.livre[bibliotheque.nbibli].titre;
		cout << endl<<"Saisir le nom de l'auteur du livre: ";
		cin >> bibliotheque.livre[bibliotheque.nbibli].nom;
		cout << endl << "Saisir l'annee de parrution du livre: ";
		cin >> bibliotheque.livre[bibliotheque.nbibli].annee;
		cout << endl << "Saisir le nombre de pages du livre: ";
		cin >> bibliotheque.livre[bibliotheque.nbibli].pages;
		if (bibliotheque.livre[bibliotheque.nbibli].pages <= 0)
		{
			cout << "Nombre de pages incorrect." << endl;
				bibliotheque.livre[bibliotheque.nbibli].nom = bibliotheque.livre[bibliotheque.nbibli  + 1].nom;
				bibliotheque.livre[bibliotheque.nbibli].annee = bibliotheque.livre[bibliotheque.nbibli + 1].annee;
				bibliotheque.livre[bibliotheque.nbibli].pages = bibliotheque.livre[bibliotheque.nbibli + 1].pages;
				bibliotheque.livre[bibliotheque.nbibli].titre = bibliotheque.livre[bibliotheque.nbibli + 1].titre;
		}
		else
		{
			bibliotheque.nbibli = bibliotheque.nbibli + 1;
		}
	}
	system("PAUSE");
}

void suppression(t_biblio& bibliotheque)
{
	int i, j;
	bool test;
	test = true;
	i = 0;
	string titre, nom;
	int annees, pages;

	cout << "Quel est le titre du livre ?" << endl;
	cin >> titre;
	cout << "Quel est le nom de l'auteur du livre ?" << endl;
	cin >> nom;
	cout << "Quel est l'annee de parution du livre ?" << endl;
	cin >> annees;
	cout << "Quel est le nombre de pages du livre ?" << endl;
	cin >> pages;

	for (i = 0; i < bibliotheque.nbibli - 1; i++)
	{
		if (titre == bibliotheque.livre[i].titre)
		{
			if (nom == bibliotheque.livre[i].nom)
			{
				if (annees == bibliotheque.livre[i].annee)
				{
					if (pages == bibliotheque.livre[i].pages)
					{
						for (j = 0; j < bibliotheque.nbibli; j++)
						{
							bibliotheque.livre[i].nom = bibliotheque.livre[i + 1].nom;
							bibliotheque.livre[i].annee = bibliotheque.livre[i + 1].annee;
							bibliotheque.livre[i].pages = bibliotheque.livre[i + 1].pages;
							bibliotheque.livre[i].titre = bibliotheque.livre[i + 1].titre;
						}
						cout << "Le livre a bien etait supprimé." << endl;
					}
				}
			}
		}
		else
		{
			cout << "Impossible de supprimer ce livre, nous ne le possedons pas." << endl;
		}
	}
	bibliotheque.nbibli = bibliotheque.nbibli - 1;
	system("PAUSE");
}

int recherche(t_biblio& bibliotheque, string titre)
{
	int i, j;
	j = 0;

	for (i = 0; i < bibliotheque.nbibli - 1; i++)
	{
		if (Maj(bibliotheque.livre[i].titre) == Maj(titre))
		{
			j = i;
		}
		else
		{
			j = -1;
		}
	}
	return j;
}

string Maj(string chaine) {
	int i;
	string ch = chaine;

	for (i = 0; i <= int(chaine.length()); i++) {
		ch[i] = (toupper(ch[i]));
	}
	return ch;
}

bool verif(t_biblio& bibliotheque)
{
	bool verif;
	int i, j;
	i = 0; 
	j = 0; 
	verif = true; 

	while (verif && i != bibliotheque.nbibli)
	{
		for (j = i + 1; j < bibliotheque.nbibli - 1; j++)
		{
			if (bibliotheque.livre[j].titre == bibliotheque.livre[i].titre)
			{
				if (bibliotheque.livre[j].nom == bibliotheque.livre[i].nom)
				{
					if (bibliotheque.livre[j].annee == bibliotheque.livre[i].annee)
					{
						if (bibliotheque.livre[j].pages == bibliotheque.livre[i].pages)
						{
							verif = false;
						}
					}
				}
			}
		}
		i = i++;
	}
	return verif;
}