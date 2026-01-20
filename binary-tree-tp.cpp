/*
Nous souhaitons implémenter un arbre binaire.

Un arbre binaire est formé de noeuds (Node).

Chaque noeud a deux sous-arbres (left, right) potentiellement nuls et une valeur entière.

Un de ces noeuds est la racine de l'arbre, tous les noeuds de l'arbre sont accessibles à partir de cette racine.

Voici un exemple d'arbre avec 3 noeuds,
on le dessine "allongé" avec sa racine à gauche:

      37
26
      11

   la racine est 26
   l'arbre gauche est réduit au noeud 11
   l'arbre droit est réduit au noeud 37

Un autre avec les mêmes valeurs
mais une autre forme (la forme dépend de l'ordre d'insertion des éléments)
            37
      26
11

Vous l'avez compris, étant donné un noeud:
   - les valeurs des noeuds du sous-arbre gauche sont strictement inférieures à la valeur du noeud
   - les valeurs des noeuds du sous-arbre droit sont strictement supérieures à la valeur du noeud.

Voici le dessin de l'arbre nous allons prendre en exemple dans le main (8 est la racine):
en trichant on a inséré les valeurs de manière à ce qu'il soit équilibré...
Quel est la complexité en temps de la recherche d'un élément dans un arbre binaire équilibré ?
dégénéré
               15
          14
               13
     12
               11
          10
               9
8
               7
          6
               5
     4
               3
          2
               1

Si j'ai beaucoup moins de chance, je peux obtenir en insérant les mêmes valeurs
un arbre "dégénéré":
30
     29
          28
               27
                    26
                         25
                              24
                                   23
                                        22
                                             21
                                                  20
                                                       19
                                                            18
                                                                 17
                                                                      16

Quel est la complexité en temps de la recherche d'un élément dans des arbres binaires de cette forme ?

I) Construction de l'arbre:

L'arbre est construit de manière à être trié c'est à dire quand on est à un noeud:
   - toutes les valeurs de son sous-arbre gauche sont strictement inférieures à la valeur du noeud
   - toutes les valeurs de son sous-arbre droit sont strictement supérieures à la valeur du noeud

On donne des indices mais vous pouvez coder autrement.

L'arbre initial est créé vide - sa racine est donc le pointeur nul (nullptr).

Implémenter la méthode insert(int v) qui ajoute une valeur entière à l'arbre à la bonne place i.e.
  - on va se déplacer dans l'arbre jusqu'à trouver l'endroit où insérer cette valeur
  - si la valeur existe déjà dans l'arbre, on ne fait rien
  - sinon on crée un noeud qu'on raccorde.

  Réfléchissez à la manière de faire un tel parcours récursivement, soit codez-le soit regardez les indices ci-dessous.

Indices pour l'insertion dans l'arbre binaire:
  - si la racine n'existe pas on crée un noeud avec la valeur et ses deux sous-arbres nuls (nullptr)
  - si la racine existe on lance l'insertion sur ce noeud racine (on appelle une méthode d'insertion des noeuds)

Indices pour la méthode d'insertion sur un noeud:
  - si la valeur du noeud est égale à la valeur à insérer on ne fait rien (le noeud y est déjà)
  - si la valeur est inférieure et si l'arbre gauche existe on lance l'insertion sur le noeud gauche
  -                             et si l'arbre gauche n'existe pas, on crée un noeud avec la valeur et il devient le fils gauche
  - pareil à droite

II) Parcours de l'arbre:

Implémentez la méthode depth() qui va parcourir cet arbre en profondeur en affichant ses valeurs.
Réfléchissez à la manière de faire ce parcours de manière récursive et soit vous le codez soit vous lisez les indices ci-dessous.

Indices pour un parcours en profondeur récursif d'un arbre binaire:
   - ce parcours lance le parcours récursif du noeud racine de l'arbre (i.e. appelle la méthode depth des noeuds)
   - si ce noeud a un fils gauche, on lance le parcours sur le noeud gauche (i.e. appelle la méthode sur le noeud gauche)
   - si ce noeud n'a pas de fils gauche, on affiche la valeur du noeud et on lance le parcours sur le noeud droit
...

Lors de ce parcours on peut afficher la valeur des noeuds à plusieurs endroits:
   - si on l'affiche en début de l'appel du parcours sur un noeud: on a un affichage dit préfixe
   - si on l'affiche entre les appels à gauche et à droite on a un affichage dit infixe
   - si on l'affiche à la fin de l'appel de la méthode sur un noeud: on a un affichage dit postfixe

Pour décider de l'affichage, on peut donc passer à cette méthode le type de l'affichage désiré
(par exemple un objet qui est une énumération (enum) voir exemple ci-dessous)

*/
#include <iostream>

