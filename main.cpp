#include <iostream>
char valeurs[]={'A','K','Q','J','T','9','8','7','6','5','4','3','2'};

bool generateMain(char*);
void afficherMain(const char *);
bool trouveCarteidentique(const char*);
bool paire(const char*);
bool deuxpaire(const char *);
bool brelan(const char*);
void test(const char *);
bool carre(const char *);
bool trouveCarteidentique(char *main) {
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(main[i]==main[j])
            {

                return true;
            }
        }
    }
    return false;
}
bool generateMain(char *main) {

    /********************génération de la main*********************/
    for(int i=0;i<5;i++)
    {
        main[i]=valeurs[rand() %13];
    }
    /******************vérification si valide***********************/
    int cpt=0;
    for(int i=0;i<5;i++) //boucle pour choisir la carte a tester
    {
        cpt=0;
        for(int j=0;j<5;j++) //boucle de comparaison avec les autres cartes
        {
            if(main[i]==main[j]) //si on on trouve en double
                cpt++; //incrémentation du compteur
        }
        if(cpt>4) //si supérieur à 4
        {
            return false; //main invalide
        }
    }

    return true;
}


void afficherMain(char *main)
{
    for(int i=0;i<5;i++)
    {
        printf("%c",main[i]);
    }

}




bool paire(char *main) {
    int cpt=0;
    if(trouveCarteidentique(main)) //si il y a deux cartes identiques il y a au moins une main
    {
        return true;

        }
    else
    return false;

  }


bool deuxpaire(char *main) {
    int cpt=0;
    int cptpaire=0;
    if(trouveCarteidentique(main))
    {
        for(int i=0;i<5;i++) //boucle pour choisir la carte a tester
        {
            if(cpt==2) //si égale à 2
            {
                return true;
            }
            for(int j=i+1;j<5;j++) //boucle de comparaison avec les autres cartes
            {
                if(main[i]==main[j]) {//si on on trouve en double
                    cpt++;
                    break;
                }   //incrémentation du compteur
            }

        }

    }
    return false;
}
bool brelan(const char *main) {
    int cpt=0;
    if(trouveCarteidentique(main))
    {
        for(int i=0;i<5;i++) //boucle pour choisir la carte a tester
        {
            cpt=0;
            for(int j=i+1;j<5;j++) //boucle de comparaison avec les autres cartes
            {
                if(main[i]==main[j]) //si on on trouve en double

                {
                    cpt++;//incrémentation du compteur

                }
                if(cpt==2) //si égal à 2
                {
                    return true; //main brelan
                }
            }

        }

    }

    return false;
}

bool carre(const char *main) {
    int cpt = 0;
    if (trouveCarteidentique(main)) {
        for (int i = 0; i < 5; i++) //boucle pour choisir la carte a tester
        {
            cpt = 0;
            for (int j = i + 1; j < 5; j++) //boucle de comparaison avec les autres cartes
            {
                if (main[i] == main[j]) //si on on trouve en double

                {
                    cpt++;//incrémentation du compteur

                }
                if (cpt == 3) //si égal à 3
                {
                    return true; //main carre
                }
            }

        }
    }
    return false;
    }





void test(char *main) {
    for(int i=0;i<100;i++)
    {
        if(generateMain(main))
        {
            afficherMain(main);

            printf("  %s %s\n ","PAIRE", paire(main) ? "true" : "false");
            printf("  %s %s\n ","DEUX PAIRES", deuxpaire(main) ? "true" : "false");
            printf("  %s %s\n ","BRELAN", brelan(main) ? "true" : "false");
            printf("----------------------------------------------------------------\n");
        }
    }


}




int main() {
    char mamain[5]={' ',' ',' ',' ',' '}; //intialisation du tableau car variable locale
    srand(time(NULL)); //initialisation de la commnande
    test(mamain);
    return 0;
}

