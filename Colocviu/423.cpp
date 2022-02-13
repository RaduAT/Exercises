#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>


//Clasa de Baza
class Angajat{
    
    //Date membre
    protected:
        std::string tip_angajat;            //Tip_angajat are rol de identificator de obiecte din array pentru fiecare tip de obiect
        std::string nume;
        std::string departament;
        
    //Constructor
    public:
        
        //Constructor Gol
        Angajat(){}
        
        //Constructor cu Lista de Initializare
        Angajat(std::string tip_angajat, std::string nume, std::string departament): tip_angajat(tip_angajat), nume(nume), departament(departament){}
        
        
    //Functii
    public:
    
        //Setters si Getters
            //Declaram virtual functiile din celelalte clase ca sa le foloseasca
            //de baza care actioneaza pe post de container
            
        std::string get_tip_angajat(){
            return this->tip_angajat;
        }
        
        std::string get_nume(){
            return this->nume;
        }
        
        std::string get_departament(){
            return this->departament;
        }
        
        
        //Daca are VIRTUAL o functie inseamna ca este transferabila la toate clasele (parinti si derivate)
        //dar in fiecare face ceva diferit, dar are acelasi nume si acelasi scop
    
    
        //Pentru problemele de genul unde avem mai multe tipuri de obiecte in acelasi array
        //cam toate functiile pleaca din clasa parinte
        //PANA SI SETTERS SI GETTERS din derivate trebuie pus in baza
        
        //Exemplu GETTER
        virtual std::string get_salariu_net(){return 0;} //Nu e folosit in problema
        
        //Functii cerinta 1
        virtual void afisare(){}
        
        //Functii cerinta 2 & 4
        virtual float salariu_brut(){return 0;}
        virtual float salariu_brut_IT(){return 0;}
        
        //Functii cerinta 3 DOAR PENTRU SALARIATI
        virtual float rentabilitate_angajat(){return 0;}
        virtual int concediu(){return 0;}
        
        
};


//Clasa Derivata din Baza
class Salariat:public Angajat{
    
    //Date membre
    private:
        int norma;
        int vechime;
        float salariu_net;
        
        
    //Constructor
    public:
    
        //Constructor Gol
        Salariat(){}
        
        //Constructor cu Lista de Initializare
        Salariat(std::string tip_angajat, std::string nume, std::string departament, int norma, int vechime, float salariu_net): Angajat(tip_angajat, nume, departament), norma(norma), vechime(vechime), salariu_net(salariu_net){}
   
   
   //Functii
   public:
   
        //Setters si Getters
        
        
        //Alte Functii
        void afisare(){
            std::cout<<nume<<" "<<norma<<" "<<vechime<<" "<<salariu_net<<std::endl;
        }
        
        float salariu_brut(){
            float salariu_brut=0;
            salariu_brut = salariu_net*12/0.55;
            return salariu_brut;
        }
        
        
        float salariu_brut_IT(){
            float salariu_brut_IT=0;
            salariu_brut_IT = salariu_net*12/0.65;
            return salariu_brut_IT;
            
        }
        
        //Mai avem nevoie de o functie concediu care sa calculeze numarul de zile in plus la concediu
        //bazat pe vechime
        int concediu(){
            int concediu;
            concediu=vechime/3;
            return concediu;
        }
        
        float rentabilitate_angajat(){
            
            float rentabilitate_angajat=0;
            
            // int concediu=concediu();
            // float salariu_brut_it=salariu_brut_IT()
            
            if(departament == "IT"){
                rentabilitate_angajat=norma*(250-concediu())/salariu_brut_IT();
            }
            
            if(departament != "IT"){
                rentabilitate_angajat=norma*(250-concediu())/salariu_brut();
            }
            
            return rentabilitate_angajat;
        }
        
};


//Clasa Derivata din Baza
class Colaborator:public Angajat{
    
    //Date membre
    private:
        float onorariu;
        float nr_prestari_anuale;
        
        
    //Constructor
    public:
        
        //Constructor Gol
        Colaborator(){}
        
        //Constructor cu Lista de Initializare
        Colaborator(std::string tip_angajat, std::string nume, std::string departament, float onorariu, float nr_prestari_anuale): Angajat(tip_angajat, nume, departament), onorariu(onorariu), nr_prestari_anuale(nr_prestari_anuale){}
    
    
    //Functii
    public:
    
        //Setters si Getters
        
        
        //Alte Functii
        void afisare(){
            std::cout<<nume<<" "<<onorariu<<" "<<nr_prestari_anuale<<std::endl;
        }
        
        float salariu_brut(){
            float salariu_brut=0;
            salariu_brut = onorariu*nr_prestari_anuale/0.55;
            return salariu_brut;
        }
        
        
        float salariu_brut_IT(){
            float salariu_brut_IT=0;
            salariu_brut_IT = onorariu*nr_prestari_anuale/0.65;
            return salariu_brut_IT;
        }

};



