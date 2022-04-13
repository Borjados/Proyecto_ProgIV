#include "../../lib/cJSON/cJSON.h"

#ifndef PROYECTO_PROGIV_CFG_H
#define PROYECTO_PROGIV_CFG_H

#define FICHERO_CONFIGURACION "config.json"

// Estructura de configuracion, anadir los campos que hagan falta.
// Recordar leer los campos nuevos en leer_configuracion
typedef struct Config {
    char *usuarioAdmin;
    char *contrasenyaAdmin;
    char *nombreBD;
    char *rutaBD;
} Config;

int leer_fichero_json(cJSON **json, char *ruta);
int leer_configuracion(Config *config);

#endif //PROYECTO_PROGIV_CFG_H
