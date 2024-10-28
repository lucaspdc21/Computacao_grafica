cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Esfera)

# Define a versão do C++
set(CMAKE_CXX_STANDARD 14)

# Encontrar o SDL2
find_package(SDL2 REQUIRED)

# Adiciona o diretório de cabeçalhos
include_directories(include)

# Adiciona os arquivos fonte
set(SOURCES
    main.cpp
    src/Sphere.cpp
    src/Vector.cpp
    src/Canvas.cpp
    src/Display.cpp
    src/Ray.cpp
)

# Cria o executável
add_executable(esfera ${SOURCES})

# Linka a biblioteca SDL2 ao executável
target_link_libraries(esfera SDL2::SDL2)
