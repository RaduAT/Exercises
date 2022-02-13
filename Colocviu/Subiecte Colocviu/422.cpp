#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>


//Clasa de Baza
class Card_calatorie{
    
    //Date membre
    protected:
        std::string tip_card;       //identificator card
        int id;

        
    //Constructor
    public:
        
        //Constructor Gol
        Card_calatorie(){}
    
    
        //Constructor cu Lista de Initializare
        Card_calatorie(std::string tip_card, int id): tip_card(tip_card), id(id){}
        
 
    //Functii
    public:
    
        //Setters si Getters
        std::string get_tip_card(){return this->tip_card;}
        int get_id(){return this->id;}
        
        virtual int get_moment(){return 0;}
        virtual int get_sc(){return 0;}     //GETTER pentru sold sau numar calatorii
       
    
        //Alte Functii
        virtual void afisare(){}
    
        virtual void incarcare_2(int x){}
        virtual void validare_3(int x){}
        virtual void incarcare_4(int x){}
        virtual void descarcare_4(int x){}
        
        
    
};


//Clasa Derivata din Baza
class Card_autobuz:public Card_calatorie{
    
    //Date membre
    private:
        int sold;
        int moment_ultima_validare;
        
    //Constructor
    public:
        
        //Constructor Gol
        Card_autobuz(){}
        
        //Constructor cu Lista de Initializare
        Card_autobuz(std::string tip_card, int id, int sold, int moment_ultima_validare): Card_calatorie(tip_card, id), sold(sold), moment_ultima_validare(moment_ultima_validare){}
        
        
    //Functii
    public:
    
        //Setters si Getters
        int get_moment(){return this->moment_ultima_validare;}
        int get_sc(){return this->sold;}
    
    
        //Alte Functii
        void afisare(){std::cout<<id<<" "<<tip_card<<" "<<sold<<" "<<moment_ultima_validare<<std::endl;}
        
        void incarcare_2(int x){sold=sold+x;}
        
        void validare_3(int x){
            
            if(sold >= 3){
                if(x-moment_ultima_validare > 90){
                    sold=sold-3;
                    moment_ultima_validare=x;
                }
            }
            
            else
                std::cout<<"Sold insuficient"<<std::endl;
            
        }
        
        
        
        void incarcare_4(int x){sold=sold+x;}
        void descarcare_4(int x){sold=sold-x;}
        
        
        
        
        
};


//Clasa Derivata din Baza
class Card_metrou:public Card_calatorie{
    
    //Date membre
    private:
        int numar_calatorii;
        int moment_ultima_validare;
        
        
    //Constructor
    public:
        
        //Constructor Gol
        Card_metrou(){}
        
        //Constructor cu Lista de Initializare
        Card_metrou(std::string tip_card, int id, int numar_calatorii, int moment_ultima_validare): Card_calatorie(tip_card, id), numar_calatorii(numar_calatorii), moment_ultima_validare(moment_ultima_validare){}
        
        
    //Functii
    public:
    
        //Setters si Getters
        int get_moment(){return this->moment_ultima_validare;}
        int get_sc(){return this->numar_calatorii;}
    
        //Alte Functii
        void afisare(){std::cout<<id<<" "<<tip_card<<" "<<numar_calatorii<<" "<<moment_ultima_validare<<std::endl;}
        
        void incarcare_2(int x){numar_calatorii=numar_calatorii+x;}

        void validare_3(int x){
            
            if(numar_calatorii >= 1){
                if(x-moment_ultima_validare > 90){
                    numar_calatorii=numar_calatorii-1;
                    moment_ultima_validare=x;
                }
            }
            
            else
                std::cout<<"Numar calatorii insuficient"<<std::endl;
            
        }
        
        
        void incarcare_4(int x){numar_calatorii=numar_calatorii+x;}
        void descarcare_4(int x){numar_calatorii=numar_calatorii-x;}
    
};


//Functia main
int main(){
    
    //Initializam Date
    int numar_carduri;
    std::string tip_card;
    int id;
    int sold;
    int calatorii;
    
    std::cin>>numar_carduri;
    
    
    //Facem Array de Obiecte (Toate pot sa fie de o clasa diferita)
        //Folosim Alocare Dinamica
        
        
    Card_calatorie **card_array = nullptr;
    card_array = new Card_calatorie*[numar_carduri];
    
    int k=0;    //Variabila de lucru care pune pe pozitii
    
    //Generam fiecare obiect
    for(int i=0; i<numar_carduri; i++){
        
        std::cin>>tip_card;
        
        //Autobuz
        if(tip_card=="a"){
            std::cin>>id;
            std::cin>>sold;
            
            //Punem elementele in obiect
            *(card_array+(k++))= new Card_autobuz(tip_card, id, sold, 0);
        }
        
        
        //Metrou
        if(tip_card=="m"){
            
            std::cin>>id;
            std::cin>>calatorii;
            
            *(card_array+(k++))= new Card_metrou(tip_card, id, calatorii, 0);
            
        }
        
        
        
    }
    
    //Optiuni
        
    int optiune;
    int turn=1;
    
    
    do{
        std::cin>>optiune;
        
        //Optiunea 1
        if(optiune==1){
            for(int i=0; i<numar_carduri; i++){
                (*(card_array+i))->afisare();
            }
        }
        
        
        //Optiunea 2
        if(optiune==2){
            
            int id_2;
            int increment_2;
            
            std::cin>>id_2;
            std::cin>>increment_2;
            
            //Adaugam incarcarea
            for(int i=0; i<numar_carduri; i++){
                if((*(card_array+i))->get_id() == id_2){
                    (*(card_array+i))->incarcare_2(increment_2);
                }
            }
        }
        
        
        //Optiunea 3
        if(optiune==3){
            
            int id_3;
            int moment_3;
            
            std::cin>>id_3;
            std::cin>>moment_3;
            
            //Adaugam incarcarea
            for(int i=0; i<numar_carduri; i++){
                if((*(card_array+i))->get_id() == id_3){
                    (*(card_array+i))->validare_3(moment_3);
                }
            }
            
        }
        
        
        //Optiunea 4
        if(optiune==4){
            
            int id_4;
            int id_5;
            int transfer;
            
            int c1;         //Contor de lucru
            int c2;         //Contor de lucru
            
            std::cin>>id_4;
            std::cin>>id_5;
            std::cin>>transfer;
            
            
            //Salvam POZITIA cardurilor de care avem nevoie
            
            //Card 1
            for(int i=0; i<numar_carduri; i++){
                if((*(card_array+i))->get_id() == id_4){
                    c1=i;
                }
            }
            
            //Card 2
            for(int i=0; i<numar_carduri; i++){
                if((*(card_array+i))->get_id() == id_5){
                    c2=i;
                }
            }
            
            
            //Verificam daca sunt de acelasi tip
            if((*(card_array+c1))->get_tip_card() == (*(card_array+c2))->get_tip_card()){
                
                if((*(card_array+c1))->get_sc() >= transfer){
                    
                    (*(card_array+c1))->descarcare_4(transfer);
                    (*(card_array+c2))->incarcare_4(transfer);
           
                }
                
                else{
                    std::cout<<"Transfer nereusit"<<std::endl;
                    
                }
   
            }
            
            
            //Daca sunt de tip diferit
            if((*(card_array+c1))->get_tip_card() != (*(card_array+c2))->get_tip_card()){
                std::cout<<"Transfer nereusit"<<std::endl;
               
            }
  
        }
        
        //Optiunea 5
        if(optiune==5){
            turn=0;
        }
        
    }while(turn);    
       
    
    
    return 0;
}







