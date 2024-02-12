#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct PlantacionCacao {
    string nombre;
    float area;
    int edad;
    float produccionAnual;
};

struct PlantacionArroz {
    string nombre;
    float area;
    int edad;
    float produccionAnual;
};

void agregarPlantacionCacao(vector<PlantacionCacao>& plantaciones, float porcentajeArcilla, float porcentajeArena, float porcentajeLimo, float pH, float materiaOrganica);
void agregarPlantacionArroz(vector<PlantacionArroz>& plantaciones, float porcentajeArcilla, float porcentajeArena, float porcentajeLimo, float pH, float materiaOrganica);
void calcularPorcentajeSuelos(int, float&, float&, float&, float&, float&);
void clasificarCacao(float, float, float, float, float);
void clasificarArroz(float, float, float, float, float);
void mostrarInventarioCacao(const vector<PlantacionCacao>& plantacionesCacao);
void mostrarInventarioArroz(const vector<PlantacionArroz>& plantacionesArroz);


int main() {
    int opcion = 0;

    vector<PlantacionCacao> inventarioCacao;
    vector<PlantacionArroz> inventarioArroz;

    do {
        int muestras;
        float porcentajeArcilla, porcentajeArena, porcentajeLimo;
        float pH, materiaOrganica;

        cout << "|| SISTEMA DE CLASIFICACION DE SUELOS PARA EL MANEJO DE SUELOS || " << endl;
        cout << endl;
        cout << "            || OPCIONES ||                " << endl;
        cout << "(1) Manejo de Cultivos \n(2) Inventario de Cultivos \n(3) Salir\n";
        cin >> opcion;
        int opcionManejo = 0;

        switch (opcion) {
            case 1:
                cout << "        || MANEJO DE CULTIVOS ||                " << endl;
                cout << "(1) Manejo de Cacao\n(2) Manejo de Arroz\n";
                cin >> opcionManejo;
                switch (opcionManejo) {
                    case 1:
                        cout << "   || BIENVENIDO AL MANEJO DE CACAO || " << endl;
                        cout << " Por favor ingrese la cantidad de muestras: "; 
                        cin >> muestras;
                        for (int i = 0; i < muestras; i++) {
                            calcularPorcentajeSuelos(i + 1, porcentajeArcilla, porcentajeArena, porcentajeLimo, pH, materiaOrganica);
                            agregarPlantacionCacao(inventarioCacao, porcentajeArcilla, porcentajeArena, porcentajeLimo, pH, materiaOrganica);
                        }
                        break;
                    case 2:
                        cout << "   || BIENVENIDO AL MANEJO DE ARROZ || " << endl;
                        cout << " Por favor ingrese la cantidad de muestras: "; 
                        cin >> muestras;
                        for (int i = 0; i < muestras; i++) {
                            calcularPorcentajeSuelos(i + 1, porcentajeArcilla, porcentajeArena, porcentajeLimo, pH, materiaOrganica);
                            agregarPlantacionArroz(inventarioArroz, porcentajeArcilla, porcentajeArena, porcentajeLimo, pH, materiaOrganica);
                        }
                        break;
                }
                break;
            case 2:
                cout << "|| INVENTARIO DE CULTIVOS ||" << endl;
                cout << "Cacao:" << endl;
                mostrarInventarioCacao(inventarioCacao);
                cout << endl << "Arroz:" << endl;
                mostrarInventarioArroz(inventarioArroz);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}

void calcularPorcentajeSuelos(int numeroMuestra, float& porcentajeArcilla, float& porcentajeArena, float& porcentajeLimo, float& pH, float& materiaOrganica) {
    cout << "Ingrese el porcentaje de arcilla de la muestra " << numeroMuestra << ": ";
    cin >> porcentajeArcilla;
    cout << "Ingrese el porcentaje de arena de la muestra " << numeroMuestra << ": ";
    cin >> porcentajeArena;
    cout << "Ingrese el porcentaje de limo de la muestra " << numeroMuestra << ": ";
    cin >> porcentajeLimo;
    cout << "Ingrese el pH de la muestra " << numeroMuestra << ": ";
    cin >> pH;
    cout << "Ingrese la materia orgánica de la muestra " << numeroMuestra << ": ";
    cin >> materiaOrganica;
}

void agregarPlantacionCacao(vector<PlantacionCacao>& plantaciones, float porcentajeArcilla, float porcentajeArena, float porcentajeLimo, float pH, float materiaOrganica) {
    if (porcentajeArcilla >= 20 || porcentajeArcilla < 40 && porcentajeArena >= 30 || porcentajeArena < 50 && porcentajeLimo >= 20 || porcentajeLimo < 40 && pH < 6.5 && materiaOrganica < 3.0) {
        cout << "Tipo de suelo Entisoles: Apto para cultivo de cacao" << endl;
        PlantacionCacao nuevaPlantacion;
        cout << "Nombre de la plantación: ";
        cin >> nuevaPlantacion.nombre;
        cout << "Área de la plantación (hectáreas): ";
        cin >> nuevaPlantacion.area;
        cout << "Edad de la plantación (años): ";
        cin >> nuevaPlantacion.edad;
        cout << "Producción anual de cacao (toneladas): ";
        cin >> nuevaPlantacion.produccionAnual;
        plantaciones.push_back(nuevaPlantacion);
        cout << "Plantación de cacao agregada exitosamente." << endl;
    }
}

void agregarPlantacionArroz(vector<PlantacionArroz>& plantaciones, float porcentajeArcilla, float porcentajeArena, float porcentajeLimo, float pH, float materiaOrganica) {
    if (porcentajeArcilla >= 20 || porcentajeArcilla < 40 && porcentajeArena >= 40 || porcentajeArena < 60 &&  porcentajeLimo < 40 && pH < 7.0 && materiaOrganica < 1.0) {
        cout << "Tipo de suelo Inceptisoles: Apto para cultivo de arroz" << endl;
        PlantacionArroz nuevaPlantacion;
        cout << "Nombre de la plantación: ";
        cin >> nuevaPlantacion.nombre;
        cout << "Área de la plantación (hectáreas): ";
        cin >> nuevaPlantacion.area;
        cout << "Edad de la plantación (años): ";
        cin >> nuevaPlantacion.edad;
        cout << "Producción anual de arroz (toneladas): ";
        cin >> nuevaPlantacion.produccionAnual;
        plantaciones.push_back(nuevaPlantacion);
        cout << "Plantación de arroz agregada exitosamente." << endl;
    } 
}

void mostrarInventarioCacao(const vector<PlantacionCacao>& plantacionesCacao) {
    cout << "===============================================================================" << endl;
    cout << "|    Nombre    |    Área (hectáreas)    |    Edad (años)    |    Producción Anual (toneladas)    |" << endl;
    cout << "===============================================================================" << endl;

    for (const auto& plantacion : plantacionesCacao) {
        cout << "| " << setw(13) << left << plantacion.nombre << " | " 
             << setw(23) << left << plantacion.area << " | " 
             << setw(17) << left << plantacion.edad << " | " 
             << setw(34) << left << plantacion.produccionAnual << " |" << endl;
    }
    cout << "===============================================================================" << endl;
}

void mostrarInventarioArroz(const vector<PlantacionArroz>& plantacionesArroz) {
    cout << "===============================================================================" << endl;
    cout << "|    Nombre    |    Área (hectáreas)    |    Edad (años)    |    Producción Anual (toneladas)    |" << endl;
    cout << "===============================================================================" << endl;

    for (const auto& plantacion : plantacionesArroz) {
        cout << "| " << setw(13) << left << plantacion.nombre << " | " 
             << setw(23) << left << plantacion.area << " | " 
             << setw(17) << left << plantacion.edad << " | " 
             << setw(34) << left << plantacion.produccionAnual << " |" << endl;
    }
    cout << "===============================================================================" << endl;
}
