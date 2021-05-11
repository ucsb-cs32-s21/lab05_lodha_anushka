#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"

/*
  class to represent combined demographic data 
*/
class demogCombo : public demogData {
  public:
        //write demogCombo constructor

//fill in

  friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

private:
    //fill in
};
#endif
