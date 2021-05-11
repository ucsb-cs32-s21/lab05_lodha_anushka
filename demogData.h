#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/
class demogData : public regionData {
  public:
    demogData(string inN, string inS, double in65, double in18,
        double in5, int totPop14) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), totalPopulation2014(totPop14) {}

    string getName() const { return name; }

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    const string name;
    const string state;
    const double popOver65;
    const double popUnder18;
    const double popUnder5;
    const int totalPopulation2014;

};
#endif
