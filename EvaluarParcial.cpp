#include "Parcial.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

// Clase para evaluar el rendimiento y resultados del parcial
class EvaluarParcial {
public:
    // Ejecuta la evaluación del parcial
    //
    // Pseudocódigo:
    // Procedimiento ejecutar()
    //     parcial = nuevo objeto Parcial
    //     vertices = lista de vértices con datos de ejemplo
    //     
    //     parcial.cargar(vertices)
    //     imprimir "Grafo generado:"
    //     parcial.imprimirGrafo()
    //     
    //     inicio_tiempo = obtener tiempo actual
    //     resultado = parcial.run()
    //     previos = resultado.first
    //     distancias = resultado.second
    //     fin_tiempo = obtener tiempo actual
    //     
    //     duracion = fin_tiempo - inicio_tiempo
    //     
    //     imprimir "Tiempo de ejecución: " + duracion
    //     
    //     imprimir "Rutas más cortas desde D1 Centro:"
    //     Para cada vértice destino en vertices (excluyendo el primero)
    //         ruta = lista vacía
    //         v = índice del vértice destino
    //         Mientras v != -1
    //             añadir v al inicio de ruta
    //             v = previos[v]
    //         Fin Mientras
    //         
    //         imprimir "A " + nombre del vértice destino + ":"
    //         imprimir "  Ruta: " + nombres de los vértices en ruta
    //         imprimir "  Distancia total: " + distancias[índice del vértice destino]
    //     Fin Para
    // Fin Procedimiento
    //
    // Explicación:
    // 1. Creamos un objeto Parcial y cargamos los datos de ejemplo.
    // 2. Imprimimos la estructura del grafo para visualización.
    // 3. Medimos el tiempo de ejecución del algoritmo de Dijkstra.
    // 4. Para cada destino (excluyendo el vértice inicial):
    //    a. Reconstruimos la ruta más corta usando el vector de 'previos'.
    //    b. Imprimimos la ruta completa y la distancia total.
    // Este proceso nos permite visualizar y analizar las rutas más cortas y el rendimiento del algoritmo.
    void ejecutar() {
        Parcial parcial;

        // Datos de ejemplo (coordenadas aproximadas de algunos barrios de Medellín)
        std::vector<Vertice> vertices = {
            {"D1 Centro", 6.2442, -75.5812},
            {"D1 Poblado", 6.2084, -75.5687},
            {"D1 Laureles", 6.2453, -75.5939},
            {"D1 Belén", 6.2308, -75.6075},
            {"D1 Envigado", 6.1664, -75.5836}
        };

        // Cargar datos
        parcial.cargar(vertices);

        std::cout << "Grafo generado:" << std::endl;
        parcial.imprimirGrafo();

        // Medir tiempo de ejecución de run()
        auto inicio = std::chrono::high_resolution_clock::now();
        
        // Ejecutar el algoritmo y obtener resultados
        std::pair<std::vector<int>, std::vector<double>> resultado = parcial.run();
        std::vector<int> previos = resultado.first;
        std::vector<double> distancias = resultado.second;
        
        auto fin = std::chrono::high_resolution_clock::now();

        // Calcular duración
        auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);

        // Imprimir resultados
        std::cout << "Tiempo de ejecución del método run(): " 
                  << duracion.count() << " microsegundos" << std::endl;

        std::cout << "\nRutas más cortas desde D1 Centro:" << std::endl;
        auto vertices_grafo = parcial.obtenerVertices();
        for (size_t i = 1; i < vertices_grafo.size(); ++i) {
            std::cout << "A " << vertices_grafo[i].nombre << ":" << std::endl;
            
            // Reconstruir la ruta
            std::vector<int> ruta;
            for (int v = i; v != -1; v = previos[v]) {
                ruta.push_back(v);
            }
            
            // Imprimir la ruta
            std::cout << "  Ruta: ";
            for (auto it = ruta.rbegin(); it != ruta.rend(); ++it) {
                std::cout << vertices_grafo[*it].nombre;
                if (std::next(it) != ruta.rend()) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
            
            // Imprimir la distancia total
            std::cout << "  Distancia total: " << std::fixed << std::setprecision(2) 
                      << distancias[i] << " km" << std::endl << std::endl;
        }
    }
};

int main() {
    EvaluarParcial evaluador;
    evaluador.ejecutar();
    return 0;
}