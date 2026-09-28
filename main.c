#include <stdio.h>

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

typedef struct
{
    Client client[20];
    int nombre_client;
} Clients;

/**
 * Recherche si dans le tableau de Client un client existe déja sur base de son numéro
 * Si le client n'existe pas encore -> on l'ajoute et on l'inscrémente au compteur.
 *
 *@param *clients le pointeur qui contient l'adresse de la structure contenant le tableau de client
 *@param *client le pointeur qui contient l'adresse de la structure client dont on cherche si il son numéro existe déja
 *@return renvoie le numéro du client qui existe, 0 sinon.
 */
int cherche_client(Clients *clients, Client *client)
{

    // on parcours de 0 au nombre de clients dans la structure
    for (int i = 0; i < clients->nombre_client; i++)
    {
        // si le numéro d'un des clients du tableau est le même que le client a chercher -> renvoie 1
        if ((clients->client + i)->numero == client->numero)
        {

            return i;
        }
    }

    return 0;
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
int ajouter_Client(Clients *clients, Client *client)
{

    // si le compteur est inférieur à 20
    if (clients->nombre_client < 20)
    {
        // si le numéro existe déja dans la liste
        if (cherche_client(clients, client) == 0)
        {

            // on ajoute le client et on incrémente
            // on ajoute le client à l'index nombre_client et on incrémente le compteur
            clients->client + clients->nombre_client = client;

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
 * @return 1 si le client a bien été supprimé au tableau, 0 sinon.
 */
int supprimer_client(Clients *clients, Client *client){

    //on récupère l'indice du client a supprimer dans le tableau
    int client_a_supprimer = cherche_client(clients, client);

    //on supprimer le client dans le tableau de la structure clients
    clients->client + client_a_supprimer = 


}









int main()
{
    printf("Hello, World!\n");
    return 0;
}
