#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    out << std::setprecision(2) << std::fixed;
    out << "\nNumber of incidents: " << PD.RcaseNum;
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.R65 << " %: " << PD.getCasesOver65Per();
    out << "\n(19 to 64): " << (PD.RcaseNum - PD.R65 - PD.R18) << " %: " << ((PD.RcaseNum - PD.R65 - PD.R18) * 100.0 / PD.RcaseNum);
    out << "\n(under 18): " << PD.R18 << " %: " << PD.getCasesUnder18Per();
    out << "\nIncidents involving fleeing: " << PD.Rflee << " %: " << PD.getFleeingPer();
    out << "\nIncidents involving mental illness: " << PD.Rment_ill << " %: " << PD.getNumMentalIPer();
    out << "\nMale incidents: " << PD.Rmale << " female incidents: " << PD.Rfemale;
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();

    return out;
}