int cpt=0;

// the type enum
enum Order
{
     Prefix,  // will be set to 0
     Infix,   // will be set to the previous + 1
     Postfix, // idem
};

void enum_values()
{
     std::cout << "Prefix is " << Order::Prefix << std::endl;
     std::cout << "Infix is " << Order::Infix << std::endl;
     std::cout << "Postfix is " << Order::Postfix << std::endl;
}

// Les structures de base de l'arbre binaire BinaryTree et Node:
// avec les méthodes pour que le code compile.
struct Node
{
     int value;
     Node *left;
     Node *right;

     Node(int v) : value(v), left(nullptr), right(nullptr)
     {
     }

     void insert(int v)
     {
          if (v > value)
          {
               if (right == nullptr)
               {
                    right = new Node(v);
               }
               else
               {
                    right->insert(v);
               }
          }
          if (v < value)
          {
               if (left == nullptr)
               {
                    left = new Node(v);
               }
               else
               {
                    left->insert(v);
               }
          }
     }

     void traversal()
     {
          if (left == nullptr and right == nullptr)
          {
               std::cout << value;
          }
          left->traversal();
          std::cout << value;
          right->traversal();
     }

     bool search(int v)
     {
          if (v == value)
          {
               return true;
          }
          if ((left == nullptr and v < value) or (right == nullptr and v > value))
          {
               return false;
          }
          if (v < value)
          {
               return left->search(v);
          }
          if (v > value)
          {
               return right->search(v);
          }
     }

     void printN(int h)
     {
          for (int i = 0; i < h; i++)
          {
               std::cout<<"   ";
          }
          std::cout<<value<<std::endl;
     }

     void print()
     {
          if (left == nullptr and right == nullptr)
          {
               printN(cpt);
          }
          cpt+=1;
          right->traversal();
          printN(cpt);
          left->traversal();
          cpt-=1;
     }
};

struct BinaryTree
{
     Node *root = nullptr;
     // et ces fonctions à implémenter à minima
     void insert(int v)
     {
          if (root == nullptr)
          {
               root = new Node(v);
          }
          else
          {
               root->insert(v);
          }
     }
     void depth(Order o)
     {
          root->traversal();
     }
     bool search(int v)
     {
          return root->search(v);
     }

     // celle là est plus difficile
     void print()
     {
          root->print();
     }
};

int main()
{
     // enum_values(); // exemple pour voir un enum

     // on construit l'arbre

     // cet ordre d'insertion donne un bel arbre binaire équilibré
     // ce qui n'est bien sûr pas toujours le cas...
     // il existe des algorithmes pour garder l'arbre équilibré
     // mais c'est en dehors de notre cadre d'une simple programmation
     BinaryTree b;
     b.insert(8);
     b.insert(4);
     b.insert(6);
     b.insert(12);
     b.insert(10);
     b.insert(11);
     b.insert(9);
     b.insert(2);
     b.insert(1);
     b.insert(3);
     b.insert(5);
     b.insert(14);
     b.insert(15);
     b.insert(13);
     b.insert(7);
     b.print();
     std::cout << "Infix ";
     b.depth(Order::Infix);
     std::cout << "Postfix ";
     b.depth(Order::Postfix);
     std::cout << "Prefix ";
     b.depth(Order::Prefix);
     std::cout << std::boolalpha << b.search(25) << std::endl;
     std::cout << std::boolalpha << b.search(2) << std::endl;
     std::cout << "Cet arbre est dégénéré:\n";
     BinaryTree bad1;
     for (int i = 1; i < 16; i++)
          bad1.insert(i);
     bad1.print();
     std::cout << "\ncelui là aussi:\n";
     BinaryTree bad2;
     for (int i = 30; i > 15; i--)
          bad2.insert(i);
     bad2.print();
}

/* l'exécution de ce programme donne:
    ----------------------------------

Prefix is 0
Infix is 4
Postfix is 5
               15
          14
               13
     12
               11
          10
               9
8
               7
          6
               5
     4
               3
          2
               1
Infix { 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15  }
Postfix { 1 3 2 5 7 6 4 9 11 10 13 15 14 12 8  }
Prefix { 8 4 2 1 3 6 5 7 12 10 9 11 14 13 15  }
false
true
Cet arbre est dégénéré:
                                                                      15
                                                                 14
                                                            13
                                                       12
                                                  11
                                             10
                                        9
                                   8
                              7
                         6
                    5
               4
          3
     2
1

celui là aussi:
30
     29
          28
               27
                    26
                         25
                              24
                                   23
                                        22
                                             21
                                                  20
                                                       19
                                                            18
                                                                 17
                                                                      16
*/
