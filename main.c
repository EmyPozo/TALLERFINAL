#include <stdio.h>
#include "operaciones.h"
#include "lecturas.h"

void mostrarMenu() {
    printf("Menu de opciones:\n");
    printf("1. Ingresar Producto\n");
    printf("2. Modificar Producto\n");
    printf("3. Eliminar Producto\n");
    printf("4. Consultar Producto\n");
    printf("5. Adicionar Compra Producto (Aumentar Stock)\n");
    printf("6. Ver Productos\n");
    printf("7. Ingresar Cliente\n");
    printf("8. Modificar Cliente\n");
    printf("9. Consultar Cliente\n");
    printf("10. Ver Listado de Clientes\n");
    printf("11. Facturar\n");
    printf("12. Buscar Factura\n");
    printf("13. Ver Listado de Facturas\n");
    printf("14. Salir\n");
}

int main() {
    char productosNombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int productosCantidades[MAX_PRODUCTOS];
    float productosPrecios[MAX_PRODUCTOS];
    int numProductos = 0;

    char clientesCedulas[MAX_CLIENTES][MAX_CEDULA];
    char clientesNombres[MAX_CLIENTES][MAX_NOMBRE];
    int numClientes = 0;

    char facturasFecha[MAX_FACTURAS][MAX_FECHA];
    char facturasCedula[MAX_FACTURAS][MAX_CEDULA];
    char facturasNombre[MAX_FACTURAS][MAX_NOMBRE];
    float facturasValor[MAX_FACTURAS];
    int facturasCantidad[MAX_FACTURAS];
    int numFacturas = 0;

    int opcion;

    do {
        mostrarMenu();
        opcion = leerEnteroEntre("Seleccione una opcion: ", 1, 14);
        switch(opcion) {
            case 1:
                ingresarProducto(productosNombres, productosCantidades, productosPrecios, &numProductos);
                break;
            case 2:
                modificarProducto(productosNombres, productosCantidades, productosPrecios, numProductos);
                break;
            case 3:
                eliminarProducto(productosNombres, productosCantidades, productosPrecios, &numProductos);
                break;
            case 4:
                consultarProducto(productosNombres, productosCantidades, productosPrecios, numProductos);
                break;
            case 5:
                adicionarCompraProducto(productosNombres, productosCantidades, numProductos);
                break;
            case 6:
                verProductos(productosNombres, productosCantidades, productosPrecios, numProductos);
                break;
            case 7:
                {
                    char cedula[MAX_CEDULA];
                    printf("Ingresar cedula del cliente: ");
                    scanf("%s", cedula);
                    if (validarCedulaEcuatoriana(cedula)) {
                        ingresarCliente(clientesCedulas, clientesNombres, &numClientes);
                    } else {
                        printf("Cedula invalida.\n");
                    }
                }
                break;
            case 8:
                modificarCliente(clientesCedulas, clientesNombres, numClientes);
                break;
            case 9:
                consultarCliente(clientesCedulas, clientesNombres, numClientes);
                break;
            case 10:
                verListadoClientes(clientesCedulas, clientesNombres, numClientes);
                break;
            case 11:
                facturar(facturasFecha, facturasCedula, facturasNombre, facturasValor, facturasCantidad, &numFacturas, productosNombres, productosCantidades, productosPrecios, numProductos, clientesCedulas, clientesNombres, numClientes);
                break;
            case 12:
                buscarFactura(facturasFecha, facturasCedula, facturasNombre, facturasValor, facturasCantidad, numFacturas);
                break;
            case 13:
                verListadoFacturas(facturasFecha, facturasCedula, facturasNombre, facturasValor, facturasCantidad, numFacturas);
                break;
            case 14:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while(opcion != 14);

    return 0;
}
