#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
class Automobil
{
private:
    std::string tip;
    int capacitate;

public:
    Automobil() {}
    Automobil(std::string tip, int capacitate) : tip(tip), capacitate(capacitate) {}
    virtual void afisare() = 0;
    virtual void afisare2() = 0;
    int get_capacitate()
    {
        return this->capacitate;
    }
    std::string get_tip()
    {
        return this->tip;
    }
};
class Masina : public Automobil
{
private:
    std::string nume;
    int viteza_medie;

public:
    Masina() {}
    Masina(std::string tip, std::string nume, int capacitate, int viteza_medie) : nume(nume), viteza_medie(viteza_medie), Automobil(tip, capacitate) {}
    void afisare()
    {
        std::cout << this->nume << "\n"
                  << Automobil::get_capacitate() << "\n"
                  << this->viteza_medie << "\n";
    }
    void afisare2()
    {
        std::cout << this->nume << "\n"
                  << Automobil::get_capacitate() << "\n";
    }
};
class Autocar : public Automobil
{
private:
    std::string nume;
    int capacitate;
    float viteza_medie;

public:
    Autocar() {}
    Autocar(std::string tip, std::string nume, int capacitate, int viteza_medie) : nume(nume), viteza_medie(viteza_medie), Automobil(tip, capacitate) {}
    void afisare()
    {
        std::cout << this->nume << "\n"
                  << Automobil::get_capacitate() << "\n"
                  << this->viteza_medie << "\n";
    }
    void afisare2()
    {
        std::cout << this->nume << "\n"
                  << Automobil::get_capacitate() << "\n";
    }
};
bool cap(Automobil *a1, Automobil *a2)
{

    return a1->get_capacitate() > a2->get_capacitate();
}
class FirmaInchirieri
{
private:
    std::vector<Automobil *> automobile;

public:
    FirmaInchirieri() {}
    std::vector<Automobil *> get_automobile()
    {
        return this->automobile;
    }
    void set_automobile(std::vector<Automobil *> automobileeeee)
    {
        this->automobile = automobileeeee;
    }
    void afisare()
    {
        int i = 0;
        while (this->automobile[i])
        {

            automobile[i]->afisare();
            i++;
        }
    }
    void grup(int n)
    {
        int total = 0, i = 0, masini = 0, autocare = 0;
        std::sort((this->automobile).begin(), (this->automobile).end(), cap);
        while (total < n)
        {
            total = total + (this->automobile[i])->get_capacitate();
            if ((this->automobile[i])->get_tip() == "Masina")
                masini++;
            if ((this->automobile[i])->get_tip() == "Autocar")
                autocare++;
            i++;
            if (total >= n)
            {
                break;
            }
        }
        std::cout << "Masini: " << masini << "\nAutocare:" << autocare << "\n";
        for (int j = 0; j < i; j++)
        {
            (this->automobile[j])->afisare2();
        }
    }
};

int main()
{
    int c, n, capacitate, viteza_medie;
    std::string tip, nume;
    FirmaInchirieri firma;
    std::vector<Automobil *> automobile;
    std::cin >> c >> n;
    for (int i = 0; i < n; i++)
    {

        std::cin >> tip;
        std::cin >> std::ws;
        std::getline(std::cin, nume);
        std::cin >> std::ws;
        std::cin >> capacitate >> viteza_medie;
        if (tip == "Masina")
        {
            automobile.push_back(new Masina(tip, nume, capacitate, viteza_medie));
        }
        if (tip == "Autocar")
        {
            automobile.push_back(new Autocar(tip, nume, capacitate, viteza_medie));
        }
    }
    firma.set_automobile(automobile);
    if (c == 1)
    {
        firma.afisare();
    }
    if (c == 2)
    {
        std::cin >> n;
        firma.grup(n);
    }

    return 0;
}
