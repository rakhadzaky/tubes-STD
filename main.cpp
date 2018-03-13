#include <iostream>
#include <conio.h>
#include "buku.h"
#include "pembeli.h"
#include "info.h"

int main()
{
    List_buku list_book;
    List_pembeli list_beli;
    List_info list_info;
    cout<<"WELCOME TO BOOK APP"<<endl;
    cout<<"<press enter to continue>";
    getch();

    system("cls");
    createList_book(list_book);
    cout<<"1. percobaan pertama function allo_book"<<endl<<endl;
    infotype_buku a;
    cout<<"Masukan judul buku = ";
    cin>>a;
    cout<<"a = "<<a<<endl;
    adr_buku x = allo_book(a);
    cout<<"Alamat yang di dapat adalah "<<x<<endl;
    cout<<"Isi yang dimasukan adalah "<<info(x)<<endl;
    cout<<"2. percobaan procedure insert_book"<<endl;
    insert_book(list_book, x);
    cout<<"3. percobaan procedure print_book"<<endl;
    print_book(list_book);
    getch();

    system("cls");
    createList_pembeli(list_beli);
    cout<<"1. percobaan function allo_pembeli dan insert_pembeli"<<endl;
    infotype_pembeli b;
    cout<<"masukan nama orang = ";
    cin>>b;
    insert_pembeli(list_beli, allo_pembeli(b));
    cout<<"2. percobaan print_pembeli"<<endl;
    print_pembeli(list_beli);

    getch();

    system("cls");
    createList_info(list_info);
    cout<<"1. percobaan funtion allo_info dan insert_info"<<endl;
    insert_info(list_info, allo_info(first(list_beli), first(list_book)));

    cout<<"2. percobaan procedure print_info"<<endl;
    print_info(list_info);

}
