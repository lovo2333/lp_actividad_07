#include <iostream>

using namespace std;

class Mobile{
    protected:
        string Brand;
        string Model;
        string OperativeSystem;

    public:
        Mobile(string B, string M, string OS) : Brand(B), Model(M), OperativeSystem(OS){
            cout << "Construyendo un objeto Movil" << endl;
        }

        virtual ~Mobile(){
            cout << "Destruyendo un objeto Movil" << endl;
        }

        virtual void ShowInformation(){
            cout << "Marca: " << Brand << endl;
            cout << "Modelo: " << Model << endl;
            cout << "Sistema Operativo: " << OperativeSystem << endl;
        }
};

class Phone : public Mobile{
    private:
        string PhoneNumber;

    public:
        Phone(string B, string M, string OS, string PN) : Mobile(B, M, OS), PhoneNumber(PN){
            cout << "Construyendo un objeto Telefono" << endl;
        }

        ~Phone(){
            cout << "Destruyendo un objeto Telefono" << endl;
        }

        void ShowInformation(){
            Mobile::ShowInformation();
            cout << "Número de Teléfono: " << PhoneNumber << endl;
        }
};

class Tablet : public Mobile{
    private:
        string ScreenSize;

    public:
        Tablet(string Brand, string Model, string OperativeSystem, string ScreenSize) : Mobile(Brand, Model, OperativeSystem), ScreenSize(ScreenSize){
            cout << "Construyendo un objeto Tablet" << endl;
        }

        ~Tablet(){
            cout << "Destruyendo un objeto Tablet" << endl;
        }

        void ShowInformation(){
            Mobile::ShowInformation();
            cout << "Tamaño de Pantalla: " << ScreenSize << " pulgadas" << endl;
        }
};

int main(){
    Mobile* movil1 = new Phone("Samsung", "A12", "Android", "+51 928172372");
    Mobile* movil2 = new Tablet("Samsung", "Galaxy Tab S7", "Android", "11");

    movil1 -> ShowInformation();
    cout << endl;
    movil2 -> ShowInformation();

    delete movil1;
    delete movil2;

    return 0;
}
