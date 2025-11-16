#include <iostream>

// Nous allons implémenter une pile d'entiers de manière très basique.
// Nous la complexifierons par la suite.

// La pile est constituée:
//    - d'un tableau d'entier, avec sa taille et son nombre d'éléments empilés
//    - des quatre fonctions: push, pop, top, print, is_empty et is_full
//      (qui testent si la pile est resp. vide ou pleine)
//      il faut les utiliser dans votre code de push et pop

void print(int *tab, int size, int nb)
{
    int i = 0;
    while (i < nb)
    {
        std::cout << tab[i] << std::endl;
        i = i + 1;
    }
}

// renvoie true si la pile est vide, false sinon
bool is_empty(int *tab, int size, int nb)
{
    int z = 0;
    if (nb == z)
    {
        return true;
    }
    return false;
}

// renvoie true si la pile est pleine, false sinon
bool is_full(int *tab, int size, int nb)
{
    if (nb == size)
    {
        return true;
    }
    return false;
}

void push(int *tab, int size, int &nb, int a)
// cette fonction ajoute un entier à la pile passé en argument
// elle doit s'assurer que la pile n'est pas pleine avant d'empiler
// elle lance une exception si problème
{
    if (is_full(tab, size, nb))
    {
        throw std::length_error(std::string("exception of type: length error"));
    }
    tab[nb] = a;
    nb = nb + 1;
}

int top(int *tab, int size, int nb) // (cette fonction ne dépile pas)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné reste dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (is_empty(tab, size, nb))
    {
        throw std::length_error(std::string("exception of type: length error"));
    }
    return tab[nb - 1];
}

int pop(int *tab, int size, int &nb) // (cette fonction dépile)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné n'est plus compté dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (is_empty(tab, size, nb))
    {
        throw std::length_error(std::string("exception of type: length error"));
    }
    int res = tab[nb - 1];
    nb = nb - 1;
    return res;
}

#include <stdexcept>
// https://en.cppreference.com/w/cpp/header/stdexcept.html
// pour un exemple d'exception voir le fichier exception.cpp

int main()
{

    // on définit les 3 variables constituant la pile
    int size = 5;
    int stack[size];
    int nb = 0;

    // rajoutez aux blocks catch les erreurs
    // pouvant être déclenchées par les opérations sur la pile
    try
    {
        print(stack, size, nb); // affiche [ [
        push(stack, size, nb, -17);

        // on affiche l'élément en haut de pile
        std::cout << top(stack, size, nb) << std::endl; // affiche -17
        push(stack, size, nb, 90);
        print(stack, size, nb); // affiche [-17 90 [

        int e = pop(stack, size, nb);
        std::cout << e << std::endl;
        print(stack, size, nb); // affiche [-17 [

        push(stack, size, nb, 20);
        push(stack, size, nb, -78);
        push(stack, size, nb, -9);
        push(stack, size, nb, -56);
        //push(stack, size, nb, 45);
        print(stack, size, nb);
    }
    catch (std::length_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}