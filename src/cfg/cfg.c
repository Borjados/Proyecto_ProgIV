#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/cJSON/cJSON.h"
#include "cfg.h"

/* leer contenido de un fichero y volcarlo a un struct de cJSON */
int leer_fichero_json(cJSON **json, char *ruta) {

    // Leer el contenido de $ruta y guardarlo en $buffer
    char *buffer = 0;
    int length;
    FILE *file = fopen (ruta, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer) {
            fread(buffer, 1, length, file);
        }
        fclose(file);
    }

    if (!buffer) {
        // error leyendo buffer
        return 1;
    }

    *json = cJSON_ParseWithLength(buffer, length);
    if (!*json) {
        // error parseando JSON
        free(buffer);
        return 1;
    }

    free(buffer);

    return 0;
}

int leer_configuracion(Config *config)
{
    // $json es el objecto JSON principal
    cJSON *json = NULL;
    // $campo se usa como variable temporal
    cJSON *campo = NULL;
    int error;

    error = leer_fichero_json(&json, FICHERO_CONFIGURACION);
    if (error) {
        printf("Error leyendo fichero de configuracion\n");
    }

    campo = cJSON_GetObjectItem(json, "usuarioAdmin");
    config->usuarioAdmin = strdup(campo->valuestring);
    campo = cJSON_GetObjectItemCaseSensitive(json, "contrasenyaAdmin");
    config->contrasenyaAdmin = strdup(campo->valuestring);
    campo = cJSON_GetObjectItemCaseSensitive(json, "nombreBD");
    config->nombreBD = strdup(campo->valuestring);
    campo = cJSON_GetObjectItemCaseSensitive(json, "rutaBD");
    config->rutaBD = strdup(campo->valuestring);

    // liberar la memoria
    cJSON_Delete(json);

    return 0;
}
