// création d'une enum pour les différents type de fréquentation d'un client (très régulier, régulier, occasionel)
typedef enum
{
    TRES_REGULIER = 1,
    REGULIER = 2,
    OCCASIONEL = 3,
    INCONNU = 4
} Frequentation;

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
    Frequentation statut;
} Client;

/**
 * Sur base du pointeur Client contenant les infos on charge ces infos dans l'objet
 * @param *nouv_client est le pointeur vers la structure client par laquelle on souhaite initialiser l'objet
 * via ses différents composants (numero, nom, prenom, adresse, statut).
 *
 */
void init_client(Client *nouv_client, int numero, const char *nom, const char *prenom, const char *adresse, Frequentation statut);


/**
 * Renvoi le numéro du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un entier qui est le numéro du client, si le pointeur client est null -> renvoi -1.
 */
int getNumero(const Client *client);
/**
 * Renvoi le nom du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un pointeur constant de type char, si le client est null -> renvoie nullptr
 */
const char *getNom(const Client *client);
/**
 * Renvoi le prenom du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un pointeur constant de type char, si le client est null -> renvoie nullptr
 */
const char *getPrenom(const Client *client);

/**
 * Renvoi l'adresse du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return un pointeur constant de type char, si le client est null -> renvoie nullptr
 */
const char *getAdresse(const Client *client);
/**
 * Renvoi le numéro du client et le pointeur ne doit pas être null
 *
 * @param *client est le pointeur du client qui contient l'info
 * @return une constante Frequentation qui est le statut du client, renvoie INCONNU si le client est un ptr null.
 */
Frequentation getFrequentation(const Client *client);