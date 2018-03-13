#include "info.h"
#include "pembeli.h"
#include "buku.h"

void createList_info(List_info &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_info allo_info(adr_pembeli x, adr_buku y){
    adr_info P = new elm_info;
    pembeli(P) = x;
    buku(P) = y;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void insert_info(List_info &L, adr_info P){
    if (first(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}

void print_info(List_info L){
    if (first(L) != NULL){
        adr_info P = first(L);
        while (P != NULL){
            cout<<"Nama : "<<info(pembeli(P))<<endl;
            cout<<"Buku : "<<info(buku(P))<<endl;
            P = next(P);
        }
    }else{
        cout<<"data kosong";
    }
}
