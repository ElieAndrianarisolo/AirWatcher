/*************************************************************************
 Data  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI 
e-mail               : aya.talbi-el-alami@insa-lyon.fr 
*************************************************************************/

//---------- Interface de la classe <Data> (fichier Data.h) ----------------
#if ! defined (DATA_H)
#define DATA_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>
#include <memory>
#include "Capteur.h"
#include "Cleaner.h"
#include "UtilisateurPrive.h"
#include "Date.h"
#include "Periode.h"
#include "Zone.h"
#include "Attributs.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Data>
// Classe représentant une collection de données comprenant des capteurs,
// des utilisateurs privés, des purificateurs et d'autres attributs liés.
//------------------------------------------------------------------------

class Cleaner; // Déclaration anticipée de la classe Cleaner

class Data
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Getters

    vector<Capteur> getListeCapteurs() const;
    // Mode d'emploi :
    // Renvoie la liste des capteurs de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    vector<Cleaner> getListeCleaners() const;
    // Mode d'emploi :
    // Renvoie la liste des purificateurs de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    vector<UtilisateurPrive> getListeUtilisateurPrive() const;
    // Mode d'emploi :
    // Renvoie la liste des utilisateurs privés de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    vector<Capteur> getListeCapteursPrives() const;
    // Mode d'emploi :
    // Renvoie la liste des capteurs privés de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    Date getDateDerniereVerification() const;
    // Mode d'emploi :
    // Renvoie la date de la dernière vérification de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

//----------------------------------------------------- Méthodes d'application

    void initialiserAttributs();
    // Mode d'emploi :
    // Initialise les attributs de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    void initialiserCapteurs();
    // Mode d'emploi :
    // Initialise les capteurs de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    void initialiserCleaners();
    // Mode d'emploi :
    // Initialise les purificateurs de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    void initialiserDonneesPrives();
    // Mode d'emploi :
    // Initialise les données privées de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    void initialiserMesures();
    // Mode d'emploi :
    // Initialise les mesures de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    double calculerMoyenneAir(Zone * zone, Periode * periode);
    // Mode d'emploi :
    // Calcule la moyenne de la qualité de l'air dans une zone donnée sur une période donnée.
    // Contrat :
    // Aucun contrat spécifique.

    tuple<bool, int> findFournisseur(int idF) const;
    // Mode d'emploi :
    // Vérifie si un fournisseur avec l'ID spécifié existe dans la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

    tuple<bool, int> findUtilisateurPrive(int idUP) const;
    // Mode d'emploi :
    // Vérifie si un utilisateur privé avec l'ID spécifié existe dans la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Constructeurs - destructeur
    
    Data(); 
    // Mode d'emploi :
    // Constructeur par défaut de la classe Data.
    // Contrat :
    // Aucun contrat spécifique.

protected:

//----------------------------------------------------- Attributs protégés

    vector<Capteur> listeCapteurs;                      // Liste des capteurs de la classe Data
    vector<Cleaner> listeCleaners;                      // Liste des purificateurs de la classe Data
    vector<UtilisateurPrive> listeUtilisateursPrives;   // Liste des utilisateurs privés de la classe Data
    vector<Capteur> listeCapteursPrives;                // Liste des capteurs privés de la classe Data
    Date dateDerniereVerification;                      // Date de la dernière vérification de la classe Data
};

#endif // DATA_H
