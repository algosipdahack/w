#pragma once
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <iostream>
#include <mutex>

#include "sqlite/sqlite3.h"
#include "base/gtrace.h"

struct Data_List {
    int argc;
    char** argv;
    char** column;

    static void list_free(std::list<Data_List> data);
};

struct DB_Connect {
private:
    sqlite3* db;
    std::string db_name;
    std::mutex m;

    DB_Connect();
    ~DB_Connect();

public:
    int rc;
    static DB_Connect& getInstance() {
        static DB_Connect db_connect;
        return db_connect;
    }
    std::list<Data_List> select_query(std::string query);
    int send_query(std::string query);
protected:
    static int callback(void* dl, int ac, char** av, char** c);
};