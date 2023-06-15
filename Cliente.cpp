#include "Cliente.h"

std::string Cliente::to_string() const {
  fflush(stdin);
  std::stringstream ss;
  ss << "Nro. de Cliente: " << nro_cliente << "\n";
  ss << "Nombre: " << nombre << " " << apellido << "\n";
  ss << "Tipo: " << tipo << "\n";
  ss << "Anio: " << anio << "\n";
  ss << "Estado: " << estado << "\n";
  return ss.str();
}

void Cliente::guardar_clientes(const std::vector<Cliente>& clientes) {
  std::ofstream archivo(R"(C:\Users\Ivan\UCC\Programacion\trabajo-final-v1-2217940-2205853\cliente.txt)", std::ios::app);

  if (!archivo) {
    std::cout << "Error al abrir el archivo clientes.txt" << std::endl;
    return;
  }

  for (const auto& cliente : clientes) {
    archivo << cliente.nro_cliente << "," << cliente.nombre << "," << cliente.apellido << ","
            << cliente.tipo << "," << cliente.anio << "," << cliente.estado << "\n";
  }

  archivo.close();
}

std::vector<Cliente> Cliente::leer_clientes() {
  std::vector<Cliente> clientes;
  std::ifstream archivo(R"(C:\Users\Ivan\UCC\Programacion\trabajo-final-v1-2217940-2205853\cliente.txt)",std::ios::app);

  if (!archivo) {
    std::cout << "Error al abrir el archivo clientes.txt" << std::endl;
    return clientes;
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
      int nro_cliente = std::stoi(campos[0]);
      std::string nombre = campos[1];
      std::string apellido = campos[2];
      std::string tipo = campos[3];
      int anio = std::stoi(campos[4]);
      std::string estado = campos[5];
      Cliente cliente(nro_cliente, nombre, apellido, tipo, anio, estado);
      clientes.push_back(cliente);
    }
  }

  archivo.close();
  return clientes;
}

std::vector<Cliente> Cliente::buscar_clientes_por_numero(const std::vector<Cliente>& clientes, int numero) {
  std::vector<Cliente> resultados;

  for (const auto& cliente : clientes) {
    if (cliente.nro_cliente == numero) {
      resultados.push_back(cliente);
    }
  }
  return resultados;
}

bool Cliente::tiene_tarjeta_credito() const {
  if (tipo == "oro" || tipo == "black") {
    return true;
  }
  return false;
}

double Cliente::obtener_limite_tarjeta_credito() const {
  if (tipo == "oro") {
    return 50000.0;
  } else if (tipo == "black") {
    return 250000.0;
  }
  return 0.0;
}

bool Cliente::verificar_antiguedad(const Cliente& cliente) {
  int anio_actual = 2023;

  if (anio_actual - cliente.anio < 3 && cliente.tipo == "black") {
    return false;
  }
  return true;
}
