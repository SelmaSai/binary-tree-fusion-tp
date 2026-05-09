

  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <stdbool.h>

  /** Implémentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai ; // Définition du type d'élément de l'arbre binaire (entier)
  typedef struct Noeud_Ai * Pointeur_Ai ; // Définition d'un pointeur vers un noeud de l'arbre binaire

  struct Noeud_Ai  // STRUCTURE D'UN NOEUD DE L'ARBRE DE RECHERCHE BINAIRE
  {
      Typeelem_Ai  Val ; // Valeur de noeud
      Pointeur_Ai Fg ; // Pointeur vers le fils gauche du noeud
      Pointeur_Ai Fd ; // Pointeur vers le fils droit du noeud
      Pointeur_Ai Pere ; // Pointeur vers le père du noeud
  } Noeud_Ai;

     // Accès au champ Info du noeud référencé par P.

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

    //Accès au champ Fils gauche du noeud référencé par P.

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

    // Accès au champ Fils droit du noeud référencé par P.

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

    //Accès au champ Père du noeud référencé par P.

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

    // Affecter au champ Info du noeud référencé par p, la valeur Val

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
  {
       P->Val = Val ;
  }

   // Affecter au champ Fils gauche du noeud référencé par p, l'adresse Q

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

    // Affecter au champ Fils droit du noeud référencé par p, l'adresse Q

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

    // Affecter au champ Père du noeud référencé par p, l'adresse Q

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

 // Crée un noeud avec champs à NIL et retourne l'adresse

  void Creernoeud_Ai( Pointeur_Ai *P)
  {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
  }

    // Libère le noeud d'adresse P.

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }

  /** Variables du programme principal **/
  Pointeur_Ai A1=NULL;
  Pointeur_Ai B1=NULL;
  Pointeur_Ai A2=NULL;
  Pointeur_Ai B2=NULL;
  Pointeur_Ai A3=NULL;
  Pointeur_Ai B3=NULL;
  Pointeur_Ai A4=NULL;
  Pointeur_Ai B4=NULL;
  Pointeur_Ai A5=NULL;
  Pointeur_Ai B5=NULL;
  Pointeur_Ai Result1=NULL;
  Pointeur_Ai Result2=NULL;
  Pointeur_Ai Result3=NULL;
  Pointeur_Ai Result4=NULL;
  Pointeur_Ai Result5=NULL;
  int N;
  int M;
  int I;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Prototypes des fonctions **/

  void Bienvenue();
  void Inserer_arb (Pointeur_Ai *X , int *Val);
  bool  Existe_arb (Pointeur_Ai *X , int *Val) ;
  void Creer_arb_alea (Pointeur_Ai *A , int *N);
  void Ajouter_alea (Pointeur_Ai *A , int *X);
  Pointeur_Ai Premier_ino (Pointeur_Ai *A) ;
  Pointeur_Ai Premier_post (Pointeur_Ai *A) ;
  Pointeur_Ai Inordre_successeur (Pointeur_Ai *A , Pointeur_Ai *P) ;
  Pointeur_Ai Postordre_successeur (Pointeur_Ai *A , Pointeur_Ai *P) ;
  Pointeur_Ai Preordre_successeur (Pointeur_Ai *A , Pointeur_Ai *P) ;
  void Fusion_pre_pre (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result);
  void Fusion_ino_pos (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result);
  void Fusion_ino_pre (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result);
  void Fusion_pos_pos (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result);
  void Fusion_pre_pos (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result);
  void Inordre (Pointeur_Ai *B);
  bool  Est_bst (Pointeur_Ai *A) ;
  void Nbr_noeuds (Pointeur_Ai *B , int *N);
  void Validation (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result);
  void Nbr_noeuds_Sous_Arb_G(Pointeur_Ai* A, int* N);
  void Nbr_noeuds_Sous_Arb_D(Pointeur_Ai* A, int* N);
  void Liberer_arbre(Pointeur_Ai* A);
  int Nbr_feuilles(Pointeur_Ai A);
  float rapport_feuilles_noeuds(Pointeur_Ai *A);
  int hauteur_max(Pointeur_Ai A);
  int hauteur_gauche(Pointeur_Ai A);
  int hauteur_droite(Pointeur_Ai A);
  int Nbr_noeuds_un_niveau(Pointeur_Ai A, int niveau);
  void Nbr_noeuds_tout_niveaux(Pointeur_Ai A);
  int hauteur_min(Pointeur_Ai A);
  size_t espace_memoire(Pointeur_Ai A);

  /* L'IMPLEMENTATIONS DES FONCTIONS ET DES ACTIONS NECESSAIRES */

  void Bienvenue()
  {

      /** Corps du module **/

     printf ( "\t**************************************************************************************************\n" ) ;
     printf ( "\t*                        BIENVENUE DANS NOTRE TRAVAIL PRATIQUE N 02 - ALSDD                      *\n" ) ;
     printf ( "\t**************************************************************************************************\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                           THEME: FUSION D'ARBRES DE RECHERCHE BINAIRE                          *\n" ) ;
     printf ( "\t*                          ----------------------------------------------                        *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                            REALISE PAR: SAIDI SELMA ET MEZDOUR HEYAM INES                      *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                                    SECTION: D          GROUPE: 11                              *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                                    ANNEE UNIVERSITAIRE: 2022/2023                              *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t*                                                                                                *\n" ) ;
     printf ( "\t**************************************************************************************************\n" ) ;

  }
  /* DES FONCTIONS ET DES PROCEDURES POUR LA GENERATION ET LA MANIPULATION DES ARBRES DE RECHERCHE BINAIRE */
  /* UNE PROCEDURES POUR INSERER UNE VALEUR DANS UN ARBRE DE RECHERCHE BINAIRE QUI PEUT CONTENIR LES DOUBLES */
  void Inserer_arb (Pointeur_Ai *X , int *Val)
  {
      /** Variables locales **/
      Pointeur_Ai Y=NULL;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
    /* SI LA RACINE N'EXISTE PAS C'EST A DIRE L'ARBRE EST VIDE */
     if( ( *X == NULL ))
     {
       Creernoeud_Ai (& *X ) ;
       Aff_info_Ai ( *X , *Val ) ;
     }
     else
     {
      /* SI Val EST SUPPERIEUR A INFO DE RACINE */
       if( ( *Val > Info_Ai ( *X ) ))
       {
        /* SI LE FILS DROIT DE LA RACINE N'EXISTE PAS */
         if( ( Fd_Ai ( *X ) == NULL ))
         {
           Creernoeud_Ai (& Y ) ;
           Aff_info_Ai ( Y , *Val ) ;
           Aff_fd_Ai ( *X , Y ) ;
         }
         else
         {
           _Px1 =  Fd_Ai ( *X ) ;
           Inserer_arb ( &_Px1, & *Val ) ;
          /* INSERTION RECURSIVE DANS LE FILS DROIT DE *P */

         } ;
         }
       else
       {
        /* SI LE FILS GAUCHE DE LA RACINE N'EXISTE PAS */
         if( ( Fg_Ai ( *X ) == NULL ))
         {
           Creernoeud_Ai (& Y ) ;
           Aff_info_Ai ( Y , *Val ) ;
           Aff_fg_Ai ( *X , Y ) ;
         }
         else
         {
           _Px2 =  Fg_Ai ( *X ) ;
           Inserer_arb ( &_Px2, & *Val ) ;
          /* INSERTION RECURSIVE DANS LE FILS GAUCHE DE *P */

         } ;

         } ;

       } ;

    }
  /* UNE FONCTION POUR SAVOIR SI UNE VALEUR EXISTE DEJA DANS L'ARBRE OU NON */
  bool  Existe_arb (Pointeur_Ai *X , int *Val)
  {
      /** Variables locales **/
      bool  Existe2 ;
      bool Exister;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
    /* SI LA RACINE DE L'ARBRE EST NIL */
     if( ( *X == NULL ))
     {
       Exister  =  false ;
      /* AFFECTER FAUX A LA VARIABLE EXISTER */
     }
     else
     {
      /* SI *Val EGALE A L'INFORMATION DE LA RACINE */
       if( ( *Val == Info_Ai ( *X ) ))
       {
        /* AFFECTER VRAI A EXISTER */
         Exister  =  true;
       }
       else
       {
         if( ( *Val < Info_Ai ( *X ) ))
         {
           _Px1 =  Fg_Ai ( *X ) ;
           Exister  =  Existe_arb ( &_Px1, & *Val ) ;
          /* APPEL RECURSIF DE LA FONCTION POUR LE FILS GAUCHE DE LA RACINE */
         }
         else
         {
           _Px2 =  Fd_Ai ( *X ) ;
           Exister  =  Existe_arb ( &_Px2, & *Val ) ;
          /* APPEL RECURSIF DE LA FONCTION POUR LE FILS DROIT DE LA RACINE */

         } ;

         } ;

     } ;
     Existe2  =  Exister ;
    /* RETOURNER EXISTER */

     return Existe2 ;
    }

  /* UNE PROCEDURE POUR AJOUTER UN NOEUD AVEC UNE VALEUR ALEATOIRE X DANS L'ARBRE A */
  void Ajouter_alea (Pointeur_Ai *A , int *X)
  {
      /** Variables locales **/
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;

      /** Corps du module **/
    /* SI LA RACINE EST NIL C'EST *A DIRE L'ARBRE EST VIDE */
     if( ( *A == NULL ))
     {
       Creernoeud_Ai (& Q ) ;
       Aff_info_Ai ( Q , *X ) ;
      /* Q DEVIENT LA RACINE DE L'ARBRE *A */
       *A  =  Q;
     }
     else
     {
       P  =  *A ;
      /* AFFECTER LA RACINE DE L'ARBRE *A *A LA VARIABLE P */
       Q  =  *A ;
      /* AFFECTER LA RACINE DE L'ARBRE *A *A LA VARIABLE Q */
      /* BOUCLE TANT QUE *X DIFFERENT DE INFO DE P ET Q N'EST PAS NIL */
       while( ( *X != Info_Ai ( P ) ) && ( Q != NULL ))
       {
         P  =  Q ;
        /* P RECOIT Q */
        /* SI *X INFERIEUR AU INFO DE NOEUD REFERENCE PAR P */
         if( ( *X < Info_Ai ( P ) ))
         {
          /* PASSER AU FILS GAUCHE DE NOEUD REFERENCE PAR P */
           Q  =  Fg_Ai ( P );
         }
         else
         {
           ;
          /* PASSER AU FILS DROIT DE NOEUD REFERENCE PAR P */
           Q  =  Fd_Ai ( P );
         } ;

       } ;
      /* SI *X EST DIFFERENT DE INFO DE NOEUD REFERENCE PAR P */
       if( ( *X != Info_Ai ( P ) ))
       {
         Creernoeud_Ai (& Q ) ;
         Aff_info_Ai ( Q , *X ) ;
        /* SI *X EST INFERIEUR A INFO DE NOEUD REFERENCE PAR P */
         if( ( *X < Info_Ai ( P ) ))
         {
           Aff_fg_Ai ( P , Q );
         }
         else
         {
           Aff_fd_Ai ( P , Q );
         } ;
         Aff_pere_Ai ( Q , P ) ;

       } ;

     } ;

}

  /* PROCEDURE POUR CREER UN ARBRE DE RECHERCHE BINAIRE AVEC N DONNEES ALEATOIRES */
  void Creer_arbre_alea (Pointeur_Ai *A , int *N)
  {
      /** Variables locales **/
      int I;
      int Val;

      /** Corps du module **/
     *A  =  NULL ;
    /* INITIALISER LA RACINE *A NIL */
     I  =  *N ;
    /* I RECOIT LE NOMBRE DE NOEUDS SOUHAITE */
    /* BOUCLE TANT QUE ON *N'*A PAS ATTEINT LE NOMBRE DE NOEUDS REQUIS */
     while( ( I > 0 ))
     {
       Val  =  Aleanombre(20000 ) ;
      /* VAL RECOIT UN NOMBRE ALEATOIRE DE 0 *A 1000 */
      /* SI LA VALEUR VAL N'EXISTE PAS DANS L'ARBRE *A */
       if( ( Existe_arb ( & *A , & Val ) == false ))
       {
         Ajouter_alea ( & *A , & Val ) ;
        /* ON INSERE VAL DANS L'ARBRE *A */
         I  =  I - 1 ;
        /* DECREMENTER LE COMPTEUR I */

       } ;

     } ;

}

  /* DES FONCTIONS QUI RETOURNE LE PREMIER NOEUD DANS UN PARCOURS D'UN ARBRE BINAIRE DE RECHERCHE */
  /* LE PREMIER PREORDER DANS UN ARBRE DE RECHERCHE BINAIRE EST LA RECINE */
  /* UNE FONCTION QUI RETOURNE LE PREMIER NOEUD DANS LE PARCOURS INORDRE D'UN ARBRE BINAIRE DE RECHERCHE */
  Pointeur_Ai Premier_ino (Pointeur_Ai *A)
  {
      /** Variables locales **/
      Pointeur_Ai Premier_ino2 =NULL;
      Pointeur_Ai P=NULL;

      /** Corps du module **/
     P  =  *A ;
    /* INITIALISER P AVER ARBRE */
    /* BOUCLE TANT QUE LE FILS GAUCHE DE DE NOEUD REFERENCE PAR P N'EST PAS NIL */
     while( ( Fg_Ai ( P ) != NULL ))
     {
      /* PASSER AU FILS GAUCHE DE DE NOEUD REFERENCE PAR P */
       P  =  Fg_Ai ( P );
     } ;
    /* RETOURNER P */
     Premier_ino2  =  P;
     return Premier_ino2 ;
    }
  /* UNE FONCTION QUI RETOURNE LE PREMIER NOEUD DANS LE PARCOURS POSTORDRE D'UN ARBRE BINAIRE DE RECHERCHE */
  Pointeur_Ai Premier_post (Pointeur_Ai *A)
  {
      /** Variables locales **/
      Pointeur_Ai Premier_post2 =NULL;
      Pointeur_Ai P=NULL;
      bool Continue;

      /** Corps du module **/
     P  =  *A ;
    /* INITIALISER P AVEC ARBRE */
     Continue  =  true ;
    /* INTIALISER LA VARIABLE CONTINUE A VRAI */
    /* BOUCLE TANT QUE CONTINUE EST A VRAI */
     while( Continue)
     {
      /* BOUCLE TANT QUE LE FILS GAUCHE DE NOEUD REFERENCE PAR P N'EST PAS NIL */
       while( ( Fg_Ai ( P ) != NULL ))
       {
        /* PASSER AU FILS GAUCHE DE NOEUD REFERENCE PAR P */
         P  =  Fg_Ai ( P );
       } ;
      /* SI LE FILS DROIT DE NOEUD REFERENCE PAR P N'EST PAS NIL */
       if( ( Fd_Ai ( P ) != NULL ))
       {
        /* PASSER AU FILS DROIT DE NOEUD REFERENCE PAR P */
         P  =  Fd_Ai ( P );
       }
       else
       {
         Continue  =  false ;
        /* AFFECTER FAUX A LA VARIABLE CONTINUE */
        /* RETOURNER P */
         Premier_post2  =  P;
       } ;

     } ;

     return Premier_post2 ;
  }
  /* DES FONCTIONS QUI RETOURNE LE SUCESSEUR D'UN NOEUD DANS UN ARBRE BINAIRE DE RECHERCHE SELON UN ORDRE DONNEE*/
  /* UNE FONCTION QUI RETOURNE LE SUCESSEUR INORDRE D'UN NOEUD DONNEE DANS UN ARBRE BINAIRE DE RECHERCHE */
  Pointeur_Ai Inordre_successeur (Pointeur_Ai *A , Pointeur_Ai *P)
  {
      /** Variables locales **/
      Pointeur_Ai Inordre_successeur2 =NULL;
      bool Continue;
      Pointeur_Ai Q=NULL;

      /** Corps du module **/
    /* SI LE FILS DROIT DE NOEUD REFERENCE PAR *P N'EST PAS NIL */
     if( ( Fd_Ai ( *P ) != NULL ))
     {
       *P  =  Fd_Ai ( *P ) ;
      /* PASSER AU FILS DROIT DE NOEUD REFERENCE PAR *P */
      /* BOUCLE TANT QUE LE FILS GAUCHE DE NOEUD REFERENCE PAR *P N'EST PAS NIL*/
       while( ( Fg_Ai ( *P ) != NULL ))
       {
        /* PASSER AU FILS GAUCHE DE NOEUD REFERENCE PAR *P */
         *P  =  Fg_Ai ( *P );
       } ;
       Inordre_successeur2  =  *P ;
      /* RETOURNER *P */
     }
     else
     {
       Q  =  Pere_Ai ( *P ) ;
      /* AFFECTER LE PERE DE NOEUD REFERENCE PAR *P *A Q */
       Continue  =  true ;
      /* INITIALISER LA VARIABLE CONTINUE *A VRAI */
      /* BOUCLE TANT QUE Q N'EST PAS NIL ET CONTINUE EST *A VRAI */
       while( ( ( Q != NULL ) && Continue ))
       {
        /* SI *P EST LE FILS DROIT DE Q */
         if( ( *P == Fd_Ai ( Q ) ))
         {
           *P  =  Q ;
          /* AFFECTER Q *A *P */
           Q  =  Pere_Ai ( *P ) ;
          /* AFFECTER LE PERE DE NOEUD REFERENCE PAR *P *A Q */
         }
         else
         {
          /* AFFECTER FAUX *A LA VARIABLE CONTINUE */
           Continue  =  false ;
         } ;

       } ;
      /* SI Q N'EST PAS NIL */
       if( ( Q != NULL ))
       {
        /* RETOURNER Q */
         Inordre_successeur2  =  Q;
       }
       else
       {
         Inordre_successeur2  =  NULL ;
        /* RETOURNER NIL */

       } ;

     } ;

     return Inordre_successeur2 ;
  }
  /* UNE FONCTION QUI RETOURNE LE SUCESSEUR POSTORDRE D'UN NOEUD DONNEE DANS UN ARBRE BINAIRE DE RECHERCHE */
  Pointeur_Ai Post_successeur (Pointeur_Ai *A , Pointeur_Ai *P)
  {
      /** Variables locales **/
      Pointeur_Ai Post_successeur2 =NULL;
      Pointeur_Ai Q=NULL;
      bool Continue;

      /** Corps du module **/
     Q  =  Pere_Ai ( *P ) ;
    /* AFFECTER *A Q LE PERE DE NOEUD REFERENCE PAR *P */
    /* SI Q EST NIL */
     if( ( Q == NULL ))
     {
       Post_successeur2  =  NULL ;
      /* RETOURNER NIL */
     }
     else
     {
      /* SI *P EST LE FILS GAUCHE DE Q */
       if( ( *P == Fg_Ai ( Q ) ))
       {
        /* SI Q N'EST PAS NIL */
         if( ( Fd_Ai ( Q ) != NULL ))
         {
           *P  =  Fd_Ai ( Q ) ;
          /* *P RECOIT LE FILS DROIT DE Q */
          /* BOUCLE TANT QUE NON FEUILLE */
           while( ( ( Fg_Ai ( *P ) != NULL ) || ( Fd_Ai ( *P ) != NULL ) ))
           {
            /* SI FILS GAUCHE DE *P N'EST PAS NIL */
             if( ( Fg_Ai ( *P ) != NULL ))
             {
              /* *P RECOIT FILS GAUCHE DE NOEUD REFERENCE PAR *P */
               *P  =  Fg_Ai ( *P );
             }
             else
             {
              /* FILS DROIT DE *P N'EST PAS NIL */
               if( ( Fd_Ai ( *P ) != NULL ))
               {
                /* *P RECOIT FILS DROIT DE NOEUD REFERENCE PAR *P */
                 *P  =  Fd_Ai ( *P );
               } ;

             } ;

           } ;
          /* RETOURNER *P */
           Post_successeur2  =  *P;
           }
         else
         {
          /* RETOURNER Q */
           Post_successeur2  =  Q;
         } ;
         }
       else
       {
        /* RETOURNER Q */
         Post_successeur2  =  Q;
       } ;

     } ;

     return Post_successeur2 ;
  }
  /* UNE FONCTION QUI RETOURNE LE SUCESSEUR PREORDRE D'UN NOEUD DONNEE DANS UN ARBRE BINAIRE DE RECHERCHE */
  Pointeur_Ai Preordre_successeur(Pointeur_Ai *A, Pointeur_Ai *P)
  {
  Pointeur_Ai Preordre_successeur2 = NULL; // Initialise le pointeur de successeur en préordre à NULL
  Pointeur_Ai Q = NULL; // Initialise un pointeur temporaire
  bool Continue = true; // Indique si on doit continuer la recherche

  if (Fg_Ai(*P) != NULL)
  { // Si le nœud a un fils gauche
    Preordre_successeur2 = Fg_Ai(*P); // Le successeur en préordre est le fils gauche
  }
  else
  {
    if (Fd_Ai(*P) != NULL)
    { // Sinon, si le nœud a un fils droit
      Preordre_successeur2 = Fd_Ai(*P); // Le successeur en préordre est le fils droit
    }
    else
    {
      Q = Pere_Ai(*P); // Sinon, on remonte vers le nœud parent
      while (Q != NULL && Continue)
      { // Tant que le parent existe et qu'on doit continuer la recherche
        if (*P == Fd_Ai(Q))
        { // Si le nœud actuel est le fils droit du parent
          *P = Q; // Met à jour le nœud actuel avec le parent
          Q = Pere_Ai(*P); // Remonte encore vers le nœud parent
        }
        else
        {
          if (Fd_Ai(Q) != NULL)
          { // Sinon, si le parent a un fils droit
            Continue = false; // Arrête la recherche
          } else
          {
            *P = Q; // Met à jour le nœud actuel avec le parent
            Q = Pere_Ai(*P); // Remonte encore vers le nœud parent
          }
        }
      }

      if (Q != NULL)
      { // Si on a trouvé un parent non NULL
        Preordre_successeur2 = Fd_Ai(Q); // Le successeur en préordre est le fils droit du parent
      }
    }
  }

  return Preordre_successeur2; // Retourne le successeur en préordre
}
  /* UNE PROCEDURE QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
  /* PARCOURIR EN PARALLELE LES ARBRES X ET Y , LE PREMIER SELON L'ORDRE PREORDRE ET LE SECOND SELON L'ORDRE PREORDRE */
  void Fusion_pre_pre (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result)
  {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
    /* BOUCLE TANT QUE *X ET *Y NE SONT PAS NIL */
     while( ( ( *X != NULL ) && ( *Y != NULL ) ))
     {
      /* SI INFO DE DE NOEUD POINTE PAR *X EST LE MINIMUM */
       if( ( Info_Ai ( *X ) <= Info_Ai ( *Y ) ))
       {
         _Px1 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px1) ;
        /* INSERE INFO DE DE NOEUD POINTE PAR *X DANS L'ARBRE RESULT */
         *X  =  Preordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT PREORDRE DE LA RACINE DE L'ARBRE POINTE PAR *X */
       }
       else
       {
        /* SI INFO DE DE NOEUD POINTE PAR *Y EST LE MINIMUM */
         if( ( Info_Ai ( *Y ) < Info_Ai ( *X ) ))
         {
           _Px2 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px2) ;
          /* INSERE INFO DE DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULT */
           *Y  =  Preordre_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT PREORDRE DE LA RACINE DE L'ARBRE POINTE PAR *Y */

         } ;

       } ;

     } ;
    /* SI *Y EST NIL ET *X N'EST PAS NIL */
     if( ( ( *Y == NULL ) && ( *X != NULL ) ))
     {
       while( ( *X != NULL ))
       {
         ;
        /* BOUCLE TANT QUE *X N'EST PAS NIL */
         _Px3 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px3) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULT */
         *X  =  Preordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTE PAR *X */

       } ;
       }
       else
       {
      /* SI *X EST NIL ET *Y N'EST PAS NIL */
       if( ( ( *X == NULL ) && ( *Y != NULL ) ))
       {
         while( ( *Y != NULL ))
         {
           ;
          /* BOUCLE TANT QUE *Y N'EST PAS NIL */
           _Px4 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px4) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULT */
           *Y  =  Preordre_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTE PAR *Y */

         } ;

       } ;

     } ;

  }
  /* UNE PROCEDURE QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
  /* PARCOURIR EN PARALLELE LES ARBRES X ET Y , LE PREMIER SELON L'ORDRE INORDRE ET LE SECOND SELON L'ORDRE POSTORDRE */
  void Fusion_ino_pos (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result)
  {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *X  =  Premier_ino ( & *X ) ;
    /* *X RECOIT LE PREMIER NOEUD SELON LE PARCOURS INORDRE DE L'ARBRE POINTE PAR *X */
     *Y  =  Premier_post ( & *Y ) ;
    /* *Y RECOIT LE PREMIER NOEUD EN PARCOURS POSTORDRE DE L'ARBRE POINTE PAR *Y */
    /* BOUCLE TANT QUE *X ET *Y NE SONT PAS NIL */
     while( ( ( *X != NULL ) && ( *Y != NULL ) ))
     {
      /* SI INFO DE DE NOEUD POINTE PAR *X EST LE MINIMUM */
       if( ( Info_Ai ( *X ) <= Info_Ai ( *Y ) ))
       {
         _Px1 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px1) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULT */
         *X  =  Inordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT INORDRE DE NOEUD POINTE PAR *X */
       }
       else
       {
        /* SI INFO DE DE NOEUD POINTE PAR *Y EST LE MINIMUM */
         if( ( Info_Ai ( *Y ) < Info_Ai ( *X ) ))
         {
           _Px2 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px2) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULT */
           *Y  =  Post_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTE PAR *Y */

         } ;

       } ;

     } ;
    /* SI *Y EST NIL ET *X N'EST PAS NIL */
     if( ( ( *Y == NULL ) && ( *X != NULL ) ))
     {
       while( ( *X != NULL ))
       {
         ;
        /* BOUCLE TANT QUE *X N'EST PAS NIL */
         _Px3 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px3) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULT */
         *X  =  Inordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT INORDRE DE NOEUD POINTE PAR *X */

       } ;
       }
     else
     {
      /* SI *X EST NIL ET *Y N'EST PAS NIL */
       if( ( ( *X == NULL ) && ( *Y != NULL ) ))
       {
         while( ( *Y != NULL ))
         {
           ;
          /* BOUCLE TANT QUE *Y N'EST PAS NIL */
           _Px4 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px4) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULT */
           *Y  =  Post_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTE PAR *X */

         } ;

       } ;

     } ;

  }
  /* UNE PROCEDURE QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
  /* PARCOURIR EN PARALLELE LES ARBRES X ET Y , LE PREMIER SELON L'ORDRE INORDRE ET LE SECOND SELON L'ORDRE PREORDRE */
  void Fusion_ino_pre (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result)
  {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *X  =  Premier_ino ( & *X ) ;
    /* *X RECOIT LE PREMIER NOEUD SELON LE PARCOURS INORDRE DE L'ARBRE POINTEE PAR *X */
     while( ( ( *X != NULL ) && ( *Y != NULL ) ))
     {
       ;
      /* BOUCLE TANT QUE *X ET *Y NE SONT PAS A NIL */
      /* SI INFO DE DE NOEUD POINTE PAR *X EST LE MINIMUM */
       if( ( Info_Ai ( *X ) <= Info_Ai ( *Y ) ))
       {
         _Px1 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px1) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULTAT */
         *X  =  Inordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT INORDRE DE NOEUD POINTEE PAR *X */
       }
       else
       {
        /* SI INFO DE DE NOEUD POINTE PAR *Y EST LE MINIMUM */
         if( ( Info_Ai ( *Y ) < Info_Ai ( *X ) ))
         {
           _Px2 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px2) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULTAT */
           *Y  =  Preordre_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTEE PAR *Y */

         } ;

       } ;

     } ;
    /* *Y EST NIL ET *X N'EST PAS NIL */
     if( ( ( *Y == NULL ) && ( *X != NULL ) ))
     {
       while( ( *X != NULL ))
       {
         ;
        /* BOUCLE TANT QUE *X N'EST PAS NIL */
         _Px3 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px3) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULT */
         *X  =  Inordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT INORDRE DE NOEUD POINTE PAR *X */

       } ;
       }
       else
       {
      /* *X EST NIL ET *Y N'EST PAS NIL */
       if( ( ( *X == NULL ) && ( *Y != NULL ) ))
       {
         while( ( *Y != NULL ))
         {
           ;
          /* BOUCLE TANT QUE *Y N'EST PAS NIL */
           _Px4 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px4) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULT */
           *Y  =  Preordre_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTE PAR *Y */

         } ;

       } ;

     } ;

    }
  /* UNE PROCEDURE QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
  /* PARCOURIR EN PARALLELE LES ARBRES , LE PREMIER SELON L'ORDRE POSTORDRE ET LE SECOND SELON L'ORDRE POSTORDRE */
  void Fusion_pos_pos (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result)
  {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *X  =  Premier_post ( & *X ) ;
    /* *Y RECOIT LE PREMIER NOEUD SELON LE PARCOURS POSTORDRE DE L'ARBRE POINTEE PAR *Y */
     *Y  =  Premier_post ( & *Y ) ;
     while( ( ( *X != NULL ) && ( *Y != NULL ) ))
     {
       ;
      /* BOUCLE TANT QUE *X ET *Y NE SONT PAS A NIL */
      /* SI INFO DE DE NOEUD POINTE PAR *X EST LE MINIMUM */
       if( ( Info_Ai ( *X ) <= Info_Ai ( *Y ) ))
       {
         _Px1 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px1) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULTAT */
         *X  =  Post_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR *X */
        }
        else
        {
        /* SI INFO DE DE NOEUD POINTE PAR *Y EST LE MINIMUM */
         if( ( Info_Ai ( *Y ) < Info_Ai ( *X ) ))
         {
           _Px2 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px2) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULTAT */
           *Y  =  Post_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR *X */

         } ;

       } ;

     } ;
    /* *Y EST NIL ET *X N'EST PAS NIL */
     if( ( ( *Y == NULL ) && ( *X != NULL ) ))
     {
       while( ( *X != NULL ))
       {
         ;
        /* BOUCLE TANT QUE *X N'EST PAS NIL */
         _Px3 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px3) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULTAT */
         *X  =  Post_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR *X */

       } ;
       }
       else
       {
      /* *X EST NIL ET *Y N'EST PAS NIL */
       if( ( ( *X == NULL ) && ( *Y != NULL ) ))
       {
         while( ( *Y != NULL ))
         {
           ;
          /* BOUCLE TANT QUE *Y N'EST PAS NIL */
           _Px4 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px4) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULTAT */
           *Y  =  Post_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR *Y */

         } ;

       } ;

     } ;

    }
  /* UNE PROCEDURE QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
  /* PARCOURIR EN PARALLELE LES ARBRES , LE PREMIER SELON L'ORDRE PREORDRE ET LE SECOND SELON L'ORDRE POSTORDRE */
  void Fusion_pre_pos (Pointeur_Ai *X , Pointeur_Ai *Y , Pointeur_Ai *Result)
  {
      /** Variables locales **/
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     *Y  =  Premier_post ( & *Y ) ;
     while( ( ( *X != NULL ) && ( *Y != NULL ) ))
     {
       ;
      /* BOUCLE TANT QUE *X ET *Y NE SONT PAS A NIL */
      /* SI INFO DE DE NOEUD POINTE PAR *X EST LE MINIMUM */
       if( ( Info_Ai ( *X ) <= Info_Ai ( *Y ) ))
       {
         _Px1 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px1) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULTAT */
         *X  =  Preordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTEE PAR *X */
       }
       else
       {
        /* SI INFO DE DE NOEUD POINTE PAR *Y EST LE MINIMUM */
         if( ( Info_Ai ( *Y ) < Info_Ai ( *X ) ))
         {
           _Px2 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px2) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULTAT */
           *Y  =  Post_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR *Y */

         } ;

       } ;

     } ;
    /* *Y EST NIL ET *X N'EST PAS NIL */
     if( ( ( *Y == NULL ) && ( *X != NULL ) ))
     {
       while( ( *X != NULL ))
       {
         ;
        /* BOUCLE TANT QUE *X N'EST PAS NIL */
         _Px3 =  Info_Ai ( *X ) ;
         Inserer_arb ( & *Result , &_Px3) ;
        /* INSERER INFO DE NOEUD POINTE PAR *X DANS L'ARBRE RESULTAT */
         *X  =  Preordre_successeur ( & *X , & *X ) ;
        /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTEE PAR *X */

       } ;
    }
    else
    {
      /* *X EST NIL ET *Y N'EST PAS NIL */
       if( ( ( *X == NULL ) && ( *Y != NULL ) ))
       {
         while( ( *Y != NULL ))
         {
           ;
          /* BOUCLE TANT QUE *Y N'EST PAS NIL */
           _Px4 =  Info_Ai ( *Y ) ;
           Inserer_arb ( & *Result , &_Px4) ;
          /* INSERER INFO DE NOEUD POINTE PAR *Y DANS L'ARBRE RESULTAT */
           *Y  =  Post_successeur ( & *Y , & *Y ) ;
          /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR *Y */

         } ;

       } ;

     } ;

    }
  /* UNE PROCEDURE QUI AFFICHE UN ARBRE DE RECHERCHE BINAIRE SELON LE PARCOURS INORDRE (GAUCHE - RACINE - DROIT)*/
  void Inordre (Pointeur_Ai *B)
  {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( ( *B != NULL ))
     {
       _Px1 =  Fg_Ai ( *B ) ;
       Inordre ( &_Px1) ;
      /* PARCOURS RECURSIF DE FILS GAUCHE DE *A */
       printf ( " %d | ", Info_Ai(*B) ) ;
      /* AFFICHE LA VALEUR DE NOEUD COURANT */
       _Px2 =  Fd_Ai ( *B ) ;
       Inordre ( &_Px2) ;
      /* PARCOURS RECURSIF DE FILS DROIT DE *A */

     }
    }
  /* DES FONCTIONS ET DES PROCEDURES POUR LA VERIFICATION DE LA VALIDITE DES FUSIONS DE DEUX ARBRES BINAIRE DE RECHERCHE */
  /* UNE FONCTION QUI VERIFIER SI UN ARBRE BINAIRE EST UN ARBRE DE RECHERCHE BINAIRE " BST " */
