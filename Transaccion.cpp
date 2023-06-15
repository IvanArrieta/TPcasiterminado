#include "Transaccion.h"

std::string Transaccion::to_string() const {
  std::stringstream ss;
  ss << "Nro. de Transaccion: " << nro_transaccion << "\n";
  ss << "Cantidad: " << cantidad << "\n";
  ss << "Tipo: " << tipo << "\n";
  ss << "Fecha: " << dia << "/" << mes << "/" << anio << "\n";
  return ss.str();
}

std::vector<Transaccion> Transaccion::leer_transacciones() {
  std::vector<Transaccion> transacciones;
  std::ifstream archivo(R"(C:\Users\Ivan\UCC\Programacion\trabajo-final-v1-2217940-2205853\transaccion.txt)", std::ios::app);

  if (!archivo) {
    std::cout << "Error al abrir el archivo transacciones.txt" << std::endl;
    return transacciones;
  }

  std::string linea;

  while (std::getline(archivo, linea)) {
    std::stringstream ss(linea);
    std::string campo;
    std::vector<std::string> campos;
    while (std::getline(ss, campo, ',')) {
      campos.push_back(campo);
    }

    if (campos.size() == 6) {
      int nro_transaccion = std::stoi(campos[0]);
      double cantidad = std::stod(campos[1]);
      std::string tipo = campos[2];
      int dia = std::stoi(campos[3]);
      int mes = std::stoi(campos[4]);
      int anio = std::stoi(campos[5]);
      Transaccion transaccion(nro_transaccion, cantidad, tipo, dia, mes, anio);
      transacciones.push_back(transaccion);
    }
  }

  archivo.close();
  return transacciones;
}

std::vector<Transaccion> Transaccion::obtener_transacciones_por_cliente(const std::vector<Transaccion>& transacciones, int numero_cliente) {
  std::vector<Transaccion> resultados;

  for (const auto& transaccion : transacciones) {
    if (transaccion.nro_transaccion == numero_cliente) {
      resultados.push_back(transaccion);
    }
  }
  return resultados;
}

std::vector<Transaccion> Transaccion::filtrar_transacciones_por_periodo(const std::vector<Transaccion>& transacciones, int mes, int anio) {
  std::vector<Transaccion> resultados;

  for (const auto& transaccion : transacciones) {
    if (transaccion.mes == mes && transaccion.anio == anio) {
      resultados.push_back(transaccion);
    }
  }
  return resultados;
}

std::vector<Transaccion> Transaccion::filtrar_transacciones_por_anio(const std::vector<Transaccion>& transacciones, int anio) {
  std::vector<Transaccion> resultados;

  for (const auto& transaccion : transacciones) {
    if (transaccion.anio == anio) {
      resultados.push_back(transaccion);
    }
  }
  return resultados;
}

double Transaccion::calcular_total_transacciones(const std::vector<Transaccion>& transacciones) {
  double total = 0.0;

  for (const auto& transaccion : transacciones) {
    total += transaccion.cantidad;
  }

  return total;
}

void Transaccion::guardar_transacciones(const std::vector<Transaccion>& transacciones) {
  std::ofstream archivo(R"(C:\Users\Ivan\UCC\Programacion\trabajo-final-v1-2217940-2205853\transaccion.txt)", std::ios::app);

  if (!archivo) {
    std::cout << "Error al abrir el archivo transacciones.txt" << std::endl;
    return;
  }

  for (const auto& transaccion : transacciones) {
    archivo << transaccion.nro_transaccion << "," << transaccion.cantidad << "," << transaccion.tipo << ","
            << transaccion.dia << "," << transaccion.mes << "," << transaccion.anio << "\n";
  }

  archivo.close();
}
