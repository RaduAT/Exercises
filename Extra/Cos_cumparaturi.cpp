#include <iostream>
#include <limits>
#include <string>
#include <math.h>
#include <iomanip>



class Cos{

        private:
    std::string nume;
    std::string categorie;
    float pret;
    float greutate;
    int buc;
        public:
    Cos(){}

    Cos(std::string nume, std::string categorie, float pret, float greutate, int buc):nume(nume), categorie(categorie),
    pret(pret), greutate(greutate), buc(buc){}

    //Getter

    std::string get_nume(){
        return this->nume;
    }
    

    std::string get_categorie(){
        return this->categorie;
    }

    float get_pret(){
        return this->pret;
    }

    float get_greutate(){
        return this->greutate;
    }

    void set_buc(int buc){this->buc=buc;}

    void set_nume(std::string nume){this->nume=nume;}



    void afisare(){
        std::cout<<nume<<", "<<categorie<<", "<<pret<<" lei, "<<greutate<<" kg"<<std::endl;
    }

    void afisare2(){
        std::cout<<nume<<", "<<categorie<<", "<<pret<<" lei, "<<greutate<<" kg, "<<buc<<" buc"<<std::endl;
    }

};


int main(){
    int n; //nr de produse
    std::string nume;
    std::string categorie;                             
    float pret;
    float greutate;
    
  
    std::cin>>n;
    Cos ** cos_array=nullptr;
    cos_array= new Cos *[n];
    int k=0;
    for(int i=0;i<n;i++){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin,nume);
        std::getline(std::cin,categorie);
        std::cin>>pret;
        std::cin>>greutate;

        *(cos_array+(k++))= new Cos(nume, categorie, pret, greutate, 0);
        }

        int optiune;
        std::cin>>optiune;

        if(optiune==1){
            for(int i=0;i<n;i++){
                (*(cos_array+i))->afisare();
            }
        }

        if(optiune==2){
            int ok=0;
            std::string categorie_cautata;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::getline(std::cin,categorie_cautata);
            for(int i=0;i<n;i++){
                if((*(cos_array+i))->get_categorie()==categorie_cautata){
                    (*(cos_array+i))->afisare();
                    ok=1;
                }

            }
            if(ok==0){
                std::cout<<"N/A"<<std::endl;
            }

        }

        if(optiune==3){

            for(int i=0;i<n;i++){
                int buc=0;
                for(int j=i;j<n;j++){
                if(((cos_array+i))->get_nume()==((cos_array+j))->get_nume())
                {buc++;}
                }
                (*(cos_array+i))->set_buc(buc);
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(((cos_array+i))->get_nume()==((cos_array+j))->get_nume())
                        (*(cos_array+j))->set_nume("Nu");
                }
            }
            for(int i=0;i<n;i++){
                if((*(cos_array+i))->get_nume()!="Nu")
                    (*(cos_array+i))->afisare2();
            }



        }

        if(optiune==4){
            float greutate_totala=0;
            for(int i=0;i<n;i++){
                greutate_totala=greutate_totala+(*(cos_array+i))->get_greutate();
            }
            std::cout<<greutate_totala<<std::setprecision(2)<<std::endl;
        }

        if(optiune==5){
            float greutate_maxima;
            float pret_suplimentar;
            std::cin>>greutate_maxima;
            std::cin>>pret_suplimentar;

            float greutate_ramasa=0;
            int calcul_intermediar;
            float greutate_totala=0;
            for(int i=0;i<n;i++){
                greutate_totala=greutate_totala+(*(cos_array+i))->get_greutate();
            }
            float pret_total=0;
            for(int i=0;i<n;i++){
                pret_total=pret_total+(*(cos_array+i))->get_pret();
            }

            greutate_ramasa=greutate_totala-greutate_maxima;

            calcul_intermediar=(greutate_ramasa*10);

            calcul_intermediar=calcul_intermediar%10;

            greutate_ramasa=(greutate_ramasa*10)+(10-calcul_intermediar);

            greutate_ramasa=greutate_ramasa/10;

            pret_total=pret_total+greutate_ramasa*pret_suplimentar;

            std::cout<<pret_total<<std::setprecision(2)<<std::endl;



        }


    return 0;
}4
