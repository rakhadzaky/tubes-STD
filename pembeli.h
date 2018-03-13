#ifndef PEMBELI_H_INCLUDED
#define PEMBELI_H_INCLUDED
#include <iostream>
#include <string>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

using namespace std;

//pendeklarasian ADT dari pembeli
typedef string infotype_pembeli;
typedef struct elm_pembeli *adr_pembeli;
struct elm_pembeli{
    infotype_pembeli info;
    adr_pembeli next;
};
struct List_pembeli{
    adr_pembeli first;
};
//akhire pendeklarasian ADT

//pendeklarasian procedure
void createList_pembeli(List_pembeli &L);
void insert_pembeli(List_pembeli &L, adr_pembeli P);
void print_pembeli (List_pembeli L);

//Pendeklarasian function
adr_pembeli allo_pembeli(infotype_pembeli x);

#endif // PEMBELI_H_INCLUDED
