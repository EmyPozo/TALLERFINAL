

#define MAX_NOMBRE 50
#define MAX_CEDULA 20
#define MAX_FECHA 12
#define MAX_PRODUCTOS 100
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100

// Función para validar la cédula ecuatoriana
int validarCedulaEcuatoriana(const char *cedula);

// Funciones para manejar productos
void ingresarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos);
void modificarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos);
void eliminarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos);
void consultarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos);
void adicionarCompraProducto(char nombres[][MAX_NOMBRE], int cantidades[], int numProductos);
void verProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos);

// Funciones para manejar clientes
void ingresarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int *numClientes);
void modificarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int numClientes);
void consultarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int numClientes);
void verListadoClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int numClientes);

// Funciones para manejar facturas
void facturar(char facturasFecha[][MAX_FECHA], char facturasCedula[][MAX_CEDULA], char facturasNombre[][MAX_NOMBRE], float facturasValor[], int facturasCantidad[], int *numFacturas, char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos, char cedulas[][MAX_CEDULA], char clientesNombres[][MAX_NOMBRE], int numClientes);
void buscarFactura(char facturasFecha[][MAX_FECHA], char facturasCedula[][MAX_CEDULA], char facturasNombre[][MAX_NOMBRE], float facturasValor[], int facturasCantidad[], int numFacturas);
void verListadoFacturas(char facturasFecha[][MAX_FECHA], char facturasCedula[][MAX_CEDULA], char facturasNombre[][MAX_NOMBRE], float facturasValor[], int facturasCantidad[], int numFacturas);
