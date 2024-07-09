#include <stdio.h>
#include <string.h>
#include "operaciones.h"
#include "lecturas.h"

int validarCedulaEcuatoriana(const char *cedula) {
    if (strlen(cedula) != 10) {
        return 0;
    }

    int provincia = (cedula[0] - '0') * 10 + (cedula[1] - '0');
    if (provincia < 1 || provincia > 24) {
        return 0;
    }

    int tercer_digito = cedula[2] - '0';
    if (tercer_digito > 6) {
        return 0;
    }

    int suma_pares = 0, suma_impares = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            int valor = digito * 2;
            if (valor > 9) valor -= 9;
            suma_impares += valor;
        } else {
            suma_pares += digito;
        }
    }

    int total = suma_pares + suma_impares;
    int digito_verificador = total % 10 == 0 ? 0 : 10 - (total % 10);

    return (cedula[9] - '0') == digito_verificador;
}

void ingresarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos) {
    printf("Ingresar nombre del producto: ");
    scanf("%s", nombres[*numProductos]);
    cantidades[*numProductos] = leerEnteroPositivo("Ingresar cantidad: ");
    precios[*numProductos] = leerFlotantePositivo("Ingresar precio: ");
    (*numProductos)++;
}

void modificarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos) {
    char nombre[MAX_NOMBRE];
    printf("Ingresar nombre del producto a modificar: ");
    scanf("%s", nombre);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            cantidades[i] = leerEnteroPositivo("Ingresar nueva cantidad: ");
            precios[i] = leerFlotantePositivo("Ingresar nuevo precio: ");
            printf("Producto modificado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos) {
    char nombre[MAX_NOMBRE];
    printf("Ingresar nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < *numProductos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            for (int j = i; j < *numProductos - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            (*numProductos)--;
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void consultarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos) {
    char nombre[MAX_NOMBRE];
    printf("Ingresar nombre del producto a consultar: ");
    scanf("%s", nombre);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            printf("Producto: %s, Cantidad: %d, Precio: %.2f\n", nombres[i], cantidades[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void adicionarCompraProducto(char nombres[][MAX_NOMBRE], int cantidades[], int numProductos) {
    char nombre[MAX_NOMBRE];
    printf("Ingresar nombre del producto a aumentar stock: ");
    scanf("%s", nombre);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            cantidades[i] += leerEnteroPositivo("Ingresar cantidad a adicionar: ");
            printf("Stock aumentado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void verProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("Producto: %s, Cantidad: %d, Precio: %.2f\n", nombres[i], cantidades[i], precios[i]);
    }
}

void ingresarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int *numClientes) {
    char nuevaCedula[MAX_CEDULA];
    char nuevoNombre[MAX_NOMBRE];
    printf("Ingresar cedula del cliente: ");
    scanf("%s", nuevaCedula);
    printf("Ingresar nombre del cliente: ");
    scanf("%s", nuevoNombre);

    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(cedulas[i], nuevaCedula) == 0) {
            printf("Cliente con esta cedula ya existe.\n");
            return;
        }
    }

    strcpy(cedulas[*numClientes], nuevaCedula);
    strcpy(nombres[*numClientes], nuevoNombre);
    (*numClientes)++;
}

void modificarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int numClientes) {
    char cedula[MAX_CEDULA];
    printf("Ingresar cedula del cliente a modificar: ");
    scanf("%s", cedula);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            printf("Ingresar nuevo nombre: ");
            scanf("%s", nombres[i]);
            printf("Cliente modificado exitosamente.\n");
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

void consultarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int numClientes) {
    char cedula[MAX_CEDULA];
    printf("Ingresar cedula del cliente a consultar: ");
    scanf("%s", cedula);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            printf("Cliente: %s, Cedula: %s\n", nombres[i], cedulas[i]);
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

void verListadoClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int numClientes) {
    for (int i = 0; i < numClientes; i++) {
        printf("Cliente: %s, Cedula: %s\n", nombres[i], cedulas[i]);
    }
}

void facturar(char facturasFecha[][MAX_FECHA], char facturasCedula[][MAX_CEDULA], char facturasNombre[][MAX_NOMBRE], float facturasValor[], int facturasCantidad[], int *numFacturas, char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos, char cedulas[][MAX_CEDULA], char clientesNombres[][MAX_NOMBRE], int numClientes) {
    char fecha[MAX_FECHA];
    char cedula[MAX_CEDULA];
    char nombreProducto[MAX_NOMBRE];
    int cantidadComprada;

    printf("Ingresar fecha de la factura (dd/mm/yyyy): ");
    scanf("%s", fecha);
    printf("Ingresar cedula del cliente: ");
    scanf("%s", cedula);

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            strcpy(facturasNombre[*numFacturas], clientesNombres[i]);
            clienteEncontrado = 1;
            break;
        }
    }
    if (!clienteEncontrado) {
        printf("Cliente no encontrado.\n");
        return;
    }

    printf("Ingresar nombre del producto: ");
    scanf("%s", nombreProducto);

    int productoEncontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreProducto) == 0) {
            printf("Ingresar cantidad de productos comprados: ");
            cantidadComprada = leerEnteroPositivo("");
            if (cantidadComprada <= cantidades[i]) {
                cantidades[i] -= cantidadComprada;
                facturasCantidad[*numFacturas] = cantidadComprada;
                facturasValor[*numFacturas] = cantidadComprada * precios[i];
                strcpy(facturasFecha[*numFacturas], fecha);
                strcpy(facturasCedula[*numFacturas], cedula);
                (*numFacturas)++;
                printf("Factura creada exitosamente.\n");
                productoEncontrado = 1;
                return;
            } else {
                printf("Stock insuficiente.\n");
                return;
            }
        }
    }
    if (!productoEncontrado) {
        printf("Producto no encontrado.\n");
    }
}

void buscarFactura(char facturasFecha[][MAX_FECHA], char facturasCedula[][MAX_CEDULA], char facturasNombre[][MAX_NOMBRE], float facturasValor[], int facturasCantidad[], int numFacturas) {
    char fecha[MAX_FECHA];
    printf("Ingresar fecha de la factura a buscar (dd/mm/yyyy): ");
    scanf("%s", fecha);

    for (int i = 0; i < numFacturas; i++) {
        if (strcmp(facturasFecha[i], fecha) == 0) {
            printf("Factura encontrada: Fecha: %s, Cedula: %s, Nombre: %s, Valor pagado: %.2f, Cantidad comprada: %d\n",
                   facturasFecha[i], facturasCedula[i], facturasNombre[i], facturasValor[i], facturasCantidad[i]);
            return;
        }
    }
    printf("Factura no encontrada.\n");
}

void verListadoFacturas(char facturasFecha[][MAX_FECHA], char facturasCedula[][MAX_CEDULA], char facturasNombre[][MAX_NOMBRE], float facturasValor[], int facturasCantidad[], int numFacturas) {
    for (int i = 0; i < numFacturas; i++) {
        printf("Factura: Fecha: %s, Cedula: %s, Nombre: %s, Valor pagado: %.2f, Cantidad comprada: %d\n",
               facturasFecha[i], facturasCedula[i], facturasNombre[i], facturasValor[i], facturasCantidad[i]);
    }
}

