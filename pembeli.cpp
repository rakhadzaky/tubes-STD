#include "pembeli.h"

void createList_pembeli(List_pembeli &L){
    first(L) = NULL;
}

adr_pembeli allo_pembeli(infotype_pembeli x){
    adr_pembeli P = new elm_pembeli;
    info(P) = x;
    next(P) = NULL;

    return P;
}

void insert_pembeli(List_pembeli &L, adr_pembeli P){
    if (first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
    }
}

void print_pembeli(List_pembeli L){
    if (first(L) != NULL){
        adr_pembeli P = first(L);
        while (P != NULL){
            cout<<info(P)<<endl;
            P = next(P);
        }
    }else{
        cout<<"Data kososng"<<endl;
    }
}
