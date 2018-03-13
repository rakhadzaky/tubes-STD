#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>
#include <string>

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


//pendeklarasian function
adr_buku allo_book(infotype_buku x);

#endif // BUKU_H_INCLUDED
