/*************************************************************************
AgentGouvernement  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AgentGouvernement> (fichier AgentGouvernement.h) ----------------
#if ! defined (AGENTGOUVERNEMENT_H)
#define AGENTGOUVERNEMENT_H
//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AgentGouvernement> :
// Représenter un agent du gouvernement
//------------------------------------------------------------------------

class AgentGouvernement : public Personne
{
    //----------------------------------------------------------------- PUBLIC

  public:
    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const AgentGouvernement & agent);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe AgentGouvernement.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    AgentGouvernement & operator = (const AgentGouvernement & unAgentGouvernement);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe AgentGouvernement.
    // Contrat :
    // Aucun contrat spécifique.

    //-------------------------------------------- Constructeurs - destructeur

    AgentGouvernement(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse);
    // Mode d'emploi :
    // Construit un objet AgentGouvernement avec les paramètres spécifiés.
    // Contrat :
    // Aucun contrat spécifique.
};

#endif // AGENTGOUVERNEMENT_H
