



/**
 * Je créé 2 structure : Client -> possède : un numéro, un nom, un prenom et une adresse
 *
 *                       Clients -> possède : un tableau contenant max 20 Client et un compteur
 *
 */
typedef struct
{
    int numero;
    char nom[40];
    char prenom[30];
    char adresse[80];
} Client;