cmake_minimum_required(VERSION 3.16)
project(TPIHotel VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    src/main.cpp
    src/hotel.cpp
    src/quarto.cpp
    src/gerente.cpp
    src/hospede.cpp
    src/reserva.cpp
    src/hotel_service.cpp
    
)


set(HEADERS
    
    entidades/Gerente.h
    entidades/Hospede.h
    entidades/Hotel.h
    entidades/Pessoa.h
    entidades/Quarto.h
    entidades/Reserva.h
    
  
    implementacao/HotelService.h
    implementacao/GerenteService.h
    implementacao/HospedeService.h
    implementacao/QuartoService.h
    implementacao/ReservaService.h
    
    
    interfaces/IHotelService.h
    interfaces/IGerenteService.h
    interfaces/IHospedeService.h
    interfaces/IQuartoService.h
    interfaces/IReservaService.h
    
  
    dominios/Capacidade.h
    dominios/Cartao.h
    dominios/Codigo.h
    dominios/Data.h
    dominios/Dinheiro.h
    dominios/Email.h
    dominios/Endereco.h
    dominios/Nome.h
    dominios/Numero.h
    dominios/Ramal.h
    dominios/Senha.h
    dominios/Telefone.h
)


include_directories(
    include
    entidades
    implementacao
    interfaces
    dominios
)

add_executable(TPIHotel ${SOURCES} ${HEADERS})

target_compile_features(TPIHotel PRIVATE cxx_std_11)