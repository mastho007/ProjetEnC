#ifndef CONSOLE_H
#define CONSOLE_H

#include "Clients.h"

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
int afficher_menu(int choix);

/**
 * Affiche un message de succès si le résultat est 1, si c'est 0 alors message d'erreur.
 * @param resultat de l'opération soit 1 ou 0.
 * @param *opération est le pointeur de tableau de char qui contient le type d'opération utilisée.
 */
void afficherNotification(int resultat, const char *operation);

/**
 * Sur base du tableau transmis via pointeur on vient récupérer le numéro du client que l'utilisateur a choisiµ
 * @return renvoi un entier qui est le numéro du client
 */
int inserer_numero_client();


void afficher_fin_de_partie();

void afficher_mauvais_choix();



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


#endif