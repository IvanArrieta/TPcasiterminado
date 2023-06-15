#include "Base_de_Datos.h"

void Base_de_Datos::mostrarClientes() {
  std::cout << "----- Clientes -----" << std::endl;
  for (const auto& cliente : clientes) {
    std::cout << cliente.to_string() << std::endl;
  }
  system("pause");
  system("cls");
}

void Base_de_Datos::mostrarTransacciones() {
  std::cout << "----- Transacciones -----" << std::endl;
  for (const auto& transaccion : transacciones) {
    std::cout << transaccion.to_string() << std::endl;
  }
  system("pause");
  system("cls");
}

void Base_de_Datos::agregarCliente() {
  fflush(stdin);
  int nro_cliente = 0, anio = 0;
  std::string nombre = " ", apellido = " ", tipo = " ", estado = " ";

  std::cout << "Ingrese el numero de cliente: ";
  std::cin >> nro_cliente;
  std::cout << "Ingrese el nombre del cliente: ";
  std::cin >> nombre;
  std::cout << "Ingrese el apellido del cliente: ";
  std::cin >> apellido;
  std::cout << "Ingrese el tipo de cliente (plata/oro/black): ";
  std::cin >> tipo;
  std::cout << "Ingrese el anio de ingreso del cliente: ";
  std::cin >> anio;
  std::cout << "Ingrese el estado del cliente: ";
  std::cin >> estado;

  Cliente nuevo_cliente(nro_cliente, nombre, apellido, tipo, anio, estado);
  clientes.push_back(nuevo_cliente);
  Cliente::guardar_clientes(clientes);

  system("pause");
  system("cls");
}

void Base_de_Datos::agregarTransaccion() {
  fflush(stdin);
  int nro_transaccion = 0, dia = 0, mes = 0, anio = 0;
  double cantidad = 0;
  std::string tipo = " ";
  std::cout << "Ingrese el numero de transaccion: ";
  std::cin >> nro_transaccion;
  std::cout << "Ingrese la cantidad de la transaccion: ";
  std::cin >> cantidad;
  std::cout << "Ingrese el tipo de transaccion(e/d): ";
  std::cin >> tipo;
  std::cout << "Ingrese el dia de la transaccion: ";
  std::cin >> dia;
  std::cout << "Ingrese el mes de la transaccion: ";
  std::cin >> mes;
  std::cout << "Ingrese el anio de la transaccion: ";
  std::cin >> anio;

  Transaccion nueva_transaccion(nro_transaccion, cantidad, tipo, dia, mes, anio);
  transacciones.push_back(nueva_transaccion);
  Transaccion::guardar_transacciones(transacciones);

  system("pause");
  system("cls");
}

void Base_de_Datos::buscarClientePorNumero() {
  int numero_cliente = 0;

  std::cout << "Ingrese el numero de cliente: ";
  std::cin >> numero_cliente;
  std::vector<Cliente> resultados = Cliente::buscar_clientes_por_numero(clientes, numero_cliente);

  if (resultados.empty()) {
    std::cout << "No se encontraron clientes con el numero ingresado." << std::endl;
  } else {
    std::cout << "----- Resultados de busqueda -----" << std::endl;
    for (const auto& cliente : resultados) {
      std::cout << cliente.to_string() << std::endl;
    }
  }

  system("pause");
  system("cls");
}

void Base_de_Datos::mostrarTransaccionesCliente() {
  int numero_cliente = 0;

  std::cout << "Ingrese el numero de cliente: ";
  std::cin >> numero_cliente;
  std::vector<Transaccion> resultados = Transaccion::obtener_transacciones_por_cliente(transacciones, numero_cliente);

  if (resultados.empty()) {
    std::cout << "No se encontraron transacciones para el cliente ingresado." << std::endl;
  } else {
    std::cout << "----- Transacciones del cliente -----" << std::endl;
    for (const auto& transaccion : resultados) {
      std::cout << transaccion.to_string() << std::endl;
    }
  }

  system("pause");
  system("cls");
}

