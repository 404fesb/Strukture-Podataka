#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

typedef struct cvor* KD;

struct cvor
{
    int niz1[3];
    
    KD lijevo;
    KD desno;
    
};

KD insert(KD, int[], int);
int read();
KD stvoriCvor(int[]);
bool pretrazi(KD, int [], int);
bool usporedi(int[], int []);

int main(void)
{
    const int k = 3;
    struct cvor* head = NULL;
        
    int n = 0;    
    int trazi[3];
   
    // ucitavanje iz datoteke;
    FILE* fp;
    int niz[5][3] = { 0,0,0 };
    int i, j;

    fp = fopen("br.txt", "r");

    if (fp == NULL)
        printf("Greska pri otvaranju datoteke!");

    else
    {
        for (i = 0; !feof(fp); i++)
        {
            for (j = 0; j < 3; j++)
                fscanf(fp, "%d", &niz[i][j]);
        }

    }
    fclose(fp);
   
    for (int i = 0; i < 5; i++)
         head = insert(head, niz[i], 0);

    

    while (n != 3)
    {
        printf("Za pretragu stabla unesite 1.\nZa izlaz unesite 2.\n");
        scanf("%d", &n);

        switch (n) {
        case 1:
            printf("Koji broj zelite pretraziti?\nUnesite ga u obliku X,Y,Z:\n");
            for (int i = 0; i < 3; i++) 
            {
                printf("Unesite broj:");
                scanf("%d", &trazi[i]);
            }
            if (pretrazi(head, trazi, 0))
                printf("Broj je pronaden.\n");
            else
                printf("Broj ne postoji.\n");

            break;             
        case 2:
            printf("Kraj programa.\n");
            break;
        default:
            printf("Krivi unos! Unesi ponovo!");
        }

    }


    return 0;
}
int read()
{
    FILE* fp;

    const int k = 3;
    int niz[20][3] = { 0,0,0 };

    int i, j;

    fp = fopen("br.txt", "r");

    if (fp == NULL)
        printf("Greska pri otvaranju datoteke!\n");

    else
    {
        for (i = 0; !feof(fp); i++)
        {
            for (j = 0; j < 3; j++)
                fscanf(fp, "%d", &niz[i][j]);
        }

    }
    fclose(fp);

    return niz;
}
KD insert(KD head, int niz[], int dubina)
{
    int k = 3;

    if (head == NULL)
    {
        printf("Stablo je prazno.Stvaramo cvor.\n");
        return stvoriCvor(niz);
    }

    int trenutna = dubina % k;

    if (niz[trenutna] < head->niz1[trenutna])
        head->lijevo = insert(head->lijevo, niz, dubina + 1);
    else if (niz[trenutna] >= head->niz1[trenutna])
        head->desno = insert(head->desno, niz, dubina + 1);
    else
        return head;


    return head;

}
KD stvoriCvor(int niz[])
{
    KD q;
    int k = 3;
    q = (KD)malloc(sizeof(struct cvor));
    
    for (int i = 0; i < k; i++)
        q->niz1[i] = niz[i];

    q->lijevo = NULL;
    q->desno = NULL;

    return q;

}
bool pretrazi(KD head, int niz[], int dubina)
{
    int k = 3;
    if (head == NULL)
    {        
        return false;
    }

    if (usporedi(head->niz1, niz))
        return true;

    int trenutna = dubina % k;

    if (niz[trenutna] < head->niz1[trenutna])
        return pretrazi(head->lijevo, niz, dubina + 1);
    
    return pretrazi(head->desno, niz, dubina + 1);
}
bool usporedi(int niz1[], int niz2[])
{
    int k = 3;
    for (int i=0;i<k;i++)
    {
        if (niz1[i] != niz2[i])
            return false;
    }
    return true;
}



