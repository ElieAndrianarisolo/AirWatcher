/*************************************************************************
UtilisateurPrive  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <UtilisateurPrive> (fichier UtilisateurPrive.h) ----------------
#if ! defined (UTILISATEURPRIVE_H)
#define UTILISATEURPRIVE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Capteur.h"
#include "Personne.h"
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <UtilisateurPrive> :
// Représenter un utilisateur privé
//------------------------------------------------------------------------

class UtilisateurPrive : public Personne
{
    //----------------------------------------------------------------- PUBLIC

  public:
    //----------------------------------------------------- Méthodes publiques

    bool getFiabilite() const;
    // Mode d'emploi :
    // Renvoie la fiabilité de l'utilisateur privé.
    // Contrat :
    // Aucun contrat spécifique.

    void setFiabilite(bool fiab);
    // Mode d'emploi :
    // Modifie la fiabilité de l'utilisateur privé avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    int getNote() const;
    // Mode d'emploi :
    // Renvoie la note de l'utilisateur privé.
    // Contrat :
    // Aucun contrat spécifique.

    void setNote(int grade);
    // Mode d'emploi :
    // Modifie la note de l'utilisateur privé avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    Date getDateDerniereVerification() const;
    // Mode d'emploi :
    // Renvoie la date de dernière vérification de l'utilisateur privé.
    // Contrat :
    // Aucun contrat spécifique.

    void setDateDerniereVerification(Date newDate);
    // Mode d'emploi :
    // Modifie la date de dernière vérification de l'utilisateur privé avec la valeur spécifiée.
    // Contrat :
    // Aucun contrat spécifique.

    vector<Capteur> getCapteursPrives() const;
    // Mode d'emploi :
    // Renvoie la liste des capteurs privés de l'utilisateur.
    // Contrat :
    // Aucun contrat spécifique.

    void setCapteursPrives(Capteur capteursPrives);
    // Mode d'emploi :
    // Modifie la liste des capteurs privés de l'utilisateur avec les capteurs spécifiés.
    // Contrat :
    // Aucun contrat spécifique.

    //-------------------------------------------- Méthodes d'application

    void augmenterNote();
    // Mode d'emploi :
    // Incrémente la note de l'utilisateur privé.
    // Contrat :
    // Aucun contrat spécifique.

    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const UtilisateurPrive & unUtilisateurPrive);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe UtilisateurPrive.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    UtilisateurPrive & operator = (const UtilisateurPrive & unUtilisateurPrive);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe UtilisateurPrive.
    // Contrat :
    // Aucun contrat spécifique.

    //-------------------------------------------- Constructeurs - destructeur

    UtilisateurPrive(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse, bool newFiabilite, int newNote, Date newDate);
    // Mode d'emploi :
    // Construit un objet UtilisateurPrive avec les paramètres spécifiés.
    // Contrat :
    // Aucun contrat spécifique.

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Attributs protégés

    bool fiabilite;                     // Indique la fiabilité de l'utilisateur privé
    int note;                           // Note attribuée à l'utilisateur privé
    Date dateDerniereVerification;      // Date de la dernière vérification de l'utilisateur privé
    vector<Capteur> capteursPrives;     // Liste des capteurs privés de l'utilisateur

};

#endif // UTILISATEURPRIVE_H
