#include "Client.h"
#include "Clients.h"
#include "Console.h"
int main()
{
    // on déclare la liste clients qui ne contient aucun client au départ
    Clients clients;

    initialise_clients(&clients, nullptr, 0);

    int choix = 0;

    // on créé un choix de menu entre les différentes opérations à réaliser
    while (choix != 5)
    {

        choix = afficher_menu(choix);

        switch (choix)
        {
        case 1:
            // on choisi d'afficher les clients
            afficher_liste_clients(&clients);

            break;
        case 2:
            // on ajoute un client
            Client nouv_client;
            saisir_Client(&nouv_client);
            int resultat = ajouter_Client(&clients, &nouv_client);
            afficherNotification(resultat, "ajout d'un client");

            break;
        case 3:

            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        default:
            break;
        }
    }

    return 0;
}
