/*************************************************************************
Fournisseur  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp)------------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Fournisseur.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Fournisseur & fournisseur)
{
    os << "Fournisseur : {id : " << fournisseur.id << ", prenom : " << fournisseur.prenom << ", nom : " << fournisseur.nom << ", adresse : " << fournisseur.adresse << ", login : " << fournisseur.login << ", mot de passe : " << fournisseur.motDePasse << "}";
    return os;
} //----- Fin de operator <<

Fournisseur &Fournisseur::operator=(const Fournisseur &unFournisseur)
{
    id = unFournisseur.id;
    prenom = unFournisseur.prenom;
    nom = unFournisseur.nom;
    adresse = unFournisseur.adresse;
    login = unFournisseur.login;
    motDePasse = unFournisseur.motDePasse;

    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

Fournisseur::Fournisseur(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse) : Personne(newId,newPrenom,newNom,newAdresse,newLogin,newMotDePasse) 
{
    #ifdef MAP
        cout << "Appel au constructeur de <Fournisseur>" << endl;
    #endif
} //----- Fin de Fournisseur
