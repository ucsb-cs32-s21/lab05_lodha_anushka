#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include "regionData.h"

using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData {
  public:
    //add appropriate function paramaters to constructor once you add data
    psData(string inState, string inName, int inAge, string inGender, string inRace,
    string inCounty, string inMI, string inFlee) : regionData{inCounty, inState}, name(inName), age(inAge), gender(inGender),
    race(inRace), county(inCounty), mental_illness(inMI), flee(inFlee) {}

    // getter functions
    string getPName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    string getRace() { return race; }
    string getCounty() { return county; }
    string getMI() { return mental_illness; }
    string getFlee() { return flee; }

   friend std::ostream& operator<<(std::ostream &out, const psData &PD);
    void toString(ostream& os) const{
     os << *this;
    }

private:
    const string state;
    string name;
    int age;
    string gender;
    string race;
    string county;
    string mental_illness;
    string flee;

};

#endif
