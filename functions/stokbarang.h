#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../defines.h"
#include "../db/connection.h"
#include "../db/sqlite3.h"

void stokBarang()
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sql;
    int rc;

    db = connectDB();

    sql = "SELECT * FROM persediaan;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "ERROR: Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("+--------------------------------------------------+\n");
    printf("|                 Stok Barang Toko                 |\n");
    printf("+--------------------------------------------------+\n");
    printf("| Kode | Nama Barang | Bahan | Jumlah | Harga      |\n");
    printf("+--------------------------------------------------+\n");

    while (1)
    {
        rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW)
        {
            printf("| %4d | %-11s | %-5s | %-6d | Rp. %d |\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_int(stmt, 3), sqlite3_column_int(stmt, 4));
        }
        else if (rc == SQLITE_DONE)
        {
            break;
        }
        else
        {
            fprintf(stderr, "ERROR: Cannot execute statement: %s\n", sqlite3_errmsg(db));
            break;
        }
    }
    printf("+--------------------------------------------------+\n");
    printf("\n");

    system("pause");
    system("cls");

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}