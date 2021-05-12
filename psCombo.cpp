#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    //out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    //fill in

    //out << "State Info: " << PD.getState();
    out << "\nNumber of incidents: " << PD.RcaseNum;
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.R65;
    out << "\n(19 to 64): " << (PD.RcaseNum - PD.R65 - PD.R18);
    out << "\n(under 18): " << PD.R18;
    out << "\nIncidents involving fleeing: " << PD.Rflee;
    out << "\nIncidents involving mental illness: " << PD.Rment_ill;
    out << "\nMale incidents: " << PD.Rmale << " female incidents: " << PD.Rfemale;
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();

    return out;
}