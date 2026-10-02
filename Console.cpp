#include "Console.h"
#include <stdio.h>

/**
 * Affiche le menu principale du main
 * 1.Afficher tout les clients
 * 2. Ajouter un client
 * 3. Supprimer un client
 * 4. Rechercher un client
 * 5. Quitter
 * @param choix est le numéro qui réprésente l'opération choisie par l'utilisateur.
 * @return un entier qui contient le choix de l'utilisateur
 */
int afficher_menu(int choix)
{
    printf("Veillez choisir une operation : \n");
    printf("1.Afficher tout les clients \n2. Ajouter un client\n3. Supprimer un client\n4. Rechercher un client\n5. Quitter");
    scanf("%d", &choix);
    fflush(stdin);
    return choix;
}

/**
 * Affiche un message de succès si le résultat est 1, si c'est 0 alors message d'erreur.
 * @param resultat de l'opération soit 1 ou 0.
 * @param *opération est le pointeur de tableau de char qui contient le type d'opération utilisée.
 */
void afficherNotification(int resultat, const char *operation)
{

    (resultat == 1) ? printf("L'opération %s s'est déroulé avec succès.", operation) : printf("L'opération %s a échouée.", operation);
}

void afficher_fin_de_partie()
{

    printf("Fin de partie.");
}

void afficher_mauvais_choix()
{

    printf("Vous devez choisir un nombre entre 1 et 5 inclus, Veuillez réessayez.");
}

/**
 * Sur base du tableau transmis via pointeur on vient récupérer le numéro du client que l'utilisateur a choisiµ
 * @return renvoi un entier qui est le numéro du client
 */
int inserer_numero_client()
{

    int numero_client;

    printf("Insérer un numéro client : ");
    scanf("%d", &numero_client);
    fflush(stdin);

    return numero_client;
}

/**
 * Sur base d'un pointeur qui pointe vers un client, on récupère ses données et on affiche celle ci.
 * @param *Client le pointeur qui pointe vers la structure Client qui contient les infos.
 */
void afficher_client(const Client *client)
{
    // on vérif pointeur non null
    if (client != nullptr)
    {

        printf("%7s|\t%20s|\t%20s|\t%20s|\t%20s\n", "numero", "nom", "prenom", "adresse", "Frequentation");

        printf("%7d|\t%20s|\t%20s|\t%20s|\t%20s\n", getNumero(client), getNom(client), getPrenom(client), getAdresse(client), getFrequentation(client));
    }
    else
    {

        afficherNotification(0, "Afficher client");
    }
}

/**
 * Affiche pour chaque client son (numero, nom, prenom, adresse, frequentation)
 *
 */
void afficher_liste_clients(const Clients *clients)
{

    // on vérif pointeur non null
    if (clients != nullptr)
    {

        // on passe en revue tout les clients
        for (int i = 0; i < getNombreClient(clients); i++)
        {

            afficher_client(&clients->client[i]);
        }
    }
}

/**
 * On récupère sur base des saisie de l'utilisateur :
 * - numero, nom, prenom, adresse et fréquentation du client
 * - on l'initialise grace à la fonction Client et on revoi un pointeur qui contient la structure initialisée
 * @param *client un pointeur client qui sera utiliser pour stocker les info de la saisie Client
 */
void saisir_Client(Client *client)
{
    // on vérif pointeur non null
    if (client != nullptr)
    {

        int numero;
        char nom[40];
        char prenom[30];
        char adresse[80];
        int choix;
        Frequentation statut;

        printf("Pour créé un client veuillez : \n");
        printf("insérer un numéro client : ");
        scanf("%d", &numero);
        printf("insérer un nom de client : ");
        scanf("%s", nom);
        printf("insérer un prénom : ");
        scanf("%s", prenom);
        fflush(stdin);
        printf("insérer un adresse de client : ");
        fgets(adresse, sizeof(adresse), stdin);

        printf("1. %s\n2. %s\n3. %s\n", "TRES_REGULIER", "REGULIER", "OCCASIONEL");
        printf("choisir un statut de fréquentation : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            statut = TRES_REGULIER;
            break;
        case 2:
            statut = REGULIER;
            break;
        case 3:
            statut = OCCASIONEL;
            break;
        default:
            statut = INCONNU;
        }

        init_client(client, numero, nom, prenom, adresse, statut);
    }
}
