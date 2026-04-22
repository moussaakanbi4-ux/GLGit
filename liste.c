#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include "pathway.h"

struct element {
    struct element *next;
    void* contenu;
};

liste creerliste() {
    liste l = (liste) malloc (sizeof(struct element));
    l->next=NULL;
    l->contenu=(void *) malloc (sizeof(void *));
    return l;
}

void ajouter(liste l, void* element) {
    liste tmp=l;
    while (tmp->next!=NULL) {
        tmp=tmp->next;
    }
    tmp->contenu=element;
    liste nouvellecase = creerliste();
    tmp->next=nouvellecase;
    //l=tmp;
}

liste supprimer(liste l, void* cible) {
    if (l == NULL) return NULL;

    liste courant = l;
    liste precedent = NULL;

    while (courant != NULL && courant->contenu != cible) {
        precedent = courant;
        courant = courant->next;
    }

    if (courant == NULL) return l;

    if (precedent == NULL) {
        l = courant->next;
    }
    else {
        precedent->next = courant->next;
    }

    free(courant);
    return l;
}
  

void afficherliste(liste l) {
    liste tmp = l;
    while (tmp != NULL) {
        affichage_voie(tmp->contenu);
        tmp = tmp->next;
    }
}

int case_vide(liste l) {
    return (int)(l->next==NULL);
}

liste case_suivante(liste l) {
    return (l->next);
}

ptr_pathway retourcontenu(liste l) {
    return (l->contenu);
}
