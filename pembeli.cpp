#include "pembeli.h"
#include "info.h"

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
        int i = 1;
        while (P != NULL){
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
            i++;
        }
    }else{
        cout<<"Data kososng"<<endl;
    }
}

void Search_pembeli(List_pembeli L, adr_pembeli &P, infotype_pembeli x){
    if (first(L) != NULL){
        P = first(L);
        while ((P != NULL) and (info(P) != x)){
            P = next(P);
        }
        //if (info(P) != x) {
        //    P = NULL;
   //     }
    }else{
        P = NULL;

    }
}



void DeleteFirst_pembeli(List_pembeli &L){
    adr_pembeli P;
    if(next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void DeleteLast_pembeli(List_pembeli &L){
    adr_pembeli P;
    if(next(first(L)) == NULL ){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        adr_pembeli Q = first(L);
        while(next(P) != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}

void DeleteAfter_pembeli(List_pembeli &L, infotype_pembeli x){
    adr_pembeli P = first(L);
    adr_pembeli Q = first(L);
    while ((next(P) != NULL) and (info(P) != x)){
        Q = P;
        P = next(P);
    }
    next(Q) = next(P);
    next(P) = NULL;
}
