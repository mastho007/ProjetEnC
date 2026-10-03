#ifndef CLIENTS_H
#define CLIENTS_H
#include "Client.h"

/**
 * Contient la liste des clients avec (la liste clients, nombre de clients)
 *
 */
typedef struct
{
    Client client[20];
    int nombre_client;
} Clients;

/**
 * Initialise la structure Clients sur base de son tableau de clients et son compteur
 * @param *clients le pointeur qui pointe vers la structure Clients
 * @param client le tableau clients qui contient les différents clients
 * @param nombre_client le compteur du nombre de clients
 */
void initialise_clients(Clients *clients, const Client *client, int nombre_client);

/**
 * Récupère le tableau de clients
 * Revoie un pointeur qui pointe vers le tableau client
 */
const Client *getClients(const Clients *clients);

/**
 * Renvoie le nombre de clients du tableau et -1 si le pointeur clients est null
 */
int getNombreClient(const Clients *clients);
/**
 * Recherche si dans le tableau de Client un client existe déja sur base de son numéro
 * Si le client n'existe pas encore -> on l'ajoute et on l'inscrémente au compteur.
 *
 *@param *clients le pointeur qui contient l'adresse de la structure contenant le tableau de client
 *@param *client le pointeur qui contient l'adresse de la structure client dont on cherche si il son numéro existe déja
 *@return renvoie le numéro du client qui existe, -1 sinon.
 */
int cherche_client(const Clients *clients, const Client *client);

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
int ajouter_Client(Clients *clients, const Client *client);

/**
 * On supprime un client à la structure clients :
 *
 *
 * @param *clients est un pointeur de la structure du Clients qui contient le tableau de client
 * @param *client est un pointeur de la structure du client, c'est le client à supprimer
 * @return 1 si le client a bien été supprimé au tableau, -1 sinon.
 */
int supprimer_client(Clients *clients, const Client *client);


#endif