bool Est_bst(Pointeur_Ai *A)
{
  if (*A == NULL)
  { // Si l'arbre est vide
    return true; // Il est considéré comme un BST (arbre de recherche binaire) valide
  }
  else
  {
    bool Bst = true; // Variable pour suivre si l'arbre est un BST
    Pointeur_Ai P = *A; // Pointeur pour parcourir l'arbre en préordre
    while (P != NULL && Bst)
    { // Tant que le nœud actuel existe et que l'arbre est toujours considéré comme un BST
      if (Fg_Ai(P) != NULL && Fd_Ai(P) != NULL)
      { // Si le nœud a à la fois un fils gauche et un fils droit
        if (Info_Ai(Fg_Ai(P)) <= Info_Ai(P) && Info_Ai(Fd_Ai(P)) > Info_Ai(P))
        {
        // Si les valeurs du fils gauche sont inférieures ou égales à la valeur du nœud,
        // et si les valeurs du fils droit sont strictement supérieures à la valeur du nœud,
        Bst = true;
        }
        else
        {
          Bst = false;
        }
      }
      else if (Fg_Ai(P) != NULL && Fd_Ai(P) == NULL)
      { // Si le nœud a seulement un fils gauche
      if (Info_Ai(Fg_Ai(P)) <= Info_Ai(P))
      {  // Si la valeur du fils gauche est inférieure ou égale à la valeur du nœud,
          Bst = true;
      }
      else
      {
          Bst = false;
      }
      }
      else if (Fg_Ai(P) == NULL && Fd_Ai(P) != NULL)
      { // Si le nœud a seulement un fils droit
        if (Info_Ai(Fd_Ai(P)) > Info_Ai(P))
        {           // Si la valeur du fils droit est strictement supérieure à la valeur du nœud,
          Bst = true;
        } else
        {
          Bst = false;
        }
      }

      P = Preordre_successeur(A, &P); // Passage au nœud suivant en préordre
    }

    return Bst; // Retourne si l'arbre est un BST ou non
  }
}
// UNE PROCEDURE QUI CALCUL LE NOMBRE DE NOEUDS DANS UN ARBRE BINAIRE DE RECHERCHE
void Nbr_noeuds(Pointeur_Ai *B, int *N)
{
  if (*B == NULL)
  { // Si l'arbre est vide
    *N = 0; // Il n'y a aucun nœud
  }
  else
  {
    int N1; // Variable pour stocker le nombre de nœuds dans le sous-arbre gauche
    int N2; // Variable pour stocker le nombre de nœuds dans le sous-arbre droit
    Pointeur_Ai _Px1 = NULL; // Pointeur temporaire pour parcourir le sous-arbre gauche
    Pointeur_Ai _Px2 = NULL; // Pointeur temporaire pour parcourir le sous-arbre droit
    _Px1 = Fg_Ai(*B);  // Récupère le fils gauche de l'arbre
    Nbr_noeuds(&_Px1, &N1); // Appel récursif pour calculer le nombre de nœuds dans le sous-arbre gauche
    _Px2 = Fd_Ai(*B); // Récupère le fils droit de l'arbre
    Nbr_noeuds(&_Px2, &N2); // Appel récursif pour calculer le nombre de nœuds dans le sous-arbre droit
    *N = 1 + N1 + N2; // Le nombre total de nœuds est la somme du nœud actuel et des nœuds dans les sous-arbres gauche et droit
  }
}
// UNE PROCEDURE QUI CALCUL LE NOMBRE DE NOEUDS DANS LE SOUS ARBRE GAUCHE D'UN ARBRE BINAIRE DE RECHERCHE
void Nbr_noeuds_Sous_Arb_G(Pointeur_Ai* A, int* L)
{
    *A = Fg_Ai(*A); // Déplace le pointeur vers le sous-arbre gauche
  if (*A == NULL)
  { // Si le sous-arbre gauche est vide
    *L = 0; // Il n'y a aucun nœud
  }
  else
  {
    int L1; // Variable pour stocker le nombre de nœuds dans le sous-arbre gauche
    int L2; // Variable pour stocker le nombre de nœuds dans le sous-arbre droit
    Pointeur_Ai _Px1 = NULL; // Pointeur temporaire pour parcourir le sous-arbre gauche
    Pointeur_Ai _Px2 = NULL; // Pointeur temporaire pour parcourir le sous-arbre droit
    _Px1 = Fg_Ai(*A); // Récupère le fils gauche de l'arbre actuel
    Nbr_noeuds(&_Px1, &L1); // Appel récursif pour calculer le nombre de nœuds dans le sous-arbre gauche
    _Px2 = Fd_Ai(*A); // Récupère le fils droit de l'arbre actuel
    Nbr_noeuds(&_Px2, &L2); // Appel récursif pour calculer le nombre de nœuds dans le sous-arbre droit
    *L = 1 + L1 + L2; // Le nombre total de nœuds est la somme du nœud actuel et des nœuds dans les sous-arbres gauche et droit
  }
}
// UNE PROCEDURE QUI CALCUL LE NOMBRE DE NOEUDS DANS LE SOUS ARBRE DROIT D'UN ARBRE BINAIRE DE RECHERCHE
void Nbr_noeuds_Sous_Arb_D(Pointeur_Ai* A, int* L)
{
    *A = Fd_Ai(*A); // Déplace le pointeur vers le sous-arbre droit
    if (*A == NULL)
    { // Si le sous-arbre droit est vide
    *L = 0; // Il n'y a aucun nœud
    }
    else
    {
    int L1;  // Variable pour stocker le nombre de nœuds dans le sous-arbre gauche
    int L2; // Variable pour stocker le nombre de nœuds dans le sous-arbre droit
    Pointeur_Ai _Px1 = NULL; // Pointeur temporaire pour parcourir le sous-arbre gauche
    Pointeur_Ai _Px2 = NULL; // Pointeur temporaire pour parcourir le sous-arbre droit
    _Px1 = Fg_Ai(*A); // Récupère le fils gauche de l'arbre actuel
    Nbr_noeuds(&_Px1, &L1); // Appel récursif pour calculer le nombre de nœuds dans le sous-arbre gauche
    _Px2 = Fd_Ai(*A); // Récupère le fils droit de l'arbre actuel
    Nbr_noeuds(&_Px2, &L2); // Appel récursif pour calculer le nombre de nœuds dans le sous-arbre droit
    *L = 1 + L1 + L2; // Le nombre total de nœuds est la somme du nœud actuel et des nœuds dans les sous-arbres gauche et droit
  }
}
// Validation de l'arbre binaire de recherche résultant

