cmake_minimum_required(VERSION 4.0)
project(tp1)

set(CMAKE_CXX_STANDARD 20)

include_directories(interfaces)

add_executable(tp1 main.cpp
        dominios/Codigo.cpp
        dominios/Codigo.h
        dominios/Capacidade.cpp
        dominios/Capacidade.h
        dominios/Cartao.cpp
        dominios/Cartao.h
        dominios/Nome.cpp
        dominios/Nome.h
        dominios/Endereco.cpp
        dominios/Endereco.h
        dominios/Numero.cpp
        dominios/Numero.h
        dominios/Ramal.cpp
        dominios/Ramal.h
        dominios/Senha.cpp
        dominios/Senha.h
        dominios/Telefone.cpp
        dominios/Telefone.h
        dominios/Dinheiro.cpp
        dominios/Dinheiro.h
        dominios/Email.cpp
        dominios/Email.h
        dominios/Data.cpp
        dominios/Data.h
        entidades/Gerente.cpp
        entidades/Gerente.h
        entidades/Hospede.cpp
        entidades/Hospede.h
        entidades/Quarto.cpp
        entidades/Quarto.h
        entidades/Hotel.cpp
        entidades/Hotel.h
        entidades/Reserva.cpp
        entidades/Reserva.h
        entidades/Pessoa.cpp
        entidades/Pessoa.h
        interfaces/IHotelService.cpp
        interfaces/IHotelService.h
        interfaces/IReservaService.cpp
        interfaces/IReservaService.h
        interfaces/IGerenteService.cpp
        interfaces/IGerenteService.h
        interfaces/IPessoaService.cpp
        interfaces/IPessoaService.h
        interfaces/IHospedeService.cpp
        interfaces/IHospedeService.h
        interfaces/IQuartoService.cpp
        interfaces/IQuartoService.h
        implementacao/HotelService.cpp
        implementacao/HotelService.h
        implementacao/ReservaService.cpp
        implementacao/ReservaService.h
        implementacao/GerenteService.cpp
        implementacao/GerenteService.h
        implementacao/QuartoService.cpp
        implementacao/QuartoService.h
        implementacao/HospedeService.cpp
        implementacao/HospedeService.h
)
