#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>
#include <limits>


//Clasa de Baza
class Automobil{

    //Date membre
    protected:
        std::string tip_automobil;
        std::string nume;
        int capacitate;
        int viteza_medie;

    //Constructor
    public:

        //Conctructor Gol
        Automobil(){}


        //Constructoru cu Lista de Initializare
        Automobil(std::string tip_automobil, std::string nume, int capacitate, int viteza_medie): tip_automobil(tip_automobil), nume(nume), capacitate(capacitate), viteza_medie(viteza_medie){}


    //Functii
    public:

        //Setters si Getters
        virtual std::string get_nume(){return this->nume;}

        //Alte Functii
        virtual void afisare(){}

        virtual void grup_2(int x){}
};


//Clasa Derivata din Baza
class Masina: public Automobil{

    //Date membre
    private:


    //Constructor
    public:

        //Conctructor Gol
        Masina(){}


        //Constructoru cu Lista de Initializare
        Masina(std::string tip_automobil, std::string nume, int capacitate, int viteza_medie): Automobil(tip_automobil, nume, capacitate, viteza_medie){}


    //Functii
    public:

        //Setters si Getters


        //Alte Functii
        void afisare(){std::cout<<nume<<"\n"<<capacitate<<"\n"<<viteza_medie<<std::endl;}

        void grup_2(int x){
            int capacitate_necesara = x/capacitate + x%capacitate;
            std::cout<<nume<<std::endl;
            std::cout<<capacitate_necesara<<std::endl;
        }

};


//Clasa Derivata din Baza
class Autocar: public Automobil{

    //Date membre
    private:


    //Constructor
    public:

        //Conctructor Gol
        Autocar(){}


        //Constructoru cu Lista de Initializare
        Autocar(std::string tip_automobil, std::string nume, int capacitate, int viteza_medie): Automobil(tip_automobil, nume, capacitate, viteza_medie){}


    //Functii
    public:

        //Setters si Getters


        //Alte Functii
        void afisare(){std::cout<<nume<<"\n"<<capacitate<<"\n"<<viteza_medie<<std::endl;}

        void grup_2(int x){
            int capacitate_necesara = x/capacitate + x%capacitate;
            std::cout<<nume<<std::endl;
            std::cout<<capacitate_necesara<<std::endl;
        }

};




//Clasa
class FirmaInchirieri{

};



//Functia main
int main()
{

    std::string tip_automobil;
    std::string nume;
    int capacitate;
    int viteza_medie;




    int optiune;
    std::cin>>optiune;

    int numar_automobile;
    std::cin>>numar_automobile;

    //Facem Array de Obiecte (Toate pot sa fie de o clasa diferita)
        //Folosim Alocare Dinamica

    Automobil **automobil_array = nullptr;
    automobil_array = new Automobil*[numar_automobile];

    int k=0; //Variabila de lucru care pune pe pozitii


    //Generam fiecare obiect
    for(int i=0; i<numar_automobile; i++){

        std::cin>>tip_automobil;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin, nume);
        std::cin>>capacitate;
        std::cin>>viteza_medie;

        if(tip_automobil == "Masina"){
            *(automobil_array+(k++))=new Masina(tip_automobil,nume,capacitate,viteza_medie);
        }

        if(tip_automobil == "Autocar"){
            *(automobil_array+(k++))=new Autocar(tip_automobil,nume,capacitate,viteza_medie);
        }


    }

    //Optiune 1
    if(optiune == 1){

         for(int i=0; i<numar_automobile; i++){
            (*(automobil_array+i))->afisare();
        }
    }


    //Optiune 2
    if(optiune == 2){

        int capacitate_necesara;
        std::cin>>capacitate_necesara;

        for(int i=0; i<numar_automobile; i++){
            (*(automobil_array+i))->grup_2(capacitate_necesara);

        }

    }


    //Optiune 3
    if(optiune == 3){

    }


    //Optiune 4
    if(optiune == 4){

    }


    return 0;
}
