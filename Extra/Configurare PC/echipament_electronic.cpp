#include "echipament_electronic.h"

Echipament_electronic::Echipament_electronic(float pret=0, std::string nume="", std::string tip=""):pret(pret), nume(nume), tip(tip){}

float Echipament_electronic::get_pret(){return pret;}

std::string Echipament_electronic::get_nume(){return nume;}

std::string Echipament_electronic::get_tip(){return tip;}