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
    psCombo(string inS, string inCounty, int NMI, int FC, int C65, int C18, raceDemogData RD, int inMale, int inFemale,
        int numcase) : regionData{inCounty, inS}, state(inS), Rment_ill(NMI), Rflee(FC), R65(C65), R18(C18), raceData(RD), Rmale(inMale),
        Rfemale(inFemale), RcaseNum(numcase) {}

    // getter functions
    int getNumMentalI() { return Rment_ill; }
    int getFleeingCount() { return Rflee; }
    int getCasesOver65() {return R65; }
    int getCasesUnder18() { return R18; }
    raceDemogData getRacialData() const { return raceData; }
    int getnumMales() { return Rmale; }
    int getnumFemales() { return Rfemale; }
    int getNumberOfCases() { return RcaseNum; }

    // setter functions used for hashmap in DataAQ.cpp
    void setMI(int num)
    {
      Rment_ill = num; // number of counties per the corresponding state
    }
    void set65(int num)
    {
      R65 = num;
    }
    void set18(int num)
    {
      R18 = num;
    }
    void setFC(int num)
    {
      Rflee = num;
    }
    void setMale(int num)
    {
      Rmale = num;
    }
    void setFemale(int num)
    {
      Rfemale = num;
    }
    void setCase(int num)
    {
        RcaseNum = num;
    }
    void setRace(raceDemogData R) // adds the fields from raceDemogData object passed in to raceData (raceDemogData private variable)
    {
      raceData += R;
    }

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);
    void toString(ostream& os) const{
      os << *this;
    }

protected:
    const string state;
    int Rment_ill;
    int Rflee;
    int R65;
    int R18;
    int Rmale;
    int Rfemale;
    int RcaseNum;
    raceDemogData raceData;
};

#endif