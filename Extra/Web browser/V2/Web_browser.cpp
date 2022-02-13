#include <iostream>
#include <string>
#include <limits>
#include <list> // lista dublu inlantuita



//Clasa Nod
class Website{
    
    
    //Date membre
    private:
    
        //Componenta Lista
        Website *next;
        Website *prev;
        
        //Continut Pagina
        std::string url;
        std::string titlu;
        std::string continut;
        int pagina_referinta;
    
    
    //Constructor
    public:
        
        //Constructor Gol
        Website(){}
        
        //Constructor cu Lista de Initializare
        Website(std::string url, std::string titlu,std::string continut, int pagina_referinta): url(url), titlu(titlu), continut(continut), pagina_referinta(pagina_referinta), next(nullptr), prev(nullptr){}
    
    
    //Functii
    public:
    
        //Setters si Getters
        void set_next(Website *next){this->next=next;}
        Website* get_next(){return this->next;}
        
        void set_prev(Website *prev){this->prev=prev;}
        Website* get_prev(){return this->prev;}
        
        void set_url(std::string url){this->url=url;}
        std::string get_url(){return this->url;}
        
        void set_titlu(std::string titlu){this->titlu=titlu;}
        std::string get_titlu(){return this->titlu;}
        
        void set_continut(std::string continut){this->continut=continut;}
        std::string get_continut(){return this->continut;}
        
        void set_pagina_referinta(int pagina_referinta){this->pagina_referinta=pagina_referinta;}
        int get_pagina_referinta(){return this->pagina_referinta;}
    
};


//Clasa Lista Dublu Inlantuita
class Browser: public Website{
    
    
    //Date membre
    private:
        Website *head;
        Website *tail;
        
    //Constructor
    public:
        
        //Constructor cu Lista de Initializare
        Browser():head(nullptr), tail(nullptr){
            
            
            
        }
        
    
    //Functii
    public:
        
        //Functie sa adaugam Nod nou la sfarsit
        void link(std::string url, std::string titlu,std::string continut, int pagina_referinta){
            
            Website *newNode = new Website(url, titlu, continut, pagina_referinta);
            
            //Umplem Nodul
            newNode->set_url(url);
            newNode->set_titlu(titlu);
            newNode->set_continut(continut);
            newNode->set_pagina_referinta(pagina_referinta);
            
            
            //Assign to the Next of newNode
            newNode->set_next(head->get_next());
            
            
            
            //Lista Goala
            if(head->get_next() != NULL){
                    (head->get_next())->set_prev(newNode);
            }
            
            head->set_next(newNode);
            newNode->set_prev(NULL);
            
            
            
        }
        
        void back(){}
        
        void forward(){}
        
        //Functia de afisare
        void afisare_pagina(){
            
            while(head){
                std::cout<<head->get_url()<<" ";
                std::cout<<head->get_titlu()<<" ";
                std::cout<<head->get_continut()<<" ";
                head = head->get_next();
            }
            std::cout<<std::endl;
            
        }
        
        
        
    
 
};



int main(){
    
    
    //Initializam Date
    std::string url;
    std::string titlu;
    std::string continut;
    
    int pagina_referinta;       //Numar pentru fiecare pagina
    int pagina_actuala;         //Pagina dorita
    int numar_tastatura;
    std::cin>>numar_tastatura;
    
    //Facem Lista cu Alocare Dinamica
    Browser **browser_array = nullptr;
    browser_array = new Browser*[numar_tastatura];
    
    
    //Optiuni CU BUCLA
    int optiune;
    int k=1;
    
    do{
        std::cin>>optiune;
        
        if(optiune == 1){
            
            for(int i=0; i<numar_tastatura; i++){
                
                pagina_referinta=i;
                 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, url);
                std::getline(std::cin, titlu);
                std::getline(std::cin, continut);
                
                
                (*(browser_array))->link(url, titlu, continut, pagina_referinta);
                
            }
        }
        
        if(optiune == 2){
            
            std::string identificator_url;
            std::cin>>identificator_url;
            
            for(int i=0; i<numar_tastatura; i++){
                
                if(identificator_url == (*(browser_array+i))->get_url()){
                    pagina_actuala=((*(browser_array+i))->get_pagina_referinta());
                }
                
            }
            
        }
        
        if(optiune == 3){
            
            (*(browser_array+pagina_actuala))->afisare_pagina();
        }
        
        if(optiune == 4){
            
        }
        
        if(optiune == 5){
            
        }
        
        if(optiune == 6){
            k=0;
        }
        
        
        
        
    }while(k);
    
    
    //Descturcot Obiecte
    for(int i=0; i<numar_tastatura; i++){
        delete *(browser_array+i);
    }
    
    return 0;
}