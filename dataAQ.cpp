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
    string name = element->getRegionName(); // create a variable to hold the current region (state) name for the element

    race = element->getRace();
    
    if(allComboDemogData.count(name) < 1) // check dataState hashmap to see if the state already exists in hashmap
    {

      auto State = make_shared<demogCombo>(element->getName(), name, element->getpopOver65(), element->getpopUnder18(),
      element->getpopUnder5(), element->getBAup(), element->getHSup(), element->getpopPoverty(), race, element->getPop(), 1);

      allComboDemogData[name] = State;
      
    }
    else // if state not already in hashmap, create new object with demogState constructor
    {
      // the key is the state name and the "value" is the entire set of population data (demogState object)
      //cout << " element" << element->getpopOver65() << endl;
      //cout << " state " << allComboDemogData[name]->getpopOver65() << endl;
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

      //cout << " elementAFTER" << element->getpopOver65() << endl;
      //cout << " stateAFTER " << allComboDemogData[name]->getpopOver65() << endl;
    }
    race = raceDemogData(); // reset race fields
  }
  
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
//fill in
 raceDemogData race = raceDemogData(); // initialize race fields to 0

  for(auto element : theData) // loop through all elements in theData
  {
    int male(0);
    int female(0);
    int mental_illness(0);
    int flee(0);
    int age65(0);
    int age18(0);

    // increment the counts of current individual
    if (element->getGender() == "M")
      male++;
    else if (element->getGender() == "F")
      female++;

    if(static_cast<int>(element->getAge()) > 65 || static_cast<int>(element->getAge()) == 65)
      age65++;
    else if(static_cast<int>(element->getAge()) < 18 || static_cast<int>(element->getAge()) == 18)
      age18++;

    if(element->getMI() == "True")
      mental_illness++;

    if(element->getFlee() == "Foot" || element->getFlee() == "Car" || element->getFlee() == "Other")
      flee++;

    // increment race counts based on current individual
    if (element->getRace() == "N")
    {
      race.addFirstNationCount(1);
      race.addCommunityCount(1);
    }
    else if (element->getRace() == "A")
    {
      race.addAsianCount(1);
      race.addCommunityCount(1);
    }
    else if (element->getRace() == "B")
    {
      race.addBlackCount(1);
      race.addCommunityCount(1);
    }
    else if (element->getRace() == "H")
    {
      race.addLatinxCount(1);
      race.addCommunityCount(1);
    }
    else if (element->getRace() == "W")
    {
      race.addWhiteCount(1);
      race.addWhiteNHCount(1);
      race.addCommunityCount(1);
    }
    else 
    {
      race.addOtherCount(1);
      race.addCommunityCount(1);
    }

    string name = element->getState(); // variable to hold state name of current individual
    if(allComboPoliceData.count(name) > 0) // check poDataState hashmap to see if individual's state already exists in hashmap
    {
      // IDEA: if the key is present in the hashmap, just add the data of current individual to the current data 
      // from poDataState for each population type
      
      allComboPoliceData[name]->set65(allComboPoliceData[name]->getCasesOver65() + age65);
      allComboPoliceData[name]->set18(allComboPoliceData[name]->getCasesUnder18() + age18);
      allComboPoliceData[name]->setMI(allComboPoliceData[name]->getNumMentalI() +  mental_illness);
      allComboPoliceData[name]->setFC(allComboPoliceData[name]->getFleeingCount() + flee);
      allComboPoliceData[name]->setMale(allComboPoliceData[name]->getnumMales() + male);
      allComboPoliceData[name]->setFemale(allComboPoliceData[name]->getnumFemales() + female);
      allComboPoliceData[name]->setCase(allComboPoliceData[name]->getNumberOfCases() + 1);
      allComboPoliceData[name]->setRace(race);
      race = raceDemogData();

    }
    else // if state not already in hashmap, create new object with pState constructor
    {
      // the key is the state name and the "value" is the entire set of population data (pState object)
      allComboPoliceData[name] = make_shared<psCombo>(name, "County", mental_illness, flee, age65, age18, race, male, female, 1);
    }
  }
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