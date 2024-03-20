#ifndef DEFINES_H
#define DEFINES_H

struct Barang
{
    int kode;
    char nama[50];
    char bahan[50];
};

struct Persediaan
{
    struct Barang details;
    int jumlah;
    int harga;
};

#endif