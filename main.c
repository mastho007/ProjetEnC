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


/**
 * Contient la liste des clients avec (la liste clients, nombre de clients)
 * 
 */
typedef struct
{
    Client client[20];
    int nombre_client;
} Clients;



void initialise_clients(Clients *clients, Client client[20], int nombre_client){


    
}










/**
 * Recherche si dans le tableau de Client un client existe déja sur base de son numéro
 * Si le client n'existe pas encore -> on l'ajoute et on l'inscrémente au compteur.
 *
 *@param *clients le pointeur qui contient l'adresse de la structure contenant le tableau de client
 *@param *client le pointeur qui contient l'adresse de la structure client dont on cherche si il son numéro existe déja
 *@return renvoie le numéro du client qui existe, -1 sinon.
 */
int cherche_client(Clients *clients, Client *client)
{

    // on parcours de 0 au nombre de clients dans la structure
    for (int i = 0; i < clients->nombre_client; i++)
    {
        // si le numéro d'un des clients du tableau est le même que le client a chercher -> renvoie 1
        if (clients->client[i].numero == client->numero)
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
int ajouter_Client(Clients *clients, Client *client)
{

    // si le compteur est inférieur à 20
    if (clients->nombre_client < 20)
    {
        // si le numéro existe déja dans la liste
        if (cherche_client(clients, client) == -1)
        {

            // on ajoute le client à l'indice nombre_client et on incrémente
            // on ajoute le client à l'index nombre_client et on incrémente le compteur
            clients->client[clients->nombre_client] = *client;

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
int supprimer_client(Clients *clients, Client *client)
{

    // on récupère l'indice du client a supprimer dans le tableau
    int index_supp = cherche_client(clients, client);

    if (index_supp != -1)
    {

        // on décale les éléments après le client d'intéret d'un case en moins de façon à supprimer la case du client à supprimer
        for (int j = index_supp; j < clients->nombre_client - 1; j++)
        {

            clients->client[j] = clients->client[j + 1];
        }

        clients->nombre_client--;

        return 1;
    }

    // si le numéro n'a pas été trouvé
    return -1;
}

/**
 * On affiche les différents clients sur base de leurs info (numero, nom, prenom, adresse)
 *
 */
void afficher_clients(Clients *clients)
{

    printf("%7s|\t%20s|\t%20s|\t%20s|\n", "numero", "nom", "prenom", "adresse");

    // on passe en revue tout les clients
    for (int i = 0; i < clients->nombre_client; i++)
    {

        printf("%7d|\t%20s|\t%20s|\t%20s|\n", ((clients->client) + i)->numero,
               ((clients->client) + i)->nom, ((clients->client) + i)->prenom, ((clients->client) + i)->adresse);
    }
}

int main()
{
    Client c1 = {1, "Hausmann", "Thomas", "rue du paradis"};

    Client c2 = {2, "Leduc", "Brian", "rue du paradis"};

    Clients liste_clients = {{}, 0};

    ajouter_Client(&liste_clients, &c1);

    ajouter_Client(&liste_clients, &c2);

    supprimer_client(&liste_clients, &c2);

    afficher_clients(&liste_clients);



    return 0;
}
