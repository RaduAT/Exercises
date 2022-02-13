#include "echipament_electronic.h"
#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

class Placa_de_baza : protected Echipament_electronic
{
  
protected:

    std::string socket;

public:

    Placa_de_baza(float pret = 0.0f, std::string nume = "", std::string tip = "", std::string socket = "")
    :Echipament_electronic(pret, nume, tip), socket(socket){}
  
    void afisare(){std::cout<<tip<<", "<<nume<<", "<<socket<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return -1.0f;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}
    std::string get_socket(){return socket;}
};

class CPU : protected Echipament_electronic
{
  
protected:

    std::string socket;
    int frecventa; // Ghz

public:

    CPU(float pret = 0.0f, std::string nume = "", std::string tip = "", std::string socket = "", int frecventa = 0)
    :Echipament_electronic(pret, nume, tip), socket(socket), frecventa(frecventa){}
  
    void afisare(){std::cout<<tip<<", "<<nume<<", "<<socket<<", "<<frecventa<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return (float)frecventa/pret;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}
    std::string get_socket(){return socket;}
    
};

class GPU : protected Echipament_electronic
{
    
protected:

    int memorie; // in GB

public:
    
    GPU(float pret = 0.0f, std::string nume = "", std::string tip = "", int memorie = 0)
    :Echipament_electronic(pret, nume, tip), memorie(memorie){}
    
    void afisare(){std::cout<<tip<<", "<<nume<<", "<<memorie<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return (float)memorie/pret;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}
};

class Stocare : protected Echipament_electronic
{
    
protected:

    float memorie;

public:

    Stocare(float pret = 0.0f, std::string nume = "", std::string tip = "", float memorie = 0.0f)
    :Echipament_electronic(pret, nume, tip), memorie(memorie){}

    void afisare(){std::cout<<tip<<", "<<nume<<", "<<memorie<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return memorie/pret;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}
};

class Manager
{
    
    Placa_de_baza** V1;
    int index_v1;
    
    CPU** V2;
    int index_v2;
    
    GPU** V3;
    int index_v3;
    
    Stocare** V4;
    int index_v4;
    
public:

    Manager()
    {
        index_v1 = 0;
        index_v2 = 0;
        index_v3 = 0;
        index_v4 = 0;
        
        V1 = new Placa_de_baza*[100];
        V2 = new CPU*[100];
        V3 = new GPU*[100];
        V4 = new Stocare*[100];
    }
    
    void citire_date()
    {
        float pret;
        std::string nume;
        std::string tip;
        
        std::string socket;
        int frecventa;
        int memorie;
        float memorie_stocare;
        
        std::cin>>pret>>nume>>tip;
        if(tip == "placa_baza")
        {
            std::cin>>socket;
            V1[index_v1++] = new Placa_de_baza(pret, nume, tip, socket);
        }
        else if(tip == "cpu")
        {
            std::cin>>socket>>frecventa;
            V2[index_v2++] = new CPU(pret, nume, tip, socket, frecventa);
        }
        else if(tip == "gpu")
        {
            std::cin>>memorie;
            V3[index_v3++] = new GPU(pret, nume, tip, memorie);
        }
        else if(tip == "stocare")
        {
            std::cin>>memorie_stocare;
            V4[index_v4++] = new Stocare(pret, nume, tip, memorie_stocare);
        }
    }
    
    void afisare_componente()
    {
        for(int i=0; i<index_v1; i++) V1[i]->afisare();
        
        for(int i=0; i<index_v2; i++) V2[i]->afisare();
        
        for(int i=0; i<index_v3; i++) V3[i]->afisare();
        
        for(int i=0; i<index_v4; i++) V4[i]->afisare();
    }
    
    void configuratie_PC(std::string cpu, std::string gpu, std::string stocare)
    {
        float suma = 0.0f;
        int index_cpu=0, index_gpu=0, index_stocare=0;
        
        for(int i=0; i<index_v2; i++)
            if(V2[i]->get_nume() == cpu) index_cpu = i;
        
        for(int i=0; i<index_v3; i++)
            if(V3[i]->get_nume() == gpu) index_gpu = i;
        
        for(int i=0; i<index_v4; i++)
            if(V4[i]->get_nume() == stocare) index_stocare = i;
        
        if(V2[index_cpu]->get_socket() == V1[0]->get_socket())
        {
            suma += V1[0]->get_pret() + V2[index_cpu]->get_pret() + V3[index_gpu]->get_pret() + V4[index_stocare]->get_pret();
            V1[0]->afisare();
            V2[index_cpu]->afisare();
            V3[index_gpu]->afisare();
            V4[index_stocare]->afisare();
            std::cout<<suma<<'\n';
        }
    }
    
