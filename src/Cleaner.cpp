/*************************************************************************
 Cleaner  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier this->cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Cleaner.h"
#include "Data.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Getters et setters

int Cleaner::getId() const
{
    return id;
} //----- Fin de getId

int Cleaner::getFournisseurId() const
{
    return fournisseurId;
} //----- Fin de getFournisseurId

double Cleaner::getLatitude() const
{
    return latitude;
} //----- Fin de getLatitude

double Cleaner::getLongitude() const
{
    return longitude;
} //----- Fin de getLongitude

Date Cleaner::getStart() const
{
    return start;
} //----- Fin de getStart

Date Cleaner::getStop() const
{
    return stop;
} //----- Fin de getStop

void Cleaner::setId(int id)
{
    this->id = id;
} //----- Fin de setId

void Cleaner::setFournisseurId(int fournisseurId)
{
    this->fournisseurId = fournisseurId;
} //----- Fin de setFournisseurId

void Cleaner::setLatitude(double lati)
{
    latitude = lati;
} //----- Fin de setLatitude

void Cleaner::setLongitude(double longi)
{
    longitude = longi;
} //----- Fin de setLongitude

void Cleaner::setStart(Date start)
{
    this->start = start;
} //----- Fin de setStart

void Cleaner::setStop(Date stop)
{
    this->stop = stop;
} //----- Fin de setStop

//-------------------------------------------------- Méthodes d'application

tuple<double, double> Cleaner::voirImpact(Data objData) const
{
    double rayon = 0.0;
    double impact = 1.0;

    Zone zone(this->getLatitude(), this->getLongitude(), rayon);

    int cleanerStartMois = this->getStart().getMois();
    int mAv = cleanerStartMois;
    int cleanerStartJour = this->getStart().getJour();
    int jAv = cleanerStartJour, jAp = this->getStop().getJour(), mAp = this->getStop().getMois();

    if(cleanerStartJour == 1)
    {
        if (cleanerStartMois == 3) // 1 Mars
        {
            jAv = 28;

        }
        else if(cleanerStartMois == 5 || cleanerStartMois == 7 || cleanerStartMois == 10 || cleanerStartMois == 12)
        {
            jAv = 30;
        }
        else{
            jAv = 31;
        }

        if (cleanerStartMois == 1) // janvier
        {
            mAv = 12;
        }
        else{
            mAv = cleanerStartMois - 1;
        }
    }
    else
    {
        --jAv;
    }

    if(cleanerStartJour >= 28)
    {
        jAp = 1;
        mAp = this->getStop().getMois() + 1;
    }
    else
    {
        ++jAp;
    }

    Date jourAvant(jAv, mAv, this->getStart().getAnnee());

    Date jourApres(jAp, mAp, this->getStop().getAnnee());

    Periode Periode_avant(jourAvant, this->getStart());
    Periode Periode_apres(this->getStart(), jourApres);

    double result = 0.0;
    double ancienneMoyenne = 0.0;
    double nouvelleMoyenne = 0.0;

    double tmpOldAverage = 0.0;
    double tmpNewAverage = 0.0;

    int rayonMax = 1001; 

    while(rayon < rayonMax && impact>0)
    {
        rayon += 40;
        zone.setRayon(rayon);

        tmpNewAverage = objData.calculerMoyenneAir(&zone, &Periode_apres);
        tmpOldAverage = objData.calculerMoyenneAir(&zone, &Periode_avant);

        impact = tmpOldAverage - tmpNewAverage;

        if(impact<=0)
        {
            break;
        }

        if(!isnan(impact))
        {
            ancienneMoyenne = tmpOldAverage;
            nouvelleMoyenne = tmpNewAverage;
        }
    }

    // Calcul de l'écart relatif
    result = ((ancienneMoyenne-nouvelleMoyenne)/ancienneMoyenne) * 100.0;
    result = round(result * 100) / 100;

    return make_tuple(result,  rayon-40);
} //----- Fin de voirImpact

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Cleaner & cleaner)
{
    os <<"Cleaner : {id : "<< cleaner.id << ", id fournisseur : " << cleaner.fournisseurId << ", latitude : "<< cleaner.latitude << ", longitude : "<< cleaner.longitude << ", start : " << cleaner.start << ", stop : "<< cleaner.stop<< "}";
    return os;
} //----- Fin de operator <<

Cleaner &Cleaner::operator=(const Cleaner &cleaner)
{
    id = cleaner.id;
    fournisseurId = cleaner.fournisseurId;
    latitude = cleaner.latitude;
    longitude = cleaner.longitude;
    start = cleaner.start;
    stop = cleaner.stop;
    
    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner(int id, int fournisseurId, double lati, double longi, Date start, Date stop)
{
    this->id = id;
    this->fournisseurId = fournisseurId;
    latitude = lati;
    longitude = longi;
    this->start = start;
    this->stop = stop;

    #ifdef MAP
        cout << "Appel au constructeur de <Cleaner>" << endl;
    #endif
} //----- Fin de Cleaner
