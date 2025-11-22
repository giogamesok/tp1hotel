cmake_minimum_required(VERSION 3.16)  
project(TP1Hotel VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Arquivos fonte do projeto
set(SOURCES
    src/main.cpp
    src/hotel.cpp
    src/quarto.cpp
    src/gerente.cpp
    src/hospede.cpp
    src/reserva.cpp
    src/hotel_service.cpp
)

# Arquivos de cabeçalho
set(HEADERS
    include/hotel.h
    include/quarto.h
    include/gerente.h
    include/hospede.h
    include/reserva.h
    include/hotel_service.h
    include/id_generator.h
)

# Diretórios de include
include_directories(include)


add_executable(TP1Hotel ${SOURCES} ${HEADERS})

target_compile_features(TP1Hotel PRIVATE cxx_std_11)


if(WIN32)
    target_link_libraries(TP1Hotel)
endif()