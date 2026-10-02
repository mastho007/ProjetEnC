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
        {
            // on choisi d'afficher les clients
            afficher_liste_clients(&clients);
            break;
        }
        case 2:
        {
            // on ajoute un client
            Client nouv_client;
            saisir_Client(&nouv_client);
            int resultat = ajouter_Client(&clients, &nouv_client);
            afficherNotification(resultat, "ajout d'un client");

            break;
        }
        case 3:
        {
            // on supprime un client
            Client supp_client;
            int numero_client = inserer_numero_client();
            // sur base du numéro client on récupère la structure client
            supp_client.numero = numero_client;
            int resultat = supprimer_client(&clients, &supp_client);

            afficherNotification(resultat, "supprimer un client");

            break;
        }
        case 4:
        {
            // on recherche un client
            // on récupère son numéro
            Client temp;
            int numero_client = inserer_numero_client();
            // sur base du numéro client on récupère la structure client
            temp.numero = numero_client;

            int index_client = cherche_client(&clients, &temp);
            // si le client existe bien -> on affiche cellui ci
            if (index_client != -1)
            {

                afficher_client(&getClients(&clients)[index_client]);
            }
            else
            {

                afficherNotification(0, "Afficher client");
            }

            break;
        }

        case 5:
        {
            // on quitte le menu
            afficher_fin_de_partie();

            choix = 5;

            break;
        default:
            afficher_mauvais_choix();

            break;
        }
        }
    }

    return 0;
}
