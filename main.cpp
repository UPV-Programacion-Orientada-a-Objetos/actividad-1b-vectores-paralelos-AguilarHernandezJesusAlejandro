#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Definimos el tamaño máximo de productos
const int MAX_PRODUCTOS = 100;

// Arreglos paralelos para almacenar datos de los productos
int codigos[MAX_PRODUCTOS];
string nombres[MAX_PRODUCTOS];
int stock[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];

// Variable para llevar el conteo de productos en el inventario
int totalProductos = 5;

// Función para inicializar los productos predefinidos
// Función para cargar los productos iniciales en el inventario
void cargarProductos() {
    codigos[0] = 101; 
    nombres[0] = "Martillo de bola"; 
    stock[0] = 50; 
    precios[0] = 15.50;

    codigos[1] = 102; 
    nombres[1] = "Destornillador"; 
    stock[1] = 120; 
    precios[1] = 8.75;

    codigos[2] = 103; 
    nombres[2] = "Cinta métrica"; 
    stock[2] = 75; 
    precios[2] = 20.00;

    codigos[3] = 104; 
    nombres[3] = "Llave inglesa"; 
    stock[3] = 45; 
    precios[3] = 25.99;

    codigos[4] = 105; 
    nombres[4] = "Taladro inalámbrico"; 
    stock[4] = 10; 
    precios[4] = 120.00;
}


// Función para consultar un producto
void consultarProducto(int codigo) {
    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (codigos[i] == codigo) {
            cout << "Información del Producto:" << endl;
            cout << "Código: " << codigos[i] << endl;
            cout << "Nombre: " << nombres[i] << endl;
            cout << "Cantidad en stock: " << stock[i] << endl;
            cout << "Precio unitario: $" << precios[i] << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}

// Función para actualizar el inventario
void actualizarInventario(int codigo, int cantidad) {
    for (int i = 0; i < totalProductos; i++) {
        if (codigos[i] == codigo) {
            if (stock[i] + cantidad < 0) {
                cout << "No se puede tener un inventario negativo." << endl;
            } else {
                stock[i] += cantidad;
                cout << "Inventario actualizado. Nueva cantidad en stock: " << stock[i] << endl;
            }
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

// Función para generar el reporte completo
void generarReporte() {
    cout << "--- Reporte de Inventario ---" << endl;
    cout << "Código    | Nombre             | Stock | Precio" << endl;
    for (int i = 0; i < totalProductos; i++) {
        cout << codigos[i] << "       | " << nombres[i] << "   | " << stock[i] << "    | $" << precios[i] << endl;
    }
}

// Función para encontrar el producto más caro
void encontrarProductoMasCaro() {
    int indiceMasCaro = 0;
    for (int i = 1; i < totalProductos; i++) {
        
    }
    
}

// Función principal
int main() {
    cargarProductos();
    int opcion, codigo, cantidad;

    do {
        cout << "--- Menú principal ---" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Consultar un producto" << endl;
        cout << "2. Actualizar inventario" << endl;
        cout << "3. Generar reporte completo" << endl;
        cout << "4. Encontrar el producto más caro" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción seleccionada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el código del producto a consultar: ";
                cin >> codigo;
                consultarProducto(codigo);
                break;
            case 2:
                cout << "Ingrese el código del producto a actualizar: ";
                cin >> codigo;
                cout << "Ingrese la cantidad a agregar o restar (número negativo para restar): ";
                cin >> cantidad;
                actualizarInventario(codigo, cantidad);
                break;
            case 3:
                generarReporte();
                break;
            case 4:
                encontrarProductoMasCaro();
                break;
            case 5:
                cout << "Gracias por usar el sistema de inventario. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
