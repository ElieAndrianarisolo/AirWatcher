#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // std::time_t t = std::time(nullptr);
    // std::tm* now = std::localtime(&t);
 
    // std::cout << "Current Date: " << now->tm_mday << '/' << (now->tm_mon + 1) << '/'
    //         << (now->tm_year + 1900) << std::endl;
    
    Date d;

    cout<<d.getJour()<<endl;
    cout<<d.getMois()<<endl;
    cout<<d.getAnnee()<<endl;

 
    return 0;
}