#pragma once
#include "../entidades/Hotel.h"
#include <vector>

/**
 * @interface IHotelService
 * @brief Interface para operações CRUD relacionadas a hotéis no sistema.
 */
class IHotelService {
public:
    virtual ~IHotelService() = default;

    /**
     * @brief Retorna a lista de hotéis cadastrados.
     * @return Vetor de objetos Hotel.
     */
    virtual std::vector<Hotel> listarHoteis() const = 0;

    /**
     * @brief Cadastra um novo hotel.
     * @param hotel Instância da entidade Hotel.
     */
    virtual void criarHotel(const Hotel& hotel) = 0;

    /**
     * @brief Atualiza dados de um hotel existente.
     * @param hotel Instância atualizada do hotel.
     */
    virtual void atualizarHotel(const Hotel& hotel) = 0;

    /**
     * @brief Remove um hotel pelo seu código identificador.
     * @param codigo Código do hotel a ser removido.
     */
    virtual void removerHotel(const std::string& codigo) = 0;
};
