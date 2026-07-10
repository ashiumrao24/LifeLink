#include "../include/databaseManager.h"

#include <iostream>

using namespace std;

DatabaseManager::DatabaseManager()
{
    session = nullptr;
}

DatabaseManager::~DatabaseManager()
{
    disconnect();
}

bool DatabaseManager::connect()
{
    try
    {
        session = new mysqlx::Session(
            "localhost",
            33060,
            "root",
            ""
        );

        cout << "✅ Connected to MySQL successfully!" << endl;

        return true;
    }
    catch(const mysqlx::Error& err)
    {
        cout << "❌ MySQL Error: "
             << err.what()
             << endl;

        return false;
    }
}

void DatabaseManager::disconnect()
{
    if(session)
    {
        delete session;
        session = nullptr;
    }
}

mysqlx::Session* DatabaseManager::getSession()
{
    return session;
}
void DatabaseManager::initializeDatabase()
{
    try
    {
        cout << "Creating database..." << endl;

        session->sql("CREATE DATABASE IF NOT EXISTS lifelink").execute();

        cout << "Using database..." << endl;

        session->sql("USE lifelink").execute();

        cout << "Creating donors table..." << endl;

        session->sql(R"(
            CREATE TABLE IF NOT EXISTS donors
            (
                donor_id INT PRIMARY KEY,
                name VARCHAR(100),
                blood_group VARCHAR(5),
                phone VARCHAR(20),
                latitude DOUBLE,
                longitude DOUBLE,
                last_donation DATE,
                available BOOLEAN
            )
        )").execute();

        cout << "Creating requests table..." << endl;

        session->sql(R"(
            CREATE TABLE IF NOT EXISTS requests
            (
                request_id INT PRIMARY KEY,
                patient_name VARCHAR(100),
                required_blood_group VARCHAR(5),
                hospital_name VARCHAR(100),
                latitude DOUBLE,
                longitude DOUBLE,
                urgency VARCHAR(20),
                status VARCHAR(20)
            )
        )").execute();

        cout << "✅ Database initialized successfully!" << endl;
    }
    catch(const mysqlx::Error& err)
    {
        cout << "MySQL Error: " << err.what() << endl;
    }
}