void Validation(Pointeur_Ai *X, Pointeur_Ai *Y, Pointeur_Ai *Result)
{
  int N1, N2 , N3 , N4;
  Nbr_noeuds(&*Result, &N3); // Calcul du nombre de nœuds dans l'arbre Result
  Nbr_noeuds(&*X, &N1); // Calcul du nombre de nœuds dans l'arbre X
  Nbr_noeuds(&*Y, &N2); // Calcul du nombre de nœuds dans l'arbre Y
  N4 = N1 + N2 ; // Calcul du nombre total de nœuds attendus dans l'arbre Result
  printf("LE NOMBRE DES NOEUDS DANS L'ARBRE RESULTANTE : %d " , N3 );  // Affichage du nombre de nœuds dans l'arbre Result
  printf("%s", "\n\n");
  // Vérification de la validité de l'arbre Result
  if ( (N3 == N4) && (Est_bst(&*Result)) )
  { // Si le nombre de nœuds est correct et que Result est un ABR valide

  	printf("  L'ARBRE RESULTANTE EST VALIDE\n\n");
  }
  else
  {
    printf("  L'ARBRE RESULTANTE EST INVALIDE\n\n");
  }

}
// UNE PROCEDURE QUI LIBERE LA MEMOIRE D'UN ARBRE BINAIRE DE RECHERCHE
void Liberer_arbre(Pointeur_Ai* A)
{
if (*A == NULL)
{ // Si l'arbre est vide
    return; // On quitte la fonction
}

Liberer_arbre(&((*A)->Fg)); // Libère récursivement le sous-arbre gauche
Liberer_arbre(&((*A)->Fd)); // Libère récursivement le sous-arbre droit

free(*A); // Libère le nœud actuel
*A = NULL; // Réinitialise le pointeur à NULL pour éviter les accès indésirables
}
// DES FONCTIONS ET DES PROCEDURES DE SIMULATION POUR COMPARER LES DIFFERENTS TYPES DE PARCOURS POUR DEDUIRE LE TYPE LE PLUS ADEQUAT
// Fonction pour compter le nombre de feuilles dans un arbre binaire de recherche
int Nbr_feuilles(Pointeur_Ai A)
{
    if (A == NULL)
    { // Si l'arbre est vide
        return 0; // Il n'y a aucune feuille
    }
    if (Fg_Ai(A) == NULL && Fd_Ai(A) == NULL)
    {  // Si le nœud actuel est une feuille
        return 1; // On compte une feuille
    }
    return Nbr_feuilles(Fg_Ai(A)) + Nbr_feuilles(Fd_Ai(A)); // Récursivement, on compte les feuilles dans les sous-arbres gauche et droit
}

