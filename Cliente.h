#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Transaccion.h"

class Cliente {
public:
  int nro_cliente;
  std::string nombre;
  std::string apellido;
  std::string tipo;
  int anio;
  std::string estado;

  Cliente(int nro, const std::string& nom, const std::string& ape, const std::string& t, int a,
          const std::string& est)
      : nro_cliente(nro), nombre(nom), apellido(ape), tipo(t), anio(a), estado(est) {}

  std::string to_string() const;

  bool tiene_tarjeta_credito() const;

  double obtener_limite_tarjeta_credito() const;

  static std::vector<Cliente> leer_clientes();

  static std::vector<Cliente> buscar_clientes_por_numero(const std::vector<Cliente>& clientes, int numero);

  static bool verificar_antiguedad(const Cliente& cliente);

  static void guardar_clientes(const std::vector<Cliente>& clientes);
};

#endif
