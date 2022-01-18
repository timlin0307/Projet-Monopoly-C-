/*
 * Terrain.cpp
 *
 *  Created on: 18 d�c. 2021
 *      Author: lucas
 */


#include <iostream>
#include <string>
using namespace std;
#include "Terrain.h"
#include "Joueur.h"


Terrain :: Terrain(string nomcase, int loyer, int prixachat, string nomjoueur,
		int valhypo,string couleur, int * list_loyer, int prix_maison, int nb_maisons, Joueur* jref, bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	this -> couleur = couleur;
	this -> list_loyer = list_loyer;
	this -> prix_maison = prix_maison;
	this -> nb_maisons = nb_maisons;
	this -> appartient_a = jref;
}


void Terrain :: arreterSur(Joueur* j, int de)
{
	if (nom_joueur == "")
	{
		cout << "la case n'appartient � personne" << endl;
		cout << "le prix d'achat est de " << prixAchat << endl;
		cout << "votre solde de compte en banque est " << (*j).getSolde() << endl;
		cout << "souhaitez vous l'acheter ?" << endl;
		cout << "Si oui taper 1, si non taper 2" << endl;
		int achat;
		cin >> achat ;

		if (achat == 1)
		{
			(*j).debiter(prixAchat);
			nom_joueur = (*j).getNom();
			appartient_a = j;
			cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
		}
	}

	else if (hypotheque == false )
	{
		cout << "la case appartient � " << nom_joueur << endl;
		this -> calcul_loyer();
		int a_payer = loyer;
		(*appartient_a).crediter(a_payer);
		(*j).debiter(a_payer);
		cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
	}
	else
	{
		cout << "la case appartient � " << nom_joueur << endl;
		cout << "elle est hypoth�qu�e tu n'as rien a pay�" << endl;
	}
}

void Terrain :: calcul_loyer()
{
	if (nb_maisons == 0)
	{
		loyer = list_loyer[0];/* verif si le joueur a les cases de la meme couleur si oui *2 terrain nu */
	}
	else
	{
		loyer = list_loyer[nb_maisons];
	}
}


int Terrain :: get_NBmaisons()
{
	return nb_maisons;
}


void Terrain :: ajoute_maison()
{
	cout << "vous avez actuellement " << nb_maisons <<endl;
	cout <<  "voulez-vous en racheter une ou plusieurs, sachaant que vous ne pouvez pas exceder 5 maisons qui est �quivalent � un hotel ?" << endl;
	int nb;
	cin >> nb ;

	try {
		if (nb + nb_maisons <= 5)
		{
			throw (nb);
		}
		else
		{
			string except = "Vous ne pouvez pas construire autant de maisons. Veuillez recommencer ";
			throw (except);
		}
	}
	catch (int nb) {
	cout << "On va rajouter " << nb << " maisons " << "\n" ;
	(*appartient_a).debiter(nb*prix_maison);
	nb_maisons = nb_maisons + nb;
	cout << "votre nouveau solde de compte en banque est " << (*appartient_a).getSolde() << endl;
	cout <<  "Vous avez maintenant " << nb << " maisons " << endl;
	}
	catch (string except) {
	cout << except << "\n" ;


	}
}
