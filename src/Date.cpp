/*************************************************************************
 Date  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Getters et setters

int Date::getJour() const
{
    return jour;
} //----- Fin de getJour

int Date::getMois() const
{
    return mois;
} //----- Fin de getMois

int Date::getAnnee() const
{
    return annee;
} //----- Fin de getAnnee

void Date::setJour(int jj)
{
    jour = jj;
} //----- Fin de setJour

void Date::setMois(int mm)
{
    mois = mm;
} //----- Fin de setMois

void Date::setAnnee(int an)
{
    annee = an;
} //----- Fin de setAnnee

//----------------------------------------------------- Méthode pour l'application

bool Date::precede(Date uneDate) const
{
    if ((annee < uneDate.annee) || (annee == uneDate.annee && mois < uneDate.mois) || (mois == uneDate.mois && jour < uneDate.jour))
    {
        return true;
    }

    return false;
} //----- Fin de precede

vector<int> Date::today()
{
    time_t t = std::time(nullptr);
    tm* now = std::localtime(&t);
 
    vector<int> tab;
    tab.push_back(now->tm_mday);
    tab.push_back(now->tm_mon + 1);
    tab.push_back(now->tm_year + 1900);

    return tab;
} //----- Fin de today

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Date & uneDate)
{
    os << uneDate.jour << "/" << uneDate.mois << "/" << uneDate.annee;
    return os;
} //----- Fin de operator <<

Date &Date::operator=(const Date &uneDate)
{
    jour = uneDate.jour;
    mois = uneDate.mois;
    annee = uneDate.annee;

    return (*this);
} //----- Fin de operator =

bool Date::operator== (const Date & uneDate) const
{
    if (annee == uneDate.annee && mois == uneDate.mois && jour == uneDate.jour)
    {
        return true;
    }

    return false;
} //----- Fin de operator ==

bool Date::operator<=(const Date& other) const 
{
    if (annee < other.annee)
    {
        return true;
    }
    else if (annee == other.annee && mois < other.mois)
    {
        return true;
    }
    else if (annee == other.annee && mois == other.mois && jour < other.jour)
    {
        return true;
    } 
    else if (annee == other.annee && mois == other.mois && jour == other.jour)
    {
        return true;
    } 

    return false;
} //----- Fin de operator <=

//-------------------------------------------- Constructeurs - destructeur

Date::Date()
{
    jour = today().at(0);
    mois = today().at(1);
    annee = today().at(2);   
    #ifdef MAP
        cout << "Appel au constructeur de <Date>" << endl;
    #endif
} //----- Fin de Date

Date::Date(int jj , int mm, int an)
{
    jour = jj;
    mois = mm;
    annee = an;
    
    #ifdef MAP
        cout << "Appel au constructeur de <Date>" << endl;
    #endif
} //----- Fin de Date
