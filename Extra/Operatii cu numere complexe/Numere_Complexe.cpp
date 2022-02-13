#include <iostream>
#include <string>
#include <limits>

//Clasa de Baza
class Complex{
    
    //Date membre:
    private:
        float re;
        float im;

    //Constructor
    public:
        
        //Constructor Gol
        Complex(){}
        
        //Constructor cu Lista de Initializare
        Complex(float re, float im): re(re), im(im){}
        
        
    //Functii
    public:
    
        //Setters si Getters
        void set_re(float re){this->re = re;}
        float get_re(){return this->re;}
        
        void set_im(float im){this->im = im;}
        float get_im(){return this->im;}
        
        
        //Functii de calcul
        
        //Functia +
            //Aceasta o sa fie automat folosita la intalnirea + intre doua obiecte de tip Complex
        Complex operator+(const Complex &c){
            return Complex(re+c.re, im+c.im);
        }
        
        //Functia -
            //Aceasta o sa fie automat folosita la intalnirea - intre doua obiecte de tip Complex
        Complex operator-(const Complex &c){
            return Complex(re-c.re, im-c.im);
        }
        
        //Functia *
            //Aceasta o sa fie automat folosita la intalnirea * intre doua obiecte de tip Complex
        Complex operator*(const Complex &c){
            return Complex(re*c.re - im*c.im, re*c.im + c.re*im);
        }
        
        //Functia /
            //Aceasta o sa fie automat folosita la intalnirea / intre doua obiecte de tip Complex
        Complex operator/(const Complex &c){
            
            //Calculam fiecare parte (cu formula)
            float re_nou;
            float im_nou;
            
            re_nou=(re*c.re + im*c.im)/(c.re*c.re + c.im*c.im);
            im_nou=(c.re*im - re*c.im)/(c.re*c.re + c.im*c.im);
            
            return Complex(re_nou, im_nou);
        }
        
        
        
        //Functia de afisare
        void afisare(){
            std::cout<<re<<" "<<im<<std::endl;
        }
};

//Functia main
int main(){
    
    //Initializam Date
    float re1;
    float im1;
    float re2;
    float im2;
    
    std::cin>>re1;
    std::cin>>im1;
    std::cin>>re2;
    std::cin>>im2;
    
    //Initializam Obiecte
    Complex c1(re1, im1);
    Complex c2(re2, im2);
    
    
    //Optiuni
    int optiune;
    std::cin>>optiune;
    
    //Adunare +
    if(optiune == 1){
        Complex c3=c1+c2;
        c3.afisare();
    }
    
    //Scadere -
    if(optiune == 2){
        Complex c3=c1-c2;
        c3.afisare();
    }
    
    //Inmultire *
    if(optiune == 3){
        Complex c3=c1*c2;
        c3.afisare();
    }
    
    //Impartire /
    if(optiune == 4){
        Complex c3=c1/c2;
        c3.afisare();
    }
    
    
    
    return 0;
}