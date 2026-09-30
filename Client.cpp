#include "Client.h"
#include <string.h>

/**
 * Sur base du pointeur Client contenant les infos on charge ces infos dans l'objet
 * @param *nouv_client est le pointeur vers la structure client par laquelle on souhaite initialiser l'objet
 * via ses différents composants (numero, nom, prenom, adresse, statut).
 *
 */
void init_client(Client *nouv_client, int numero, const char *nom, const char *prenom, const char *adresse, Frequentation statut)
{
    // on s'assure que le pointeur n'est pas null
    if (nouv_client != nullptr)
    {

        nouv_client->numero = numero;
        //on s'assure que les tableau nom, adresse, prenom occupent bien la taille de la structure
        strncpy(nouv_client->nom, nom, sizeof(nouv_client->nom) - 1);
        strncpy(nouv_client->prenom, prenom, sizeof(nouv_client->prenom) - 1);
        strncpy(nouv_client->adresse, adresse, sizeof(nouv_client->adresse) - 1);

        //on s'assure que la dernière case soit bien '\0'
        nouv_client->nom[sizeof(nouv_client->nom) - 1] = '\0';
        nouv_client->prenom[sizeof(nouv_client->prenom) - 1] = '\0';
        nouv_client->adresse[sizeof(nouv_client->adresse) - 1] = '\0';

        nouv_client->statut = statut;
    }
}

/**
 * Renvoi le numéro du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un entier qui est le numéro du client, si le pointeur client est null -> renvoi -1.
 */
int getNumero(const Client *client)
{

    return (client == nullptr) ? -1 : client->numero;
}

/**
 * Renvoi le nom du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un pointeur constant de type char, si le client est null -> renvoie nullptr
 */
const char *getNom(const Client *client)
{

    return (client == nullptr) ? nullptr : client->nom;
}

/**
 * Renvoi le prenom du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un pointeur constant de type char, si le client est null -> renvoie nullptr
 */
const char *getPrenom(const Client *client)
{

    return (client == nullptr) ? nullptr : client->prenom;
}

/**
 * Renvoi l'adresse du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un pointeur constant de type char, si le client est null -> renvoie nullptr
 */
const char *getAdresse(const Client *client)
{

    return (client == nullptr) ? nullptr : client->adresse;
}

/**
 * Renvoi le numéro du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return une constante Frequentation qui est le statut du client, renvoie INCONNU si le client est un ptr null.
 */
Frequentation getFrequentation(const Client *client)
{

    return (client == nullptr) ? INCONNU : client->statut;
}
