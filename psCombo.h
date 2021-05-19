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
    // counts
    int getNumMentalI() { return Rment_ill; }
    int getFleeingCount() { return Rflee; }
    int getCasesOver65() {return R65; }
    int getCasesUnder18() { return R18; }
    raceDemogData getRacialData() const { return raceData; }
    int getnumMales() { return Rmale; }
    int getnumFemales() { return Rfemale; }
    int getNumberOfCases() { return RcaseNum; }

    // percentages
    double getNumMentalIPer() const { return double(Rment_ill * 100.0)/ RcaseNum; }
    double getFleeingPer() const { return double(Rflee * 100.0) / RcaseNum; }
    double getCasesOver65Per() const { return double(R65 * 100.0) / RcaseNum; }
    double getCasesUnder18Per() const { return double(R18 * 100.0) / RcaseNum; }

    // setter functions used for hashmap in DataAQ.cpp
    void addRegion(shared_ptr<psData> element){
      addState(element->getState());
    }

    void setRace(raceDemogData R) {// adds the fields from raceDemogData object passed in to raceData (raceDemogData private variable)
      raceData += R;
    }
    
    void setPSData(shared_ptr<psData> element, int male, int female, int mental_illness, int flee, int age65, int age18) {
      R65 += age65;
      R18 += age18;
      Rment_ill += mental_illness;
      Rflee += flee;
      Rmale += male;
      Rfemale += female;
      RcaseNum += 1;
      //raceData += element->getRace();
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