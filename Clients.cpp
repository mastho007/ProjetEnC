#include "Client.h"
#include "Clients.h"

/**
 * Initialise la structure Clients sur base de son tableau de clients et son compteur
 * @param *clients le pointeur qui pointe vers la structure Clients
 * @param client le tableau clients qui contient les différents clients
 * @param nombre_client le compteur du nombre de clients
 */
void initialise_clients(Clients *clients, const Client *client, int nombre_client)
{

    if (clients != nullptr && client != nullptr)
    {
        //on vérif si le nombre de clients n'est pas soit inférieur à 0 et supérieur à 20
        if (nombre_client > 20)
        {
            nombre_client = 20;
        }

        if (nombre_client < 0)
        {
            nombre_client = 0;
        }

        // on insère les différents clients dans le tableau de la structure clients
        for (int i = 0; i < nombre_client; i++)
        {
            // il faut aussi que je vérif si un client est null?
            clients->client[i] = client[i];
        }

        clients->nombre_client = nombre_client;
    }
}

/**
 * Récupère le tableau de clients
 * Revoie un pointeur qui pointe vers le tableau client
 */
const Client *getClients(const Clients *clients)
{

    return (clients == nullptr) ? nullptr : clients->client;
}

/**
 * Renvoie le nombre de clients du tableau et -1 si le pointeur clients est null
 */
int getNombreClient(const Clients *clients)
{

    return (clients == nullptr) ? -1 : clients->nombre_client;
}

/**
 * Recherche si dans le tableau de Client un client existe déja sur base de son numéro
 * Si le client n'existe pas encore -> on l'ajoute et on l'inscrémente au compteur.
 *
 *@param *clients le pointeur qui contient l'adresse de la structure contenant le tableau de client
 *@param *client le pointeur qui contient l'adresse de la structure client dont on cherche si il son numéro existe déja
 *@return renvoie le numéro du client qui existe, -1 sinon.
 */
int cherche_client(const Clients *clients, const Client *client)
{

    // on parcours de 0 au nombre de clients dans la structure
    for (int i = 0; i < getNombreClient(clients); i++)
    {

        // si le numéro d'un des clients du tableau est le même que le client a chercher -> renvoie 1
        // je ne sais pas comment utiliser getNumero pour la liste CLients
        if (getNumero(&clients->client[i]) == getNumero(client))
        {

            return i;
        }
    }

    return -1;
}

/**
 * On ajoute un client à la structure clients :
 *
 * respect de 2 condition :
 * - le tableau ne doit pas être plein.
 * - le numéro du client n'existe pas encore.
 *
 * On ajoute alors à la dernière case le Client Et on incrémente le compteur de client
 * @param *clients est un pointeur de la structure du Clients qui contient le tableau de client
 * @param *client est un pointeur de la structure du client, c'est le client à ajouter
 * @return 1 si le client a bien été ajouté au tableau, 0 sinon.
 */
int ajouter_Client(Clients *clients, const Client *client)
{

    // si le compteur est inférieur à 20
    if (getNombreClient(clients) < 20 && clients != nullptr && client != nullptr)
    {
        // si le numéro existe déja dans la liste
        if (cherche_client(clients, client) == -1)
        {

            // on ajoute le client à l'indice nombre_client et on incrémente
            // on ajoute le client à l'index nombre_client et on incrémente le compteur
            clients->client[getNombreClient(clients)] = *client;

            clients->nombre_client++;

            return 1;
        }
    }

    return 0;
}

/**
 * On supprime un client à la structure clients :
 *
 *
 * @param *clients est un pointeur de la structure du Clients qui contient le tableau de client
 * @param *client est un pointeur de la structure du client, c'est le client à supprimer
 * @return 1 si le client a bien été supprimé au tableau, -1 sinon.
 */
int supprimer_client(Clients *clients, const Client *client)
{
    if (clients != nullptr && client != nullptr)
    {

        // on récupère l'indice du client a supprimer dans le tableau
        int index_supp = cherche_client(clients, client);

        if (index_supp != -1)
        {

            // on décale les éléments après le client d'intéret d'un case en moins de façon à supprimer la case du client à supprimer
            for (int j = index_supp; j < getNombreClient(clients) - 1; j++)
            {

                clients->client[j] = clients->client[j + 1];
            }

            clients->nombre_client--;

            return 1;
        }
    }

    // si le numéro n'a pas été trouvé
    return -1;
}
