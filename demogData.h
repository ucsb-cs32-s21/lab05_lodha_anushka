#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include <iostream>
#include "raceDemogData.h"
#include <cmath>
#include "regionData.h"

using namespace std;

/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/
class demogData : public regionData {
  public:
    demogData(string inN, string inS, int in65, int in18,
        int in5, int totPop14) : regionData{inS, inS, totPop14}, popOver65(in65), popUnder18(in18),
        popUnder5(in5), popUndergrad(-1), popHighSchool(-1), popPoverty(-1), racePop() {}

    demogData(string inN, string inS, int in65, int in18, 
        int in5, int inUG, int inHS, int inPov, raceDemogData r, int totPop14) :
        regionData{inN, inS, totPop14}, popOver65(in65), popUnder18(in18), 
        popUnder5(in5), popUndergrad(inUG), popHighSchool(inHS),
        popPoverty(inPov), racePop(r) {}

    // getters for counts
    int getpopOver65() const { return popOver65; }
    int getpopUnder18() const { return popUnder18; }
    int getpopUnder5() const { return popUnder5; }
    int getBAup() const { return popUndergrad; }
    int getHSup() const { return popHighSchool; }
    int getpopPoverty() const { return popPoverty; }
    raceDemogData getRace() const { return racePop; }

    // convert to percentages
    double getpopOver65Per() const { return (((double(popOver65) * 100.0) / population)); }
    double getpopUnder18Per() const { return (((double(popUnder18) * 100.0) / population)); }
    double getpopUnder5Per() const { return (((double(popUnder5) * 100.0) / population)); }
    double getBAupPer() const { return (((double(popUndergrad) * 100.0) / population)); }
    double getHSupPer() const { return (((double(popHighSchool) * 100.0) / population)); }
    double getpopPovertyPer() const { return (((double(popPoverty) * 100.0) / population)); }

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);
   void toString(ostream& os) const{
     os << *this;
   }

protected: // used to be private, changed so that demogCombo could have access
    int popOver65;
    int popUnder18;
    int popUnder5;
    int popUndergrad;
    int popHighSchool;
    int popPoverty;
    raceDemogData racePop;
};
#endif
