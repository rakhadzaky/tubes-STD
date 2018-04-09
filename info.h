#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#include "buku.h"
#include "pembeli.h"

#define pembeli(P) (P)->pembeli
#define buku(P) (P)->buku
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
#include <conio.h>

//pendeklarasian ADT dari info
typedef struct elm_info *adr_info;
struct elm_info{
    adr_pembeli pembeli;
    adr_buku buku;
    adr_info next;
    adr_info prev;
};
struct List_info{
    adr_info first;
    adr_info last;
};
//akhir pendeklarasian

//pendeklarasian procedure
void createList_info(List_info &L);
void insert_info(List_info &L, adr_info P);
void print_info (List_info L);
void print_info_khusus_buku(List_info L, infotype_buku buku);
void print_most_book_with_pembeli(List_info L);
void print_less_book(List_info L);
void Delete_first_infopembeli(List_info &L);
void Delete_last_infopembeli(List_info &L);
void Delete_after_infopembeli(List_info &L, adr_info P);
void Delete_infopembeli(List_info &L, adr_info P);
void Delete_pembeli(List_info &K, List_pembeli &L, infotype_pembeli x);
//void print_less_book(list_info l);

//pendeklarasian function
adr_info allo_info(adr_pembeli x, adr_buku y);

#endif // INFO_H_INCLUDED
