#include "Client.h"
#include "Clients.h"


/**
 * Sur base d'un pointeur qui pointe vers un client, on récupère ses données et on affiche celle ci.
 * @param *Client le pointeur qui pointe vers la structure Client qui contient les infos.
 */
void afficher_client(const Client *client);
/**
 * Affiche pour chaque client son (numero, nom, prenom, adresse, frequentation)
 *
 */
void afficher_liste_clients(const Clients *clients);

/**
 * On récupère sur base des saisie de l'utilisateur :
 * - numero, nom, prenom, adresse et fréquentation du client
 * - on l'initialise grace à la fonction Client et on revoi un pointeur qui contient la structure initialisée
 * @param *client un pointeur client qui sera utiliser pour stocker les info de la saisie Client
 */
void saisir_Client(Client *client);
