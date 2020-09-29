#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED

struct EstructuraSucursales
{
    char codigo[5];
    char provincia[20];
    int cantidad_articulos;
    float monto_mensual;
    float m_cuadrados;
    char casa_matriz[5];
};

//typedef struct EstructuraSucursales* Sucursal;

void crearSucursal (EstructuraSucursales* sucur,char codigo[5], char Provincia[20],int Articulos, float MontoMensual, float mCuadrados, char casa_matriz[5]);
void nuevoSucursal(EstructuraSucursales *sucur,char codigo[5], char provincia[20],int articulos, float montoMensual, float mCuadrados, char casaMatriz[5]);

void destruirSucursal(EstructuraSucursales* sucur);

char *getCodigo (EstructuraSucursales* sucur);
void setCodigo (EstructuraSucursales* sucur, char NewCodigo[5]);

char *getProvincia(EstructuraSucursales* sucur);
void setProvincia(EstructuraSucursales* sucur,char NewProvincia[20]);

int getCantidadArticulos(EstructuraSucursales* sucur);
void setCantidadArticulos(EstructuraSucursales* sucur, int NewCantidad);

float getMontoMensual(EstructuraSucursales* sucur);
void setMontoMensual (EstructuraSucursales* sucur, float NewMontoMensual);

float getMCuadrados(EstructuraSucursales* sucur);
void setMCuadrados (EstructuraSucursales* sucur,float NewMetros);

char *getCasaMatriz(EstructuraSucursales* sucur);
void setCasaMatriz(EstructuraSucursales* sucur, char NewCasaMatriz[5]);

void mostrarSucursal (EstructuraSucursales* sucur);

#endif // TDA_H_INCLUDED
