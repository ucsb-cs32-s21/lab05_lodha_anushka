#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include <memory>
#include <cassert>

using namespace std;

class psCombo : public regionData  {
public:
    //write psCombo constructor
    
    //complete these
    int getNumMentalI();
    int getFleeingCount();
    int getCasesOver65();
    int getCasesUnder18();
    raceDemogData getRacialData();
    int getnumMales();
    int getnumFemales();
    int getNumberOfCases();

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

protected:
    //fill in
};

#endif