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
    demogData(string inN, string inS, double in65, double in18,
        double in5, int totPop14) : regionData{inN, inS, totPop14},
        /*name(inN), state(inS),*/ popOver65(in65), popUnder18(in18),
        popUnder5(in5), popUndergrad(-1), popHighSchool(-1), popPoverty(-1), racePop(), totalPopulation2014(totPop14) {}

    demogData(string inN, string inS, double in65, double in18, 
        double in5, double inUG, double inHS, double inPov, raceDemogData r, int totPop14) :
        regionData{inN, inS, totPop14}, name(inN), state(inS), popOver65(in65), popUnder18(in18), 
        popUnder5(in5), popUndergrad(inUG), popHighSchool(inHS),
        popPoverty(inPov), racePop(r), totalPopulation2014(totPop14) {} // CHANGED FIRST PARAMETER TO inN PROLLY WRONG

    string getName() const { return name; }
    //string getState() const { return state; }
    double getpopOver65() const { return popOver65; }
    double getpopUnder18() const { return popUnder18; }
    double getpopUnder5() const { return popUnder5; }
    double getBAup() const { return popUndergrad; }
    double getHSup() const { return popHighSchool; }
    double getpopPoverty() const { return popPoverty; }
    raceDemogData getRace() const { return racePop; }
    //int getPop() const { return totalPopulation2014; }

    // convert to percentages
    double getpopOver65Per() const { return ((popOver65/population) * 100.0); }
    double getpopUnder18Per() const { return ((popUnder18/population) * 100.0); }
    double getpopUnder5Per() const { return ((popUnder5/population) * 100.0); }
    double getBAupPer() const { return ((popUndergrad/population) * 100.0); }
    double getHSupPer() const { return ((popHighSchool/population) * 100.0); }
    double getpopPovertyPer() const { return ((popPoverty/population) * 100.0); }

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);
   void toString(ostream& os) const{
     os << *this;
   }

protected: // used to be private, changed so that demogCombo could have access
    string name; // name of county
    string state; // name of state
    double popOver65;
    double popUnder18;
    double popUnder5;
    double popUndergrad;
    double popHighSchool;
    double popPoverty;
    raceDemogData racePop;
    int totalPopulation2014;

};
#endif