// Fonction pour calculer le rapport du nombre de feuilles sur le nombre total de nœuds
float rapport_feuilles_noeuds(Pointeur_Ai *A)
{
	int noeuds_total ;
     Nbr_noeuds(& *A , &noeuds_total); // Calcul du nombre total de nœuds dans l'arbre
    int feuilles = Nbr_feuilles(*A); // Calcul du nombre de feuilles dans l'arbre

    if (noeuds_total == 0)
    { // Si l'arbre est vide
        return 0;
    }

    return (float)feuilles / (float)noeuds_total; // Calcul le rapport de nombre de feuilles sur le nombre de noeuds
}
// fonction qui calcule la hauteur maximale de l'arbre
 int hauteur_max(Pointeur_Ai A)
 {
    if (A == NULL)
    {
        return -1; // Un arbre vide a une hauteur maximale de -1
    }
    else
    {
        int hauteur_g = hauteur_max(Fg_Ai(A)); // Calcul de la hauteur du sous-arbre gauche

        int hauteur_d = hauteur_max(Fd_Ai(A) ); // Calcul de la hauteur du sous-arbre droit
         // Hauteur maximale entre les sous-arbres gauche et droit
         if (hauteur_g > hauteur_d)
         {
             return hauteur_g +1 ;
         }
         else
         {
             return hauteur_d +1;
         }
    }
}
// fonction qui calcul la hauteur maximale de sous arbre gauche

