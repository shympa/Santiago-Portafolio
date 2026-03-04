/*
* Author(s): Professor Pullen
* TODO - Add your documentation to this file
*        if you change it, either way remove
*        this TODO comment once finished
*/

#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include <string>
#include <fstream>

class SalesManager {
private:
    std::string filename;
    std::ofstream logStream;

    // Helper Functions
    std::string getCurrentDate();
    std::string getCurrentTime();

public:
    SalesManager(std::string);
    ~SalesManager();
    void logPurchase(std::string, double);
};

#endif