void Base_de_Datos::generarInformePorPeriodo() {
  int mes = 0, anio = 0;
  std::cout << "Ingrese el mes: ";
  std::cin >> mes;
  std::cout << "Ingrese el anio: ";
  std::cin >> anio;
  std::vector<Transaccion> resultados = Transaccion::filtrar_transacciones_por_periodo(transacciones, mes, anio);

  if (resultados.empty()) {
    std::cout << "No se encontraron transacciones para el periodo ingresado." << std::endl;
  } else {
    double total = Transaccion::calcular_total_transacciones(resultados);
    std::cout << "----- Informe de extracciones y depositos por periodo -----" << std::endl;
    for (const auto& transaccion : resultados) {
      std::cout << transaccion.to_string() << std::endl;
    }
    std::cout << "Total: $" << total << std::endl;
  }

  system("pause");
  system("cls");
}

void Base_de_Datos::generarInformePorAnio() {
  int anio = 0;
  std::cout << "Ingrese el anio: ";
  std::cin >> anio;
  std::vector<Transaccion> resultados = Transaccion::filtrar_transacciones_por_anio(transacciones, anio);

  if (resultados.empty()) {
    std::cout << "No se encontraron transacciones para el anio ingresado." << std::endl;
  } else {
    double total = Transaccion::calcular_total_transacciones(resultados);
    std::cout << "----- Informe de extracciones y depositos por anio -----" << std::endl;
    for (const auto& transaccion : resultados) {
      std::cout << transaccion.to_string() << std::endl;
    }
    std::cout << "Total: $" << total << std::endl;
  }

  system("pause");
  system("cls");
}

void Base_de_Datos::generarInformeTotal() {
  double total = Transaccion::calcular_total_transacciones(transacciones);
  std::cout << "----- Informe de extracciones y depositos totales -----" << std::endl;

  for (const auto& transaccion : transacciones) {
    std::cout << transaccion.to_string() << std::endl;
  }
  std::cout << "Total: $" << total << std::endl;

  system("pause");
  system("cls");
}

void Base_de_Datos::mostrarMenu() {
  fflush(stdin);
  int opcion = 0;

  do {
    std::cout << "\tMenu" << std::endl;
    std::cout << "1. Mostrar clientes" << std::endl;
    std::cout << "2. Mostrar transacciones" << std::endl;
    std::cout << "3. Agregar cliente" << std::endl;
    std::cout << "4. Agregar transaccion" << std::endl;
    fflush(stdin);
    std::cout << "5. Buscar cliente por numero de cliente" << std::endl;
    std::cout << "6. Mostrar todas las transacciones de un cliente" << std::endl;
    std::cout << "7. Generar informe de extracciones y depositos por periodo de 6 meses" << std::endl;
    std::cout << "8. Generar informe de extracciones y depositos por anio" << std::endl;
    std::cout << "9. Generar informe de extracciones y depositos totales" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;
    if (opcion != 0) {
      system("cls");
    }

    switch (opcion) {
    case 1: {
      mostrarClientes();
      break;
    }
    case 2: {
      mostrarTransacciones();
      break;
    }
    case 3: {
      agregarCliente();
      break;
    }
    case 4: {
      agregarTransaccion();
      break;
    }
    case 5: {
      buscarClientePorNumero();
      break;
    }
    case 6: {
      mostrarTransaccionesCliente();
      break;
    }
    case 7: {
      generarInformePorPeriodo();
      break;
    }
    case 8: {
      generarInformePorAnio();
      break;
    }
    case 9: {
      generarInformeTotal();
      break;
    }
    case 0: {
      std::cout << "Saliendo del programa..." << std::endl;
      break;
    }
    default: {
      std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
      break;
    }
    }
  } while (opcion != 0);
}
