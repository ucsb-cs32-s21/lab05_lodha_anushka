#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    //out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    //fill in
    return out;
}