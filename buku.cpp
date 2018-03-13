#include "buku.h"

void createList_book(List_buku &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_buku allo_book(infotype_buku x){
    adr_buku P = new elm_buku;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void insert_book(List_buku &L, adr_buku P){
    if (first(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}

void print_book(List_buku L){
    if (first(L) != NULL){
        adr_buku P = first(L);
        int i = 1;
        while (P != NULL){
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
            i++;
        }
    }else{
        cout<<"Belum ada data buku";
    }
}
