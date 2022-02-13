#ifndef ECHIPAMENT_ELECTRONIC_H
#define ECHIPAMENT_ELECTRONIC_H

#include <string>

class Echipament_electronic{
protected:
    float pret;
    std::string nume;
    std::string tip;
public:
    Echipament_electronic(float, std::string, std::string);
    float get_pret();
    std::string get_nume();
    std::string get_tip();
    virtual void afisare()=0;
    virtual float raport_calitate_pret()=0;
};

#endif