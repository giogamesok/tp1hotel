#pragma once
#include "../entidades/Hospede.h"
#include <vector>

/**
 * @interface IHospedeService
 * @brief Interface para operações relativas a hóspedes.
 */
class IHospedeService {
public:
    virtual ~IHospedeService() = default;

    /**
     * @brief Lista todos os hóspedes cadastrados.
     * @return Vetor de hóspedes.
     */
    virtual std::vector<Hospede> listarHospedes() const = 0;

    /**
     * @brief Cadastra um novo hóspede.
     * @param hospede Instância do hóspede.
     */
    virtual void criarHospede(const Hospede& hospede) = 0;

    /**
     * @brief Remove um hóspede pelo email.
     * @param email Email do hóspede.
     */
    virtual void removerHospede(const std::string& email) = 0;
};
