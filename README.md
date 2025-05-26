# Juego de Serpientes y Escaleras

## Requisitos

* Un compilador de C++ que soporte C++20 (por ejemplo, GCC, Clang, MSVC).
* CMake (versión 3.10 o superior recomendada).
* Git.

## Cómo compilar y ejecutar

1. **Clonar el repositorio:**
    ```bash
    git clone https://github.com/Alanzphy/SyEProject
    cd SyEProject 
    ```


2. **Configurar el proyecto con CMake:**
   Crea un directorio de compilación (por ejemplo, `build`) y ejecuta CMake desde allí:
    ```bash
    mkdir build
    cd build
    cmake ..
    ```
   *Si estás en Windows y usas Visual Studio usa `cmake .. -G "Visual Studio 17 2022"`.*


3. **Compilar el proyecto:**
   Desde el directorio de compilación (`build`):
    ```bash
    cmake --build .
    ```

4. **Ejecutar el juego:**
   El ejecutable se llamará `snakes` (o `snakes.exe` en Windows) y estará ubicado dentro del directorio de compilación (`build/snakes` o `build/Debug/snakes.exe`)


Desde el directorio `build`:
    ```bash
    ./snakes 
    ```
   O en Windows:
    ```bash
    .\snakes.exe 
    ```
   (Si se encuentra en una subcarpeta como `Debug`, ajusta la ruta: `.\Debug\snakes.exe`)

## Controles del juego
* Presiona 'C' para avanzar al siguiente turno.
* Presiona 'E' para finalizar el juego.

---
Ejecutar con docker si no quieres configurar el entorno localmente:

1. Construir la imagen:
    ```bash
    docker build -t <nombredelconteneder> .
    ```

2. Ejecutar el juego de forma interactiva:
    ```bash
    docker run -it <nombredelconteneder>
    ```
Luego de ejecutar el comando anterior, el juego iniciará y podrás interactuar con él a través de la terminal.

---

## Discusión: Conceptos de POO utilizados y justificación del diseño

En este proyecto se aplico conceptos de POO con el objetivo de hacer un sistema modular, que se pueda extender y sobre todo fácil de mantener

### 1. **Abstracción y encapsulamiento**
Se crearon clases que representan entidades del juego como `Player`, `Dice`, `Casilla`, `Tablero` y `Game`, cada clase contiene los atributos y métodos necesarios para su comportamiento, evitando y limitando el acceso directo a atributos privados haciendo uso del encapsulamiento y permitiendo o exponiendo atributos publicos que se denomina como una interfaz

### 2. **Herencia y polimorfismo**
Se utilizó herencia para crear distintos tipos de casillas, los cuales a partir de una clase abstracta `Casilla`, heredamos hacia `CasillaNormal`, `CasillaEscalera` y `CasillaSerpiente`, permitiendonos usar **polimorfismo**, invocando métodos como `getSiguienteCasilla()` sin necesidad de conocer el tipo específico de casilla que es, lo cual nos facilita el mantenimiento y extensión del programa a la hora de implementar nuevas funciones.

### 3. **Modularidad y responsabilidad única**
Cada clase se creo con una responsabilidad unica y delimitada:
- `Dice` simula el comportamiento de un dado.
- `Player` almacena el estado de cada jugador.
- `Casilla` y sus clases hijas definen las reglas del tablero.
- `Tablero` administra las casillas y nos da acceso a ellas.
- `Game` maneja toda la lógica del flujo del juego.
  Esta forma de estructurar nos permite modificar o extender cada parte sin afectar otras

### 4. **Justificación del diseño**
El uso de clases hijas para los tipos de casillas evita condicionales innecesarios en la lógica del juego, por lo que cada tipo de casilla sabe que debe hacer, y `Game` puede centrarse únicamente en el flujo del turno, además, al representar jugadores y casillas como objetos, se facilita la reutilización de código, y al querer agregar mas jugadores
