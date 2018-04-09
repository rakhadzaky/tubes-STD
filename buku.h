#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdio.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)

using namespace std;

//pendeklarasian ADT dari buku
typedef string infotype_buku;
typedef struct elm_buku *adr_buku;
struct elm_buku{
    infotype_buku info;
    adr_buku next;
    adr_buku prev;
};
struct List_buku{
    adr_buku first;
    adr_buku last;
};
//akhir pendeklarasian

//pendeklarasain procedure
void insert_book(List_buku &L, adr_buku P);
void print_book(List_buku L);
void createList_book(List_buku &L);
void Search_buku(List_buku L, adr_buku &P, infotype_buku x);
void SortBuku(List_buku X, List_buku K);
void deleteBuku(List_buku &L, adr_buku x);
void deleteFirst_book(List_buku &L);
void deleteLast_book(List_buku &L);
void deleteAfter_book(List_buku &L, adr_buku x);


//pendeklarasian function
adr_buku allo_book(infotype_buku x);
bool Is_Null (List_buku L);

#endif // BUKU_H_INCLUDED
