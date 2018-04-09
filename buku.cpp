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

void Search_buku(List_buku L, adr_buku &P, infotype_buku x){
    if (first(L) != NULL){
        P = first(L);
        while ((P != NULL) and (info(P) != x)){
            P = next(P);
        }
    }else{
        P = NULL;
    }
}

bool Is_Null(List_buku L){
    return first(L) != NULL;
}

void deleteBuku (List_buku &L, adr_buku x){
    if(first(L) != NULL){
        if(x == first(L)){
            deleteFirst_book(L);
        }else if(x == last(L)){
            deleteLast_book(L);
        }else{
            deleteAfter_book(L,x);
        }
    }
}

void deleteFirst_book(List_buku &L){
    if(first(L) != NULL){
        adr_buku P;
        if(first(L) != last(L)){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
        }else{
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
    }
}

void deleteLast_book(List_buku &L){
    if(first(L) != NULL){
        adr_buku P;
        if(first(L) != last(L)){
            P = last(L);
            last(L) = prev(P);
            next(last(L)) = NULL;
        }else{
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
    }
}

void deleteAfter_book(List_buku &L, adr_buku x){
    adr_buku P = prev(x);
    next(P) = next(x);
    prev(next(x)) = P;
}

void SortBuku(List_buku X, List_buku K){
    adr_buku P, maks;
    List_buku L;
    L = X;
//    createList_book(K);
    while (first(L) != NULL){
        P = first(L);
        maks = NULL;
        while (P != NULL){
            if (maks == NULL){
                maks = P;
            }else{
                if (info(P) <= info(maks)){
                    maks = P;
                }
            }
            P =next(P);
        }
        insert_book(K, allo_book(info(maks)));
        deleteBuku(L,maks);
    }
    print_book(K);
}
