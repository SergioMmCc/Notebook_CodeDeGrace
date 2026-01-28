#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define BLACK 0
#define RED 1
#define NILKey -2147483647
#define MAXN 1200000
#define MAXFROG 200000

struct nodeRBTree {
    int key;
    int color;
    //int frequency;
    struct nodeRBTree *p;
    struct nodeRBTree *left;
    struct nodeRBTree *right;
};

typedef struct 
{
    int id;
    int currentPosition;
} frogs;

void inOrderTreeWalk (struct nodeRBTree *x) {
    if (x->key != NILKey) {
        inOrderTreeWalk (x->left);
        if (x->color == RED)
            printf ("[%d, RED] ", x->key);
        else
            printf ("[%d, BLACK] ", x->key);
        inOrderTreeWalk (x->right);
    }
}

struct nodeRBTree *treeSearch (struct nodeRBTree *x, int k) {
    while ((x->key != NILKey) && (k != x->key)) {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

struct nodeRBTree *treeMinimum (struct nodeRBTree *x) {
    while (x->left->key != NILKey)
        x = x->left;
    return x;
}

struct nodeRBTree *treeMaximum (struct nodeRBTree *x) {
    while (x->right->key != NILKey)
        x = x->right;
    return x;
}

struct nodeRBTree *treeSucessor (struct nodeRBTree *x) {
    struct nodeRBTree *y;
    if (x->right->key != NILKey)
        return treeMinimum (x->right);
    y = x->p;
    while ((y->key != NILKey) && (x == y->right)) {
        x = y;
        y = y->p;
    }
    
    return y;
}

struct nodeRBTree *treePredecessor (struct nodeRBTree *x) {
    struct nodeRBTree *y;
    if (x->left->key != NILKey)
        return treeMaximum (x->left);
    y = x->p;
    while ((y->key != NILKey) && (x == y->left)) {
        x = y;
        y = y->p;
    }
    
    return y;
}

struct nodeRBTree *leftRotate (struct nodeRBTree *T, struct nodeRBTree *x) {
    struct nodeRBTree *y;
    
    y = x->right;
    x->right = y->left;
    y->left->p = x;
    y->p = x->p;
    
    if (x->p->key == NILKey)
        T = y;
    else if (x == x->p->left) 
        x->p->left = y;
    else
        x->p->right = y;
        
    y->left = x;
    x->p = y;
    
    return T;
}

struct nodeRBTree *rightRotate (struct nodeRBTree *T, struct nodeRBTree *x) {
    struct nodeRBTree *y;
    
    y = x->left;
    x->left = y->right;
    y->right->p = x;
    y->p = x->p;
    
    if (x->p->key == NILKey)
        T = y;
    else if (x == x->p->right) 
        x->p->right = y;
    else
        x->p->left = y;
        
    y->right = x;
    x->p = y;
    
    return T;
}

struct nodeRBTree *assignNilLeaf () {
    struct nodeRBTree *w;
    w = (struct nodeRBTree *) malloc (sizeof (struct nodeRBTree));
    w->color = BLACK;
    w->key = NILKey;
    w->left = NULL;
    w->right = NULL;
    
    return w;
}

struct nodeRBTree *RB_InsertFixup (struct nodeRBTree *T, struct nodeRBTree *z) {
    struct nodeRBTree *y;
    
    while (z->p->color == RED) {
        if (z->p == z->p->p->left) {
            y = z->p->p->right;
            if (y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else {
                if (z == z->p->right) {
                    z = z->p;
                    T = leftRotate (T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                T = rightRotate (T, z->p->p);
            }
        }
        else {
            y = z->p->p->left;
            if (y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else {
                if (z == z->p->left) {
                    z = z->p;
                    T = rightRotate (T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                T = leftRotate (T, z->p->p);
            }
        }
    }
    T->color = BLACK;
    
    return T;
}

struct nodeRBTree *RB_Insert (struct nodeRBTree *T, int k) {
    struct nodeRBTree *z, *x, *y;
    z = (struct nodeRBTree *) malloc (sizeof (struct nodeRBTree));
    z->color = RED;
    z->key = k;
    //z->frequency = 1;
    z->left = assignNilLeaf ();
    z->left->p = z;
    z->right = assignNilLeaf ();
    z->right->p = z;
    
    if (T->key != NILKey)
        y = T->p;
    else
        y = T;

    x = T;
    
    while (x->key != NILKey) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    
    if (y->key == NILKey)
        T = z; //The tree is empty.
    else {
        free (x);
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    T = RB_InsertFixup (T, z);
    
    return T;
}

struct nodeRBTree *RB_DeleteFixup (struct nodeRBTree *T, struct nodeRBTree *x) {
    struct nodeRBTree *w;
    
    while ((x != T) && (x->color == BLACK)) {
        if (x == x->p->left) {
            w = x->p->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                T = leftRotate (T, x->p);
                w = x->p->right;
            }
            if ((w->left->color == BLACK) && (w->right->color == BLACK)) {
                w->color = RED;
                x = x->p;
            }
            else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    T = rightRotate (T, w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                T = leftRotate (T, x->p);
                x = T;
            }
        }
        else {
            w = x->p->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                T = rightRotate (T, x->p);
                w = x->p->left;
            }
            if ((w->right->color == BLACK) && (w->left->color == BLACK)) {
                w->color = RED;
                x = x->p;
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    T = leftRotate (T, w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                T = rightRotate (T, x->p);
                x = T;
            }
        }
    }
    x->color = BLACK;
    
    return T;
}

struct nodeRBTree *RB_Delete (struct nodeRBTree *T, struct nodeRBTree *z)
{
    struct nodeRBTree *x, *y;
    if ((z->left->key == NILKey) || (z->right->key == NILKey))
        y = z;
    else
        y = treeSucessor(z);
    
    if (y->left->key != NILKey)
        x = y->left;
    else
        x = y->right;
        
    x->p = y->p;
    
    if (y->p->key == NILKey)
        T = x;
    else if (y == y->p->left)
        y->p->left = x;
     else
        y->p->right = x;
    
    if (y != z)
    {
        z->key = y->key;
        //z->frequency = y->frequency;
        // Copy all information fields from y to z.
    }
    
    if (y->color == BLACK)
        T = RB_DeleteFixup (T, x);
    if (y == y->left->p)
        free (y->left);
    if (y == y->right->p)
        free (y->right);
    free (y);
    
    return T;
}

struct nodeRBTree *deleteWholeRBTree (struct nodeRBTree *T) {
    while (T->key != NILKey)
        T = RB_Delete (T, T);
    
    return T;
}

int main () {
    int index, nFrogs, startingPosition, jumps, idJumping;
    frogs frog [MAXFROG + 1];
    struct nodeRBTree *z, *T, *sucessor;
    T = assignNilLeaf ();
    
    for (index = 1; index <= MAXN + 100; index++)
        T = RB_Insert (T, index);
    
    scanf ("%d", &nFrogs);
    
    for (index = 1; index <= nFrogs; index++) {
        scanf ("%d", &startingPosition);
        frog[index].id = index;
        frog[index].currentPosition = startingPosition;
        
        z = treeSearch (T, startingPosition);
        T = RB_Delete (T, z);
    }
    
    scanf ("%d", &jumps);
    
    while (jumps--) {
        scanf ("%d", &idJumping);
        T = RB_Insert (T, frog[idJumping].currentPosition);
        z = treeSearch (T, frog[idJumping].currentPosition);
        sucessor = treeSucessor (z);
        printf ("%d\n", sucessor->key);
        frog[idJumping].currentPosition = sucessor->key;
        T = RB_Delete (T, sucessor);
    }
    T = deleteWholeRBTree (T);

    return 0;
}
