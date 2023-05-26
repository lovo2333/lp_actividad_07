#include <iostream>
#include <string>

using namespace std;

class Vehicle{
protected:
    string Brand;
    string Model;
    int YearOfManufacturing;
    double Price;
    
public:
    Vehicle(string B, string M, int YM, double P) : Brand(B), Model(M), YearOfManufacturing(YM), Price(P){}
    
    virtual ~Vehicle(){}
    
    virtual void ShowInformation(){
        cout << "Marca: " << Brand << endl;
        cout << "Modelo: " << Model << endl;
        cout << "Año de Fabricación: " << YearOfManufacturing << endl;
        cout << "Precio: " << Price << " $" << endl;
    }
};

class Car : public Vehicle{
private:
    int DoorsNumber;
    string FuelType;
    
public:
    Car(string B, string M, int YM, double P, int DN, string FT) : Vehicle(B, M, YM, P), DoorsNumber(DN), FuelType(FT){}
    
    ~Car(){}
    
    void ShowInformation(){
        Vehicle::ShowInformation();
        cout << "Número de Puertas: " << DoorsNumber << endl;
        cout << "Tipo de Combustible: " << FuelType << endl;
    }
};

class Motorcycle : public Vehicle{
private:
    int EngineDisplacement;
    
public:
    Motorcycle(string B, string M, int YM, double P, int ED) : Vehicle(B, M, YM, P), EngineDisplacement(ED){}
    
    ~Motorcycle(){}
    
    void ShowInformation(){
        Vehicle::ShowInformation();
        cout << "Cilindrada: " << EngineDisplacement << " cc" << endl;
    }
};

int main(){
    Car Automovil("Toyota", "Corolla", 2022, 25000, 4, "Gasolina");
    Motorcycle Motocicleta("Honda", "GRS3234TA", 2021, 12000, 600);
    
    Automovil.ShowInformation();
    cout << endl;
    Motocicleta.ShowInformation();
    
    return 0;
}
