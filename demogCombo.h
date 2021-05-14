#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include <cmath>
#include "demogData.h"
#include "raceDemogData.h"
#include "regionData.h"

/*
  class to represent combined demographic data 
*/
/*
has aggregated state and county counts
*/
class demogCombo : public demogData {
  public:
        demogCombo(string inN, string inS, int in65, int in18, 
            int in5, int inUG, int inHS, int inPov, raceDemogData r, int totPop14, int numR) : 
            demogData{inN, inS, in65, in18, in5, inUG, inHS, inPov, r, totPop14}, numOfReg(numR) {}

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
    population = num;
  }
  void setRace(raceDemogData r) // adds the fields from raceDemogData object passed in to racePop (raceDemogData private variable)
  {
    racePop += r;
  }

  void toString(ostream& os) const{
    os << *this;
  }

private:
    int numOfReg;
};
#endif
