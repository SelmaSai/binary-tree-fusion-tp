SOIT
                        /* DECLARATIONS DES VARIABLES GLOBALES */

       A1,B1,A2,B2,A3,B3,A4,B4,A5,B5,RESULT1,RESULT2,RESULT3,RESULT4,RESULT5 DES ARB ;
       SAUV1,SAUV2,SAUV3,SAUV4,SAUV5,SAUV6,SAUV7,SAUV8,SAUV9,SAUV10 DES ARB;
       N ,M,I DES ENTIERS;

       /* DECLARACTIONS DES FONCTIONS */

       PREMIER_INO,PREMIER_POST DES FONCTIONS ( ARB ) ;
       INORDRE_SUCCESSEUR UNE FONCTION(POINTEUR VERS UN ARB);
       POST_SUCCESSEUR UNE FONCTION(POINTEUR VERS UN ARB);
       PREORDRE_SUCCESSEUR UNE FONCTION(POINTEUR VERS UN ARB);
       EST_BST UNE FONCTION(BOOLEEN);
       EXISTE_ARB UNE FONCTION(BOOLEEN);

       VALIDATION UNE ACTION;
       FUSION_INO_PRE UNE ACTION;
       FUSION_INO_POS UNE ACTION;
       FUSION_PRE_PRE UNE ACTION;
       FUSION_POS_POS UNE ACTION;                              /* DECLARATIONS DES ACTIONS */
       FUSION_PRE_POS UNE ACTION;
       BIENVENUE UNE ACTION;
       INORDRE UNE ACTION;
       AJOUTER_ALEA UNE ACTION;
       NBR_NOEUDS UNE ACTION;
       INSERER_ARB UNE ACTION;
       CREER_ARB_ALEA UNE ACTION;

       /* PROGRAMME PRINCIPALES */

       DEBUT

       APPEL BIENVENUE;

       N:=50;          /* NOMBRE DE NOEUDS POUR CHAQUE ARBRE CREER AVEC DES DONNEES ALEATOIRES */
       M:=10;          /* NOMBRE DE REPETIONS DE CHAQUE FUSION POUR LES DEUX ARBRES */

       POUR I:=1,M

       ECRIRE('');
       ECRIRE('TEST:',I);
       ECRIRE('--------');
       ECRIRE('');
       APPEL CREER_ARB_ALEA(A1,N);             /* CREER L'ARBRE A1 AVEC N DONNEES ALEATOIRES */
       ECRIRE('L''ARBRE A1 :');
       ECRIRE('-------------');
       SAUV1 := A1;
       SAUV3 := A1;
       SAUV5 := A1;
       SAUV7 := A1;
       SAUV9 := A1;
       A2 := A1;
       A3 := A1;
       A4 := A1;
       A5 := A1;
       ECRIRE('');
       APPEL INORDRE(A1);
       ECRIRE('');
       APPEL CREER_ARB_ALEA(B1,N);            /* CREER L'ARBRE A2 AVEC N DONNEES ALEATOIRES */
       ECRIRE('L''ARBRE A2 :');
       ECRIRE('-------------');
       SAUV2 := B1;
       SAUV4 := B1;
       SAUV6 := B1;
       SAUV8 := B1;
       SAUV10 := B1;
       B2 := B1;
       B3 := B1;
       B4 := B1;
       B5 := B1;
       ECRIRE('');
       APPEL INORDRE(B1);
       ECRIRE('');
       ECRIRE('L''ARBRE A3 : FUSION_INO_PRE ');
       ECRIRE('-----------------------------');
       ECRIRE('');

       APPEL FUSION_INO_PRE(A1,B1,RESULT1);
       APPEL INORDRE(RESULT1);
       ECRIRE('');
       APPEL VALIDATION(SAUV1,SAUV2,RESULT1);
       ECRIRE('');
       ECRIRE('*******************************************************');
       ECRIRE('');
       ECRIRE('L''ARBRE A3 : FUSION_INO_POS ');
       ECRIRE('-----------------------------');
       ECRIRE('');

       APPEL FUSION_INO_POS(A2,B2,RESULT2);
       APPEL INORDRE(RESULT2);
       APPEL VALIDATION(SAUV3,SAUV4,RESULT2);
       ECRIRE('');
       ECRIRE('*******************************************************');
       ECRIRE('');
       ECRIRE('L''ARBRE A3 : FUSION_PRE_PRE ');
       ECRIRE('-----------------------------');
       ECRIRE('');

       APPEL FUSION_PRE_PRE(A3,B3,RESULT3);
       APPEL INORDRE(RESULT3);
       APPEL VALIDATION(SAUV5,SAUV6,RESULT3);
       ECRIRE('');
       ECRIRE('*******************************************************');
       ECRIRE('');
       ECRIRE('L''ARBRE A3 : FUSION_POS_POS ');
       ECRIRE('-----------------------------');
       ECRIRE('');

       APPEL FUSION_POS_POS(A4,B4,RESULT4);
       APPEL INORDRE(RESULT4);
       APPEL VALIDATION(SAUV7,SAUV8,RESULT4);
       ECRIRE('');
       ECRIRE('*******************************************************');
       ECRIRE('');
       ECRIRE('L''ARBRE A3 : FUSION_PRE_POS ');
       ECRIRE('-----------------------------');
       ECRIRE('');

       APPEL FUSION_PRE_POS(A5,B5,RESULT5);
       APPEL INORDRE(RESULT5);
       APPEL VALIDATION(SAUV9,SAUV10,RESULT5);
       ECRIRE('');
       ECRIRE('*******************************************************');
       FPOUR
   FIN

