#include <iostream>
#include <conio.h>
#include "buku.h"
#include "pembeli.h"
#include "info.h"

int main()
{
    //kamus
    List_buku list_book, sort_buku;
    List_pembeli list_beli;
    List_info list_info;
    infotype_pembeli b;
    infotype_buku a;
    adr_pembeli beli;
    adr_buku buku;
    adr_info info;
    int menu;

    //algoritma
    cout<<"WELCOME TO BOOK APP"<<endl;
    cout<<"<press enter to continue>";
    createList_book(list_book);
    createList_pembeli(list_beli);
    createList_info(list_info);
    createList_book(sort_buku);
    getch();

    //dummy content
    a = "aa";
    insert_book(list_book, allo_book(a));
    a = "bb";
    insert_book(list_book, allo_book(a));

    system("cls");
    do{
        system("cls");
        cout<<"|=================MAIN MENU=================|"<<endl;
        cout<<"|1.  Input Buku                             |"<<endl;//insert_book
        cout<<"|2.  Input Pembeli                          |"<<endl;//insert_pembeli dan insert_info
        cout<<"|3.  Print Buku                             |"<<endl;//print list_book
        cout<<"|4.  Print Pembeli                          |"<<endl;//print list_pembeli
        cout<<"|5.  Delte Pembeli                          |"<<endl;//Delete pembeli dan delete info
        cout<<"|6.  Menampilakan buku dan para pembelinya  |"<<endl;
        cout<<"|7.  Mencari pembeli yang membeli suatu buku|"<<endl;
        cout<<"|8.  Buku yang dibeli paling banyak         |"<<endl;
        cout<<"|9.  Buku yang dibeli paling sedikit        |"<<endl;
        cout<<"|10. Sorting Buku Descending                |"<<endl;
        cout<<"|0.  Exit                                   |"<<endl;
        cout<<"|===========================================|"<<endl;
        cin>>menu;

        if(menu == 1){
            //1. Input Buku
            system("cls");
            //cout<<"1. percobaan pertama function allo_book"<<endl<<endl;
            cout<<"[=========INPUT BUKU===========]"<<endl;
            cout<<"Masukan judul buku = ";
            cin>>a;

//            strupr(a);

            adr_buku x;
            Search_buku(list_book, x, a);

            if (x == NULL){
                insert_book(list_book, allo_book(a));
                cout<<"Data di input"<<endl;
            }else{
                cout<<"Data sudah ada"<<endl;
            }
            getch();
        }else if(menu == 2){
            //insert pembeli dan info

            if (Is_Null(list_book)){
                //insert pembeli
                system("cls");
                //cout<<"1. percobaan function allo_pembeli dan insert_pembeli"<<endl;
                cout<<"[=========INPUT PEMBELI=========]"<<endl;
                cout<<"Masukan nama orang = ";
                cin>>b;
                beli = NULL;
                //cout<<"beli = "<<beli<<endl;
                //getch();
                Search_pembeli(list_beli, beli, b);

                if (beli == NULL) {
                    insert_pembeli(list_beli, allo_pembeli(b));
                    beli = first(list_beli);
                }else{
                    cout<<"Nama sudah terdaftar"<<endl;
                }
                cout<<"Daftar buku :"<<endl;
                print_book(list_book);
                cout<<endl;
                cout<<"masukan nama buku yang mau di beli = ";
                cin>>a;
                Search_buku(list_book, buku, a );
                if (buku == NULL) {
                    cout<<"Nama buku tidak ada";
                }else {
                cout<<"Terimakasih!!"<<endl;
                insert_info(list_info, allo_info(beli, buku));
                };
            }else{
                cout<<"Tidak ada data buku"<<endl;
            }
            getch();
        }else if(menu == 3){
            //print buku
            system("cls");
            //cout<<"3. percobaan procedure print_book"<<endl;
            cout<<"[=========DATA BUKU===========]"<<endl;
            print_book(list_book);
            getch();
        }else if (menu == 4){
            //print pembeli
            system("cls");
            //cout<<"2. percobaan print_pembeli"<<endl;
            cout<<"[=========DATA PEMBELI===========]"<<endl;
            print_pembeli(list_beli);
            getch();
        }else if (menu == 5){
            system("cls");
            cout<<"[==============HAPUS DATA PEMBELI============]"<<endl;
            print_pembeli(list_beli);
            cout<<endl;
            cout<<"Masukan nama pembeli yang ingin di hapus : ";
            cin>>b;
            beli = NULL;
            Search_pembeli(list_beli, beli, b);
            if (beli == NULL) {
                    cout<<"Data Tidak Ada";
                }else{
                    Delete_pembeli(list_info, list_beli, b);
                    cout<<"Data Pembeli Telah Dihapus"<<endl;
                }
                getch();
            //Delete_pembeli(list_info, list_beli, b);
        }else if (menu == 6){
            //print info
            system("cls");
            //cout<<"2. percobaan procedure print_info"<<endl;
            cout<<"[=========INFO DATA===========]"<<endl;
            print_info(list_info);
            getch();
        }else if (menu == 7){
            //print info
            system("cls");
            //cout<<"2. percobaan procedure info khusus buku"<<endl;
            cout<<"[=========NAMA PEMBELI DARI SUATU BUKU===========]"<<endl;
            cout<<"Masukkan nama buku = ";
            cin>>a;
            print_info_khusus_buku(list_info,a);
            getch();
        }else if (menu == 8){
            //print info
            system("cls");
            //cout<<"2. percobaan procedure buku terbanyak"<<endl;
            cout<<"[=========BUKU DENGAN PEMBELI TERBANYAK=========]"<<endl;
            print_most_book_with_pembeli(list_info);
            getch();
        }else if (menu == 9){
            //print info
            system("cls");
            //cout<<"2. percobaan procedure buku papling sedikit"<<endl;
            cout<<"[===========BUKU DENGAN PEMBELI PALING SEDIKIT===========]"<<endl;
            print_less_book(list_info);
            getch();
        }
        else if (menu == 10){
            //print info
            system("cls");
            //cout<<"2. percobaan procedure sorting buku"<<endl;
            cout<<"[===========SORTING NAMA BUKU===========]"<<endl;
            SortBuku(list_book, sort_buku);
            getch();
        }
    }while (menu != 0);

}
