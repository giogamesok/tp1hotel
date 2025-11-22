#include <iostream>
#include <vector>
#include <limits>
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

class InterfaceConsole {
private:
    void limparTela() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void pausar() {
        std::cout << "\nPressione Enter para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    void exibirCabecalho(const std::string& titulo) {
        std::cout << "==================================" << std::endl;
        std::cout << "    " << titulo << std::endl;
        std::cout << "==================================" << std::endl;
    }

public:
    void executar() {
        int opcao;
        do {
            limparTela();
            exibirCabecalho("SISTEMA DE HOTEL");
            std::cout << "1. Executar Demonstração" << std::endl;
            std::cout << "2. Sair" << std::endl;
            std::cout << "==================================" << std::endl;
            std::cout << "Escolha uma opção: ";
            std::cin >> opcao;

            switch (opcao) {
                case 1:
                    executarDemonstracao();
                    break;
                case 2:
                    std::cout << "Saindo do sistema..." << std::endl;
                    break;
                default:
                    std::cout << "Opção inválida!" << std::endl;
                    pausar();
            }
        } while (opcao != 2);
    }

private:
    void executarDemonstracao() {
        try {
            limparTela();
            exibirCabecalho("INICIANDO DEMONSTRAÇÃO");
            
            std::cout << "Criando objetos de domínio e entidades..." << std::endl;
            pausar();

            
            limparTela();
            exibirCabecalho("FASE 1 - CRIAÇÃO DE OBJETOS");
            
            std::cout << " Criando Hotel 'Hotel Premium'..." << std::endl;
            Nome nomeHotel("Hotel Premium");  
            Endereco enderecoHotel("Rua das Flores, 123");  
            Telefone telefoneHotel("+551112345678");  
            Codigo codigoHotel("h123456789"); 
            Ramal ramalGerente("25");  
            Senha senhaGerente("A1b#c");  
            Gerente gerente(Nome("Carlos Silva"), Email("carlos@example.com"), ramalGerente, senhaGerente);

            Hotel hotel(nomeHotel, enderecoHotel, telefoneHotel, codigoHotel, gerente);
            HotelService hotelService;
            hotelService.criarHotel(hotel);
            std::cout << " Hotel criado com sucesso!" << std::endl;
            pausar();

            limparTela();
            exibirCabecalho("FASE 1 - CRIAÇÃO DE OBJETOS");
            std::cout << " Criando Quarto número 49..." << std::endl;
            Numero numero(49);  
            Capacidade capacidade(2);  
            Dinheiro diaria(300.00);  
            Ramal ramalQuarto("15");  
            Codigo codigoQuarto("q123456789");  
            Quarto quarto(numero, capacidade, diaria, ramalQuarto, codigoQuarto);
            QuartoService quartoService;
            quartoService.adicionarQuarto(quarto);
            std::cout << " Quarto criado com sucesso!" << std::endl;
            pausar();

            limparTela();
            exibirCabecalho("FASE 1 - CRIAÇÃO DE OBJETOS");
            std::cout << " Criando Reserva..." << std::endl;
            Data chegada(15, "NOV", 2024);  
            Data partida(20, "NOV", 2024);  
            Dinheiro valorReserva(1500.00);  
            Codigo codigoReserva("r123456789");  
            Reserva reserva(chegada, partida, valorReserva, codigoReserva);
            ReservaService reservaService;
            reservaService.criarReserva(reserva);
            std::cout << "Reserva criada com sucesso!" << std::endl;
            pausar();

            limparTela();
            exibirCabecalho("FASE 1 - CRIAÇÃO DE OBJETOS");
            std::cout << "Criando Gerente 'Carlos Silva'..." << std::endl;
            GerenteService gerenteService;
            gerenteService.criarGerente(gerente);
            std::cout << "Gerente criado com sucesso!" << std::endl;
            pausar();

            limparTela();
            exibirCabecalho("FASE 1 - CRIAÇÃO DE OBJETOS");
            std::cout << "Criando Hóspede 'Ana Pereira'..." << std::endl;
            Email emailHospede("ana.pereira@email.com");  
            Endereco enderecoHospede("Avenida Brasil, 456");  
            Cartao cartaoHospede("4539578763621486"); 
            Hospede hospede(Nome("Ana Pereira"), emailHospede, enderecoHospede, cartaoHospede);
            HospedeService hospedeService;
            hospedeService.criarHospede(hospede);
            std::cout << "Hóspede criado com sucesso!" << std::endl;
            pausar();

           
            limparTela();
            exibirCabecalho("FASE 2 - RELATÓRIO FINAL");
            
            std::cout << "\n RESUMO DE CADASTROS:\n" << std::endl;

            std::cout << "HOTÉIS CADASTRADOS: " << hotelService.listarHoteis().size() << std::endl;
            for (const auto& h : hotelService.listarHoteis()) {
                std::cout << "   • Nome: " << h.getNome().getValor() 
                          << ", Endereço: " << h.getEndereco().getValor() << std::endl;
            }

            std::cout << "\n QUARTOS CADASTRADOS: " << quartoService.listarQuartos().size() << std::endl;
            for (const auto& q : quartoService.listarQuartos()) {
                std::cout << "   • Número: " << q.getNumero().getValor()
                          << ", Capacidade: " << q.getCapacidade().getValor()
                          << ", Diária: R$ " << q.getDiaria().getValor() << std::endl;
            }

            std::cout << "\n RESERVAS CADASTRADAS: " << reservaService.listarReservas().size() << std::endl;
            for (const auto& r : reservaService.listarReservas()) {
                std::cout << "   • Código: " << r.getCodigo().getValor()
                          << ", Chegada: " << r.getChegada().getData()
                          << ", Partida: " << r.getPartida().getData() << std::endl;
            }

            std::cout << "\n GERENTES CADASTRADOS: " << gerenteService.listarGerentes().size() << std::endl;
            for (const auto& g : gerenteService.listarGerentes()) {
                std::cout << "   • Nome: " << g.getNome().getValor()
                          << ", Ramal: " << g.getRamal().getValor() << std::endl;
            }

            std::cout << "\n HÓSPEDES CADASTRADOS: " << hospedeService.listarHospedes().size() << std::endl;
            for (const auto& p : hospedeService.listarHospedes()) {
                std::cout << "   • Nome: " << p.getNome().getValor()
                          << ", Email: " << p.getEmail().getValor() << std::endl;
            }

            std::cout << "\n DEMONSTRAÇÃO CONCLUÍDA COM SUCESSO!" << std::endl;
            std::cout << "TODOS OS DOMÍNIOS RESPEITAM OS CRITÉRIOS DE VALIDAÇÃO" << std::endl;
            pausar();

        } catch (const std::exception& ex) {
            limparTela();
            exibirCabecalho("ERRO NA DEMONSTRAÇÃO");
            std::cerr << "Erro de validação: " << ex.what() << std::endl;
            std::cerr << "Verifique os critérios dos domínios!" << std::endl;
            pausar();
        }
    }
};

int main() {
    InterfaceConsole interface;
    interface.executar();
    return 0;
}