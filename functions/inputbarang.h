#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../defines.h"
#include "../db/connection.h"
#include "../db/sqlite3.h"

void inputBarang()
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sql;
    int rc;

    db = connectDB();

    char *createSql = "CREATE TABLE IF NOT EXISTS persediaan (kode INTEGER PRIMARY KEY, nama TEXT, bahan TEXT, jumlah INTEGER, harga INTEGER);";
    rc = sqlite3_exec(db, createSql, 0, 0, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    sql = "INSERT INTO persediaan (kode, nama, bahan, jumlah, harga) VALUES (?, ?, ?, ?, ?);";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "ERROR: Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("+------------------------------------+\n");
    printf("|        Input Barang Toko           |\n");
    printf("+------------------------------------+\n");

    int n;
    printf("\n:: Banyaknya barang yang akan Anda masukkan : ");
    scanf("%d", &n);
    struct Persediaan barang[n];
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf(":: Kode Barang    : [%d] : ", i + 1);
        scanf("%d", &barang[i].details.kode);
        printf(":: Nama Barang    : [%d] : ", i + 1);
        scanf("%s", barang[i].details.nama);
        printf(":: Bahan Dasar    : [%d] : ", i + 1);
        scanf("%s", barang[i].details.bahan);
        printf(":: Jumlah         : [%d] : ", i + 1);
        scanf("%d", &barang[i].jumlah);
        printf(":: Harga per unit : [%d] : Rp. ", i + 1);
        scanf("%d", &barang[i].harga);

        sqlite3_bind_int(stmt, 1, barang[i].details.kode);
        sqlite3_bind_text(stmt, 2, barang[i].details.nama, strlen(barang[i].details.nama), 0);
        sqlite3_bind_text(stmt, 3, barang[i].details.bahan, strlen(barang[i].details.bahan), 0);
        sqlite3_bind_int(stmt, 4, barang[i].jumlah);
        sqlite3_bind_int(stmt, 5, barang[i].harga);

        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE)
        {
            printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));
        }

        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
    system("cls");
}