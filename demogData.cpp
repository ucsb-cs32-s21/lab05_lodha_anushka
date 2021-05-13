#include "demogData.h"
#include <sstream>
#include <iomanip>

/* print county demographic data */
std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    out << std::setprecision(2) << std::fixed;
    //fill in
    out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState();
    out << " total population: " << DD.population << endl;
    //consider re-writing with getters....
    out << "\nPopulation info: \n(\% over 65): " << DD.getpopOver65Per();
    out <<  " Count: " << DD.popOver65;
    out << "\n(\% under 18): " << DD.getpopUnder18Per();
    out <<  " Count: " << DD.popUnder18;
    out << "\n(\% under 5): " << DD.getpopUnder5Per();
    out <<  " Count: " << DD.popUnder5;
    out << "\nEducation info: " << "\n(% Bachelor degree or more): " << DD.getBAupPer() << " Count: " << DD.popUndergrad 
        << "\n(% high school or more): "
        << DD.getHSupPer() << " Count: " << DD.popHighSchool << endl;
    return out;
}
