#include<iostream>
#include<string>
#include<limits>
class Page{
    
    protected:
    std::string url;
    std::string titlu;
    std::string continut;
    int index;
    
    public:
    Page(){};
    Page(std::string url,std::string titlu ,std::string continut):titlu(titlu),url(url),continut(continut){index=0;};
    
    std::string get_url(){return this->url;}
    std::string get_titlu(){return this->titlu;}
    std::string get_continut(){return this->continut;}
    int get_index(){return index;}
    void incr_index(){index++;};
    void reset_index(){index=0;};
    void set_index(int a){index=a;}
    void afisare()
    {
        std::cout<<this->url<<std::endl;
        std::cout<<this->titlu<<std::endl;
        std::cout<<this->continut<<std::endl;
        // std::cout<<this->index<<std::endl;
    }
};


class Browser{
    friend class Page;
    protected:
     Page** file;
     int i;
     int home;
     int o;
     public:
     Browser(){
         i=0;
         home=0;o=1;
         file=new Page*[10] ;
     }
     void generare(Page *fila)
     {
         file[i]=fila;
         file[i]->set_index(0);
        
         i++;
     }
    void link(std::string url)
    {home++;
       for(int h,j=0;j<i;j++)
    {
            if(file[j]->get_url()==url)
            { 
                if(home==o);
            {file[j]->set_index(home);
              
                }
                if(home<o)
                {
                    for(h=0;h<i;h++)
                    {
                        if(file[h]->get_index()>home-1)
                        {
                            file[h]->reset_index();
                        }
                    }
                    o=home-1;
                             file[j]->set_index(home);      
                
                    
                }
            }
        }
        o++;
    }
    void back(){
        if(home>1){home--;}
        
        
        
    }
    void forward(){
        if(home<o){home++;}
       
    }
    void afisare_home()
    {
        for(int j=0;j<i;j++)
        {
            if(file[j]->get_index()==home)
            {
                file[j]->afisare();
               
            }
        }
    }
    
    
};


int main()
{int b; std::string a,c,d;
int k=1;
Browser chrome;
Page *temp=nullptr;
while(k){std::cin>>b;
//std::cout<<b;
if(b==1){
    std::cin.ignore(256,'\n');
    std::getline(std::cin,a); 
     std::getline(std::cin,c);
      std::getline(std::cin,d);
       temp=new Page(a,c,d);
      chrome.generare(temp);
}
    
 if(b==2){
  std::cin.ignore(1000,'\n');
    std::getline(std::cin,a); 
   
   chrome.link(a);
    
    
 }
 if(b==3)
 {
     chrome.afisare_home();
 }
 if(b==4)
 {
   chrome.back();
 }
 if(b==5)
 {
     chrome.forward();
 }
 if(b==6){
k=0 ;break;}}
}




