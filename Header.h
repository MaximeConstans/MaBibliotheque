#ifndef BIBLIO_H
#define BIBLIO_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
const int MAX_AUTEURS = 100;

typedef struct {
	string titre;
	string nom;
	int annee;
	int pages;
}t_livre;

typedef struct {
	int nbibli;
	t_livre livre[MAX];
}t_biblio;

typedef struct {
	string nom;
	string prenom;
	string nat;
	int ann_naiss;
	int ann_dec;
}t_auteur;

typedef struct {
	t_auteur auteurs[MAX_AUTEURS];
	int n;
}t_liste_auteur;

void affichage(t_biblio& bibliotheque);
void ajout(t_biblio& bibliotheque);
void suppression(t_biblio& bibliotheque);
int recherche(t_biblio& bibliotheque, std::string titre );
bool verif(t_biblio& bibliotheque);
string Maj( string nom);

#endif