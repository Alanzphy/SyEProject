# Imagen base con g++ y CMake
FROM debian:bullseye

# Instalar dependencias necesarias
RUN apt-get update && \
    apt-get install -y g++ cmake make && \
    apt-get clean

# Crear directorio de trabajo
WORKDIR /app

# Copiar todos los archivos al contenedor
COPY cmake-build-debug .

# Crear carpeta de compilación
RUN mkdir build

# Configurar con CMake y compilar
RUN cd build && cmake .. && cmake --build .

# Establecer directorio por defecto para ejecución
WORKDIR /app/build

# Ejecutar el programa
CMD ["./snakes"]

