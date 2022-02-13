#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

//Clasa de Baza
class Student{
    
    //Date membre
    private:
        std::string nume;
        int numar_note;
        std::vector<int> note;
        float medie_student;
    
    //Constructor
    public:
        Student(std::string nume, int numar_note, std::vector<int> note): nume(nume), numar_note(numar_note), note(std::move(note)){}

    //Functii
    public:
   
          
        void afisare(){
            std::cout<<nume<<"\n";
        }
        
        void medie(){
            medie_student=0;
            for(std::vector<int>::iterator it=note.begin(); it!=note.end(); ++it){
                medie_student=medie_student+ (*it);
            }
            medie_student=medie_student/numar_note;
        }
        
        float get_medie(){
            return medie_student;
        }
        
        std::string get_nume(){
            return nume;
        }
        
   
};


//Functii pentru STL
bool medie(Student s1, Student s2){
    return(s1.get_medie()<s2.get_medie());
}

bool lexicografic(Student s1, Student s2){
    const char *cstr1=s1.get_nume().c_str();
    const char *cstr2=s2.get_nume().c_str();
    return strcmp(cstr1,cstr2);
}


//Functia Main
int main(){
    
    //Initializam Date
    std::string nume;
    int numar_note;
    int numar_studenti=0;
    std::vector<int> note;
    
    std::vector<Student> studenti;
    
    //Citim pana la STOP    
    for(int i=0; ;i++){
        
        std::cin>>nume;
        
        //Punem conditia
        if(nume !="STOP"){
            
            std::cin>>numar_note;
            
            for(int j=0; j<numar_note; j++){
                int x;
                std::cin>>x;
                note.push_back(x);
            }
            
            //Punem elementele in obiect cu STL
            studenti.push_back(Student(nume, numar_note, note));
            studenti[i].medie();
            numar_studenti++;
            note.clear();
        }
        
        if(nume == "STOP"){
            break;
        }
    }
    
    
    //Optiuni
    int optiune;
    std::cin>>optiune;
    
    if(optiune==1){
        std::sort(studenti.begin(), studenti.end(), lexicografic);
        for(int i=0; i<numar_studenti;i++){
            studenti[i].afisare();
        }
    }
    
    if(optiune==2){
        std::sort(studenti.begin(), studenti.end(), medie);
        for(int i=0; i<numar_studenti;i++){
            studenti[i].afisare();
        }
    }
    
    return 0;
   
}























































// #include <iostream>
// #include <limits>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cstring>

// //Clasa de Baza
// class Student{
    
//     //Date membre
//     public:
//         std::string nume;
//         int numar_note;
//         int *note;
//         float medie_student;
    
//     //Constructor
//     public:
//         Student(std::string nume, int numar_note, int*note): nume(nume), numar_note(numar_note){
//             this->note = new int[numar_note+1];
//             for(int i=0; i<numar_note; i++){
//                 this->note[i]=note[i];
//             }
//         }
  
  
  
//     //Functii
//     public:
    
//         void afisare(){
//             std::cout<<nume<<"\n";
//         }
        
//         void medie(){
//             medie_student=0;
//             for(int i=0; i<numar_note; i++){
//                 medie_student=medie_student+note[i];
//             }
//             medie_student=medie_student/numar_note;
//         }
   
// };


// //Functii pentru STL
// bool medie(const Student &s1, const Student &s2){
//     return(s1.medie_student<s2.medie_student);
// }

// bool lexicografic(const Student &s1, const Student &s2){
//     const char *cstr1=s1.nume.c_str();
//     const char *cstr2=s2.nume.c_str();
//     return strcmp(cstr1,cstr2);
// }


// //Functia Main
// int main(){
    
//     //Initializam Date
//     std::string nume;
//     int numar_note;
//     int numar_studenti=0;
//     int note[100];
    
//     std::vector<Student> studenti;
    
//     //Citim pana la STOP    
//     for(int i=0; ;i++){
        
//         std::cin>>nume;
        
//         //Punem conditia
//         if(nume !="STOP"){
            
//             std::cin>>numar_note;
            
//             for(int j=0; j<numar_note; j++){
//                 std::cin>>note[j];
//             }
            
//             //Punem elementele in obiect cu STL
//             studenti.push_back(Student(nume, numar_note, note));
//             studenti[i].medie();
//             numar_studenti++;
            
//         }
        
//         if(nume == "STOP"){
//             break;
//         }
//     }
    
    
//     //Optiuni
//     int optiune;
//     std::cin>>optiune;
    
//     if(optiune==1){
//         std::sort(studenti.begin(), studenti.end(), lexicografic);
//         for(int i=0; i<numar_studenti;i++){
//             studenti[i].afisare();
//         }
//     }
    
//     if(optiune==2){
//         std::sort(studenti.begin(), studenti.end(), medie);
//         for(int i=0; i<numar_studenti;i++){
//             studenti[i].afisare();
//         }
//     }
    
//     return 0;
   
// }

























