#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Matrice MatAllouer(int NbLig, int NbCol) {
    unsigned char **tab;
    if ((NbLig==0)||(NbCol==0))
    {
        return NULL;
    }
    *tab = malloc(NbLig*NbCol*sizeof(unsigned char));
    return *tab;
}

Matrice MatLire (int *pNbLig, int *pNbCol) {
    // initialisation du nombre de colonnes et lignes
    printf("Entrez le nombre de ligne :");
    scanf("%d",pNbLig);
    printf("Entrez le nombre de colonne :");
    scanf("%d",pNbCol);

    // allocation de la matrice
    unsigned char **tab = MatAllouer(pNbLig,pNbCol);
    if (**tab==NULL) return NULL; // condition d'arret si NULL
    printf("Entrez vos valeurs : \n");
    for (int i=0; i<pNbLig; i++)
    {
        for (int j=0; j<pNbCol; j++)
        {
            scanf("%hhu",tab[i][j]);
        }
    }
    return **tab;
}

void MatAfficher(Matrice Mat, int NbLig, int NbCol){
      for (int i=0; i<NbLig; i++)
    {
        for (int j=0; j<NbCol; j++)
        {
            printf("%hhu",Mat[i][j]);
        }
    }
}

int main (void) {
    int ligne,colonne;
    unsigned char tab;
    tab = MatLire(&ligne,&colonne);
    MatAfficher (tab,ligne,colonne);
    return 0;
}