int hauteur_gauche(Pointeur_Ai A)
{
    if (A == NULL)
    {
        return -1; // Un arbre vide a une hauteur maximale de -1
    }
    else
    {
        return hauteur_max(Fg_Ai(A)) + 1; // Calcul de la hauteur du sous-arbre gauche
    }
}
// fonction qui calcul la hauteur maximale de sous arbre droit

int hauteur_droite(Pointeur_Ai A)
{
    if (A == NULL)
    {
        return -1; // Un arbre vide a une hauteur maximale de -1
    }
    else
    {
        return hauteur_max(Fd_Ai(A)) + 1; // Calcul de la hauteur du sous-arbre droit
    }
}
// fonction qui calcul le nombre de noeuds a chaque niveau donne

  int Nbr_noeuds_un_niveau(Pointeur_Ai A, int niveau)
  {
    if (A == NULL)
        return 0;

    if (niveau == 0)
        return 1;

    int compteur_gauche = Nbr_noeuds_un_niveau(Fg_Ai(A), niveau - 1); // Nombre de nœuds dans le sous-arbre gauche à ce niveau
    int compteur_droit = Nbr_noeuds_un_niveau(Fd_Ai(A), niveau - 1); // Nombre de nœuds dans le sous-arbre droit à ce niveau

    return compteur_gauche + compteur_droit; // Total des nœuds à ce niveau
}

