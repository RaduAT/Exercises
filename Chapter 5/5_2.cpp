#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>


//Clasa de Baza
class Student{
    
    //Date membre
    public:
        std::string nume;
        int numar_note;
        int* note;
        float medie_student;
        
    //Constructor
    public:
        Student(std::string nume, int numar_note, int *note): nume(nume), numar_note(numar_note){
            
            this->note=new int[numar_note+1];
            
            for(int i=0; i<numar_note; i++){
                this->note[i]=note[i];
            }
        }
 
 
    //Functii
    public:
    
        void afisare(){
            std::cout<<nume<<std::endl;
        }
        
        void medie(){
            
            medie_student=0;
            for(int i=0; i<numar_note; i++){
                medie_student=medie_student+note[i];
            }
            medie_student=medie_student/numar_note;
        }
 
};

//Functii pentru STL
bool comparatie(const Student &s1, const Student &s2){
    return (s1.medie_student < s2.medie_student);
    
}

//Functia Main
int main(){
    
    //Initializam Date
    std::string nume;
    int numar_note;
    int numar_studenti;
    int note[100];
    
    
    std::cin>>numar_studenti;
    
    //Facem Obiectele cu STL
    std::vector<Student> studenti;
    
    
    //Facem Studentii
    for(int i=0; i<numar_studenti; i++){
        
        std::cin>>nume;
        std::cin>>numar_note;
        
        for(int j=0; j<numar_note; j++){
            std::cin>>note[j];
        }
        
        //Punem Elementele in obiect cu STL
        studenti.push_back(Student(nume, numar_note, note));
        studenti[i].medie();
        
    }
    

    //Cautam Maximul
    std::sort(studenti.begin(), studenti.end(), comparatie);
    
    //Dupa sortare valoarea dorita o sa fie ULTIMA din cauza <
    studenti[numar_studenti-1].afisare();
   
    return 0;
}