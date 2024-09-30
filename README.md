# Evaluación Parcial: Optimización de Rutas para D1 en Medellín

## Introducción

Este proyecto es una extensión del parcial de Estructuras de Datos y Algoritmos II, enfocado en la optimización logística para la cadena de tiendas D1 en Medellín. El objetivo es desarrollar un sistema eficiente para calcular las rutas más cortas entre los establecimientos D1, utilizando el algoritmo de Dijkstra.

Este README proporciona una guía detallada sobre cómo abordar y completar el proyecto, basándose en el parcial inicial.

**Importante:** Para acceder al documento original del parcial y obtener todos los detalles del reto, por favor visita el siguiente enlace:

[Parcial Inicial - Reto de Optimización Logística para D1 en Medellín](https://docs.google.com/document/d/16PKcjlLMXQUEqgT_0NR51QjZcuh5b200DqRU9KZ04Hs/edit?usp=sharing)

## Contexto del Parcial Original

El escenario planteado en el parcial inicial es el siguiente:

- D1 cuenta con más de 10 locales comerciales distribuidos en Medellín.
- Existen dos bodegas estratégicamente ubicadas: una en la zona norte y otra en la zona sur de la ciudad.
- Dos camiones, cada uno asignado a una bodega, son responsables de abastecer todos los locales.

El desafío original consistía en desarrollar un programa en C++ para determinar las dos rutas más cortas y eficientes para que los camiones abastezcan todos los locales, visitando cada uno una única vez.

## Extensión del Parcial

En esta versión extendida del proyecto, hemos ampliado el alcance para incluir:

1. Implementación de una estructura de datos de grafo eficiente.
2. Carga de datos de los establecimientos D1.
3. Ejecución del algoritmo de Dijkstra para encontrar las rutas más cortas.
4. Medición precisa del tiempo de ejecución del algoritmo.

## Estructura del Proyecto

El proyecto se compone de tres clases principales:

1. `Grafo`: Representa la red de establecimientos D1.
2. `Parcial`: Encapsula la funcionalidad del grafo y los algoritmos de búsqueda de rutas.
3. `EvaluarParcial`: Gestiona la evaluación del rendimiento y la presentación de resultados.

## Paso a Paso del Proceso

### 1. Implementación de la Clase Grafo

- Crea la estructura para representar vértices (establecimientos) y aristas (conexiones).
- Implementa métodos para agregar vértices y calcular distancias entre ellos.

### 2. Implementación de la Clase Parcial

Desarrolla dos métodos clave:

a) Método `cargar`:
```cpp
void cargar(const std::vector<Vertice>& vertices);
```
- Recibe los datos de los establecimientos D1.
- Agrega cada establecimiento como un vértice al grafo.
- Genera las conexiones (aristas) entre todos los vértices.

b) Método `run`:
```cpp
std::pair<std::vector<int>, std::vector<double>> run();
```
- Ejecuta el algoritmo de Dijkstra desde el vértice inicial.
- Retorna:
  - Un vector de índices de vértices previos en las rutas más cortas.
  - Un vector de distancias más cortas desde el inicio a cada vértice.

### 3. Implementación de la Clase EvaluarParcial

Esta clase orquesta todo el proceso:
- Crea los datos de ejemplo de los establecimientos D1.
- Instancia la clase `Parcial` y carga los datos.
- Ejecuta el algoritmo y mide el tiempo de ejecución.
- Presenta los resultados: rutas óptimas y tiempo de ejecución.

### 4. Ejecución y Evaluación

```cpp
int main() {
    EvaluarParcial evaluador;
    evaluador.ejecutar();
    return 0;
}
```
- Crea una instancia de `EvaluarParcial`.
- Llama al método `ejecutar()` para iniciar el proceso.
- Muestra los resultados en la consola.

## Compilación y Ejecución

1. Asegúrate de tener todos los archivos fuente en el mismo directorio.
2. Usa el Makefile proporcionado para compilar:
   ```
   make
   ```
3. Ejecuta el programa:
   ```
   ./run
   ```

## Criterios de Evaluación

Tu implementación será evaluada basándose en los siguientes criterios:

1. Corrección de la solución (40%): El programa debe encontrar las rutas más cortas de manera precisa y confiable.
2. Eficiencia del algoritmo (30%): La implementación debe ser eficiente en términos de tiempo de ejecución.
3. Calidad del código (10%): El código debe ser claro, bien estructurado y debidamente comentado.
4. Informe detallado (20%): Se debe entregar un informe que explique el enfoque adoptado, las decisiones de diseño y un análisis de los resultados.

## Notas Importantes

- Prioriza la eficiencia en tu implementación de `Parcial`, ya que el tiempo de ejecución es crucial en la evaluación.
- Utiliza la fórmula del haversine para calcular distancias entre establecimientos, considerando la curvatura de la Tierra.
- Implementa un grafo no dirigido, asegurando conexiones bidireccionales entre establecimientos.
- Documenta cuidadosamente tu código y explica tus decisiones de diseño en el informe.
- Asegúrate de seguir las instrucciones detalladas en el documento del parcial inicial (enlace proporcionado al inicio de este README).

## Conclusión

Este proyecto te desafía a aplicar tus conocimientos de estructuras de datos y algoritmos en un escenario del mundo real. La optimización de rutas logísticas es un problema común en la industria, y tu solución podría tener aplicaciones prácticas significativas.

Recuerda consultar frecuentemente el documento del parcial inicial para asegurarte de cumplir con todos los requisitos específicos del reto.


