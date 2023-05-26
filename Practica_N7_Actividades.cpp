#include <iostream>

using namespace std;

class Client{
    protected:
        string Name;
        string Address;
        string CardNumber;
        
    protected:
        virtual void EncryptInformation(){
            cout << "Encriptando información del cliente..." << endl;
        }
        
    public:
        Client(string N, string A, string CN) : Name(N), Address(A), CardNumber(CN){
                EncryptInformation();
            }
        
        virtual ~Client(){
            cout << "Destructor de Cliente llamado." << endl;
        }
        
        void ShowInformation(){
            cout << "Nombre: " << Name << endl;
            cout << "Dirección: " << Address << endl;
            cout << "Número de Tarjeta: " << CardNumber << endl;
        }
};

class SecureClient : public Client{
    private:
        string Clue;
        
    public:
        SecureClient(string N, string A, string CN, string C) : Client(N, A, CN), Clue(C){
                cout << "Constructor de Cliente Seguro llamado." << endl;
            }
        
        ~SecureClient(){
            cout << "Destructor de SecureClient llamado." << endl;
        }
        
        bool VerifyAuthenticity(string C){
            cout << "Verificando autenticidad del cliente..." << endl;
            return Clue == C;
        }
};

int main(){
    SecureClient cliente("Maria Mercedes", "Calle Principal 123", "123456789", "secreto");
    cliente.ShowInformation();
    cout << (cliente.VerifyAuthenticity("secreto") ? "Autenticidad comprobada" : "Denegado") << endl;
    return 0;
}
