#include "prototype.h"


//Menu Control

void menu(DATA P)
{
    int input;


    system("clear");//change to "cls" if your OS windows
    printf("\n\t JUDUL \n\n");
    printf("1. Insert data\n");
    printf("2. Update data\n");
    printf("3. Delete data\n");
    printf("4. Show data\n");
    printf("Other. Exit\n");
    printf("\n\nInput : ");scanf("%d",&input);

    switch(input)
    {
        case 1:P=InsertControl(P);menu(P);
        case 2:P=UpdateControl(P);menu(P);
        case 3:P=DeleteControl(P);menu(P);
        case 4:ShowTableControl(P);
        default:exit(EXIT_FAILURE);
    }
}

DATA InsertControl(DATA P)
{
    system("clear");
    DATA temp,last;

    if(P==Nil)
    {
        P=Alokasi();
        if(P==Nil)
        {
            printf("\nOut of Memory / Error in program\n");
        }
        else
        {
            id++;
            P=Insert(P,id);
            Next(P)=Nil;
        }
    }
    else
    {
        temp=P;
        while(temp!=Nil)
        {
            last=temp;
            temp=Next(temp);
        }
        Next(last)=Alokasi();
        last=Next(last);
        if(last==Nil)
        {
            printf("\nOut of Memory / Error in program\n");
        }
        else
        {
            id++;
            last=Insert(last,id);
            Next(last)=Nil;
        }
    }
    return (P);
}

void ShowTableControl(DATA P)
{
    char yn;
    DATA temp;
    temp = P;
    system("clear");
    if(temp==Nil)
        printf("\nData Kosong\n");
    else
    {
        printf("\tId\tNama\tDurasi(Jam)\tCost\t\n");
        while(temp!=Nil)
        {
            ShowTable(temp);
            temp=Next(temp);
        }
    }
    printf("\n\nKembali ke menu utama/exit? y/n(other) ");scanf("%s",&yn);
    if(yn=='y')
        menu(P);
    else
        exit(EXIT_FAILURE);

}

DATA UpdateControl(DATA P)
{
    int cari,first,last,middle;
    first=1;
    last=id;
    middle=(first+last)/2;
    ListToArrayControl(P);
    free(P);
    printf("Id yang diedit? ");scanf("%d",&cari);
    while( first <= last )
   {
      if ( DATAarray[middle].Id < cari )
         first = middle + 1;
      else if ( DATAarray[middle].Id == cari )
      {
         Update(middle);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if ( first > last )
      printf("Not found! %d is not present in the list.\n", cari);

    P=ArrayToListControl();
    return P;
}

DATA DeleteControl(DATA P)
{
    int cari,first,last,middle;
    first=1;
    last=id;
    middle=(first+last)/2;
    ListToArrayControl(P);
    free(P);
    printf("Id yang dihapus? ");scanf("%d",&cari);
    while( first <= last )
   {
      if ( DATAarray[middle].Id < cari )
         first = middle + 1;
      else if ( DATAarray[middle].Id == cari )
      {
         Delete(middle);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if ( first > last )
      printf("Not found! %d is not present in the list.\n", cari);

    P=ArrayToListControl();
    return P;
}



//List Control

DATA Alokasi()
{
    DATA P;
/* Algoritma */
    P = (DATA) malloc (sizeof(Customer));
    if (P != Nil)
    { /* alokasi berhasil */
        return(P);
    }
    else { return Nil; }
}

void CreateData(DATA *P)
{
    (*P) = Nil;
}

//Array Control
void ListToArrayControl(DATA P)
{
    int count=1;
    while(P!=Nil)
    {
        DATAarray[count]=ListToArray(P);
        count++;
        P=Next(P);
    }
}

DATA ArrayToListControl()
{
    DATA P;
    CreateData(&P);
    int initial=1;
    while(initial<=id)
    {
        DATA temp,last;

        if(P==Nil)
        {
            P=Alokasi();
            if(P==Nil)
            {
                printf("\nOut of Memory / Error in program\n");
            }
            else
            {
                P=ArrayToList(P,initial);
                Next(P)=Nil;
            }
        }
        else
        {
            temp=P;
            while(temp!=Nil)
            {
                last=temp;
                temp=Next(temp);
            }
            Next(last)=Alokasi();
            last=Next(last);
            if(last==Nil)
            {
                printf("\nOut of Memory / Error in program\n");
            }
            else
            {
                last=ArrayToList(last,initial);
                Next(last)=Nil;
            }
        }
        initial++;
    }
    return P;
}
