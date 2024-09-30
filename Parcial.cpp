#include "Parcial.h"

// Carga los vértices en el grafo
//
// Pseudocódigo:
// Procedimiento cargar(vertices)
//     Para cada v en vertices
//         grafo.agregarVertice(v)
//     Fin Para
// Fin Procedimiento
//
// Explicación:
// - Iteramos sobre cada vértice en la lista proporcionada.
// - Agregamos cada vértice al grafo utilizando el método agregarVertice().
// - Esto inicializa el grafo con todos los establecimientos D1.
void Parcial::cargar(const std::vector<Vertice>& vertices) {
    for (const auto& v : vertices) {
        grafo.agregarVertice(v);
    }
}

// Ejecuta el algoritmo de Dijkstra en el grafo
//
// Pseudocódigo:
// Función run()
//     return grafo.dijkstra(0)
// Fin Función
//
// Explicación:
// - Llamamos al método dijkstra() del grafo, comenzando desde el vértice 0.
// - Esto calcula las rutas más cortas desde el primer establecimiento a todos los demás.
// - Retornamos el resultado del algoritmo de Dijkstra (previos y distancias).
std::pair<std::vector<int>, std::vector<double>> Parcial::run() {
    return grafo.dijkstra(0);
}

// Imprime la estructura del grafo
//
// Explicación:
// - Simplemente llamamos al método imprimirGrafo() del objeto grafo.
// - Esto mostrará todos los vértices y sus conexiones.
void Parcial::imprimirGrafo() const {
    grafo.imprimirGrafo();
}