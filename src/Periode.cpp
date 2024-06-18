/*************************************************************************
 Periode  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Periode> (fichier Periode.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Periode.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------------ Getters et setters

Date Periode::getDebut() const
{
    return debut;
} //----- Fin de getDebut

Date Periode::getFin() const
{
    return fin;
} //----- Fin de getFin

void Periode::setDebut(Date deb)
{
    debut = deb;
} //----- Fin de setDebut

void Periode::setFin(Date fin)
{
    this->fin = fin;
} //----- Fin de setFin

//-------------------------------------------- Méthodes d'application

bool Periode::estValide() const
{
    Date d; // donne date du jour
    // Les conditions :
    // - debut <= today
    // - fin <= today
    // - debut != fin
    // - debut <= fin

    if((debut.precede(d) || debut == d) && (fin.precede(d) || fin == d) && !(debut == fin) && debut.precede(fin))
    {
        return true;
    }

    return false;
} //----- Fin de estValide

bool Periode::inclu(Date uneDate) const
{
    // debut <= uneDate et uneDate < fin
    if (debut <= uneDate && uneDate.precede(fin))
    {
        return true;
    }
    
    return false;
} //----- Fin de inclu

//------------------------------------------------- Surcharge d'opérateurs

Periode &Periode::operator=(const Periode &p)
{
    debut = p.debut;
    fin = p.fin;

    return (*this);
} //----- Fin de operator =

ostream & operator<<(ostream & os, const Periode & p)
{
    os << "Date de début : "<< p.debut << endl;
    os << "Date de fin : " << p.fin << endl;

    return os;
} //----- Fin de operator<<

//-------------------------------------------- Constructeurs - destructeur

Periode::Periode(Date deb, Date fin)
{
    debut = deb;
    this->fin = fin;

    #ifdef MAP
        cout << "Appel au constructeur de <Periode>" << endl;
    #endif
}  //----- Fin de Periode


