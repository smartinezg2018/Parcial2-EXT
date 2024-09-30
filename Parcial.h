#ifndef PARCIAL_H
#define PARCIAL_H

#include "Grafo.h"
#include <vector>

// Clase que encapsula la funcionalidad del grafo para el parcial
class Parcial {
private:
    Grafo grafo;  // Grafo que representa los establecimientos D1

public:
    // Carga los vértices en el grafo
    void cargar(const std::vector<Vertice>& vertices);

    // Ejecuta el algoritmo de Dijkstra en el grafo
    std::pair<std::vector<int>, std::vector<double>> run();

    // Imprime la estructura del grafo
    void imprimirGrafo() const;

    // Obtiene la lista de vértices del grafo
    std::vector<Vertice> obtenerVertices() const { return grafo.obtenerVertices(); }
};

#endif // PARCIAL_H