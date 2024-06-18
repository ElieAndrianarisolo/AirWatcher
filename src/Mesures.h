/*************************************************************************
Mesures  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI 
e-mail               : aya.talbi-el-alami@insa-lyon.fr 
*************************************************************************/

//---------- Interface de la classe <Mesures> (fichier Mesures.h) ----------------
#if ! defined ( MESURES_H )
#define MESURES_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <ctime>
#include <vector>
#include "Attributs.h"
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesures>
//
//------------------------------------------------------------------------

class Mesures
{
//----------------------------------------------------------------- PUBLIC

  public:
//----------------------------------------------------- Getters et setters

    const double * getValeurs() const;
    // Mode d'emploi :
    // Obtient un pointeur vers les valeurs de mesures.
    // Contrat :
    // Aucun contrat spécifique.

    bool getValide() const;
    // Mode d'emploi :
    // Obtient l'état de validité des mesures.
    // Contrat :
    // Aucun contrat spécifique.

    Date getDate() const;
    // Mode d'emploi :
    // Obtient la date des mesures.
    // Contrat :
    // Aucun contrat spécifique.

    void setDate(Date d);
    // Mode d'emploi :
    // Définit la date des mesures.
    // Contrat :
    // Aucun contrat spécifique.

    void setValeurs(double * values);
    // Mode d'emploi :
    // Définit les valeurs de mesures à partir d'un pointeur.
    // Contrat :
    // Aucun contrat spécifique.

    void setValide(bool status);
    // Mode d'emploi :
    // Définit l'état de validité des mesures.
    // Contrat :
    // Aucun contrat spécifique.

    void setAttributs(Attributs * a);
    // Mode d'emploi :
    // Définit les attributs associés aux mesures.
    // Contrat :
    // Aucun contrat spécifique.

    const Attributs * getAttributs() const;
    // Mode d'emploi :
    // Obtient les attributs associés aux mesures.
    // Contrat :
    // Aucun contrat spécifique.

//----------------------------------------------------- Méthode d'applications

    void invaliderMesures();
    // Mode d'emploi :
    // Rends les mesures invalides, c'est à dire non utilisables, dans le cas où
    // le capteur est dysfonctionnel.
    // Contrat :
    // Aucun contrat spécifique.

    double calculQualiteAir();
    // Mode d'emploi :
    // Cette méthode prend en compte les mesures effectuées par le capteur qui se trouvent
    // dans le tableau valeurs pour calculer une valeur de la qualité de l'air du capteur
    // considéré.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------- Surcharge d'opérateurs

    Mesures & operator = (const Mesures & m);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Mesures.
    // Contrat :
    // Aucun contrat spécifique.

    friend ostream & operator<<(ostream & os, const Mesures & m);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Mesures.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

//-------------------------------------------- Constructeurs - destructeur

    Mesures(double * valeurs, bool status, Date date_heure, Attributs * attributs);
    // Mode d'emploi :
    // Constructeur de la classe Mesures avec des paramètres.
    // Contrat :
    // Aucun contrat spécifique.

    //~Mesures();
    // Mode d'emploi :
    // Destructeur de la classe Mesures
    // Contrat :
    // Aucun contrat spécifique.

  protected:
//----------------------------------------------------- Attributs protégés

    Date date;                                      // Date des mesures.
    bool valide;                                    // Indique si les mesures sont valides.
    double valeurs[4];                              // Mesures effectuées (valeurs des capteurs).
    Attributs attributs[4];                         // Attributs associés aux mesures.
};

#endif // Mesures_H

