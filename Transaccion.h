#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Transaccion {
public:
  int nro_transaccion;
  double cantidad;
  std::string tipo;
  int dia;
  int mes;
  int anio;

  Transaccion(int nro, double cant, std::string t, int d, int m, int a)
      : nro_transaccion(nro), cantidad(cant), tipo(t), dia(d), mes(m), anio(a) {}

  std::string to_string() const;

  static std::vector<Transaccion> leer_transacciones();

  static std::vector<Transaccion> obtener_transacciones_por_cliente(const std::vector<Transaccion>& transacciones, int numero_cliente);

  static std::vector<Transaccion> filtrar_transacciones_por_periodo(const std::vector<Transaccion>& transacciones, int mes, int anio);

  static std::vector<Transaccion> filtrar_transacciones_por_anio(const std::vector<Transaccion>& transacciones, int anio);

  static double calcular_total_transacciones(const std::vector<Transaccion>& transacciones);

  static void guardar_transacciones(const std::vector<Transaccion>& transacciones);
};

#endif
