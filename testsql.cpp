#include <iostream>
#include "sqlite3.h"

int main()
{
    std::cout << "Hello World" << std::endl;

    sqlite3* db;
    char* errMsg = nullptr;

    if (sqlite3_open("test_db", &db) != SQLITE_OK)
    {
	std::cerr << "Error opening database" << std::endl;
	return 1;
    }

    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT);";
    if (sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
	std::cerr << " Error creating table" << std::endl;
	sqlite3_free(errMsg);
    }

    const char* insertSQL = "INSERT INTO users (name) VALUES ('Carrie');";
    if (sqlite3_exec(db, insertSQL, nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
	std::cerr << "Error inserting data: " << std::endl;
	sqlite3_free(errMsg);
    }

    std::cout << "Data inserted successfully !" << std::endl;

    sqlite3_close(db);

    return 0;
}
