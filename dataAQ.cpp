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

  if (theData->getpopPovertyPer() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getpopPovertyPer() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getpopPovertyPer() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }
  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {

  string theKey = "Key";

  if (theData->getRace() == "W") {
    theKey += "WhiteVictim";
  } else if (theData->getRace() == "A") {
    theKey += "AsianVictim";
  } else if (theData->getRace() == "H") {
    theKey += "HispanicVictim";
  } else if (theData->getRace() == "N") {
    theKey += "NativeAmericanVictim";
  } else if (theData->getRace() == "B") {
    theKey += "AfricanAmericanVictim";
  } else if (theData->getRace() == "O") {
    theKey += "OtherRaceVictim";
  } else {
    theKey += "RaceUnspecifiedVictim";
  }
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {

//fill in

raceDemogData race = raceDemogData(); // initialize race fields to 0

  for(auto element : theData) // loop through all counties in theData
  {
    string name = makeKeyExample(element); // create a variable to hold the current region (state) name for the element

    race = element->getRace();
    
    if(allComboDemogData.count(name) > 0) // check dataState hashmap to see if the state already exists in hashmap
    {
      /* if the key is present in the hashmap, just add the new data from element to the current data 
      from hashmap for each population type */
      
      allComboDemogData[name]->set65(allComboDemogData[name]->getpopOver65() + element->getpopOver65());
      allComboDemogData[name]->set18(allComboDemogData[name]->getpopUnder18() + element->getpopUnder18());
      allComboDemogData[name]->set5(allComboDemogData[name]->getpopUnder5() + element->getpopUnder5());
      allComboDemogData[name]->setHS(allComboDemogData[name]->getHSup() + element->getHSup());
      allComboDemogData[name]->setBA(allComboDemogData[name]->getBAup() + element->getBAup());
      allComboDemogData[name]->setPoverty(allComboDemogData[name]->getpopPoverty() + element->getpopPoverty());
      allComboDemogData[name]->setPop(allComboDemogData[name]->getPop() + element->getPop());
      allComboDemogData[name]->setCounties(allComboDemogData[name]->getNumOfReg() + 1);
      allComboDemogData[name]->setRace(race);
      allComboDemogData[name]->addRegion(element);
    }
    else // if state not already in hashmap, create new object with demogCombo constructor
    {
      // if state does not already exist in hashmap: 
      auto Combo = make_shared<demogCombo>(element->getRegionName(), element->getState(), element->getpopOver65(), element->getpopUnder18(),
      element->getpopUnder5(), element->getBAup(), element->getHSup(), element->getpopPoverty(), race, element->getPop(), 1);

      allComboDemogData[name] = Combo;      
    }
    race = raceDemogData(); // reset race fields
  }

}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in
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

    string name = makeKeyExample(element); // variable to hold state name of current individual
    if(allComboPoliceData.count(name) > 0) // check allComboPoliceData hashmap to see if individual's state already exists in hashmap
    {
      // if the key is present in the hashmap, just add the data of current individual to the current data 
      // from allComboPoliceData for each population type
      
      allComboPoliceData[name]->set65(allComboPoliceData[name]->getCasesOver65() + age65);
      allComboPoliceData[name]->set18(allComboPoliceData[name]->getCasesUnder18() + age18);
      allComboPoliceData[name]->setMI(allComboPoliceData[name]->getNumMentalI() +  mental_illness);
      allComboPoliceData[name]->setFC(allComboPoliceData[name]->getFleeingCount() + flee);
      allComboPoliceData[name]->setMale(allComboPoliceData[name]->getnumMales() + male);
      allComboPoliceData[name]->setFemale(allComboPoliceData[name]->getnumFemales() + female);
      allComboPoliceData[name]->setCase(allComboPoliceData[name]->getNumberOfCases() + 1);
      allComboPoliceData[name]->setRace(race);
      race = raceDemogData();
      allComboPoliceData[name]->addRegion(element);
    }
    else // if state not already in hashmap, create new object with psCombo constructor
    {
      // the key is the state name and the "value" is the entire set of population data (psCombo object)
      allComboPoliceData[name] = make_shared<psCombo>(element->getState(), "County", mental_illness, flee, age65, age18, race, male, female, 1);
      //element->addState(element->getState());
    }
  }
}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
//fill in