//Functia main
int main(){
    
    //Initializam Date
    int n;      //Numar angajati
    std::string tip_angajat;
    std::string nume_angajat;
    std::string nume_departament;
    
    
    std::cin>>n;
    
    
    //Facem Array de Obiecte (Toate pot sa fie de o clasa diferita)
        //Folosim Alocare Dinamica
        
    Angajat **angajat_array = nullptr;
    angajat_array = new Angajat*[n];
    
    int k=0; //Variabila de lucru care pune pe pozitii
    
    //Generam fiecare obiect
    for(int i=0; i<n; i++){
        
        std::cin>>tip_angajat;
        std::cin>>nume_angajat;
        std::cin>>nume_departament;
        
        if(tip_angajat == "salariat"){
            
            int norma_zilnica;
            int vechime_angajat;
            float salariu_lunar;
    
            std::cin>>norma_zilnica;
            std::cin>>vechime_angajat;
            std::cin>>salariu_lunar;
            
            //Punem elementele in obiect
            *(angajat_array+(k++))=new Salariat(tip_angajat, nume_angajat, nume_departament, norma_zilnica, vechime_angajat, salariu_lunar);
        }
        
        if(tip_angajat == "colaborator"){
            
            int onorariu_net;
            int prestari_anuale;
            
            std::cin>>onorariu_net;
            std::cin>>prestari_anuale;
            
            //Punem elementele in obiect
            *(angajat_array+(k++))=new Colaborator(tip_angajat, nume_angajat, nume_departament, onorariu_net, prestari_anuale);
            
            
        }
    
        
    }
    
    
    //Optiuni
    int optiune;
    std::cin>>optiune;
    
    //Optiunea 1
    if(optiune == 1){
        
        std::string departament_1;
        std::cin>>departament_1;
        
        
        for(int i=0; i<n; i++){
            
            if(departament_1 == (*(angajat_array+i))->get_departament())
                (*(angajat_array+i))->afisare();
        }
        
        
    }
    
    //Optiunea 2
    if(optiune == 2){
        
        int salariu_brut_2;
        
        std::string nume_2;
        std::cin>>nume_2;
        
        for(int i=0; i<n; i++){
            
            //Conteaza daca Angajatul este Salariat sau Colaborator pentru ca difera modul de calcul
            //Fiecare tip are functie definita pentru asa ceva 
            
            if(nume_2 == (*(angajat_array+i))->get_nume()){
                
                //Daca Salariatul sau Colaboratorul este in departamentul IT
                if((*(angajat_array+i))->get_departament() == "IT"){
                    salariu_brut_2 = (*(angajat_array+i))->salariu_brut_IT(); 
                    std::cout<<salariu_brut_2<<std::setprecision(2)<<std::endl;
                }
                
                //Daca Salariatul sau Colaboratorul NU este in departamentul IT
                if((*(angajat_array+i))->get_departament() != "IT"){
                    salariu_brut_2 = (*(angajat_array+i))->salariu_brut(); 
                    std::cout<<salariu_brut_2<<std::setprecision(2)<<std::endl;
                }
                
            }
         
        }
        
    }
    
    
    //Optiunea 3
        
    if(optiune == 3){
        
        int pozitie=0;    //Pozitia in Array unde O SA SE AFLE persoana care are maxim
        float rentabilitate_maxima=0;
        float rentabilitate_contor=0;
        
        //Cautam primul salariat si salvam rentabilitatea sa o folosim pe post de CONTOR
        for(int i=0; i<n; i++){
            if((*(angajat_array+i))->get_tip_angajat() == "salariat"){
                rentabilitate_maxima=(*(angajat_array+i))->rentabilitate_angajat();
                break;
            }
        }
        
        //CAUTAM RENTABILITATEA MAXIMA
        for(int i=0; i<n; i++){
            if((*(angajat_array+i))->get_tip_angajat() == "salariat"){
                rentabilitate_contor=(*(angajat_array+i))->rentabilitate_angajat();
                
                if(rentabilitate_maxima < rentabilitate_contor)
                    rentabilitate_maxima = rentabilitate_contor;
                    pozitie=i;
            }
            
        }
        
        std::cout<<(*(angajat_array+pozitie))->get_nume()<<std::endl;

    }
    
    
    //Optiunea 4
    if(optiune==4){
        
        
        int salariu_mediu_4=0;
        
        std::string departament_4;
        std::cin>>departament_4;
        
        
        //Daca voiau si pentru IT (pentru ca difera impozitul) se copia forul si se punea salariu_brut_IT
        
        for(int i=0; i<n; i++){
        
            //Verifica daca departamentul angajatului respectiv == departament_4 si daca DA aduna sumele
            if((*(angajat_array+i))->get_departament() == departament_4){
                salariu_mediu_4 = salariu_mediu_4 + (*(angajat_array+i))->salariu_brut();
                
            }
            
        }

        //La final se imparte la 2 pentru ca asa vor in problema
        std::cout<<salariu_mediu_4/2<<std::setprecision(2)<<std::endl;
    }
    
    
    
    return 0;
    
    
    
}


















