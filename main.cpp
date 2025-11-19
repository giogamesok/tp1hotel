#include <iostream>
#include <vector>
#include "implementacao/HotelService.h"
#include "implementacao/ReservaService.h"
#include "implementacao/GerenteService.h"
#include "implementacao/QuartoService.h"
#include "implementacao/HospedeService.h"
#include "dominios/Nome.h"
#include "dominios/Email.h"
#include "dominios/Ramal.h"
#include "dominios/Senha.h"
#include "dominios/Telefone.h"
#include "dominios/Codigo.h"
#include "dominios/Numero.h"
#include "dominios/Capacidade.h"
#include "dominios/Dinheiro.h"
#include "dominios/Cartao.h"
#include "dominios/Endereco.h"
#include "dominios/Data.h"
#include "entidades/Hotel.h"
#include "entidades/Reserva.h"
#include "entidades/Gerente.h"
#include "entidades/Hospede.h"
#include "entidades/Quarto.h"

int main() {
    try {
        // Criar objetos domínios e entidades
        Nome nomeHotel("HotelXYZ");
        Endereco enderecoHotel("Rua ABC, 123");
        Telefone telefoneHotel("+5511987654321");
        Codigo codigoHotel("abc123def4");
        Gerente gerente(Nome("Carlos Silva"), Email("carlo@example.com"), Ramal("1234"), Senha("Senha@123"));

        Hotel hotel(nomeHotel, enderecoHotel, telefoneHotel, codigoHotel, gerente);
        HotelService hotelService;
        hotelService.criarHotel(hotel);

        Numero numero(49);
        Capacidade capacidade(2);
        Dinheiro diaria(300.00);
        Ramal ramal("5678");
        Codigo codigoQuarto("qwe456rty2");
        Quarto quarto(numero, capacidade, diaria, ramal, codigoQuarto);
        QuartoService quartoService;
        quartoService.adicionarQuarto(quarto);

        Data chegada(10, "NOV", 2025);
        Data partida(15, "NOV", 2025);
        Dinheiro valorReserva(1500.00);
        Codigo codigoReserva("res1234567");
        Reserva reserva(chegada, partida, valorReserva, codigoReserva);
        ReservaService reservaService;
        reservaService.criarReserva(reserva);

        GerenteService gerenteService;
        gerenteService.criarGerente(gerente);

        Email emailHospede("ana@email.com");
        Endereco enderecoHospede("Av. Brasil, 456");
        Cartao cartaoHospede("4532015112830366");
        Hospede hospede(Nome("Ana Pereira"), emailHospede, enderecoHospede, cartaoHospede);
        HospedeService hospedeService;
        hospedeService.criarHospede(hospede);

        // Mostrar a quantidade cadastrada
        std::cout << "Hotéis cadastrados: " << hotelService.listarHoteis().size() << std::endl;
        for (const auto& h : hotelService.listarHoteis()) {
            std::cout << "- Nome: " << h.getNome().getValor() << ", Endereço: " << h.getEndereco().getValor() << std::endl;
        }

        std::cout << "Quartos cadastrados: " << quartoService.listarQuartos().size() << std::endl;
        for (const auto& q : quartoService.listarQuartos()) {
            std::cout << "- Número: " << q.getNumero().getValor()
                      << ", Capacidade: " << q.getCapacidade().getValor()
                      << ", Diária: " << q.getDiaria().getValor() << std::endl;
        }

        std::cout << "Reservas cadastradas: " << reservaService.listarReservas().size() << std::endl;
        for (const auto& r : reservaService.listarReservas()) {
            std::cout << "- Código: " << r.getCodigo().getValor()
                      << ", Chegada: " << r.getChegada().getData()
                      << ", Partida: " << r.getPartida().getData() << std::endl;
        }

        std::cout << "Gerentes cadastrados: " << gerenteService.listarGerentes().size() << std::endl;
        for (const auto& g : gerenteService.listarGerentes()) {
            std::cout << "- Nome: " << g.getNome().getValor()
                      << ", Ramal: " << g.getRamal().getValor() << std::endl;
        }

        std::cout << "Hóspedes cadastrados: " << hospedeService.listarHospedes().size() << std::endl;
        for (const auto& p : hospedeService.listarHospedes()) {
            std::cout << "- Nome: " << p.getNome().getValor()
                      << ", Email: " << p.getEmail().getValor() << std::endl;
        }

    } catch (const std::exception& ex) {
        std::cerr << "Erro: " << ex.what() << std::endl;
    }

    return 0;
}
