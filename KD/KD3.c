#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct cvor* KD;

struct cvor
{
    char* lista1[3];

    KD lijevo;
    KD desno;

};

KD insert(KD,const char[], int);
void ucitaj(KD);
KD stvoriCvor(char[]);
bool pretrazi(KD, char[], int);


int main(void)
{
    const int k = 3;
    struct cvor* head = NULL;

    FILE* fp;

    char* lista[] = { "Ivana Horvat 2003","Jelena Kovac 1996","Ante Josipovic 2005","Josip Ivic 1993","Mate Juric 1996" };
    long duzina;

    /*fp = fopen("studenti.txt", "r");

    if (fp == NULL)
        printf("Greska pri otvaranju datoteke!\n");

    else
    {
        fseek(fp, 0, SEEK_END);
        duzina = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        lista = (char*)malloc(duzina*sizeof(char));

        if (lista == NULL)
            printf("Greska pri alokaciji memorije!\n");

        while(!feof(fp))
        {

            //fgets(&lista[i],18,fp); ????
            printf("%s\n",&lista);
            printf("%s", lista[i]);
            i++;

        }


        fclose(fp);
    }*/

    for (int i = 0; i < 5; i++)
    {
        head = insert(head, lista[i], 0);
        
    }


    int n = 0;
    char trazi[15];

    while (n != 4)
    {
        printf("Unesite broj pored radnje koju zelite izvrsiti.\n 1. Pretraga po imenu. \n 2. Pretraga po prezimenu.\n 3. Pretraga po godistu.\n 4.Izlaz.\n");
        scanf("%d", &n);

        switch (n) {
        case 1:
            printf("Koje ime zelite pretraziti?\n");
            scanf("%s", trazi);
            pretrazi(head, trazi, 0);
            break;
        case 2:
            printf("Koje prezime zelite pretraziti?\n");
            scanf("%s", trazi);
            pretrazi(head, trazi, 1);
            break;
        case 3:
            printf("Koje godiste zelite pretraziti?\n");
            scanf("%s", trazi);
            pretrazi(head, trazi, 2);
            break;
        case 4:
            printf("Kraj programa.\n");
            break;
        default:
            printf("Krivi unos! Unesi ponovo!");
        }

    }

}
void ucitaj(KD p)
{
    /*  FILE* fp;
      struct cvor p;
      KD q;
      int niz[5][3];
      int i, j, k = 0;

      fp = fopen("studenti.txt", "r");

      if (fp == NULL)
          printf("Greska pri otvaranju datoteke!");

      else
      {
          while (!feof(fp))
          {
              q = (KD)malloc(sizeof(struct cvor));
              if (q == NULL)
                  printf("Greska pri alociranju memorije!");
              else
              {
                  fscanf(fp, " %s %s %d\n", q->ime, q->prezime, &q->godina);
                  q->next = p->next;
                  p->next = q;

              }
          }
      }
      fclose(fp);*/
}
KD insert(KD head,const char lista[], int dubina)
{
    int k = 3;

    if (head == NULL)
    {
        printf("Stvaramo cvor.\n");
        return stvoriCvor(lista);
    }

    int trenutna = dubina % k;

    char kopija[25];
    strcpy(kopija, lista);
    
    if (trenutna == 0)
    {


        char* ime = strtok(kopija, " ");
        if (strcmp(ime, head->lista1[trenutna]) < 0) //mijenja se vrijednost varijable u lista1 ?
            head->lijevo = insert(head->lijevo, lista, dubina + 1);
        else if (strcmp(ime, head->lista1[trenutna]) >= 0)
            head->desno = insert(head->desno, lista, dubina + 1);
        else
            return head;
    }
    else if (trenutna == 1)
    {
        char* prezime = strtok(kopija, " ");
        prezime = strtok(NULL, " ");
        if (strcmp(prezime, head->lista1[trenutna]) < 0)
            head->lijevo = insert(head->lijevo, lista, dubina + 1);
        else if (strcmp(prezime, head->lista1[trenutna]) >= 0)
            head->desno = insert(head->desno, lista, dubina + 1);
        else
            return head;
    }
    else if (trenutna == 2)
    {
        char* godina = strtok(kopija, " ");
        godina = strtok(NULL, " ");
        godina = strtok(NULL, " ");
        if (strcmp(godina, head->lista1[trenutna]) < 0)
            head->lijevo = insert(head->lijevo, lista, dubina + 1);
        else if (strcmp(godina, head->lista1[trenutna]) >= 0)
            head->desno = insert(head->desno, lista, dubina + 1);
        else
            return head;
    }

    return head;
}
KD stvoriCvor(char lista[])
{
    KD q;
    int k = 3;
    char kopija[25];
    strcpy(kopija, lista);

    char* str = strtok(kopija, " ");

    q = (KD)malloc(sizeof(struct cvor));

    for (int i = 0; i < k; i++)
    {
        q->lista1[i] = str;
        str = strtok(NULL, " ");

    }
    printf("Stvoren cvor: %s %s %s\n", q->lista1[0], q->lista1[1], q->lista1[2]);
    q->lijevo = NULL;
    q->desno = NULL;

    return q;

}
bool pretrazi(KD head, char trazi[], int n)
{
    int k = 3;

    if (head == NULL)
    {
        printf("Nije pronadeno!");
        return false;
    }

    if (strcmp(trazi, head->lista1[n]) == 0)
    {
        printf("\n Pronadeno: %s %s %s\n", head->lista1[0], head->lista1[1], head->lista1[2]);
        return true;
    }

    if (strcmp(trazi, head->lista1[n]) < 0)
        return pretrazi(head->lijevo, trazi, n);

    return pretrazi(head->desno, trazi, n);
}



