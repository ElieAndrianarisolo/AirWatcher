/*************************************************************************
Fournisseur  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if ! defined (FOURNISSEUR_H)
#define FOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>
#include "Personne.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur> :
// Représenter un fournisseur
//------------------------------------------------------------------------

class Fournisseur : public Personne
{
    //----------------------------------------------------------------- PUBLIC

  public:
    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const Fournisseur & fournisseur);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Fournisseur.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    Fournisseur & operator = (const Fournisseur & unFournisseur);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Fournisseur.
    // Contrat :
    // Aucun contrat spécifique.

    //-------------------------------------------- Constructeurs - destructeur

    Fournisseur(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse);
    // Mode d'emploi :
    // Construit un objet Fournisseur avec les paramètres spécifiés.
    // Contrat :
    // Aucun contrat spécifique.
};

#endif // FOURNISSEUR_H
