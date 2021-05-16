// Anushka Lodha
// CS32 S21
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "demogData.h"
#include "psData.h"
#include "parse.h"
#include "dataAQ.h"

using namespace std;

int main() {

    dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    /*std::vector<shared_ptr<demogData>> theDemogData = read_csv(
            "county_demographics.csv", DEMOG);

    std::vector<shared_ptr<psData>> thePoliceData = read_csvPolice(
            "police_shootings_cleaned.csv", POLICE);
    */
     std::vector<shared_ptr<regionData>> theDemogData = read_csv(
            "county_demographics.csv", DEMOG);

    std::vector<shared_ptr<regionData>> thePoliceData = read_csv(
            "police_shootings_cleaned.csv", POLICE);

     //debug print out
    /*
    for (const auto &obj : thePoliceData) {
        //std::cout << *obj << std::endl;
        std::cout << *(std::static_pointer_cast<demogData>(obj)) << std::endl;
    }
    */
   
    theAnswers.createComboDemogDataKey((std::vector<shared_ptr<demogData> >&)theDemogData);
    theAnswers.createComboPoliceDataKey((std::vector<shared_ptr<psData> >&)thePoliceData);
    cout << theAnswers << endl;

    //std::cout << *(theAnswers.getComboPoliceData("AsianVictim")) << endl << endl;
    //std::cout << *(theAnswers.getComboDemogData("BelowPovAboveThirtyPer")) << endl;
    
//     std::cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:" << endl;
//     theAnswers.reportTopTenStatesBP();
//     std:: cout << endl;
//     theAnswers.reportTopTenStatesPS();


    /*
    cout << "*** the state that needs the most pre-schools**" << endl;
    string needPK = theAnswers.youngestPop();
    cout << *(theAnswers.getStateData(needPK)) << endl;
    cout << "*** the state that needs the most high schools**" << endl;
    string needHS = theAnswers.teenPop();
    cout << *(theAnswers.getStateData(needHS)) << endl;
    cout << "*** the state that needs the most vaccines**" << endl;
    string needV = theAnswers.wisePop();
    cout << *(theAnswers.getStateData(needV)) << endl;

    cout << "*** the state that needs the most help with education**" << endl;
    string noHS = theAnswers.underServeHS();
    cout << *(theAnswers.getStateData(noHS)) << endl;
    cout << "*** the state with most college grads**" << endl;
    string grads = theAnswers.collegeGrads();
    cout << *(theAnswers.getStateData(grads)) << endl;

    cout << "*** the state with most population below the poverty line**" << endl;
    string belowPov = theAnswers.belowPoverty();
    cout << *(theAnswers.getStateData(belowPov)) << endl;
    */
    return 0;
}

