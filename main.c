#include "lib/defines.h"
#include "functions/inputbarang.h"
#include "functions/stokbarang.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{

    system("cls");
    int pilihan;

    do
    {

        printf("+------------------------------------+\n");
        printf("|        Tugas Database Toko         |\n");
        printf("+------------------------------------+\n");
        printf("|                                    |\n");
        printf("| 1. Input Barang                    |\n");
        printf("| 2. Lihat Stok Barang               |\n");
        printf("| 3. Exit                            |\n");
        printf("|                                    |\n");
        printf("+------------------------------------+\n");
        printf("\n");
        printf("  Pilih [1, 2, 3] : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            system("cls");
            inputBarang();
            break;
        case 2:
            system("cls");
            stokBarang();
            break;
        case 3:
            system("cls");
            printf("+-------------------------------------+\n");
            printf("|        Terima kasih telah           |\n");
            printf("|        menggunakan aplikasi ini     |\n");
            printf("+-------------------------------------+\n");
            printf("|                                     |\n");
            printf("|        Nama : Abdurrazik            |\n");
            printf("|        NIM  : 2308561083            |\n");
            printf("|        Kelas: E / Informatika       |\n");
            printf("|                                     |\n");
            printf("+-------------------------------------+\n");
            system("pause");
            closeDB();
            exit(0);
            break;
        default:
            system("cls");
            printf("-- Pilihan tidak valid --\n\n");
            break;
        }
    } while (pilihan != 3);
}