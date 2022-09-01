#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>

//Clasa de Baza
class PlatitorTaxe{
  
    //Date membre
    protected:
        std::string tip_entitate;
        std::string nume;
        int suma_bani;
        int suma_netaxata;
        
    //Constructor
    public:
    
        //Constructor Gol
        PlatitorTaxe(){}
        
        //Constructor cu Lista de Initializare
        PlatitorTaxe(std::string tip_entitate, std::string nume, int suma_bani, int suma_netaxata): tip_entitate(tip_entitate), nume(nume), suma_bani(suma_bani), suma_netaxata(suma_netaxata){}
        
        
    //Functii
    public:
    
        //Setters si Getters
        virtual std::string get_nume(){return this->nume;}
        virtual std::string get_tip(){return this->tip_entitate;}
        
        //Alte Functii
        virtual void afisare(){}
        virtual void taxe_baza_2(int x){}
        virtual float taxe_3(){return 0;}
        virtual float taxe_4(int x){return 0;}
        
        virtual void afisare_nume(){std::cout<<nume<<std::endl;}
    
    
};



//Clasa Derivata din Baza
class PersoanaFizica: public PlatitorTaxe{
    
    //Date membre
    private:
    
    
    //Constructor
    public:
    
        //Constructor Gol
        PersoanaFizica(){}
        
        //Constructor cu Lista de Initializare
        PersoanaFizica(std::string tip_entitate, std::string nume, int suma_bani, int suma_netaxata): PlatitorTaxe(tip_entitate, nume, suma_bani, suma_netaxata){}
        
    
    //Functii
    public:
    
        //Setters si Getters
        
        
        //Alte Functii
        void afisare(){std::cout<<nume<<"\n"<<suma_bani<<std::endl;}
        
        void taxe_baza_2(int x){
            
            int baza=0;
            
            baza=(suma_bani-suma_netaxata)*(x);
            baza=baza/100;
            
            std::cout<<nume<<std::endl;
            std::cout<<baza<<std::endl;
        }
    
    
        float taxe_3(){
            
            float variabila;
            float verificare;
            
            verificare=suma_bani*20/100;
            
            if(suma_netaxata<verificare){
                variabila= 0;            
            }
            
            if(suma_netaxata>verificare){
                variabila= suma_netaxata*100/suma_bani;            
            }
            
            
            return variabila;
        }
        
        
        
        
        float taxe_4(int x){
            
            float suma=0;
            float suma_finala=0;
            float diferenta=0;
            
            
            suma=suma_bani-suma_netaxata;
            
            if(suma > 300000){
                
                diferenta=suma-300000;
                
                suma_finala = (300000*x/100)+ (diferenta*40/100);
                

            }
            
            if(suma<300000){
                suma_finala=(suma*20)/100;;
            }
            
            return suma_finala;
            
        }
        
};



//Clasa Derivata din Baza
class Firma: public PlatitorTaxe{
    
    //Date membre
    private:
    
    
    //Constructor
    public:
    
        //Constructor Gol
        Firma(){}
        
        //Constructor cu Lista de Initializare
        Firma(std::string tip_entitate, std::string nume, int suma_bani, int suma_netaxata): PlatitorTaxe(tip_entitate, nume, suma_bani, suma_netaxata){}
        
    
    //Functii
    public:
    
        //Setters si Getters
        
        
        //Alte Functii
        void afisare(){std::cout<<nume<<"\n"<<suma_bani<<std::endl;}
        
        void taxe_baza_2(int x){
            
            int baza=0;
            
            baza=(suma_bani-suma_netaxata)*(x);
            baza=baza/100;
            
            std::cout<<nume<<std::endl;
            std::cout<<baza<<std::endl;
        }
        
        
        float taxe_3(){
            
            float variabila;
            float verificare;
            
            verificare=(float)suma_bani*20.00/100.00;
            
            if(suma_netaxata<verificare){
                variabila=0;            
            }
            
            if(suma_netaxata>verificare){
                variabila= suma_netaxata*100.00/(float)suma_bani;            
            }
            
            
            return variabila;
        }
        
        
        float taxe_4(int x){
            
            float suma=0;
            float suma_finala=0;
            float diferenta=0;
            
            suma=suma_bani-suma_netaxata;
            
            if(suma > 300000){
                suma_finala=(suma)*(x+19)/100;
                
            }
            
            if(suma<300000){
                suma_finala=(suma*20)/100;
            }
            
            return suma_finala;
            
        }
            
     
};


