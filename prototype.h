#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nil NULL

#define maxnama 25
#define MaxData 20

typedef struct Customer *DATA;
typedef struct Customer{
    int Id;
    char Nama[maxnama];
    int Jam;
    int Cost;
    DATA Next;
}Customer;

typedef struct
{
    int Id;
    char Nama[maxnama];
    int Jam;
    int Cost;
}CustomerArray;

CustomerArray DATAarray[100];
//typedef Customer DATA[MaxData];


#define Next(P) (P)->Next
#define Id(P) (P)->Id
#define Nama(P) (P)->Nama
#define Jam(P) (P)->Jam
#define Cost(P) (P)->Cost

int id;

void CreateData(DATA *P);
DATA Alokasi();
DATA Dealokasi(DATA P);
DATA InsertControl(DATA P);
DATA UpdateControl(DATA P);
DATA DeleteControl(DATA P);


DATA Insert(DATA P,int id);
void Update(int ubah);
void Delete(int hapus);
CustomerArray ListToArray(DATA P);
DATA ArrayToList(DATA P,int initial);

void menu();
void ShowTableControl(DATA P);
void ShowTable(DATA P);
void ListToArrayControl(DATA P);
DATA ArrayToListControl();



#endif // PROTOTYPE_H_INCLUDED
