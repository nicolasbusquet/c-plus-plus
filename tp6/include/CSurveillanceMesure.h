#ifndef CSURVEILLANCEMESURE_H
#define CSURVEILLANCEMESURE_H


class CSurveillanceMesure
{
    public:
    CSurveillanceMesure(float valdefaut = 0);
    bool mesurer();
    float valMesuree();
    float valMin();
    float valMax();
    float moyenne();
    float mediane();
    bool moyenneGlissante(float &moyenne, int nbvaleurs = 10, int indiceMesure1 = 0);
    void affichemesures();



    private:
        float tabMesures[10];
        int nbMesures;
        void tritableau();

};

#endif // CSURVEILLANCEMESURE_H
