#include "../include/application.h"
#include "../include/databaseManager.h"

int main()
{
    DatabaseManager db;

    if(db.connect())
    {
        db.initializeDatabase();
    }

    Application app;

    app.run();

    return 0;
}