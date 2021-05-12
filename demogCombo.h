#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include <cmath>
#include "demogData.h"
#include "raceDemogData.h"

/*
  class to represent combined demographic data 
*/
/*
has aggregated state and county counts
*/
class demogCombo : public demogData {
  public:
        //write demogCombo constructor
        // FIX THIS CONSTRUCTOR
        demogCombo(string inN, string inS, double in65, double in18, 
            double in5, double inUG, double inHS, double inPov, raceDemogData r, int totPop14, int numR) : 
            demogData(inN, inS, in65, in18, in5, inUG, inHS, inPov, r, totPop14), numOfReg(numR) {}

//fill in
  friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);
  int getNumOfReg() const { return numOfReg; }

  // setters
  void setCounties(int num) {
    numOfReg = num; // number of counties per the corresponding state
  }
  void set65(int num)
  {
    popOver65 = num;
  }
  void set18(int num)
  {
    popUnder18 = num;
  }
  void set5(int num)
  {
    popUnder5 = num;
  }
  void setHS(int num)
  {
    popHighSchool = num;
  }
  void setBA(int num)
  {
    popUndergrad = num;
  }
  void setPoverty(int num)
  {
    popPoverty = num;
  }
  void setPop(int num)
  {
    totalPopulation2014 = num;
  }
  void setRace(raceDemogData r) // adds the fields from raceDemogData object passed in to racePop (raceDemogData private variable)
  {
    racePop += r;
  }

  // aggregating function

  void toString(ostream& os) const{
    os << *this;
  }

private:
    //fill in
    // aggregated counts private variables
    int numOfReg;
};
#endif
