#include "barrel.hpp"

Barrel::Barrel(double start_vol, double concentration):volume(start_vol), alcohol_content(start_vol * concentration){}

double Barrel::get_concentration_percent() const{
    if(volume <= 0) return 0;
    return (alcohol_content/volume)*100.0;
}

double Barrel::extract_liquid(double amount){
    double concentration = alcohol_content / volume;
    double alc_to_extract = amount * concentration;

    volume -= amount;
    alcohol_content -= alc_to_extract;
    return alc_to_extract;
}

void Barrel::add_liquid(double total, double alc){
    volume += total;
    alcohol_content += alc;
}

void Barrel::pour_from(Barrel& source, double amount){
    double alcohol_moved = source.extract_liquid(amount);
    this -> add_liquid(amount, alcohol_moved);
}