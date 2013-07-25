#include "prototype.h"


DATA Insert(DATA P,int id)
{

    Id(P)=id;
    printf("Nama Penyewa? ");scanf("%s",Nama(P));
    printf("Durasi ? ");scanf("%d",&Jam(P));
    Cost(P)=Jam(P)*2000;

    return P;
}

void Update(int ubah)
{
    printf("Ubah Data Nama Penyewa : ");scanf("%s",DATAarray[ubah].Nama);
    printf("Ubah Data Durasi ? ");scanf("%d",&DATAarray[ubah].Jam);
    DATAarray[ubah].Cost=DATAarray[ubah].Jam*2000;
}

void Delete(int hapus)
{
    while(hapus<id)
    {
        DATAarray[hapus].Id=DATAarray[hapus+1].Id;
        strcpy(DATAarray[hapus].Nama,DATAarray[hapus+1].Nama);
        DATAarray[hapus].Jam=DATAarray[hapus+1].Jam;
        DATAarray[hapus].Cost=DATAarray[hapus+1].Cost;
        hapus++;
    }
    DATAarray[id].Id=0;
    strcpy(DATAarray[id].Nama," ");
    DATAarray[id].Jam=0;
    DATAarray[id].Cost=0;
    id--;
}

void ShowTable(DATA P)
{
    printf("\t%d\t%s\t%d\t\t%d\t\n",Id(P),Nama(P),Jam(P),Cost(P));
}

CustomerArray ListToArray(DATA P)
{
    CustomerArray D;
    D.Id = Id(P);
    strcpy(D.Nama,Nama(P));
    D.Jam = Jam(P);
    D.Cost = Cost(P);
    return D;
}

DATA ArrayToList(DATA P,int initial)
{
    Id(P)=initial;
    strcpy(Nama(P),DATAarray[initial].Nama);
    Jam(P)=DATAarray[initial].Jam;
    Cost(P)=DATAarray[initial].Cost;
    return P;
}