// fonction qui calcul le nombre de noeuds a chaque niveau de l'arbre

void Nbr_noeuds_tout_niveaux(Pointeur_Ai A)
{
    int hauteur = hauteur_max(A); // Calcul de la hauteur de l'arbre
    int niveau ;
    for ( niveau = 0; niveau <= hauteur; niveau++)
    {
        int compteur = Nbr_noeuds_un_niveau( A, niveau); // Nombre de nœuds à chaque niveau
        printf("\t \t +Niveau %d: %d noeuds\n", niveau, compteur);
    }
}

// fonction qui calcule la hauteur minimale de l'arbre

 int hauteur_min(Pointeur_Ai A)
 {
    if (A == NULL)
    {
        return 0; // Un arbre vide a une hauteur minimale de 0
    }
    else if (Fg_Ai(A) == NULL && Fd_Ai(A) == NULL)
    {
        return 0; // Un arbre avec un seul noeud a une hauteur minimale de 0
    }
    else
    {
        int hauteur_min_gauche = hauteur_min(Fg_Ai(A)); // Calcul de la hauteur minimale du sous-arbre gauche
        int hauteur_min_droite = hauteur_min(Fd_Ai(A)); // Calcul de la hauteur minimale du sous-arbre droit

         // Hauteur minimale entre les sous-arbres gauche et droit
         if (hauteur_min_gauche < hauteur_min_droite)
         {
             return hauteur_min_gauche +1;
         }
         else
         {
             return hauteur_min_droite +1 ;
         }
    }

}

