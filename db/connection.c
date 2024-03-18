#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

sqlite3 *connectDB(void)
{
    sqlite3 *db;
    char *filename = "persediaan.db";
    int rc = sqlite3_open(filename, &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    return db;
};

sqlite3 *closeDB(void)
{
    sqlite3 *db;
    sqlite3_close(db);
};