    void sort_raport_calitate_pret()
    {
        
        Placa_de_baza* tmp1;
        for(int i=0; i<index_v1-1; i++)
        {
            for(int j = i+1; j<index_v1; j++)
            {
                if(V1[i]->raport_calitate_pret() > V1[j]->raport_calitate_pret())
                {
                    tmp1 = V1[i];
                    V1[i] = V1[j];
                    V1[j] = tmp1;
                }
            }
        }
        
        CPU* tmp2;
        for(int i=0; i<index_v2-1; i++)
        {
            for(int j = i+1; j<index_v2; j++)
            {
                if(V2[i]->raport_calitate_pret() > V2[j]->raport_calitate_pret())
                {
                    tmp2 = V2[i];
                    V2[i] = V2[j];
                    V2[j] = tmp2;
                }
            }
        }
        
        GPU* tmp3;
        for(int i=0; i<index_v3-1; i++)
        {
            for(int j = i+1; j<index_v3; j++)
            {
                if(V3[i]->raport_calitate_pret() > V3[j]->raport_calitate_pret())
                {
                    tmp3 = V3[i];
                    V3[i] = V3[j];
                    V3[j] = tmp3;
                }
            }
        }
        
        Stocare* tmp4;
        for(int i=0; i<index_v4-1; i++)
        {
            for(int j = i+1; j<index_v4; j++)
            {
                if(V4[i]->raport_calitate_pret() > V4[j]->raport_calitate_pret())
                {
                    tmp4 = V4[i];
                    V4[i] = V4[j];
                    V4[j] = tmp4;
                }
            }
        }
    }
    
    void configuratie_optima_PC(int buget)
    {
        int index_motherboard=0;
        int index_cpu=0;
        int index_gpu=0;
        int index_stocare=0;
        
        int min = INT_MAX;
        
        for(int i=0; i<index_v2; i++)
        {
            if(V2[i]->get_pret()<min)
            {
                min = V2[i]->get_pret();
                index_cpu = i;
            }
        }
        
        min = INT_MAX;
        
        for(int i=0; i<index_v3; i++)
        {
            if(V3[i]->get_pret()<min)
            {
                min = V3[i]->get_pret();
                index_gpu = i;
            }
        }
        
        min = INT_MAX;
        
        for(int i=0; i<index_v4; i++)
        {
            if(V4[i]->get_pret()<min)
            {
                min = V4[i]->get_pret();
                index_stocare = i;
            }
        }
        
        int sum = V1[index_motherboard]->get_pret() + V2[index_cpu]->get_pret() + V3[index_gpu]->get_pret() + V4[index_stocare]->get_pret();
        
        int ok;
        while(sum <= buget)
        {
            ok = 0;
            
            if(index_gpu < index_v3-1)
            {
                if(sum + (V3[index_gpu+1]->get_pret() - V3[index_gpu]->get_pret()) > buget) ok++;
                else 
                {
                    sum += V3[index_gpu+1]->get_pret() - V3[index_gpu]->get_pret();
                    index_gpu++;
                }
            }
            else ok++;
            
            if(index_cpu < index_v2-1)
            {
                if(sum + (V2[index_cpu+1]->get_pret() - V2[index_cpu]->get_pret()) > buget) ok++;
                else 
                {
                    sum += V2[index_cpu+1]->get_pret() - V2[index_cpu]->get_pret();
                    index_cpu++;
                }
            }
            else ok++;
            
            if(index_stocare < index_v4-1)
            {
                if(sum + (V4[index_stocare+1]->get_pret() - V4[index_stocare]->get_pret()) > buget) ok++;
                else 
                {
                    sum += V4[index_stocare+1]->get_pret() - V4[index_stocare]->get_pret();
                    index_stocare++;
                }
            }
            else ok++;
            
            if(ok == 3) break;
        }
        
        V1[index_motherboard]->afisare();
        V2[index_cpu]->afisare();
        V3[index_gpu]->afisare();
        V4[index_stocare]->afisare();
    }
};

int main(){

    Manager vlad;
    
    int comanda;
    
    while(true)
    {
        std::cin>>comanda;    
        if(comanda  == 1) vlad.citire_date();
        
        if(comanda == 2) vlad.afisare_componente();
        
        if(comanda == 3)
        {
            std::string cpu, gpu, stocare;
            std::cin>>cpu>>gpu>>stocare;
            
            vlad.configuratie_PC(cpu, gpu, stocare);
        }
        
        if(comanda == 4)
        {
            vlad.sort_raport_calitate_pret();
            //vlad.afisare_componente();
            
            int buget;
            std::cin>>buget;
            
            vlad.configuratie_optima_PC(buget);
        }
        
        if(comanda == 5) break;
    }
    
    return 0;
}