raceDemogData race = raceDemogData(); // initialize race fields to 0

  for(auto element : theData) // loop through all counties in theData
  {
    string name = element->getState(); // create a variable to hold the current region (state) name for the element

    race = element->getRace();
    
    if(allComboDemogData.count(name) > 0) // check dataState hashmap to see if the state already exists in hashmap
    {
      /* if the key is present in the hashmap, just add the new data from element to the current data 
      from hashmap for each population type */

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
    else // if state not already in hashmap, create new object with demogCombo constructor
    {
      // if state does not already exist in hashmap: 
      auto State = make_shared<demogCombo>(element->getRegionName(), name, element->getpopOver65(), element->getpopUnder18(),
      element->getpopUnder5(), element->getBAup(), element->getHSup(), element->getpopPoverty(), race, element->getPop(), 1);

      allComboDemogData[name] = State;
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
    if(allComboPoliceData.count(name) > 0) // check allComboPoliceData hashmap to see if individual's state already exists in hashmap
    {
      // if the key is present in the hashmap, just add the data of current individual to the current data 
      // from allComboPoliceData for each population type
      
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
    else // if state not already in hashmap, create new object with psCombo constructor
    {
      // the key is the state name and the "value" is the entire set of population data (psCombo object)
      allComboPoliceData[name] = make_shared<psCombo>(name, "County", mental_illness, flee, age65, age18, race, male, female, 1);
    }
  }
}

// compare predicate functions, used in reportTopTenState functions
bool compareShootings(shared_ptr<psCombo> x, shared_ptr<psCombo> y)
{
  return (x->getNumberOfCases() > y->getNumberOfCases());
}

bool comparePoverty(shared_ptr<demogCombo> x, shared_ptr<demogCombo> y)
{
  return (x->getpopPovertyPer() > y->getpopPovertyPer());
}

//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  //fill in
  std::vector< shared_ptr<psCombo> > p_shoot;

  // add data from hashmap to a vector (p_shoot)
  for (auto entry : allComboPoliceData)
  {
    p_shoot.push_back(entry.second);
  }

  sort(p_shoot.begin(), p_shoot.end(), compareShootings);
  cout.setf(ios::fixed); // set precision to 2 decimal points
  cout.setf(ios::showpoint);
  for (int i = 0; i < 3; i++)
  {
    cout << p_shoot[i]->getState() << endl;
    cout << "Total population: " << allComboDemogData[p_shoot[i]->getState()]->getPop() << endl;
    cout << "Police shooting incidents: " << p_shoot[i]->getNumberOfCases() << endl;
    cout << "Percent below poverty: " << std::setprecision(2) << allComboDemogData.at(p_shoot[i]->getState())->getpopPovertyPer() << endl;
  }
  for(int i = 3; i < 10; i++)
  {
    cout << p_shoot[i]->getState() << endl;
  }
}

    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
//fill in
  std::vector< shared_ptr<demogCombo> > poverty;
    // add data from hashmap to a vector (poverty)
    for (auto entry : allComboDemogData)
    {
      poverty.push_back(entry.second);
    }

    sort(poverty.begin(), poverty.end(), comparePoverty);
    cout.setf(ios::fixed); // set precision to 2 decimal points
    cout.setf(ios::showpoint);
    for (int i = 0; i < 3; i++)
    {
      cout << poverty[i]->getState() << endl;
      cout << "Total population: " << poverty[i]->getPop() << endl;
      cout << "Percent below poverty: " << std::setprecision(2) << poverty[i]->getpopPovertyPer() << endl;
      cout << "Police shooting incidents: " << allComboPoliceData[poverty[i]->getState()]->getNumberOfCases() << endl;
    }
    for(int i = 3; i < 10; i++)
    {
      cout << poverty[i]->getState() << endl;
    }

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