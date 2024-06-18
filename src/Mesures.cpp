/*************************************************************************
 Mesures  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI
e-mail               : aya.talbi-el-alami@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Mesures> (fichier Mesures.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Mesures.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------------------- Getters et setters

const Attributs * Mesures::getAttributs() const
{ 
    return attributs;
} //----- Fin de getAttributs

const double* Mesures::getValeurs() const
{
    return valeurs;
} //----- Fin de getValeurs

bool Mesures::getValide() const
{
    return valide;
} //----- Fin de getValide

Date Mesures::getDate() const
{
    return date;
} //----- Fin de getDate

void Mesures::setDate(Date d)
{
    date.setJour(d.getJour());
    date.setMois(d.getMois());
    date.setAnnee(d.getAnnee());
} //----- Fin de setDate

void Mesures::setValide(bool status)
{   
    valide = status;
} //----- Fin de setValide

void Mesures::setValeurs(double * values)
{
    for(int i = 0; i < 4; i++)
    {
        valeurs[i] = values[i];
    }
}//----- Fin de setValeurs

void Mesures::setAttributs(Attributs * attributs)
{
    for(int i = 0; i < 4; i++)
    {
        this->attributs[i] = attributs[i];
    }
} //----- Fin de setAttributs

//--------------------------------------------------------- Méthode d'application

void Mesures::invaliderMesures()
{
    valide = false;
} //----- Fin de invaliderMesures

double Mesures::calculQualiteAir()
{
    double qualite = 0.0;

    for(int i = 0; i<4; i++)
    {
	//Test de la présence d'une valeur, la limite est abaissable
        if(valeurs[i]<0.01)
            return 0;
	//Récupération du max
        qualite = qualite<attributs[i].getIndiceATMO(valeurs[i])? attributs[i].getIndiceATMO(valeurs[i]):qualite;
    }

    return qualite;
} //----- Fin de calculQualiteAir

//------------------------------------------------- Surcharge d'opérateurs

Mesures &Mesures::operator=(const Mesures &m)
{
    date.setJour(m.getDate().getJour());
    date.setMois(m.getDate().getMois());
    date.setAnnee(m.getDate().getAnnee());                    
    valide = m.valide;

    for(int i = 0; i < 4; i++)
    {
        valeurs[i] = m.valeurs[i];
    }

    for(int i = 0; i < 4; i++)
    {
        this->attributs[i] = m.attributs[i];
    }                  
    
    return (*this);
} //----- Fin de operator =

ostream & operator<<(ostream & os, const Mesures & m)
{
    os << "Mesures prises le " << m.getDate().getJour() << "/" << m.getDate().getMois() << "/" << m.getDate().getAnnee() << endl;
    
    for(int i = 0; i<4; i++)
    {
        os << m.attributs[i].getId() << " : " << m.getValeurs()[i] << " " << m.getAttributs()[i].getUnite() <<endl;
    }

    return os;
} //----- Fin de operator<<

//-------------------------------------------- Constructeurs - destructeur

Mesures::Mesures(double * values, bool status, Date d, Attributs * attribut)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Mesures>" << endl;
    #endif

    valide = status;

    date.setJour(d.getJour());
    date.setMois(d.getMois());
    date.setAnnee(d.getAnnee());

    for(int i = 0; i < 4; i++)
    {
        valeurs[i] = values[i];
    }

    for(int i = 0; i < 4; i++)
    {
        this->attributs[i] = attribut[i];
    }
} //----- Fin de Mesures




