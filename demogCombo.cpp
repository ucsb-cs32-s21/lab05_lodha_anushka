#include "demogCombo.h"
#include "demogData.h"
#include "regionData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {

    out.setf(ios::fixed); // set precision to 2 decimal points
    out.setf(ios::showpoint);
    out << "Combo Info: " << ComboD.printState() << endl;
    out << "Number of Counties: " << ComboD.getNumOfReg();
    out << " County Demographics Info: comboData, " << ComboD.getState();
    out << "\nPopulation info: \n(over 65): " << std::setprecision(2) << ComboD.getpopOver65Per() << "%";
    out <<  " and total: " << ComboD.getpopOver65();
    out << "\n(under 18): " << std::setprecision(2) << ComboD.getpopUnder18Per() << "%";
    out <<  " and total: " << ComboD.getpopUnder18();
    out << "\n(under 5): " << std::setprecision(2) << ComboD.getpopUnder5Per() << "%";
    out <<  " and total: " << ComboD.getpopUnder5();
    out << "\nEducation info: " << "\n(Bachelor or more): " << std::setprecision(2) << ComboD.getBAupPer() << "%" << " and total: " << ComboD.getBAup() 
        << "\n(high school or more): "
        << std::setprecision(2) << ComboD.getHSupPer() << "%" << " and total: " << ComboD.getHSup() << endl;
    out << "persons below poverty: " << std::setprecision(2) << ComboD.getpopPovertyPer() << "%" << " and total: " << ComboD.getpopPoverty() << endl;
    out << "Total population: " << ComboD.getPop();
    out << "\nRace stuff: " << ComboD.racePop;

    return out;

    // out.setf(ios::fixed); // set precision to 2 decimal points
    // out.setf(ios::showpoint);
    // out << "State Info: " << ComboD.getState() << endl;
    // out << "Number of Counties: " << ComboD.getNumOfReg();
    // out << "\nPopulation info: \n(over 65): " << std::setprecision(2) << ComboD.getpopOver65Per() << "%";
    // out <<  " and total: " << ComboD.getpopOver65();
    // out << "\n(under 18): " << std::setprecision(2) << ComboD.getpopUnder18Per() << "%";
    // out <<  " and total: " << ComboD.getpopUnder18();
    // out << "\n(under 5): " << std::setprecision(2) << ComboD.getpopUnder5Per() << "%";
    // out <<  " and total: " << ComboD.getpopUnder5();
    // out << "\nEducation info: " << "\n(Bachelor degree or more): " << std::setprecision(2) << ComboD.getBAupPer() << "%" << " and total: " << ComboD.getBAup() 
    //     << "\n(high school or more): "
    //     << std::setprecision(2) << ComboD.getHSupPer() << "%" << " and total: " << ComboD.getHSup() << endl;
    // out << "persons below poverty: " << std::setprecision(2) << ComboD.getpopPovertyPer() << "%" << " and total: " << ComboD.getpopPoverty() << endl;
    // out << "Total population: " << ComboD.getPop();
    // out << "\nRace stuff: " << ComboD.racePop;

    // return out;
}
