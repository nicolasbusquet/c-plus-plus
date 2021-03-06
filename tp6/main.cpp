#include<iostream>
using namespace std;
#include "CSurveillanceMesure.h"
#include <cstdlib>

int main()
{
    CSurveillanceMesure mesure(-1);
    int t;
    bool verif;
    float dernval;
    float minimum;
    float maximum;
    float moyenne;
    float mediane;
    int nbmesur;
    int indice;
    bool gliss;

    verif = mesure.mesurer();
    while (verif==false)
        {
            cout << "mesure echouee, entrez une nouvelle mesure" << endl;
            verif = mesure.mesurer();
        }

    while (1)
    {
        cout << "1: effectuer une mesure" << endl;
        cout << "2: afficher la derniere valeur mesuree" << endl;
        cout << "3: afficher la valeur minimale" << endl;
        cout << "4: afficher la valeur maximale" << endl;
        cout << "5: afficher la moyenne" << endl;
        cout << "6: afficher la mediane" << endl;
        cout << "7: afficher la moyenne glissante" << endl;
        cout << "8: afficher les mesures" << endl;
        cout << "9: quitter" << endl;
        cin >> t;
        system("cls");
        switch(t)
        {
            case 1:  verif = mesure.mesurer();
                     while (verif==false)
                        {
                            cout << "mesure echouee" << endl;
                            verif = mesure.mesurer();
                        }
                    break;
            case 2: dernval = mesure.valMesuree();
                    cout << "derniere valeur mesuree = " << dernval << endl;
                    cout << "" << endl;
                    break;
            case 3: minimum = mesure.valMin();
                    cout << "minimum = " << minimum << endl;
                    cout << "" << endl;
                    break;
            case 4: maximum = mesure.valMax();
                    cout << "maximum = " << maximum << endl;
                    cout << "" << endl;
                    break;
            case 5: moyenne = mesure.moyenne();
                    cout << "moyenne = "<< moyenne << endl;
                    cout << "" << endl;
                    break;
            case 6: mediane = mesure.mediane();
                    cout << "mediane = "<< mediane << endl;
                    cout << "" << endl;
                    break;
            case 7: cout << "saisissez le nombre de mesures sur lesquels faire la moyenne" << endl;
                    cin >> nbmesur;
                    cout << "saisissez le numero de la mesure a partir duquel vous souhaitez effectuer la moyenne" << endl;
                    cin >> indice;
                    gliss = mesure.moyenneGlissante(moyenne, nbmesur, indice);
                    while(gliss == false)
                    {
                        cout << "fatal error, resaisissez vos valeurs" << endl;
                        cout << "saisissez le nombre de mesures sur lesquels faire la moyenne" << endl;
                        cin >> nbmesur;
                        cout << "saisissez le numero de la mesure a partir duquel vous souhaitez effectuer la moyenne" << endl;
                        cin >> indice;
                        gliss = mesure.moyenneGlissante(moyenne=-1, nbmesur, indice);
                    }
                    cout << "moyenne glissante = "<< moyenne << endl;
                    cout << "" << endl;
                    break;
            case 8: mesure.affichemesures();
                    break;
            case 9: return 0;

        }
    }
}
