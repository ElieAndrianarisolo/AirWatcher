/*************************************************************************
Main -  description

début      : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//Réalisation du module <Main> (fichier Main.cpp)-------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "Main.h"

//------------------------------------------------------ Include personnel

/*
int main()
{
    
    cout << "-----------  Test  ------------" << endl << endl;

    Data d;

    d.initialiserCapteurs();
    d.initialiserAttributs();
    d.initialiserMesures();
    d.initialiserCleaners();
    d.initialiserDonneesPrives();
    
    vector<Capteur> listeCapteurs = d.getListeCapteurs();                      
    vector<Cleaner> listeCleaners = d.getListeCleaners();                      
    vector<UtilisateurPrive> listeUtilisateursPrives = d.getListeUtilisateurPrive();   
    vector<Capteur> listeCapteursPrives = d.getListeCapteursPrives();                        

    for(int i = 0; i<listeCapteurs.size(); i++)
    {
        cout << listeCapteurs[i] << endl;
    }

    cout << "--------------------------" << endl << endl;

    for(int i = 0; i<listeCleaners.size(); i++)
    {
        cout << listeCleaners[i] << endl;
    }

    cout << "--------------------------" << endl << endl;

    for(int i = 0; i<listeUtilisateursPrives.size(); i++)
    {
        cout << listeUtilisateursPrives[i] << endl;
    }

    cout << "--------------------------" << endl << endl;

    for(int i = 0; i<listeCapteursPrives.size(); i++)
    {
        cout << listeCapteursPrives[i] << endl;
    }

    cout << "--------------------------" << endl << endl;

    tuple<double, double> t = listeCleaners[0].voirImpact(d);

    cout << "Impact : " << get<0>(t) << endl; 
    cout << "Rayon : " << get<1>(t) << endl <<endl; 

    
    return 0;
}
*/

//----------------------------------------------------------------- PUBLIC

//---------------------------------------------------- Fonctions publiques

bool estFormatPeriodeValide(const string& periode) 
{
    regex pattern(R"(\d{2}/\d{2}/\d{4})");
    return regex_match(periode, pattern);
}

bool estFormatZoneValide(const string& zone) 
{
    regex pattern(R"((-?\d+(\.\d+)?);(-?\d+(\.\d+)?);(\d+(\.\d+)?))");
    return regex_match(zone, pattern);
}

string enleverZeros(const string& str) 
{
    string resultat = str;
    size_t pos = 0;

    // Recherche de la position du premier caractère différent de zéro
    while (pos < resultat.length() && resultat[pos] == '0')
    {
        pos++;
    }

    // Cas où la chaîne ne contient que des zéros
    if (pos == resultat.length()) {
        return "0";
    }

    // Suppression des zéros du début de la chaîne
    resultat.erase(0, pos);

    return resultat;
}

bool estBissextile(int annee) 
{
    return (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0));
}

