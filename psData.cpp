#include <sstream>
#include "psData.h"

/* print police data - fill in*/
std::ostream& operator<<(std::ostream &out, const psData &PD) {
    out << "Police Shooting Info: " << PD.state;
    out << "\nPerson name: " << PD.name;
    out << "\nAge: " << PD.age;
    out << "\nGender: " << PD.gender;
    out << "\nRace:" << PD.race;
    out << "\nMental Illness:" << PD.mental_illness;
    out << "\nFleeing:" << PD.flee;
    return out;
}
