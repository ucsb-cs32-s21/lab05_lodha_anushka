#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include <cmath>
#include "demogData.h"
#include "raceDemogData.h"
#include "regionData.h"
#include <map>
#include <vector>

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
  void addRegion(shared_ptr<demogData> element){
    addState(element->getState());
  }

  void setData(shared_ptr<demogData> element) {
    popOver65 += element->getpopOver65();
    popUnder18 += element->getpopUnder18();
    popUnder5 += element->getpopUnder5();
    popUndergrad += element->getBAup();
    popHighSchool += element->getHSup();
    popPoverty += element->getpopPoverty();
    population += element->getPop();
    numOfReg += 1;
    racePop += element->getRace();
  }


  void toString(ostream& os) const{
    os << *this;
  }

private:
    int numOfReg;
};
#endif