//Clasa de Baza
class AgentieAdministrareFiscala{
    
};


//Functia main
int main(){
    
    //Initializare Date
    std::string tip_entitate;
    std::string nume;
    int suma_bani;
    int suma_netaxata;
    
    
    int optiune;
    std::cin>>optiune;
    
    int numar_entitati;
    std::cin>>numar_entitati;
    
    
    //Facem Array de Obiecte cu Alocare Dinamica
    PlatitorTaxe **platitori_array = nullptr;
    platitori_array = new PlatitorTaxe*[numar_entitati];
    
    int k=0; //Variabila care salveaza pozitia
    
    //Generam fiecare obiect
    for(int i=0; i<numar_entitati; i++){
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin, tip_entitate);
        std::getline(std::cin, nume);
        std::cin>>suma_bani;
        std::cin>>suma_netaxata;
        
        if(tip_entitate == "Persoana Fizica"){
            *(platitori_array+(k++))=new PersoanaFizica(tip_entitate, nume, suma_bani, suma_netaxata);
        }
        
        if(tip_entitate == "Firma"){
            *(platitori_array+(k++))=new Firma(tip_entitate, nume, suma_bani, suma_netaxata);
        }
            

    }
    
    
    //Optiune 1
    if(optiune == 1){
        for(int i=0; i<numar_entitati; i++)
            (*(platitori_array+i))->afisare();
    }
    
    
    //Optiune 2
    if(optiune == 2){
        
        int procent_persoana;
        int procent_firma;
        
        std::cin>>procent_persoana;
        std::cin>>procent_firma;
        
        
        for(int i=0; i<numar_entitati; i++){
        
            if((*(platitori_array+i))->get_tip() == "Persoana Fizica"){
                (*(platitori_array+i))->taxe_baza_2(procent_persoana);
            }
        
            if((*(platitori_array+i))->get_tip() == "Firma"){
                (*(platitori_array+i))->taxe_baza_2(procent_firma);
            }

        }
           
    }
    
    
    //Optiune 3
    if(optiune == 3){
        
        float turn;    
    
        for(int i=0; i<numar_entitati; i++){
            turn =0;
            if((*(platitori_array+i))->get_tip() == "Persoana Fizica"){
                turn=(*(platitori_array+i))->taxe_3();
                
                if(turn != 0){
                    (*(platitori_array+i))->afisare_nume();
                    std::cout<<std::fixed<<std::setprecision(2)<<turn<<std::endl;
                    
                }
            }
        
            if((*(platitori_array+i))->get_tip() == "Firma"){
                turn=(*(platitori_array+i))->taxe_3();
                
                if(turn != 0){
                    (*(platitori_array+i))->afisare_nume();
                    std::cout<<std::fixed<<std::setprecision(2)<<turn<<std::endl;
                    
                }
            }

        }
        
        if(turn == 0)
            std::cout<<"Nicio potentiala frauda detectata"<<std::endl;
        
    }
    
    //Optiune 4
    if(optiune == 4){
        
        
        float procent_persoana;
        float procent_firma;
        
        float taxe_persoana=0;
        float taxe_persoana_lucru=0;
        
        float taxe_firma=0;
        float taxe_firma_lucru=0;
        
        
        std::cin>>procent_persoana;
        std::cin>>procent_firma;
        
        
        for(int i=0; i<numar_entitati; i++){
            
            taxe_persoana_lucru=0;
            taxe_firma_lucru=0;
            
            
            if((*(platitori_array+i))->get_tip() == "Persoana Fizica"){
                taxe_persoana_lucru= (*(platitori_array+i))->taxe_4(procent_persoana);
                taxe_persoana = taxe_persoana + taxe_persoana_lucru;
                
                //Afisam
                (*(platitori_array+i))->afisare_nume();
                std::cout<<std::fixed<<std::setprecision(2)<<taxe_persoana_lucru<<std::endl;
                
                
                
            }
        
            if((*(platitori_array+i))->get_tip() == "Firma"){
                taxe_firma_lucru = (*(platitori_array+i))->taxe_4(procent_firma);
                taxe_firma = taxe_firma + taxe_firma_lucru;
                
                //Afisam
                (*(platitori_array+i))->afisare_nume();
                std::cout<<std::fixed<<std::setprecision(2)<<taxe_firma_lucru<<std::endl;
            }

        }
        
        std::cout<<std::fixed<<std::setprecision(2)<<taxe_persoana+taxe_firma<<std::endl;

        
    }
    
    
    return 0;
}