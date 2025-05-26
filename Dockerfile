# Imagen base con g++ y CMake
FROM --platform=linux/amd64 debian:bullseye

ARG CMAKE_MAJOR_MINOR_VERSION=3.31
ARG CMAKE_PATCH_VERSION=0
ARG CMAKE_VERSION=${CMAKE_MAJOR_MINOR_VERSION}.${CMAKE_PATCH_VERSION}

# Instalar dependencias necesarias y CMake
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        g++ \
        make \
        wget \
        ca-certificates && \
    # Descargar e instalar CMake
    wget "https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-x86_64.sh" -O cmake_installer.sh && \
    # En un escenario real, se recomienda verificar el checksum del archivo descargado
    # Por ejemplo: echo "EXPECTED_CHECKSUM  cmake_installer.sh" | sha256sum -c - || exit 1
    chmod +x cmake_installer.sh && \
    ./cmake_installer.sh --skip-license --prefix=/usr/local && \
    rm cmake_installer.sh && \
    # Limpiar caché de apt
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Crear directorio de trabajo
WORKDIR /app

# Copiar todos los archivos al contenedor
COPY . .

# Crear carpeta de compilación
RUN mkdir build

# Configurar con CMake
RUN cd build && cmake ..

# Compilar el proyecto
RUN cd build && cmake --build . -- VERBOSE=1

# Establecer directorio por defecto para ejecución
WORKDIR /app/build

# Ejecutar el programa
CMD ["./snakes"]

