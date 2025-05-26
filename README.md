# Juego de Serpientes y Escaleras

Este es un juego simple de Serpientes y Escaleras implementado en C++.

## Requisitos

* Un compilador de C++ que soporte C++20 (por ejemplo, GCC, Clang, MSVC).
* CMake (versión 3.10 o superior recomendada).
* Git.

## Cómo compilar y ejecutar

1. **Clonar el repositorio:**
    ```bash
    git clone <TU_URL_DEL_REPOSITORIO_AQUI>
    cd SyEProject 
    ```
   (Reemplaza `<TU_URL_DEL_REPOSITORIO_AQUI>` con la URL real de tu repositorio de GitHub después de crearlo)

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

En este proyecto se aplicaron diversos conceptos fundamentales de la programación orientada a objetos (POO) con el objetivo de construir un sistema modular, extensible y fácil de mantener. A continuación, se describen los principales conceptos aplicados y las decisiones de diseño tomadas:

### 1. **Abstracción y encapsulamiento**
Se crearon clases que representan entidades del juego real, como `Player`, `Dice`, `Casilla`, `Tablero` y `Game`. Cada clase contiene únicamente los atributos y métodos necesarios para su comportamiento, evitando el acceso directo a variables internas (encapsulamiento) y exponiendo funciones públicas bien definidas (interfaz).

### 2. **Herencia y polimorfismo**
Se utilizó herencia para modelar los distintos tipos de casillas del tablero. A partir de una clase base abstracta `Casilla`, se derivaron las clases `CasillaNormal`, `CasillaEscalera` y `CasillaSerpiente`. Esto permitió usar **polimorfismo**, invocando métodos como `getSiguienteCasilla()` sin preocuparse por el tipo específico de casilla, lo cual facilita el mantenimiento y extensión del código.

### 3. **Modularidad y responsabilidad única**
Cada clase fue diseñada con una responsabilidad clara y bien delimitada:
- `Dice` simula el comportamiento de un dado.
- `Player` almacena el estado de cada jugador.
- `Casilla` y sus derivadas definen las reglas del tablero.
- `Tablero` administra las casillas y provee acceso a ellas.
- `Game` orquesta toda la lógica del flujo del juego.
  Esta separación permite modificar o extender cada parte sin afectar otras.

### 4. **Justificación del diseño**
El uso de clases derivadas para los tipos de casillas evita condicionales innecesarios en la lógica del juego. Así, cada tipo de casilla sabe cómo comportarse, y `Game` puede centrarse únicamente en el flujo del turno. Además, al representar jugadores y casillas como objetos, se facilita la reutilización de código, la expansión futura (más jugadores, más reglas) y la implementación de pruebas unitarias si se requiere.