size_t espace_memoire(Pointeur_Ai A)
{
    // Vérifier si l'arbre est vide
    if (A == NULL)
        return 0;
       int  Noeuds_total ;
    // Calculer le nombre total de nœuds dans l'arbre
    Nbr_noeuds(&A , &Noeuds_total) ;
    // Calculer la taille d'un nœud en octets
    size_t taille_noeud = sizeof(Noeud_Ai);
     // Calculer l'utilisation mémoire totale de l'arbre
    return taille_noeud * Noeuds_total;
}

    int main(int argc, char *argv[])
    {
     srand(time(NULL));
     Bienvenue() ;
     N  =  10000 ;
    /* NOMBRE DE NOEUDS POUR CHAQUE ARBRE CREER AVEC DES DONNEES ALEATOIRES */
     M  =  50 ;
    /* NOMBRE DE REPETIONS DE CHAQUE FUSION POUR LES DEUX ARBRES */
     int N1 , N2  ;

     printf("\n\n\n");

      printf ("*** L'AFFICHAGE DES ARBRES SELON LE PARCOURS INORDRE POUR VERIFIER LA JUSTESSE DES ARBRES CREEES ALEATOIREMENT *** \n\n\n ") ;

       for( I  =  1 ;I <=  M ; ++I){
       printf("\n\n\n");
       printf ("\t \t \t \t\t TEST NUMBER %d \n " , I ) ;
       printf ("\t \t \t \t\t ------------ \n " ) ;
       int nbNoeudsGauche = 0  ;
	   int nbNoeudsDroite = 0 ;
       Creer_arbre_alea ( & A1 , & N ) ;
       Pointeur_Ai Sauv1 ,Sauv2 ;
      /* CREER L'ARBRE A1 AVEC N DONNEES ALEATOIRES */
       printf ( " %s", " L'ARBRE A1 : \n" ) ;
       printf ( " %s", "**************\n\n" ) ;
       Sauv1 = A1 ;
       A2  =  A1 ;
       A3  =  A1 ;
       A4  =  A1 ;
       A5  =  A1 ;
       printf ("\n\n" ) ;
       Nbr_noeuds(&A1 , &N1) ;
       printf (" LE NOMBRE DE NOEUDS DE A1 est : %d \n " , N1 ) ;
       Pointeur_Ai A1_gauche = A1;
       int nbNoeudsGauche_A1 = 0;
       Nbr_noeuds_Sous_Arb_G(&A1_gauche, &nbNoeudsGauche_A1);
       printf("Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_A1);
       Pointeur_Ai A1_droit = A1;
       int nbNoeudsDroit_A1 = 0;
       Nbr_noeuds_Sous_Arb_D(&A1_droit, &nbNoeudsDroit_A1);
       printf("Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_A1);
       printf("\n");
       Inordre ( & A1 ) ;
       printf("\n");
       printf ( " %s", "" ) ;


       Creer_arbre_alea ( & B1 , & N ) ;
      /* CREER L'ARBRE A2 AVEC N DONNEES ALEATOIRES */
       printf("\n\n");
       printf ( " %s", " L'ARBRE A2 : \n" ) ;
       printf ( " %s", "**************\n\n " ) ;
       Sauv2 = B1 ;
       B2  =  B1 ;
       B3  =  B1 ;
       B4  =  B1 ;
       B5  =  B1 ;
       Nbr_noeuds(&B1 , &N2) ;
       printf ("\n\n") ;
       printf (" LE NOMBRE DE NOEUDS DE A2 : %d \n\n\n  " , N2 ) ;
       Pointeur_Ai B1_gauche = B1;
       int nbNoeudsGauche_B1 = 0;
       Nbr_noeuds_Sous_Arb_G(&B1_gauche, &nbNoeudsGauche_B1);
       printf("Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_B1);
       Pointeur_Ai B1_droit = B1;
       int nbNoeudsDroit_B1 = 0;
       Nbr_noeuds_Sous_Arb_D(&B1_droit, &nbNoeudsDroit_B1);
       printf("Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_B1);
       printf("\n");
       Inordre ( & B1 ) ;
       printf("\n");
       printf("\n");


       // FUSION 1 : INO_PRE
       printf ("\t \t***********************************************\n ") ;
	   printf ("\t \t* TEST %d : L'ARBRE A3 : FUSION 1 : INO_PRE    *\n  ",I) ;
	   printf ("\t \t***********************************************\n\n") ;
       Fusion_ino_pre ( & A1 , & B1 , & Result1 ) ;
       Inordre ( & Result1 ) ;

       printf("\n");
       printf ("---------------------------------------------------------------------------------------------------\n\n ") ;


	   printf(" PARTIE INFORMATION \n\n  ") ;
	   printf("*********************\n");
	   Validation ( & Sauv1 , & Sauv2 , & Result1 ) ;
       printf(" Le nombre de feuilles : %d \n " , Nbr_feuilles(Result1)) ;
       printf(" le rapport de nombre de feuilles sur le nombre de noeuds est : %f \n " , rapport_feuilles_noeuds(&Result1)) ;
	   printf(" La hauteur max est : %d\n " , hauteur_max(Result1) ) ;
	   printf(" La hauteur min est : %d\n " , hauteur_min(Result1)) ;
       printf(" La hauteur gauche est : %d\n",hauteur_gauche(Result1));
	   printf(" La hauteur droite est : %d\n",hauteur_droite(Result1));
       printf(" L'espace memoire consomm�es  : %zu bytes\n " , espace_memoire(Result1)) ;
       Pointeur_Ai Result1_gauche = Result1;
       int nbNoeudsGauche_Result1 = 0;
       Nbr_noeuds_Sous_Arb_G(&Result1_gauche, &nbNoeudsGauche_Result1);
       printf(" Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_Result1);
       Pointeur_Ai Result1_droit = Result1;
       int nbNoeudsDroit_Result1 = 0;
       Nbr_noeuds_Sous_Arb_D(&Result1_droit, &nbNoeudsDroit_Result1);
       printf(" Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_Result1);
       printf ("\n") ;
       printf (" Nombre des noeuds par niveau : \n ") ;
       printf("\n");
       Nbr_noeuds_tout_niveaux(Result1) ;
       printf ("\n\n\n\n") ;


       printf ("\t \t***********************************************\n") ;
	   printf ("\t \t* TEST %d : L'ARBRE A3 : FUSION 2 : INO_POS    *\n ",I) ;
	   printf ("\t \t***********************************************\n\n") ;
       Fusion_ino_pos ( & A2 , & B2 , & Result2 ) ;
       Inordre ( & Result2 ) ;
       printf("\n");

       printf ("---------------------------------------------------------------------------------------------------\n\n ") ;

       printf (" PARTIE INFORMATION  \n\n  ") ;
       printf("*********************\n");
	   Validation ( & Sauv1 , & Sauv2 , & Result2 ) ;
       printf (" Le nombre de feuilles : %d \n " , Nbr_feuilles(Result2)) ;
       printf (" le rapport de nombre de feuilles sur le nombre de noeuds est : %f \n " , rapport_feuilles_noeuds(&Result2)) ;
	   printf (" La hauteur max est : %d\n " , hauteur_max(Result2) ) ;
	   printf (" La hauteur min est : %d\n " , hauteur_min(Result2)) ;
       printf(" La hauteur gauche est : %d\n",hauteur_gauche(Result2));
	   printf(" La hauteur droite est : %d\n",hauteur_droite(Result2));
       printf (" L'espace memoire consomm�es  : %zu bytes\n " , espace_memoire(Result2)) ;
       Pointeur_Ai Result2_gauche = Result2;
       int nbNoeudsGauche_Result2 = 0;
       Nbr_noeuds_Sous_Arb_G(&Result2_gauche, &nbNoeudsGauche_Result2);
       printf(" Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_Result2);
       Pointeur_Ai Result2_droit = Result2;
       int nbNoeudsDroit_Result2 = 0;
       Nbr_noeuds_Sous_Arb_D(&Result2_droit, &nbNoeudsDroit_Result2);
       printf(" Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_Result2);
       printf ("\n") ;
       printf (" Nombre des noeuds par niveau : \n ") ;
       printf("\n");
       Nbr_noeuds_tout_niveaux(Result2) ;
       printf("\n");
       printf ("\n\n\n\n") ;


       printf ("\t \t***********************************************\n ") ;
	   printf ("\t \t* TEST %d : L'ARBRE A3 : FUSION 3 : PRE_PRE    *\n  ",I) ;
	   printf ("\t \t***********************************************\n\n  ") ;
       Fusion_pre_pre ( & A3 , & B3 , & Result3 ) ;
       Inordre ( & Result3 ) ;
       printf("\n");

       printf ("---------------------------------------------------------------------------------------------------\n\n ") ;
       printf (" PARTIE INFORMATION  \n\n  ") ;
       printf("*********************\n");
       Validation ( & Sauv1 , & Sauv2 , & Result3 ) ;
       printf (" Le nombre de feuilles : %d \n " , Nbr_feuilles(Result3)) ;
       printf (" le rapport de nombre de feuilles sur le nombre de noeuds est : %f \n " , rapport_feuilles_noeuds(&Result3)) ;
	   printf (" La hauteur max est : %d\n " , hauteur_max(Result3) ) ;
	   printf (" La hauteur min est : %d\n " , hauteur_min(Result3)) ;
       printf(" La hauteur gauche est : %d\n",hauteur_gauche(Result3));
	   printf(" La hauteur droite est : %d\n",hauteur_droite(Result3));
       printf (" L'espace memoire consomm�es  : %zu bytes\n " , espace_memoire(Result3)) ;
       Pointeur_Ai Result3_gauche = Result3;
       int nbNoeudsGauche_Result3 = 0;
       Nbr_noeuds_Sous_Arb_G(&Result3_gauche, &nbNoeudsGauche_Result3);
       printf(" Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_Result3);
       Pointeur_Ai Result3_droit = Result3;
       int nbNoeudsDroit_Result3 = 0;
       Nbr_noeuds_Sous_Arb_D(&Result3_droit, &nbNoeudsDroit_Result3);
       printf(" Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_Result3);
       printf ("\n") ;
       printf (" Nombre des noeuds par niveau : \n ") ;
       printf("\n");
       Nbr_noeuds_tout_niveaux(Result3) ;
       printf("\n");
       printf ("\n\n\n\n") ;



       printf ("\t \t***********************************************\n ") ;
	   printf ("\t \t* TEST : %d L'ARBRE A3 : FUSION 4 : POS_POS    * \n  ",I) ;
	   printf ("\t \t***********************************************\n\n  ") ;
       Fusion_pos_pos ( & A4 , & B4 , & Result4 ) ;
       Inordre ( & Result4 ) ;
       printf("\n");
       printf("\n");
       printf ("---------------------------------------------------------------------------------------------------\n\n ") ;
       printf (" PARTIE INFORMATION  \n\n  ") ;
       printf("*********************\n");
	   Validation ( & Sauv1 , & Sauv2 , & Result4 ) ;

       printf (" Le nombre de feuilles : %d \n " , Nbr_feuilles(Result4)) ;
       printf (" le rapport de nombre de feuilles sur le nombre de noeuds est : %f \n " , rapport_feuilles_noeuds(&Result4)) ;
	   printf (" La hauteur max est : %d\n " , hauteur_max(Result4) ) ;
	   printf (" La hauteur min est : %d\n " , hauteur_min(Result4)) ;
       printf(" La hauteur gauche est : %d\n",hauteur_gauche(Result4));
	   printf(" La hauteur droite est : %d\n",hauteur_droite(Result4));

       printf ("\n") ;
       printf (" L'espace memoire consomm�es  : %zu bytes\n " , espace_memoire(Result4)) ;
       Pointeur_Ai Result4_gauche = Result4;
       int nbNoeudsGauche_Result4 = 0;
       Nbr_noeuds_Sous_Arb_G(&Result4_gauche, &nbNoeudsGauche_Result4);
       printf(" Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_Result4);
       Pointeur_Ai Result4_droit = Result4;
       int nbNoeudsDroit_Result4 = 0;
       Nbr_noeuds_Sous_Arb_D(&Result4_droit, &nbNoeudsDroit_Result4);
       printf(" Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_Result4);
       printf("\n");
       printf (" Nombre des noeuds par niveau : \n ") ;
       Nbr_noeuds_tout_niveaux(Result4) ;
       printf ("\n") ;
       printf ("\n\n\n\n") ;



       printf ("\t \t***********************************************\n ") ;
	   printf ("\t \t* TEST %d : L'ARBRE A3 : FUSION 5 : PRE_POS    * \n  ",I) ;
	   printf ("\t \t***********************************************\n\n  ") ;

       Fusion_pre_pos ( & A5 , & B5 , & Result5 ) ;
       Inordre ( & Result5 ) ;
       printf("\n");

       printf ("---------------------------------------------------------------------------------------------------\n\n ") ;
       printf (" PARTIE INFORMATION  \n\n  ") ;
       printf("*********************\n");
	   Validation ( & Sauv1 , & Sauv2 , & Result5 ) ;

       printf (" Le nombre de feuilles : %d \n " , Nbr_feuilles(Result5)) ;
       printf (" le rapport de nombre de feuilles sur le nombre de noeuds est : %f \n " , rapport_feuilles_noeuds(&Result5)) ;
	   printf (" La hauteur max est : %d\n " , hauteur_max(Result5) ) ;
	   printf (" La hauteur min est : %d\n " , hauteur_min(Result5)) ;
	   printf(" La hauteur gauche est : %d\n",hauteur_gauche(Result5));
	   printf(" La hauteur droite est : %d\n",hauteur_droite(Result5));
        printf (" L'espace memoire consomm�es  : %zu bytes\n " , espace_memoire(Result5)) ;
       Pointeur_Ai Result5_gauche = Result5;
       int nbNoeudsGauche_Result5 = 0;
       Nbr_noeuds_Sous_Arb_G(&Result5_gauche, &nbNoeudsGauche_Result5);
       printf(" Nombre de noeuds dans le sous-arbre gauche : %d\n", nbNoeudsGauche_Result5);
       Pointeur_Ai Result5_droit = Result5;
       int nbNoeudsDroit_Result5 = 0;
       Nbr_noeuds_Sous_Arb_D(&Result5_droit, &nbNoeudsDroit_Result5);
       printf(" Nombre de noeuds dans le sous-arbre droit : %d\n", nbNoeudsDroit_Result5);
       printf("\n");
       printf (" Nombre des noeuds par niveau : \n ") ;
       Nbr_noeuds_tout_niveaux(Result5) ;
       printf("\n");
       printf ("\n\n\n\n") ;


       Liberer_arbre(&Sauv1);
       Liberer_arbre(&Sauv2);
       Liberer_arbre(&A1);
       Liberer_arbre(&A2);
       Liberer_arbre(&A3);
       Liberer_arbre(&A4);
       Liberer_arbre(&A5);
       Liberer_arbre(&B1);
       Liberer_arbre(&B2);
       Liberer_arbre(&B3);
       Liberer_arbre(&B4);
       Liberer_arbre(&B5);
       Liberer_arbre(&Result1);
       Liberer_arbre(&Result2);
       Liberer_arbre(&Result3);
       Liberer_arbre(&Result4);
       Liberer_arbre(&Result5);

     }

      system("PAUSE");
      return 0;
    }
