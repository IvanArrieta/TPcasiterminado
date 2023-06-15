#ifndef BASE_DE_DATOS_H
#define BASE_DE_DATOS_H

#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Transaccion.h"

class Base_de_Datos {
private:
  std::vector<Cliente> clientes;
  std::vector<Transaccion> transacciones;

public:
  void mostrarClientes();
  void mostrarTransacciones();
  void agregarCliente();
  void agregarTransaccion();
  void buscarClientePorNumero();
  void mostrarTransaccionesCliente();
  void generarInformePorPeriodo();
  void generarInformePorAnio();
  void generarInformeTotal();
  void mostrarMenu();
};

#endif
