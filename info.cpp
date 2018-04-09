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
            cout<<"Buku : "<<info(buku(P))<<endl<<endl;
            P = next(P);
        }
    }else{
        cout<<"data kosong";
    }
}

void print_info_khusus_buku(List_info L, infotype_buku buku) {
    adr_info p = first(L);
    adr_pembeli q;
    infotype_pembeli nama;
    adr_pembeli r;
    List_pembeli T;
    List_pembeli K;
    int x;
    createList_pembeli(T);
    createList_pembeli(K);

    while (p != NULL) {
        if (info(buku(p)) == buku) {
            nama = info(pembeli(p));
//            q = allo_pembeli(p->pembeli->info);
            //q = pembeli(p);
            insert_pembeli(T,allo_pembeli(nama));
        }
        p = p->next;
    }
    q = first(T);
    while (q != NULL) {
        if (first(K) == NULL) {
            nama = info(q);
            insert_pembeli(K, allo_pembeli(nama));
        }else {
            Search_pembeli(K, r, info(q));
            if (r == NULL) {
                nama = info(q);
                insert_pembeli(K, allo_pembeli(nama));
            }
        }
        q = next(q);
    }
    r = K.first;
    cout<<"Nama Buku : "<<buku<<endl;
    cout<<"Nama Pembeli : "<<endl;
    print_pembeli(K);
}

void print_most_book_with_pembeli(List_info l) {
    adr_info p = l.first;
    adr_info q = l.first;
    int x = 0;
    int maxi = 0;
    string buku;
    while (p != NULL) {
        x = 0;
        q = l.first;
        while (q != NULL) {
            if (p->buku->info == q->buku->info) {
                x = x + 1;
            }
            q = q->next;
        }
        if (x > maxi) {
            maxi = x;
            buku = p->buku->info;
        }
        p = p->next;
       }
    print_info_khusus_buku(l,buku);
}

void print_less_book(List_info l) {
    adr_info p = l.first;
    adr_info q = l.first;
    int x = 0;
    int mini = 999;
    string buku;
    while (p != NULL) {
        x = 0;
        q = l.first;
        while (q != NULL) {
            if (p->buku->info == q->buku->info) {
                x = x + 1;
            }
            q = q->next;
        }
        if (x < mini) {
            mini = x;
            buku = p->buku->info;
        }
        p = p->next;
       }
    cout<<"Nama Buku : "<<buku;
}

void Delete_first_infopembeli (List_info &L){
    adr_info P;
    if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void Delete_last_infopembeli (List_info &L){
    adr_info P;
    if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

void Delete_after_infopembeli (List_info &L, adr_info P){
    adr_info prec;
    prec = prev(P);
    next(prec) = next(P);
    prev(next(prec)) = prec;
    prev(P) = NULL;
    next(P) = NULL;
    delete P;
}

void Delete_infopembeli(List_info &L, adr_info P){
    if(first(L) == P){
        Delete_first_infopembeli(L);
    }else if(last(L) == P){
        Delete_last_infopembeli(L);
    }else{
        Delete_after_infopembeli(L, P);
    }
}

void Delete_pembeli(List_info &K, List_pembeli &L, infotype_pembeli x){
    adr_pembeli P = first(L);
    while ((P != NULL) and (info(P) != x)) {
        P = next(P);
    }
    if (info(P) == x) {
        adr_info R = first(K);
        adr_info Q;
        while (R != NULL){
            if (info(pembeli(R)) == x){
                if(R == first(K)){
                    Delete_infopembeli(K, R);
                    R = first(K);
                }else{
                    Delete_infopembeli(K, R);
                    R = Q;
                }
            }else{
                Q = R;
                R = next(R);
            }
        }
        if (first(L) == P){
            DeleteFirst_pembeli(L);
        }else if(next(P) == NULL){
            DeleteLast_pembeli(L);
        }else{
            DeleteAfter_pembeli(L, x);
        }
    }
}
