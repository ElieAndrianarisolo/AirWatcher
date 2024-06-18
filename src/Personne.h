/*************************************************************************
Personne  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Personne> (fichier Personne.h) ----------------
#if ! defined (PERSONNE_H)
#define PERSONNE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Personne> :
// Représenter une personne
//------------------------------------------------------------------------

class Personne
{
    //----------------------------------------------------------------- PUBLIC

  public:
    //----------------------------------------------------- Getters et setters

    int getId() const;
    // Mode d'emploi :
    // Renvoie l'identifiant de la personne.
    // Contrat :
    // Aucun contrat spécifique.

    void setId(int id);
    // Mode d'emploi :
    // Modifie l'identifiant de la personne avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    string getPrenom() const;
    // Mode d'emploi :
    // Renvoie le prénom de la personne.
    // Contrat :
    // Aucun contrat spécifique.

    void setPrenom(string prenom);
    // Mode d'emploi :
    // Modifie le prénom de la personne avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    string getNom() const;
    // Mode d'emploi :
    // Renvoie le nom de la personne.
    // Contrat :
    // Aucun contrat spécifique.

    void setNom(string nom);
    // Mode d'emploi :
    // Modifie le nom de la personne avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    string getAdresse() const;
    // Mode d'emploi :
    // Renvoie l'adresse de la personne.
    // Contrat :
    // Aucun contrat spécifique.

    void setAdresse(string adresse);
    // Mode d'emploi :
    // Modifie l'adresse de la personne avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    string getLogin() const;
    // Mode d'emploi :
    // Renvoie le login de la personne.
    // Contrat :
    // Aucun contrat spécifique.

    void setLogin(string login);
    // Mode d'emploi :
    // Modifie le login de la personne avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    string getMotDePasse() const;
    // Mode d'emploi :
    // Renvoie le mot de passe de la personne.
    // Contrat :
    // Aucun contrat spécifique.

    void setMotDePasse(string motDePasse);
    // Mode d'emploi :
    // Modifie le mot de passe de la personne avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.
    
    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const Personne & personne);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Personne.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    //-------------------------------------------- Constructeurs - destructeur

    Personne (int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse);
    // Mode d'emploi :
    // Construit un objet Personne avec les paramètres spécifiés.
    // Contrat :
    // Aucun contrat spécifique.

    //------------------------------------------------------------------ PRIVE
  protected:  
    //----------------------------------------------------- Attributs protégés

    int id;             // Identifiant de la personne
    string prenom;      // Prénom de la personne
    string nom;         // Nom de la personne
    string adresse;     // Adresse de la personne
    string login;       // Login de la personne
    string motDePasse;  // Mot de passe de la personne
};

#endif // PERSONNE_H
