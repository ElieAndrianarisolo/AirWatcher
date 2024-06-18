/*************************************************************************
AgentGouvernement  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//Réalisation de la classe <AgentGouvernement> (fichier AgentGouvernement.cpp)------------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "AgentGouvernement.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const AgentGouvernement & agent)
{
    os << "AgentGouvernement : {id : " << agent.id << ", prenom : " << agent.prenom << ", nom : " << agent.nom << ", adresse : " << agent.adresse << ", login : " << agent.login << ", mot de passe : " << agent.motDePasse << "}";
    return os;
} //----- Fin de operator <<

AgentGouvernement &AgentGouvernement::operator=(const AgentGouvernement &unAgentGouvernement)
{
    id = unAgentGouvernement.id;
    prenom = unAgentGouvernement.prenom;
    nom = unAgentGouvernement.nom;
    adresse = unAgentGouvernement.adresse;
    login = unAgentGouvernement.login;
    motDePasse = unAgentGouvernement.motDePasse;

    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

AgentGouvernement::AgentGouvernement(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse) : Personne(newId,newPrenom,newNom,newAdresse,newLogin,newMotDePasse)
{
    #ifdef MAP
        cout << "Appel au constructeur de <AgentGouvernement>" << endl;
    #endif
} //----- Fin de AgentGouvernement