bool estFormatDateValide(int annee, int mois, int jour)
{

    //Période actuelle
    Date d;
    vector<int> t = d.today();

    int anneeActuelle = t[2];
    int moisActuel = t[1];
    int jourActuel = t[0];

    bool isBissextile = estBissextile(annee);

    if(annee < 1 || mois < 1 || mois > 12 || jour < 1 || jour > 31)
    {
        return false;
    }
    else if(annee>anneeActuelle)
    {
        return false;
    } 
    else if(annee == anneeActuelle && mois>moisActuel)
    {
        return false;
    }
    else if(annee == anneeActuelle && mois == moisActuel && jour>jourActuel)
    {
        return false;
    }
    else if (isBissextile && mois == 2 && jour>29) 
    {
        return false;
    }
    else if(!isBissextile && mois == 2 && jour>28)
    {
        return false;
    }
    else if ((mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12) && jour>31)
    {
        return false;
    }
    else if((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour>30)
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool estFormatNumeroValide(const string& numero) 
{
    regex pattern("[1-9]\\d*");
    return regex_match(numero, pattern);
}

bool estFormatIdValide(const string& id) 
{
    regex pattern("\\d+");
    return regex_match(id, pattern);
}

int main()
{

    cout << endl;
    
    cout<<"*********************************************************** Bienvenue dans l'application AirWatcher ! **********************************************************"<<endl;
    cout<<"********************************************************** L'application qui prend soin de votre air ! *********************************************************"<<endl<<endl;

    cout<<"*************************     Cette version de l'application correspond à une version dédiée au développeur, et non au grand public    *************************"<<endl<<endl;

    Data objData;
    bool isDataInit = false;

    while(1)
    {
        
        if(isDataInit)
        {
            cout<<"***********************************************************             Choix d'utilisateur            **********************************************************"<<endl<<endl;
        }

        cout << "Etes-vous un·e:" << endl << endl;
        cout << "1- Agent·e du gouvernement" << endl;
        cout << "2- Utilisateur·rice privé·e" << endl;
        cout << "3- Fournisseur·euse" << endl << endl;

        cout << "Votre réponse (pour quitter l'application, saisissez la lettre 'q') : ";
        string answer;
        cin >> answer;

        while(answer != "1" && answer != "2" && answer != "3" && answer != "q")
        {
            cout << endl << "Votre choix est invalide. Veuillez saisir une nouvelle réponse : " ;
            cin >> answer;
        }

        cout << endl;

        if(!isDataInit)
        {
            auto start1 = chrono::high_resolution_clock::now();
            objData.initialiserCapteurs();
            auto end1 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration1 = end1 - start1;
            double tempsExecution1 = duration1.count();
            init.push_back(tempsExecution1);

            auto start2 = chrono::high_resolution_clock::now();
            objData.initialiserAttributs();
            auto end2 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration2 = end2 - start2;
            double tempsExecution2 = duration2.count();
            init.push_back(tempsExecution2);

            auto start3 = chrono::high_resolution_clock::now();
            objData.initialiserMesures();
            auto end3 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration3 = end3 - start3;
            double tempsExecution3 = duration3.count();
            init.push_back(tempsExecution3);

            auto start4 = chrono::high_resolution_clock::now();
            objData.initialiserCleaners();
            auto end4 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration4 = end4 - start4;
            double tempsExecution4 = duration4.count();
            init.push_back(tempsExecution4);
            
            auto start5 = chrono::high_resolution_clock::now();
            objData.initialiserDonneesPrives();
            auto end5 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration5 = end5 - start5;
            double tempsExecution5 = duration5.count();
            init.push_back(tempsExecution5);
            
            isDataInit = true;

        }
        
        if(answer == "1")
        {   

            perf1.clear();
            perf2.clear();

            AgentGouvernement agentGouvernement(1, "Nick", "Furry", "5 Rue du Pentagone, Washington DC, USA", "nfurry", "mdp");

            cout<<"**********************************************************           Bienvenue Agent·e "<< agentGouvernement.getNom() <<"          **********************************************************"<<endl;
            
            while(1)
            {
                string choice; 

                cout<<"**********************************************************                    Menu                    **********************************************************"<<endl<<endl;
                
                cout << "1- Calculer la moyenne de la qualité de l'air" << endl;
                cout << "2- Afficher l'impact des purificateurs sur l'air" << endl;
                cout << "3- Visualiser les performances de l'application" << endl;
                cout << "4- Quitter " << endl << endl;

                cout << "Votre réponse : ";
                cin >> choice;

                while(choice != "1" && choice != "2" && choice != "3" && choice != "4")
                {
                    cout << endl << "Votre choix est invalide. Veuillez saisir une nouvelle réponse : " ;
                    cin >> choice;
                }

                cout << endl;

                if(choice == "4")
                {
                    break;
                }
                else if(choice == "1")
                {
                    
                    cout<<"********************************************************** Calculer la moyenne de la qualité de l'air **********************************************************"<<endl<<endl;

                    string zoneInput;
                    string periodeDebutInput;
                    string periodeFinInput;

                    while(1)
                    {
                        cout<<"Entrez la zone géographique souhaitée (Format: lat;long;rayon): ";
                        cin >> zoneInput;
                        cout << endl;

                        cout<<"Entrez la période de mesure souhaitée (Format: JJ/MM/AAAA): " << endl << endl;
                        
                        cout<<"         Date de début : ";
                        cin>>periodeDebutInput;

                        cout<<"         Date de fin : ";
                        cin>>periodeFinInput;
                        cout << endl;

                        if(estFormatZoneValide(zoneInput) && estFormatPeriodeValide(periodeDebutInput) && estFormatPeriodeValide(periodeFinInput))
                        {
                            stringstream z(zoneInput);
                            stringstream p1(periodeDebutInput);
                            stringstream p2(periodeFinInput);
                            
                            //Zone utilisateur
                            string tmp;
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double latitude = stod(tmp);
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double longitude = stod(tmp);
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double rayon = stod(tmp);

                            //Période début utilisateur
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int jour1 = stoi(tmp);
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int mois1 = stoi(tmp);
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int annee1 = stoi(tmp);

                            //Période fin utilisateur
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int jour2 = stoi(tmp);
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int mois2 = stoi(tmp);
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int annee2 = stoi(tmp);

                            if(estFormatDateValide(annee1, mois1, jour1) && estFormatDateValide(annee2, mois2, jour2))
                            {
                                Zone zone(latitude, longitude, rayon);

                                Date dateDebut(jour1, mois1, annee1);
                                Date dateFin(jour2, mois2, annee2);

                                if(dateFin <= dateDebut)
                                {
                                    cout << "La période fournie est erronée. Veuillez recommencer." << endl << endl; 
                                }
                                else
                                {
                                    Periode periode(dateDebut, dateFin);
                                    
                                    auto start = chrono::high_resolution_clock::now();

                                    double moyenne = objData.calculerMoyenneAir(&zone, &periode);

                                    if(isnan(moyenne))
                                    {
                                        cout << "Il n'y a pas encore de mesures pour la zone et la période spécifiée. " << endl << endl;
                                        break;
                                    }

                                    auto end = chrono::high_resolution_clock::now();

                                    chrono::duration<double, milli> duration = end - start;
                                    double tempsExecution = duration.count();
                                    perf1.push_back(tempsExecution);

                                    cout << "La moyenne de la qualité de l'air est : " << moyenne << " indices ATMO" << endl << endl;

                                    break;
                                }
                                
                            }
                            else
                            {
                                cout << "La période fournie est erronée. Veuillez recommencer." << endl << endl; 
                            }
                        } 
                        else
                        {
                            cout << "Les informations fournies sont erronées. Veuillez recommencer." << endl << endl;
                        }
                    }
                }
                else if(choice == "2")
                {

                    cout<<"********************************************************* Afficher l'impact des purificateurs sur l'air ********************************************************"<<endl<<endl;

                    string purificateur;

                    while(1)
                    {
                        vector<Cleaner> cleaners = objData.getListeCleaners();

                        if(cleaners.empty())
                        {
                            cout<<"Il n'y a aucun purificateur." << endl << endl;
                            break;
                        }

                        cout<<"Choisissez un purificateur parmi les purificateurs suivants:" << endl << endl;

                        int i; 
                        for(i = 0; i<cleaners.size(); i++)
                        {
                            cout << "         " << i+1 << "- Purificateur " << cleaners[i].getId() << " (Lat:" << cleaners[i].getLatitude() << " Long:" << cleaners[i].getLongitude() << ")" <<endl; 
                        }

                        cout << endl;
                        cout << "Numéro sélectionné : ";

                        cin >> purificateur;
                        cout << endl;

                        if(estFormatNumeroValide(purificateur))
                        {

                            int purificateurChoisi = stoi(purificateur)-1;

                            if(purificateurChoisi>=i || purificateurChoisi<0)
                            {
                                cout << "Ce purificateur n'existe pas. Veuillez recommencer." << endl << endl;
                            }
                            else
                            {
                                auto start = chrono::high_resolution_clock::now();

                                tuple<double, double> impact = cleaners[purificateurChoisi].voirImpact(objData);

                                if(isnan(get<0>(impact)) || isnan(get<1>(impact)))
                                {
                                    cout << "Ce purificateur n'a pas encore d'impact significatif. " << endl << endl;
                                    break;
                                }

                                auto end = chrono::high_resolution_clock::now();

                                chrono::duration<double, milli> duration = end - start;
                                double tempsExecution = duration.count();
                                perf2.push_back(tempsExecution);

                                cout << "Le purificateur " << cleaners[purificateurChoisi].getId() << " a eu un impact de " << get<0>(impact) << " % dans un rayon de " << get<1>(impact) << " mètres." << endl << endl;
                                break;
                            }

                        }
                        else
                        {
                            cout << "Les informations fournies sont erronées. Veuillez recommencer." << endl << endl;
                        }
                    }

                }
                else
                {
                    bool checker = true;

                    while(checker)
                    {
                        cout<<"**********************************************************  Visualiser les performances d'AirWatcher  **********************************************************"<<endl<<endl;

                        if(perf1.empty() && perf2.empty() && init.empty())
                        {
                            cout << "Vous n'avez utilisé aucun algorithme pour l'instant." << endl << endl;
                            break;
                        }

                        cout << "Temps d'exécution des algorithmes:" << endl << endl;

                        if(init.empty())
                        {
                            cout << "         Vous n'avez pas initialisé les données pour l'instant." << endl << endl;
                        }
                        else
                        {

                            cout << "         Algorithme d'initialisation des capteurs : " << init[0] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des attributs : " << init[1] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des mesures : " << init[2] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des purificateurs : " << init[3] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des données privées : " << init[4] << " ms" << endl; 

                            cout << endl;

                        }

                        if(perf1.empty())
                        {
                            cout << "         Vous n'avez utilisé aucun algorithme de calcul de la moyenne de la qualité de l'air pour l'instant." << endl << endl;
                        }
                        else
                        {
                            for(int i = 0; i<perf1.size(); i++)
                            {
                                cout << "         Algorithme " << i+1 << " de calcul de moyenne de la qualité de l'air : " << perf1[i] << " ms" << endl; 
                            }

                            cout << endl;
                        }

                        if(perf2.empty())
                        {
                            cout << "         Vous n'avez utilisé aucun algorithme de visualisation de l'impact d'un cleaner." << endl << endl;
                        }
                        else
                        {
                            for(int i = 0; i<perf2.size(); i++)
                            {
                                cout << "         Algorithme " << i+1 << " de visualisation de l'impact d'un purificateur sur l'air : " << perf2[i] << " ms" << endl; 
                            }

                            cout << endl;
                        }

                        checker = false;
                    }
                }
            }
        } 
        else if(answer == "2")
        {
            perf1.clear();
            perf2.clear();

            string idUtilisateurP;
            int idUPTemp = 0;
            tuple<bool, int> connexionUP;

            while(1)
            {
                cout << "Quel est votre identifiant utilisateur privé ? : ";
                cin >> idUtilisateurP;

                while(!estFormatIdValide(idUtilisateurP))
                {
                    cout << endl << "Les informations fournies sont erronées. Veuillez saisir une nouvelle réponse : " ;
                    cin >> idUtilisateurP;
                }

                idUPTemp = stoi(idUtilisateurP);
                connexionUP = objData.findUtilisateurPrive(idUPTemp);

                if(get<0>(connexionUP))
                {
                    cout << endl;
                    break;
                }
                else
                {
                    cout << endl << "Cet utilisateur privé est inexistant. Veuillez recommencer. " << endl << endl;
                }

            }

            int idUP = get<1>(connexionUP);
            UtilisateurPrive u = objData.getListeUtilisateurPrive()[idUP];

            cout<<"**********************************************************             Bienvenue " << u.getPrenom() << " " << u.getNom() << "         **********************************************************"<<endl;

            while(1)
            {
                
                string choice; 
                
                cout<<"**********************************************************                    Menu                    **********************************************************"<<endl<<endl;
                
                cout << "1- Calculer la moyenne de la qualité de l'air" << endl;
                cout << "2- Visualiser la note" << endl;
                cout << "3- Visualiser les performances de l'application" << endl;
                cout << "4- Quitter " << endl << endl;

                cout << "Votre réponse : ";
                cin >> choice;

                while(choice != "1" && choice != "2" && choice != "3" && choice != "4")
                {
                    cout << endl << "Votre choix est invalide. Veuillez saisir une nouvelle réponse : " ;
                    cin >> choice;
                }

                cout << endl;

                if(choice == "4")
                {
                    break;
                }
                else if(choice == "1")
                {
                    
                    cout<<"********************************************************** Calculer la moyenne de la qualité de l'air **********************************************************"<<endl<<endl;

                    string zoneInput;
                    string periodeDebutInput;
                    string periodeFinInput;

                    while(1)
                    {
                        cout<<"Entrez la zone géographique souhaitée (Format: lat;long;rayon): ";
                        cin >> zoneInput;
                        cout << endl;

                        cout<<"Entrez la période de mesure souhaitée (Format: JJ/MM/AAAA): " << endl << endl;
                        
                        cout<<"         Date de début : ";
                        cin>>periodeDebutInput;

                        cout<<"         Date de fin : ";
                        cin>>periodeFinInput;
                        cout << endl;            

                        if(estFormatZoneValide(zoneInput) && estFormatPeriodeValide(periodeDebutInput) && estFormatPeriodeValide(periodeFinInput))
                        {
                            stringstream z(zoneInput);
                            stringstream p1(periodeDebutInput);
                            stringstream p2(periodeFinInput);
                            
                            //Zone utilisateur
                            string tmp;
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double latitude = stod(tmp);
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double longitude = stod(tmp);
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double rayon = stod(tmp);

                            //Période début utilisateur
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int jour1 = stoi(tmp);
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int mois1 = stoi(tmp);
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int annee1 = stoi(tmp);

                            //Période fin utilisateur
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int jour2 = stoi(tmp);
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int mois2 = stoi(tmp);
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int annee2 = stoi(tmp);

                            if(estFormatDateValide(annee1, mois1, jour1) && estFormatDateValide(annee2, mois2, jour2))
                            {
                                Zone zone(latitude, longitude, rayon);

                                Date dateDebut(jour1, mois1, annee1);
                                Date dateFin(jour2, mois2, annee2);

                                if(dateFin <= dateDebut)
                                {
                                    cout << "La période fournie est erronée. Veuillez recommencer." << endl << endl; 
                                }
                                else
                                {
                                    Periode periode(dateDebut, dateFin);

                                    auto start = chrono::high_resolution_clock::now();

                                    double moyenne = objData.calculerMoyenneAir(&zone, &periode);

                                    if(isnan(moyenne))
                                    {
                                        cout << "Il n'y a pas encore de mesures pour la zone et la période spécifiée." << endl << endl;
                                        break;
                                    }

                                    auto end = chrono::high_resolution_clock::now();

                                    chrono::duration<double, milli> duration = end - start;
                                    double tempsExecution = duration.count();
                                    perf1.push_back(tempsExecution);

                                    cout << "La moyenne de la qualité de l'air est : " << moyenne << " indices ATMO" << endl << endl;

                                    break;
                                }
                                
                            }
                            else
                            {
                                cout << "La période fournie est erronée. Veuillez recommencer." << endl << endl; 
                            }
                        } 
                        else
                        {
                            cout << "Les informations fournies sont erronées. Veuillez recommencer." << endl << endl;
                        }
                    }
                }
                else if(choice == "2")
                {

                    cout<<"*********************************************************                Visualiser la note             ********************************************************"<<endl<<endl;
                    
                    auto start = chrono::high_resolution_clock::now();

                    u = objData.getListeUtilisateurPrive()[idUP];
                    cout << "Vous avez " << u.getNote() << " points." << endl << endl;

                    auto end = chrono::high_resolution_clock::now();

                    chrono::duration<double, milli> duration = end - start;
                    double tempsExecution = duration.count();
                    perf2.push_back(tempsExecution);
                }
                else
                {
                    bool checker = true;

                    while(checker)
                    {
                        cout<<"**********************************************************  Visualiser les performances d'AirWatcher  **********************************************************"<<endl<<endl;

                        if(perf1.empty() && perf2.empty() && init.empty())
                        {
                            cout << "Vous n'avez utilisé aucun algorithme pour l'instant." << endl << endl;
                            break;
                        }

                        cout << "Temps d'exécution des algorithmes:" << endl << endl;

                        if(init.empty())
                        {
                            cout << "         Vous n'avez pas initialisé les données pour l'instant." << endl << endl;
                        }
                        else
                        {

                            cout << "         Algorithme d'initialisation des capteurs : " << init[0] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des attributs : " << init[1] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des mesures : " << init[2] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des purificateurs : " << init[3] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des données privées : " << init[4] << " ms" << endl; 

                            cout << endl;

                        }

                        if(perf1.empty())
                        {
                            cout << "         Vous n'avez utilisé aucun algorithme de calcul de la moyenne de la qualité de l'air pour l'instant." << endl << endl;
                        }
                        else
                        {
                            for(int i = 0; i<perf1.size(); i++)
                            {
                                cout << "         Algorithme " << i+1 << " de calcul de moyenne de la qualité de l'air : " << perf1[i] << " ms" << endl; 
                            }

                            cout << endl;
                        }

                        if(perf2.empty())
                        {
                            cout << "         Vous n'avez utilisé aucun algorithme de visualisation de votre note." << endl << endl;
                        }
                        else
                        {
                            for(int i = 0; i<perf2.size(); i++)
                            {
                                cout << "         Algorithme " << i+1 << " de visualisation de votre note : " << perf2[i] << " ms" << endl; 
                            }
                            
                            cout << endl;
                        }

                        checker = false;
                    }
                }

            }

        }
        else if(answer == "3")
        {
            perf1.clear();
            perf2.clear();

            string idFournisseur;
            int idF = 0; 
            tuple<bool, int> connexionF;

            while(1)
            {
                cout << "Quel est votre identifiant fournisseur ? : ";
                cin >> idFournisseur;

                while(!estFormatIdValide(idFournisseur))
                {
                    cout << endl << "Les informations fournies sont erronées. Veuillez saisir une nouvelle réponse : " ;
                    cin >> idFournisseur;
                }

                idF = stoi(idFournisseur);
                connexionF = objData.findFournisseur(idF);

                if(get<0>(connexionF))
                {
                    cout << endl;
                    break;
                }
                else
                {
                    cout << endl << "Ce fournisseur est inexistant. Veuillez recommencer. " << endl << endl;
                }

            }

            Fournisseur fournisseur(get<1>(connexionF), "Stan", "Lee", "21 Avenue d'Hollywood, LA, USA", "slee", "mdp");

            cout<<"**********************************************************       Bienvenue Fournisseur·euse n°" << fournisseur.getId() << "       **********************************************************"<<endl;

            while(1)
            {

                string choice; 

                cout<<"**********************************************************                    Menu                    **********************************************************"<<endl<<endl;
                
                cout << "1- Calculer la moyenne de la qualité de l'air" << endl;
                cout << "2- Afficher l'impact des purificateurs sur l'air" << endl;
                cout << "3- Visualiser les performances de l'application" << endl;
                cout << "4- Quitter " << endl << endl;

                cout << "Votre réponse : ";
                cin >> choice;

                while(choice != "1" && choice != "2" && choice != "3" && choice != "4")
                {
                    cout << endl << "Votre choix est invalide. Veuillez saisir une nouvelle réponse : " ;
                    cin >> choice;
                }

                cout << endl;

                if(choice == "4")
                {
                    break;
                }
                else if(choice == "1")
                {
                    
                    cout<<"********************************************************** Calculer la moyenne de la qualité de l'air **********************************************************"<<endl<<endl;

                    string zoneInput;
                    string periodeDebutInput;
                    string periodeFinInput;

                    while(1)
                    {
                        cout<<"Entrez la zone géographique souhaitée (Format: lat;long;rayon): ";
                        cin >> zoneInput;
                        cout << endl;

                        cout<<"Entrez la période de mesure souhaitée (Format: JJ/MM/AAAA): " << endl << endl;
                        
                        cout<<"         Date de début : ";
                        cin>>periodeDebutInput;

                        cout<<"         Date de fin : ";
                        cin>>periodeFinInput;
                        cout << endl;            

                        if(estFormatZoneValide(zoneInput) && estFormatPeriodeValide(periodeDebutInput) && estFormatPeriodeValide(periodeFinInput))
                        {
                            stringstream z(zoneInput);
                            stringstream p1(periodeDebutInput);
                            stringstream p2(periodeFinInput);
                            
                            //Zone utilisateur
                            string tmp;
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double latitude = stod(tmp);
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double longitude = stod(tmp);
                            getline(z, tmp, ';');
                            tmp = enleverZeros(tmp);
                            double rayon = stod(tmp);

                            //Période début utilisateur
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int jour1 = stoi(tmp);
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int mois1 = stoi(tmp);
                            getline(p1, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int annee1 = stoi(tmp);

                            //Période fin utilisateur
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int jour2 = stoi(tmp);
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int mois2 = stoi(tmp);
                            getline(p2, tmp, '/');
                            tmp = enleverZeros(tmp);
                            int annee2 = stoi(tmp);

                            if(estFormatDateValide(annee1, mois1, jour1) && estFormatDateValide(annee2, mois2, jour2))
                            {
                                Zone zone(latitude, longitude, rayon);

                                Date dateDebut(jour1, mois1, annee1);
                                Date dateFin(jour2, mois2, annee2);

                                if(dateFin <= dateDebut)
                                {
                                    cout << "La période fournie est erronée. Veuillez recommencer." << endl << endl; 
                                }
                                else
                                {
                                    Periode periode(dateDebut, dateFin);

                                    auto start = chrono::high_resolution_clock::now();

                                    double moyenne = objData.calculerMoyenneAir(&zone, &periode);

                                    if(isnan(moyenne))
                                    {
                                        cout << "Il n'y a pas encore de mesures pour la zone et la période spécifiée. " << endl << endl;
                                        break;
                                    }

                                    auto end = chrono::high_resolution_clock::now();

                                    chrono::duration<double, milli> duration = end - start;
                                    double tempsExecution = duration.count();
                                    perf1.push_back(tempsExecution);

                                    cout << "La moyenne de la qualité de l'air est : " << moyenne << " indices ATMO" << endl << endl;

                                    break;
                                }
                                
                            }
                            else
                            {
                                cout << "La période fournie est erronée. Veuillez recommencer." << endl << endl; 
                            }
                        } 
                        else
                        {
                            cout << "Les informations fournies sont erronées. Veuillez recommencer." << endl << endl;
                        }
                    }
                }
                else if(choice == "2")
                {

                    cout<<"********************************************************* Afficher l'impact des purificateurs sur l'air ********************************************************"<<endl<<endl;

                    string purificateur;

                    while(1)
                    {
                        vector<Cleaner> tmp = objData.getListeCleaners();

                        if(tmp.empty())
                        {
                            cout<<"Vous n'avez aucun purificateur." << endl << endl;
                            break;
                        }

                        cout<<"Choisissez un purificateur parmi les purificateurs suivants:" << endl << endl;
                        
                        vector<Cleaner> cleaners;
                        int j = 0;

                        for(int i = 0; i<tmp.size(); i++)
                        {

                            if(idF == tmp[i].getFournisseurId())
                            {
                                cleaners.push_back(tmp[i]);
                                cout << "         " << j+1 << "- Purificateur " << cleaners[j].getId() << " (Lat:" << cleaners[j].getLatitude() << " Long:" << cleaners[j].getLongitude() << ")" <<endl; 
                                ++j;
                            }

                        }

                        cout << endl;
                        cout << "Numéro sélectionné : ";

                        cin >> purificateur;
                        cout << endl;

                        if(estFormatNumeroValide(purificateur))
                        {

                            int purificateurChoisi = stoi(purificateur)-1;

                            if(purificateurChoisi>=j || purificateurChoisi<0)
                            {
                                cout << "Ce purificateur n'existe pas. Veuillez recommencer." << endl << endl;
                            }
                            else
                            {
                                auto start = chrono::high_resolution_clock::now();

                                tuple<double, double> impact = cleaners[purificateurChoisi].voirImpact(objData);

                                if(isnan(get<0>(impact)) || isnan(get<1>(impact)))
                                {
                                    cout << "Ce cleaner n'a pas encore d'impact significatif. " << endl << endl;
                                    break;
                                }

                                auto end = chrono::high_resolution_clock::now();

                                chrono::duration<double, milli> duration = end - start;
                                double tempsExecution = duration.count();
                                perf2.push_back(tempsExecution);

                                cout << "Le purificateur " << cleaners[purificateurChoisi].getId() << " a eu un impact de " << get<0>(impact) << " % dans un rayon de " << get<1>(impact) << " mètres." << endl << endl;
                                break;
                            }

                        }
                        else
                        {
                            cout << "Les informations fournies sont erronées. Veuillez recommencer." << endl << endl;
                        }
                    }

                }
                else
                {

                    bool checker = true;

                    while(checker)
                    {
                        cout<<"**********************************************************  Visualiser les performances d'AirWatcher  **********************************************************"<<endl<<endl;

                        if(perf1.empty() && perf2.empty() && init.empty())
                        {
                            cout << "Vous n'avez utilisé aucun algorithme pour l'instant." << endl << endl;
                            break;
                        }

                        cout << "Temps d'exécution des algorithmes:" << endl << endl;

                        if(init.empty())
                        {
                            cout << "         Vous n'avez pas initialisé les données pour l'instant." << endl << endl;
                        }
                        else
                        {

                            cout << "         Algorithme d'initialisation des capteurs : " << init[0] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des attributs : " << init[1] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des mesures : " << init[2] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des purificateurs : " << init[3] << " ms" << endl; 
                            cout << "         Algorithme d'initialisation des données privées : " << init[4] << " ms" << endl; 

                            cout << endl;
                            
                        }

                        if(perf1.empty())
                        {
                            cout << "         Vous n'avez utilisé aucun algorithme de calcul de la moyenne de la qualité de l'air pour l'instant." << endl << endl;
                        }
                        else
                        {
                            for(int i = 0; i<perf1.size(); i++)
                            {
                                cout << "         Algorithme " << i+1 << " de calcul de moyenne de la qualité de l'air : " << perf1[i] << " ms" << endl; 
                            }

                            cout << endl;
                        }

                        if(perf2.empty())
                        {
                            cout << "         Vous n'avez utilisé aucun algorithme de visualisation de l'impact d'un cleaner." << endl << endl;
                        }
                        else
                        {
                            for(int i = 0; i<perf2.size(); i++)
                            {
                                cout << "         Algorithme " << i+1 << " de visualisation de l'impact d'un purificateur sur l'air : " << perf2[i] << " ms" << endl; 
                            }

                            cout << endl;
                        }

                        checker = false;
                    }
                }
            }

        }
        else
        {
            break;
        }

    }

    return 0;
} //----- Fin de main 
