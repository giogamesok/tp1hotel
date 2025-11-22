//
// Created by Leonardo Sequeira on 15/11/25.
//

#include "include/implementacao/HotelService.h"
#include "include/entidades/Hotel.h"
#include <algorithm>
#include <stdexcept>

void HotelService::criarHotel(const Hotel& hotel) {

    for (const auto& h : hoteis) {
        if (h.getCodigo().getValor() == hotel.getCodigo().getValor()) {
            throw std::invalid_argument("Já existe um hotel com este código");
        }
    }
    hoteis.push_back(hotel);
}

std::vector<Hotel> HotelService::listarHoteis() const {
    return hoteis;
}

Hotel HotelService::buscarHotelPorCodigo(const std::string& codigo) const {
    for (const auto& hotel : hoteis) {
        if (hotel.getCodigo().getValor() == codigo) {
            return hotel;
        }
    }
    throw std::invalid_argument("Hotel não encontrado");
}

bool HotelService::editarHotel(const std::string& codigo, const Hotel& hotelAtualizado) {
    for (auto& hotel : hoteis) {
        if (hotel.getCodigo().getValor() == codigo) {
            hotel = hotelAtualizado;
            return true;
        }
    }
    return false;
}

bool HotelService::excluirHotel(const std::string& codigo) {
    auto it = std::remove_if(hoteis.begin(), hoteis.end(),
        [&codigo](const Hotel& hotel) {
            return hotel.getCodigo().getValor() == codigo;
        });
    
    if (it != hoteis.end()) {
        hoteis.erase(it, hoteis.end());
        return true;
    }
    return false;
}

size_t HotelService::quantidadeHoteis() const {
    return hoteis.size();
}
