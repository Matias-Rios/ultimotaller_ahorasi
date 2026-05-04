#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    int experiencia=0;
    int series=0;
    int peso[10];

public:
    Persona(string n) {
        nombre = n;
    }

    void agregar(int kg) {
        if (series < 10) {
            peso[series]=kg;
            cout << "Agregado con exito +10XP"<<endl;
            series++;
            experiencia+=10;
        } else {
            cout <<"Max ALCANZADO"<<endl;
        }
    }

    void verseries() {
        for (int i = 0; i < series; i++) {
            cout <<"Serie "<<i + 1 <<" : "<<peso[i] <<" kg "<<endl;
        }
    }

    int pesototal() {
        int total=0;

        for (int i=0; i < series; i++) {
            total+=peso[i];
        }

        return total;
    }

    int promedio() {
        if (series == 0) return 0;
        return pesototal() / series;
    }

    void verperfil() {
		cout<<"=============="<<endl;	
        cout <<"Usuario: "<<nombre << endl;
        cout <<"XP: "<<experiencia << endl;
        cout <<"Series: "<<series << endl;
        cout<<"=============="<<endl;	
    }

    int aplicarbonus(int &bonus) {
        experiencia += bonus;
        return experiencia;
    }
    int totalseries(){
    	return series;
	}
};

int main() {
    int bonus = 50;
    string user;

    cout <<"Tu username: ";
    cin >> user;

    Persona miPerfil(user);

    int opcion;
    int cantidad;

    while (true) {
        cout <<"\n=== REGISTRO DE ENTRENAMIENTO ==="<<endl;
        cout <<"1. Registrar serie"<<endl;
        cout <<"2. Ver series"<<endl;
        cout <<"3. Ver peso total"<<endl;
        cout <<"4. Ver promedio"<<endl;
        cout <<"5. Ver perfil"<<endl;
        cout <<"6. Aplicar bonus"<<endl;
        cout <<"7. Salir"<<endl;
        cout <<"Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout <<"Peso (kg): ";
            cin >> cantidad;

            while (cantidad < 0) {
                cout <<"Ingrese un peso valido: ";
                cin >> cantidad;
            }

            miPerfil.agregar(cantidad);

        } else if (opcion == 2) {
        	cout<<"=============="<<endl;
            miPerfil.verseries();
			cout<<"=============="<<endl;
        } else if (opcion == 3) {
        	cout<<"=============="<<endl;
            cout <<"Peso total: "<<miPerfil.pesototal()<<" kg "<<endl;
            cout<<"=============="<<endl;

        } else if (opcion == 4) {
        	cout<<"=============="<<endl;
            cout <<"Promedio: "<<miPerfil.promedio()<<" kg "<< endl;
            cout<<"=============="<<endl;

        } else if (opcion == 5) {
            miPerfil.verperfil();

        } else if (opcion == 6) {
        	cout<<"=============="<<endl;
            cout <<"XP actual despues del bonus: "<<miPerfil.aplicarbonus(bonus) << endl;
			cout<<"=============="<<endl;
        } else if (opcion == 7) {
            break;
        }
    }

    cout <<"Hasta luego! series finalizadas:"<<miPerfil.totalseries()<<endl;
    return 0;
}