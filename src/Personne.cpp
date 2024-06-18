/*************************************************************************
Personne  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//Réalisation de la classe <Personne> (fichier Personne.cpp)------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Personne.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Getters et setters

int Personne::getId() const
{
    return id;
} //----- Fin de getId

void Personne::setId(int Id)
{
    id = Id;
} //----- Fin de setId

string Personne::getPrenom() const
{
    return prenom;
} //----- Fin de getPrenom

void Personne::setPrenom(string pre)
{
    prenom = pre;
} //----- Fin de setPrenom

string Personne::getNom() const
{
    return nom;
} //----- Fin de getNom

void Personne::setNom(string n)
{
    nom = n;
} //----- Fin de setNom

string Personne::getAdresse() const
{
    return adresse;
} //----- Fin de getAdresse

void Personne::setAdresse(string adr)
{
    adresse = adr;
} //----- Fin de setAdresse

string Personne::getLogin() const
{
    return login;
} //----- Fin de getLogin

void Personne::setLogin(string log)
{
    login = log;
} //----- Fin de setLogin

string Personne::getMotDePasse() const
{
    return motDePasse;
} //----- Fin de getMotDePasse

void Personne::setMotDePasse(string mdp)
{
    motDePasse = mdp;
} //----- Fin de getMotDePasse

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Personne & personne)
{
    os << "Personnne : {id : " << personne.id << ", prenom : " << personne.prenom << ", nom : " << personne.nom << ", adresse : " << personne.adresse << ", login : " << personne.login << ", mot de passe : " << personne.motDePasse << "}";
    return os;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur

Personne::Personne(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse) : id(newId), prenom(newPrenom), nom(newNom), adresse(newAdresse), login(newLogin), motDePasse(newMotDePasse) 
{
    #ifdef MAP
        cout << "Appel au constructeur de <Personne>" << endl;
    #endif
} //----- Fin de Personne
