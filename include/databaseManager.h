#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <mysqlx/xdevapi.h>

class DatabaseManager
{
private:
    mysqlx::Session* session;

public:
    DatabaseManager();

    ~DatabaseManager();

    bool connect();

    void initializeDatabase();

    void disconnect();

    mysqlx::Session* getSession();
};

#endif