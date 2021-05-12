/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

dataAQ::dataAQ() {}

string makeKeyExample(shared_ptr<demogData> theData) {


  string theKey = "Key";

/*
  if (theData->getBelowPoverty() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getBelowPoverty() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getBelowPoverty() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }
*/
  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {

  string theKey = "Key";
  /*
  if (theData->getFleeing() == "Foot") {
    theKey += "FleeingOnFoot";
  } else if (theData->getFleeing() == "Car") {
    theKey += "FleeingByCar";

  } else if (theData->getFleeing() == "Other") {
    theKey += "FleeingOtherMeans";
  } else {
    theKey += "NotFleeing";
  }
  */
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {

//fill in

}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in

}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
//fill in
// function will tally up county counts into region ones (region will currently be state)
// theData is vector of pointers to demogData (counties)
// loop through theData, if statename matches, add county's counts to hashmap[state]
// if state name does not match, add county's

raceDemogData race = raceDemogData(); // initialize race fields to 0

  for(auto element : theData) // loop through all counties in theData
  {
    std::cout << "HELLO SIR" << std::endl;
    string name = element->getRegionName(); // create a variable to hold the current region (state) name for the element

    race = element->getRace();
    
    if(allComboDemogData.count(name) > 0) // check dataState hashmap to see if the state already exists in hashmap
    {
      // IDEA: if the key is present in the hashmap, just add the new data from element to the current data 
      // from DataState for each population type
      allComboDemogData[name]->set65(allComboDemogData[name]->getpopOver65() + element->getpopOver65());
      allComboDemogData[name]->set18(allComboDemogData[name]->getpopUnder18() + element->getpopUnder18());
      allComboDemogData[name]->set5(allComboDemogData[name]->getpopUnder5() + element->getpopUnder5());
      allComboDemogData[name]->setHS(allComboDemogData[name]->getHSup() + element->getHSup());
      allComboDemogData[name]->setBA(allComboDemogData[name]->getBAup() + element->getBAup());
      allComboDemogData[name]->setPoverty(allComboDemogData[name]->getpopPoverty() + element->getpopPoverty());
      allComboDemogData[name]->setPop(allComboDemogData[name]->getPop() + element->getPop());
      allComboDemogData[name]->setCounties(allComboDemogData[name]->getNumOfReg() + 1);
      allComboDemogData[name]->setRace(race);
    }
    else // if state not already in hashmap, create new object with demogState constructor
    {
      /*
      (string inN, string inS, double in65, double in18, 
            double in5, double inUG, double inHS, double inPov, raceDemogData r, int totPop14, int numR)
        */
      // the key is the state name and the "value" is the entire set of population data (demogState object)
      auto State = make_shared<demogCombo>(element->getName(), name, element->getpopOver65(), element->getpopUnder18(),
      element->getpopUnder5(), element->getBAup(), element->getHSup(), element->getpopPoverty(), race, element->getPop(), 1);

      allComboDemogData[name] = State;
    }
    race = raceDemogData(); // reset race fields
  }
  
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
//fill in
}


//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  //fill in
}


    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
//fill in

}

/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  return out;
}