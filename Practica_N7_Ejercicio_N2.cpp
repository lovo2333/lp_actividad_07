#include <iostream>

using namespace std;

class Person{
    protected:
        string Name;
        int Age;
        string Email;

    public:
        Person(string N, int A, string E) : Name(N), Age(A), Email(E){}

        virtual ~Person(){}

        virtual void ShowInformation(){
            cout << "Nombre: " << Name << endl;
            cout << "Edad: " << Age << " años" << endl;
            cout << "Correo electrónico: " << Email << endl;
        }
};

class Employee : public Person{
    private:
        double Salary;

    public:
        Employee(string N, int A, double S, string E) : Person(N, A, E), Salary(S){}

        ~Employee(){}

        void ShowInformation(){
            Person::ShowInformation();
            cout << "Salario: " << Salary << endl;
        }
    };

    class Client : public Person{
    public:
        Client(string N, int A, string E) : Person(N, A, E){}

        ~Client(){}
};

int main(){
    Employee empleado("Perico Palotes", 20, 50000.0, "Palotes@gmail.com");
    Client cliente("Pedro Quispe", 25, "Quispe@gmail.com");

    empleado.ShowInformation();
    cout << endl;
    cliente.ShowInformation();

    return 0;
}
