/*
 * Compagnie.cpp
 *
 *  Created on: 18 d�c. 2021
 *      Author: lucas
 */

#include <iostream>
#include <string>
using namespace std;
#include "Compagnie.h"
#include "Joueur.h"

Compagnie ::Compagnie(string nomcase, int loyer, int prixachat, string nomjoueur,int valhypo, joueur* j, bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	appartient_a = j;
}

void Compagnie :: arreterSur(joueur* j, int de)
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
		this -> calcul_loyer(de);
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

void Compagnie :: calcul_loyer(int de)
{
	loyer = de *4;/* il faut pouvoir s�parer les diff�rents cas */

	/*
	 * mettre le nom du joueur en argument ou carrement le pointeur du joueur a qui appartient la case
	 * L'autre case appartient � :
	 *
	 * Case departure = plateau.getCase(0);
	 * departure.deplacement(&j1, 12);	-> obliger de faire un d�placement pour retrouver l'autre case ???
	 *
	 * if meme nom
	 * int coef =10;
	 *
	 * else
	 * int coef =4;
	 *
	 * loyer = de * coef;
	 */
}