/* L'IMPLEMENTATIONS DES FONCTIONS ET DES ACTIONS NECESSAIRES */

    ACTION BIENVENUE
      DEBUT
       ECRIRE ( '**************************************************************************************************');
       ECRIRE ( '*                        BIENVENUE DANS NOTRE TRAVAIL PRATIQUE N 02 - ALSDD                      *');
       ECRIRE ( '**************************************************************************************************');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                           THEME: FUSION D''ARBRES DE RECHERCHE BINAIRE                          *');
       ECRIRE ( '*                          ----------------------------------------------                        *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                            REALISE PAR: SAIDI SELMA ET MEZDOUR HEYAM INES                      *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                                    SECTION: D          GROUPE: 11                              *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                                    ANNEE UNIVERSITAIRE: 2022/2023                              *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '*                                                                                                *');
       ECRIRE ( '**************************************************************************************************');
      FIN

 /* DES FONCTIONS ET DES ACTIONS POUR LA GENERATION ET LA MANIPULATION DES ARBRES DE RECHERCHE BINAIRE */

 /* UNE ACTION POUR INSERER UNE VALEUR DANS UN ARBRE DE RECHERCHE BINAIRE QUI PEUT CONTENIR LES DOUBLES */

  ACTION INSERER_ARB (X,VAL)

    SOIENT X, Y DES POINTEURS VERS ARB ;           /* DECLARATIONS DES VARIABLES LOCALES */

    VAL UN ENTIER ;

    DEBUT

     SI (X = NIL)      /* SI LA RACINE N'EXISTE PAS C'EST A DIRE L'ARBRE EST VIDE */

        CREERNOEUD (X);

        AFF_INFO (X,VAL);

     SINON
        SI (VAL > INFO(X))    /* SI VAL EST SUPPERIEUR A INFO DE RACINE */

            SI (FD(X) = NIL)    /* SI LE FILS DROIT DE LA RACINE N'EXISTE PAS */

                CREERNOEUD (Y);

                AFF_INFO(Y, VAL);

                AFF_FD(X, Y);

            SINON

                APPEL INSERER_ARB(FD(X),VAL);    /* INSERTION RECURSIVE DANS LE FILS DROIT DE P */

            FSI;

        SINON

            SI (FG(X) = NIL)    /* SI LE FILS GAUCHE DE LA RACINE N'EXISTE PAS */

                CREERNOEUD(Y);

                AFF_INFO(Y, VAL);

                AFF_FG(X, Y);

            SINON

                APPEL INSERER_ARB(FG(X),VAL);   /* INSERTION RECURSIVE DANS LE FILS GAUCHE DE P */

            FSI;

        FSI;

    FSI;

FIN

/* UNE FONCTION POUR SAVOIR SI UNE VALEUR EXISTE DEJA DANS L'ARBRE OU NON */

   FONCTION EXISTE_ARB(X,VAL):BOOLEEN

   SOIENT

   X UN POINTEUR VERS UN ARB;

   VAL UN ENTIER;                                 /* DECLARATIONS DES VARIABLES LOCALES */

   EXISTER UN BOOLEEN;

   DEBUT

     SI (X = NIL)     /* SI LA RACINE DE L'ARBRE EST NIL */

       EXISTER := FAUX;         /* AFFECTER FAUX A LA VARIABLE EXISTER */

     SINON

        SI (VAL = INFO(X))    /* SI VAL EGALE A L'INFORMATION DE LA RACINE */

          EXISTER := VRAI ;      /* AFFECTER VRAI A EXISTER */

        SINON

           SI (VAL < INFO(X))
                                       /* APPEL RECURSIF DE LA FONCTION POUR LE FILS GAUCHE DE LA RACINE */
               EXISTER := EXISTE_ARB(FG(X),VAL);

           SINON
                                        /* APPEL RECURSIF DE LA FONCTION POUR LE FILS DROIT DE LA RACINE */
               EXISTER := EXISTE_ARB(FD(X),VAL);
           FSI;

        FSI;

     FSI;

    EXISTE_ARB := EXISTER;    /* RETOURNER EXISTER */

   FIN

/* ACTION POUR CREER UN ARBRE DE RECHERCHE BINAIRE AVEC N DONNEES ALEATOIRES */

   ACTION CREER_ARB_ALEA (A,N ) ;

   SOIT

       I , N ,VAL DES ENTIERS ;
                                          /* DECLARATIONS DES VARIABLES LOCALES */
       A UN ARB ;



   DEBUT

       A := NIL ;     /* INITIALISER LA RACINE A NIL */

       I:= N;   /* I RECOIT LE NOMBRE DE NOEUDS SOUHAITE */

       TQ (I > 0):    /* BOUCLE TANT QUE ON N'A PAS ATTEINT LE NOMBRE DE NOEUDS REQUIS */

           VAL :=  ALEANOMBRE ( 1000 );     /* VAL RECOIT UN NOMBRE ALEATOIRE DE 0 A 1000 */

           SI (EXISTE_ARB(A,VAL)= FAUX)        /* SI LA VALEUR VAL N'EXISTE PAS DANS L'ARBRE A */

              APPEL AJOUTER_ALEA ( A ,VAL );    /* ON INSERE VAL DANS L'ARBRE A */

              I:=I-1;   /* DECREMENTER LE COMPTEUR I */

           FSI;
       FTQ;


   FIN

/* UNE ACTION POUR AJOUTER UN NOEUD AVEC UNE VALEUR ALEATOIRE X DANS L'ARBRE A */

      ACTION AJOUTER_ALEA ( A , X )

      SOIT

       A UN ARB ;
                                       /* DECLARATIONS DES VARIABLES LOCALES */
       X UN ENTIER ;

       P , Q DES ARB ;



   DEBUT

       SI (A = NIL)   /* SI LA RACINE EST NIL C'EST A DIRE L'ARBRE EST VIDE */

           CREERNOEUD ( Q ) ;

           AFF_INFO ( Q , X ) ;

           A := Q      /* Q DEVIENT LA RACINE DE L'ARBRE A */

       SINON

           P := A ;    /* AFFECTER LA RACINE DE L'ARBRE A A LA VARIABLE P */

           Q := A ;    /* AFFECTER LA RACINE DE L'ARBRE A A LA VARIABLE Q */

           TQ (( X <> INFO ( P ) ) ET ( Q <> NIL )) : /* BOUCLE TANT QUE X DIFFERENT DE INFO DE P ET Q N'EST PAS NIL */

               P := Q ;     /* P RECOIT Q */

               SI (X < INFO ( P )) /* SI X INFERIEUR AU INFO DE NOEUD REFERENCE PAR P */

                   Q := FG ( P );   /* PASSER AU FILS GAUCHE DE NOEUD REFERENCE PAR P */

               SINON ;

                   Q := FD ( P );   /* PASSER AU FILS DROIT DE NOEUD REFERENCE PAR P */

               FSI ;

           FTQ ;

           SI (X <> INFO ( P ))  /* SI X EST DIFFERENT DE INFO DE NOEUD REFERENCE PAR P */

               CREERNOEUD ( Q ) ;

               AFF_INFO ( Q , X ) ;

               SI (X < INFO ( P ))    /* SI X EST INFERIEUR A INFO DE NOEUD REFERENCE PAR P */

                   AFF_FG ( P , Q );

               SINON

                   AFF_FD ( P , Q );

               FSI ;

               AFF_PERE ( Q , P ) ;



           FSI;

       FSI;

   FIN


/* DES FONCTIONS QUI RETOURNE LE PREMIER NOEUD DANS UN PARCOURS D'UN ARBRE BINAIRE DE RECHERCHE */

/* LE PREMIER PREORDER DANS UN ARBRE DE RECHERCHE BINAIRE EST LA RECINE */

/* UNE FONCTION QUI RETOURNE LE PREMIER NOEUD DANS LE PARCOURS INORDRE D'UN ARBRE BINAIRE DE RECHERCHE */

  FONCTION PREMIER_INO ( A ) : ARB ;

   SOIT

       A,P DES ARB ;   /* DECLARATION DES VARIABLES LOCALES */

   DEBUT

       P := A ;  /* INITIALISER P AVER ARBRE */

     TQ (FG ( P ) <> NIL):   /* BOUCLE TANT QUE LE FILS GAUCHE DE DE NOEUD REFERENCE PAR P N'EST PAS NIL */

           P := FG ( P );         /* PASSER AU FILS GAUCHE DE DE NOEUD REFERENCE PAR P */

     FTQ ;

       PREMIER_INO := P ;    /* RETOURNER P */

   FIN

/* UNE FONCTION QUI RETOURNE LE PREMIER NOEUD DANS LE PARCOURS POSTORDRE D'UN ARBRE BINAIRE DE RECHERCHE */

      FONCTION PREMIER_POST ( A ) : ARB ;

   SOIT

       A,P DES ARB ;
                                /* DECLARATION DES VARIABLES LOCALES */
       CONTINUE UN BOOLEEN ;

   DEBUT

       P := A ;          /* INITIALISER P AVEC ARBRE */

       CONTINUE := VRAI ;     /* INTIALISER LA VARIABLE CONTINUE A VRAI */

       TQ CONTINUE :            /* BOUCLE TANT QUE CONTINUE EST A VRAI */

           TQ (FG ( P ) <> NIL) :     /* BOUCLE TANT QUE LE FILS GAUCHE DE NOEUD REFERENCE PAR P N'EST PAS NIL */

               P := FG ( P );       /* PASSER AU FILS GAUCHE DE NOEUD REFERENCE PAR P */

           FTQ ;

           SI (FD ( P ) <> NIL )   /* SI LE FILS DROIT DE NOEUD REFERENCE PAR P N'EST PAS NIL */

               P := FD ( P );     /* PASSER AU FILS DROIT DE NOEUD REFERENCE PAR P */

           SINON

               CONTINUE := FAUX ;   /* AFFECTER FAUX A LA VARIABLE CONTINUE */

               PREMIER_POST := P ;  /* RETOURNER P */

           FSI;

       FTQ;

   FIN

/* DES FONCTIONS QUI RETOURNE LE SUCESSEUR D'UN NOEUD DANS UN ARBRE BINAIRE DE RECHERCHE SELON UN ORDRE DONNEE*/

/* UNE FONCTION QUI RETOURNE LE SUCESSEUR INORDRE D'UN NOEUD DONNEE DANS UN ARBRE BINAIRE DE RECHERCHE */

   FONCTION INORDRE_SUCCESSEUR ( A ,P ):POINTEUR VERS UN ARB

   SOIENT

       A : ARB ;

       CONTINUE DES BOOLEENS ;          /* DECLARATION DES VARIABLES LOCALES */

       Q , P DES POINTEURS VERS ARB ;

   DEBUT

           SI (FD ( P ) <> NIL)  /* SI LE FILS DROIT DE NOEUD REFERENCE PAR P N'EST PAS NIL */

               P := FD ( P ) ;       /* PASSER AU FILS DROIT DE NOEUD REFERENCE PAR P */

               TQ (FG ( P ) <> NIL):   /* BOUCLE TANT QUE LE FILS GAUCHE DE NOEUD REFERENCE PAR P N'EST PAS NIL*/

                   P := FG ( P )     /* PASSER AU FILS GAUCHE DE NOEUD REFERENCE PAR P */

               FTQ ;

               INORDRE_SUCCESSEUR := P;     /* RETOURNER P */

           SINON

               Q := PERE ( P ) ;    /* AFFECTER LE PERE DE NOEUD REFERENCE PAR P A Q */

               CONTINUE := VRAI ;   /* INITIALISER LA VARIABLE CONTINUE A VRAI */

               TQ (( Q <> NIL ) ET CONTINUE ):      /* BOUCLE TANT QUE Q N'EST PAS NIL ET CONTINUE EST A VRAI */

                   SI (P = FD ( Q ))    /* SI P EST LE FILS DROIT DE Q */

                       P := Q ;       /* AFFECTER Q A P */

                       Q := PERE ( P ) ;   /* AFFECTER LE PERE DE NOEUD REFERENCE PAR P A Q */



                   SINON

                       CONTINUE := FAUX ;   /* AFFECTER FAUX A LA VARIABLE CONTINUE */

                   FSI;

               FTQ ;

               SI (Q <> NIL)  /* SI Q N'EST PAS NIL */

                   INORDRE_SUCCESSEUR := Q ;    /* RETOURNER Q */

               SINON

                   INORDRE_SUCCESSEUR := NIL;   /* RETOURNER NIL */

               FSI;

           FSI;
   FIN

/* UNE FONCTION QUI RETOURNE LE SUCESSEUR POSTORDRE D'UN NOEUD DONNEE DANS UN ARBRE BINAIRE DE RECHERCHE */

   FONCTION POST_SUCCESSEUR ( A , P ):POINTEUR VERS UN ARB

   SOIENT

       A UN ARB ;

       Q , P DES POINTEURS VERS ARB ;           /* DECLARATION DES VARIABLES LOCALES */

       CONTINUE DES BOOLEENS ;

   DEBUT

           Q := PERE ( P ) ;       /* AFFECTER A Q LE PERE DE NOEUD REFERENCE PAR P */

           SI (Q = NIL)      /* SI Q EST NIL */

              POST_SUCCESSEUR := NIL;           /* RETOURNER NIL */

           SINON

               SI (P = FG ( Q ))                /* SI P EST LE FILS GAUCHE DE Q */

                   SI (FD ( Q ) <> NIL)              /* SI Q N'EST PAS NIL */

                       P := FD ( Q ) ;               /* P RECOIT LE FILS DROIT DE Q */

                       TQ (( FG ( P ) <> NIL ) OU ( FD ( P ) <> NIL )):   /* BOUCLE TANT QUE NON FEUILLE */


                           SI (FG ( P ) <> NIL)    /* SI FILS GAUCHE DE P N'EST PAS NIL */

                               P := FG ( P );      /* P RECOIT FILS GAUCHE DE NOEUD REFERENCE PAR P */

                           SINON

                               SI (FD ( P ) <> NIL)               /* FILS DROIT DE P N'EST PAS NIL */

                                   P := FD ( P );                /* P RECOIT FILS DROIT DE NOEUD REFERENCE PAR P */

                               FSI;

                           FSI;

                       FTQ ;

                       POST_SUCCESSEUR := P ;    /* RETOURNER P */

                   SINON

                       POST_SUCCESSEUR := Q ;   /* RETOURNER Q */

                   FSI;

               SINON

                      POST_SUCCESSEUR := Q ;     /* RETOURNER Q */

               FSI;

           FSI;

   FIN

/* UNE FONCTION QUI RETOURNE LE SUCESSEUR PREORDRE D'UN NOEUD DONNEE DANS UN ARBRE BINAIRE DE RECHERCHE */

   FONCTION PREORDRE_SUCCESSEUR ( A , P ):POINTEUR VERS UN ARB

   SOIENT

       A UN ARB ;

       Q , P DES POINTEURS VERS ARB ;        /* DECLARATION DES VARIABLES LOCALES */

       CONTINUE DES BOOLEENS ;



   DEBUT

           SI (FG ( P ) <> NIL)               /* SI FILS GAUCHE DE P N'EST PAS NIL */

               PREORDRE_SUCCESSEUR := FG (P);     /* RETOURNER LE FILS GAUCHE DE NOEUD REFERENCE PAR P */

           SINON

               SI (FD ( P ) <> NIL)     /* SI FILS DROIT DE P N'EST PAS NIL */

                   PREORDRE_SUCCESSEUR := FD(P);    /* RETOURNER LE FILS DROIT DE NOEUD REFERENCE PAR P */

               SINON

                   Q := PERE ( P ) ;       /* AFFECTER A Q LE PERE DE P */

                   CONTINUE := VRAI ;             /* INITIALISER LA VARIABLE CONTINUE A VRAI */

                   TQ (( Q <> NIL ) ET CONTINUE):     /* BOUCLE TANT QUE Q N'EST PAS NIL ET CONTINUE EST A VRAI */

                       SI (P = FD ( Q ) )                              /* SI P EST LE FILS DROIT DE Q */

                           P := Q ;            /* AFFECTER Q A P */

                           Q := PERE ( P ) ;   /* Q RECOIT LE PERE DE P */



                       SINON

                           SI (FD ( Q ) <> NIL)           /* SI LE FILS DROIT DE Q N'EST PAS NIL */

                               CONTINUE := FAUX ;      /* AFFECTER FAUX A LA VARIABLE CONTINUE */

                           SINON

                               P := Q ;        /* P RECOIT Q */

                               Q := PERE ( P ) ;   /* Q RECOIT LE PERE DE NOEUD REFERENCE PAR P */



                           FSI;

                       FSI;

                   FTQ ;

                   SI (Q <> NIL)    /* SI Q N'EST PAS NIL */

                       PREORDRE_SUCCESSEUR := FD (Q);      /* RETOURNER LE FILS DROIT DE Q */

                   SINON

                       PREORDRE_SUCCESSEUR := NIL;        /* RETOURNER NIL */

                   FSI;

               FSI;

           FSI;

   FIN

 /* UNE ACTION QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
 /* PARCOURIR EN PARALLELE LES ARBRES X ET Y , LE PREMIER SELON L'ORDRE PREORDRE ET LE SECOND SELON L'ORDRE PREORDRE */

 ACTION FUSION_PRE_PRE(X,Y,RESULT)

 SOIENT

 X,Y,RESULT DES POINTEURS VERS ARB;      /* DECLARATION DES VARIABLES LOCALES */

 DEBUT

   TQ ((X <> NIL) ET (Y <> NIL)):    /* BOUCLE TANT QUE X ET Y NE SONT PAS NIL */

     SI (INFO(X) <= INFO(Y))       /* SI INFO DE DE NOEUD POINTE PAR X EST LE MINIMUM */

       APPEL INSERER_ARB (RESULT,INFO(X));     /* INSERE INFO DE DE NOEUD POINTE PAR X DANS L'ARBRE RESULT */

       X:= PREORDRE_SUCCESSEUR(X,X);         /* PASSER AU SUIVANT PREORDRE DE LA RACINE DE L'ARBRE POINTE PAR X */

     SINON

       SI (INFO(Y) < INFO(X))   /* SI INFO DE DE NOEUD POINTE PAR Y EST LE MINIMUM */

         APPEL INSERER_ARB(RESULT,INFO(Y));   /* INSERE INFO DE DE NOEUD POINTE PAR Y DANS L'ARBRE RESULT */

         Y := PREORDRE_SUCCESSEUR(Y,Y);     /* PASSER AU SUIVANT PREORDRE DE LA RACINE DE L'ARBRE POINTE PAR Y */

       FSI ;

     FSI;

   FTQ ;

     SI ((Y = NIL) ET (X <> NIL))    /* SI Y EST NIL ET X N'EST PAS NIL */

      TQ (X <> NIL):           /* BOUCLE TANT QUE X N'EST PAS NIL */

        APPEL INSERER_ARB (RESULT,INFO(X));    /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULT */

        X := PREORDRE_SUCCESSEUR(X,X);      /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTE PAR X */

      FTQ ;

     SINON

      SI ((X = NIL) ET (Y <> NIL))     /* SI X EST NIL ET Y N'EST PAS NIL */

        TQ (Y <> NIL):     /* BOUCLE TANT QUE Y N'EST PAS NIL */

          APPEL INSERER_ARB(RESULT,INFO(Y));    /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULT */

          Y := PREORDRE_SUCCESSEUR(Y,Y);   /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTE PAR Y */

        FTQ ;

      FSI ;

     FSI;

   FIN

 /* UNE ACTION QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
 /* PARCOURIR EN PARALLELE LES ARBRES X ET Y , LE PREMIER SELON L'ORDRE INORDRE ET LE SECOND SELON L'ORDRE POSTORDRE */


   ACTION FUSION_INO_POS(X,Y,RESULT)

   SOIENT

   X,Y,RESULT DES POINTEURS VERS ARB;         /* DECLARATION DES VARIABLES LOCALES */

   DEBUT

      X := PREMIER_INO (X);     /* X RECOIT LE PREMIER NOEUD SELON LE PARCOURS INORDRE DE L'ARBRE POINTE PAR X */

      Y := PREMIER_POST(Y);    /* Y RECOIT LE PREMIER NOEUD EN PARCOURS POSTORDRE DE L'ARBRE POINTE PAR Y */

     TQ (( X <> NIL) ET (Y <> NIL)):  /* BOUCLE TANT QUE X ET Y NE SONT PAS NIL */

       SI (INFO(X)<= INFO(Y))    /* SI INFO DE DE NOEUD POINTE PAR X EST LE MINIMUM */

         APPEL INSERER_ARB (RESULT,INFO(X));   /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULT */

         X := INORDRE_SUCCESSEUR(X,X);       /* PASSER AU SUIVANT INORDRE DE NOEUD POINTE PAR X */

       SINON

         SI (INFO(Y)<INFO(X))         /* SI INFO DE DE NOEUD POINTE PAR Y EST LE MINIMUM */

           APPEL INSERER_ARB(RESULT,INFO(Y));    /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULT */

           Y:= POST_SUCCESSEUR (Y,Y);    /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTE PAR Y */

         FSI ;

       FSI;

     FTQ ;

     SI ((Y = NIL) ET (X <> NIL))   /* SI Y EST NIL ET X N'EST PAS NIL */

      TQ (X <> NIL):      /* BOUCLE TANT QUE X N'EST PAS NIL */

        APPEL INSERER_ARB(RESULT,INFO(X));       /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULT */

        X := INORDRE_SUCCESSEUR(X,X);          /* PASSER AU SUIVANT INORDRE DE NOEUD POINTE PAR X */

      FTQ ;

     SINON

       SI ((X = NIL) ET (Y <> NIL))   /* SI X EST NIL ET Y N'EST PAS NIL */

          TQ (Y <> NIL):   /* BOUCLE TANT QUE Y N'EST PAS NIL */

            APPEL INSERER_ARB(RESULT,INFO(Y));     /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULT */

            Y := POST_SUCCESSEUR (Y,Y);    /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTE PAR X */

          FTQ ;

       FSI ;

     FSI;

   FIN

 /* UNE ACTION QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
 /* PARCOURIR EN PARALLELE LES ARBRES X ET Y , LE PREMIER SELON L'ORDRE INORDRE ET LE SECOND SELON L'ORDRE PREORDRE */


   ACTION FUSION_INO_PRE (X,Y,RESULT)

   SOIENT

   X,Y,RESULT DES POINTEURS VERS ARB;        /* DECLARATION DES VARIABLES LOCALES */

   DEBUT

     X := PREMIER_INO(X);    /* X RECOIT LE PREMIER NOEUD SELON LE PARCOURS INORDRE DE L'ARBRE POINTEE PAR X */

    TQ ((X <> NIL) ET (Y <> NIL)):    /* BOUCLE TANT QUE X ET Y NE SONT PAS A NIL */

      SI (INFO(X) <= INFO(Y))        /* SI INFO DE DE NOEUD POINTE PAR X EST LE MINIMUM */

         APPEL INSERER_ARB (RESULT,INFO(X));     /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULTAT */

         X:= INORDRE_SUCCESSEUR(X,X);        /* PASSER AU SUIVANT INORDRE DE NOEUD POINTEE PAR X */

      SINON

         SI (INFO(Y)<INFO(X))           /* SI INFO DE DE NOEUD POINTE PAR Y EST LE MINIMUM */

           APPEL INSERER_ARB(RESULT,INFO(Y));     /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULTAT */

           Y := PREORDRE_SUCCESSEUR(Y,Y);      /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTEE PAR Y */

         FSI ;

      FSI ;

    FTQ ;

      SI ((Y = NIL) ET (X <> NIL))    /* Y EST NIL ET X N'EST PAS NIL */

        TQ (X <> NIL):             /* BOUCLE TANT QUE X N'EST PAS NIL */

          APPEL INSERER_ARB (RESULT,INFO(X));     /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULT */

          X := INORDRE_SUCCESSEUR(X,X);       /* PASSER AU SUIVANT INORDRE DE NOEUD POINTE PAR X */

        FTQ ;

      SINON

        SI ( (X = NIL) ET (Y <> NIL)):      /* X EST NIL ET Y N'EST PAS NIL */

           TQ ( Y <> NIL):            /* BOUCLE TANT QUE Y N'EST PAS NIL */

              APPEL INSERER_ARB(RESULT,INFO(Y));      /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULT */

              Y := PREORDRE_SUCCESSEUR(Y,Y);    /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTE PAR Y */

           FTQ ;

        FSI ;

      FSI ;

   FIN

 /* UNE ACTION QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
 /* PARCOURIR EN PARALLELE LES ARBRES , LE PREMIER SELON L'ORDRE POSTORDRE ET LE SECOND SELON L'ORDRE POSTORDRE */

   ACTION FUSION_POS_POS(X,Y,RESULT)

   SOIENT

   X,Y,RESULT DES POINTEURS VERS ARB;          /* DECLARATION DES VARIABLES LOCALES */

   DEBUT
           /* X RECOIT LE PREMIER NOEUD SELON LE PARCOURS POSTORDRE DE L'ARBRE POINTEE PAR X */

     X := PREMIER_POST(X);

          /* Y RECOIT LE PREMIER NOEUD SELON LE PARCOURS POSTORDRE DE L'ARBRE POINTEE PAR Y */

     Y := PREMIER_POST(Y);

    TQ ((X <> NIL) ET (Y <> NIL)):         /* BOUCLE TANT QUE X ET Y NE SONT PAS A NIL */

      SI (INFO(X) <= INFO(Y))             /* SI INFO DE DE NOEUD POINTE PAR X EST LE MINIMUM */

        APPEL INSERER_ARB (RESULT,INFO(X));    /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULTAT */

        X:= POST_SUCCESSEUR(X,X);      /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR X */

      SINON

        SI (INFO(Y) < INFO(X))            /* SI INFO DE DE NOEUD POINTE PAR Y EST LE MINIMUM */

           APPEL INSERER_ARB(RESULT,INFO(Y));   /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULTAT */

           Y := POST_SUCCESSEUR(Y,Y);   /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR X */
        FSI;

      FSI;

    FTQ ;

    SI ((Y = NIL) ET (X <> NIL))     /* Y EST NIL ET X N'EST PAS NIL */

      TQ (X <> NIL):            /* BOUCLE TANT QUE X N'EST PAS NIL */

         APPEL INSERER_ARB (RESULT,INFO(X));    /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULTAT */

         X := POST_SUCCESSEUR(X,X);   /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR X */

      FTQ ;

    SINON

      SI ((X = NIL) ET (Y <> NIL))    /* X EST NIL ET Y N'EST PAS NIL */

        TQ (Y <> NIL):      /* BOUCLE TANT QUE Y N'EST PAS NIL */

           APPEL INSERER_ARB(RESULT,INFO(Y));    /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULTAT */

           Y := POST_SUCCESSEUR(Y,Y);    /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR Y */

        FTQ ;

      FSI ;

    FSI;

   FIN


 /* UNE ACTION QUI FUSIONNE DEUX ARBRES DE RECHERCHE BINAIRE SELON LE PRINCIPE SUIVANT : */
 /* PARCOURIR EN PARALLELE LES ARBRES , LE PREMIER SELON L'ORDRE PREORDRE ET LE SECOND SELON L'ORDRE POSTORDRE */


   ACTION FUSION_PRE_POS(X,Y,RESULT)

   SOIENT

   X,Y,RESULT DES POINTEURS VERS ARB;     /* DECLARATION DES VARIABLES LOCALES */

   DEBUT
                         /* Y RECOIT LE PREMIER NOEUD SELON LE PARCOURS POSTORDRE DE L'ARBRE POINTEE PAR Y */
     Y := PREMIER_POST(Y);

    TQ ((X <> NIL) ET (Y <> NIL)):    /* BOUCLE TANT QUE X ET Y NE SONT PAS A NIL */

     SI (INFO(X) <= INFO(Y))     /* SI INFO DE DE NOEUD POINTE PAR X EST LE MINIMUM */

       APPEL INSERER_ARB (RESULT,INFO(X));    /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULTAT */

       X:= PREORDRE_SUCCESSEUR(X,X);       /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTEE PAR X */

     SINON

       SI (INFO(Y) < INFO(X))     /* SI INFO DE DE NOEUD POINTE PAR Y EST LE MINIMUM */

          APPEL INSERER_ARB(RESULT,INFO(Y));   /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULTAT */

          Y := POST_SUCCESSEUR(Y,Y);    /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR Y */

       FSI;

     FSI;

    FTQ ;

       SI ((Y = NIL) ET (X <> NIL))     /* Y EST NIL ET X N'EST PAS NIL */

          TQ (X <> NIL):        /* BOUCLE TANT QUE X N'EST PAS NIL */

             APPEL INSERER_ARB (RESULT,INFO(X));     /* INSERER INFO DE NOEUD POINTE PAR X DANS L'ARBRE RESULTAT */

             X := PREORDRE_SUCCESSEUR(X,X);       /* PASSER AU SUIVANT PREORDRE DE NOEUD POINTEE PAR X */

          FTQ ;

       SINON

          SI ((X = NIL) ET (Y <> NIL ))    /* X EST NIL ET Y N'EST PAS NIL */

             TQ (Y <> NIL):    /* BOUCLE TANT QUE Y N'EST PAS NIL */

             /* INSERER INFO DE NOEUD POINTE PAR Y DANS L'ARBRE RESULTAT */

                APPEL INSERER_ARB(RESULT,INFO(Y));

                Y := POST_SUCCESSEUR(Y,Y);       /* PASSER AU SUIVANT POSTORDRE DE NOEUD POINTEE PAR Y */

             FTQ;

          FSI;

       FSI;

   FIN

/* UNE ACTION QUI AFFICHE UN ARBRE DE RECHERCHE BINAIRE SELON LE PARCOURS INORDRE (GAUCHE - RACINE - DROIT)*/

      ACTION INORDRE ( B )

      SOIT
      B UN  ARB ;

      DEBUT
        SI (B <> NIL)

           APPEL INORDRE ( FG ( B ) ) ;  /* PARCOURS RECURSIF DE FILS GAUCHE DE B */

           ECRIRE ( INFO ( B ) ) ;   /* AFFICHE LA VALEUR DE NOEUD COURANT */

           APPEL INORDRE ( FD ( B ) ); /* PARCOURS RECURSIF DE FILS DROIT DE B */

        FSI
      FIN

 /* DES FONCTIONS ET DES ACTIONS POUR LA VERIFICATION DE LA VALIDITE DES FUSIONS DE DEUX ARBRES BINAIRE DE RECHERCHE */
 /* UNE FONCTION QUI VERIFIER SI UN ARBRE BINAIRE EST UN ARBRE DE RECHERCHE BINAIRE " BST " */

  FONCTION EST_BST(A):BOOLEEN

  SOIENT

  BST UN BOOLEEN;
                       /* DECLARATIONS DES VARIABLES LOCALES */
  A UN ARB;

  DEBUT

    SI (A = NIL)    /* SI LA RACINE DE L'ARBRE EST NIL */

      BST := VRAI; /* L'ARBRE VIDE EST UN BST */

    SINON

      BST := VRAI; /* INITIALISER BST A VRAI */

       TQ ((A <> NIL) ET (BST)):   /* BOUCLE TANT QUE A N'EST PAS NIL ET BST EST A VRAI */

         SI ((FG(A) <> NIL) ET (FD(A) <> NIL)) /* LE FILS GAUCHE DE A EXISTE ET LE FILS DROIT DE A EXISTE */

           SI (INFO(FG(A)) < INFO(A)) ET (INFO(FD(A)) > INFO(A))

              BST := VRAI; /* L'ARBRE EST UN BST */

           SINON

              BST := FAUX;    /* L'ARBRE N'EST PAS UN BST */

           FSI

         SINON

           SI ((FG(A) <> NIL) ET (FD(A) = NIL))  /* LE FILS GAUCHE DE A EXISTE ET LE FILS DROIT DE A N'EXISTE PAS */

             SI (INFO(FG(A)) < INFO(A))

                BST := VRAI; /* L'ARBRE EST UN BST */

             SINON

                BST := FAUX;   /* L'ARBRE N'EST PAS UN BST */

             FSI
           SINON

             SI ((FD(A) <> NIL) ET (FG(A) = NIL)) /* LE FILS DROIT DE A EXISTE ET LE FILS GAUCHE DE A EXISTE */

               SI (INFO(FD(A)) > INFO(A))

                 BST := VRAI; /* L'ARBRE EST UN BST */

               SINON

                 BST := FAUX;  /* L'ARBRE N'EST PAS UN BST */

               FSI ;

             FSI ;

           FSI;

         FSI;

        A := PREORDRE_SUCCESSEUR(A,A);  /* PASSER AU SUCESSEUR PREORDRE DE NOEUD A POUR CONTINUER LE PARCOURS */

       FTQ;

    FSI ;

   EST_BST := BST;

  FIN

  /* UNE ACTION QUI RETOURNE LE NOMBRE DE NOEUDS DANS UN ARBRE DE RECHERCHE BINAIRE */

   ACTION NBR_NOEUDS ( B , N )

   SOIT

       B UN ARB ;
                                       /* DECLARATIONS DES VARIABLES LOCALES */
       N , N1 , N2 : ENTIER ;



   DEBUT

       SI (B = NIL)

           N := 0 ;    /* INITIALISER LE NOMBRE DES NOEUDS A 0 */

       SINON
                         /* APPEL RECURSIF POUR CALCUL NB_NOEUDS DANS LE SOUS ARBRE GAUCHE DE A */

           APPEL NBR_NOEUDS ( FG ( B ) , N1 ) ;

                                      /* APPEL RECURSIF POUR CALCUL NB_NOEUDS DANS LE SOUS ARBRE DROIT DE A */

           APPEL NBR_NOEUDS ( FD ( B ) , N2 ) ;

                                /* NB_NOEUDS DE A  = NB NOEUDS DE SOUS ARBRE GAUCHE+NB NOEUDS DE SOUS ARBRE DROIT+1 */
           N := 1 + N1 + N2 ;

       FSI ;

   FIN
/* UNE FONCTION QUI VERIFIER SI LA FUSION DE DEUX ARBRES BINAIRE DE RECHERCHE EST VALIDE OU PAS */

   ACTION VALIDATION(X,Y,RESULT)

    SOIENT

    X,Y,RESULT DES POINTEURS VERS ARB;

    VALIDE UN BOOLEEN;                        /* DECLARATIONS DES VARIABLES LOCALES */

    N1,N2,N3 DES ENTIERS;

    DEBUT

      APPEL NBR_NOEUDS(RESULT,N3);           /* POUR CALCULER NB_NOEUDS DANS L'ARBRE RESULT */

      ECRIRE('LE NOMBRE DES NOEUDS DANS L''ARBRE RESULTANTE : ',N3);

      ECRIRE('');    /* SAUTE DE LIGNE */

      APPEL NBR_NOEUDS(X,N1);   /* CALCULER LE NOMBRE DE NOEUDS DANS L'ARBRE 1 */

      APPEL NBR_NOEUDS(Y,N2); /* CALCULER LE NOMBRE DE NOEUDS DANS L'ARBRE 2 */


      SI ((N3 = N1 + N2 ) ET (EST_BST(RESULT)))   /* SI TOUT LES ELEMENTS SONT INSERES ET L'ARBRE RESULT EST BST */

          VALIDE := VRAI;     /* AFFECTER VRAI A LA VARIABLE VALIDE */

          ECRIRE('L''ARBRE RESULTANTE EST VALIDE');

      SINON

          VALIDE := FAUX;

          ECRIRE('L''ARBRE RESULTANTE EST INVALIDE');

      FSI ;

    FIN



