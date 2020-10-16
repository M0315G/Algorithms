#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node
{
    int val, degree;
    struct Node *parent, *child, *sibling;
};

struct Node *root = NULL;

int binomialLink(struct Node *h1, struct Node *h2)
{
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree = h2->degree + 1;
}

// create a Node
struct Node *createNode(int n)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    ;
    new_node->val = n;
    new_node->parent = NULL;
    new_node->sibling = NULL;
    new_node->child = NULL;
    new_node->degree = 0;
    return new_node;
}

struct Node *mergeBHeaps(struct Node *h1, struct Node *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    struct Node *res = NULL;

    if (h1->degree <= h2->degree)
        res = h1;

    else if (h1->degree > h2->degree)
        res = h2;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->degree < h2->degree)
            h1 = h1->sibling;

        else if (h1->degree == h2->degree)
        {
            struct Node *sib = h1->sibling;
            h1->sibling = h2;
            h1 = sib;
        }

        // if h2 is greater
        else
        {
            struct Node *sib = h2->sibling;
            h2->sibling = h1;
            h2 = sib;
        }
    }
    return res;
}

// This function perform union operation on two
// binomial heap i.e. h1 & h2
struct Node *unionBHeaps(struct Node *h1, struct Node *h2)
{
    if (h1 == NULL && h2 == NULL)
        return NULL;

    struct Node *res = mergeBHeaps(h1, h2);

    struct Node *prev = NULL, *curr = res,
                *next = curr->sibling;
    while (next != NULL)
    {
        if ((curr->degree != next->degree) ||
            ((next->sibling != NULL) &&
             (next->sibling)->degree ==
                 curr->degree))
        {
            prev = curr;
            curr = next;
        }

        else
        {
            if (curr->val <= next->val)
            {
                curr->sibling = next->sibling;
                binomialLink(next, curr);
            }
            else
            {
                if (prev == NULL)
                    res = next;
                else
                    prev->sibling = next;
                binomialLink(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return res;
}

// Function to insert a Node
void binomialHeapInsert(int x)
{
    root = unionBHeaps(root, createNode(x));
}

// Function to display the Nodes
void display(struct Node *h, char arr[50], int value)
{
    while (h)
    {
        if (value == -1)
        {
            printf("\nRoot Node: %d ", h->val);
        }
        else
        {
            printf("\n%d %s %d", h->val, arr, value);
        }

        display(h->child, "is a child of ", h->val);
        value = h->val;
        h = h->sibling;
        arr = "is a Sibling of ";
    }
}

int revertList(struct Node *h)
{
    if (h->sibling != NULL)
    {
        revertList(h->sibling);
        (h->sibling)->sibling = h;
    }
    else
        root = h;
}

// Function to extract minimum value
struct Node *extractMinBHeap(struct Node *h)
{
    if (h == NULL)
        return NULL;

    struct Node *min_node_prev = NULL;
    struct Node *min_node = h;

    // Find minimum value
    int min = h->val;
    struct Node *curr = h;
    while (curr->sibling != NULL)
    {
        if ((curr->sibling)->val < min)
        {
            min = (curr->sibling)->val;
            min_node_prev = curr;
            min_node = curr->sibling;
        }
        curr = curr->sibling;
    }

    if (min_node_prev == NULL &&
        min_node->sibling == NULL)
        h = NULL;

    else if (min_node_prev == NULL)
        h = min_node->sibling;

    // Remove min node from list
    else
        min_node_prev->sibling = min_node->sibling;

    if (min_node->child != NULL)
    {
        revertList(min_node->child);
        (min_node->child)->sibling = NULL;
    }

    return unionBHeaps(h, root);
}

// Function to search for an element
struct Node *findNode(struct Node *h, int val)
{
    if (h == NULL)
        return NULL;

    if (h->val == val)
        return h;

    // Recur for child
    struct Node *res = findNode(h->child, val);
    if (res != NULL)
        return res;

    return findNode(h->sibling, val);
}

void decreaseKeyBHeap(struct Node *H, int old_val,
                      int new_val)
{
    struct Node *node = findNode(H, old_val);

    if (node == NULL)
        return;

    node->val = new_val;
    struct Node *parent = node->parent;

    while (parent != NULL && node->val < parent->val)
    {
        int temp = node->val;
        node->val = parent->val;
        parent->val = temp;
        //swap(node->val, parent->val);
        node = parent;
        parent = parent->parent;
    }
}

// Function to delete an element
struct Node *binomialHeapDelete(struct Node *h, int val)
{
    if (h == NULL)
        return NULL;

    decreaseKeyBHeap(h, val, INT_MIN);
    return extractMinBHeap(h);
}
////////////////////////////////////////////////////////////// Binomial Tree //////////////////////////////////////////////////////////////////////

struct Node *bH = NULL;

struct Node *b_tree_union(struct Node *H1, struct Node *H2)
{
    struct Node *temp1;
    struct Node *temp2;
    struct Node *head;
    struct Node *temp;

    temp1 = H1;
    temp2 = H2;

    if (temp1->degree == 0)
    {
        if (temp1->val < temp2->val)
        {
            temp2->child = temp1;
            temp1->parent = temp2;
            temp2->degree += 1;
            head = temp2;
        }
        else
        {
            temp1->child = temp2;
            temp2->parent = temp1;
            temp1->degree += 1;
            head = temp1;
        }
    }
    else
    {
        if (temp1->val < temp2->val)
        {
            temp = temp2->child;
            while (temp->sibling != NULL)
            {
                temp = temp->sibling;
            }
            temp->sibling = temp1;
            temp1->parent = temp2;
            temp2->degree += 1;
            head = temp2;
        }
        else
        {
            temp = temp1->child;
            while (temp->sibling != NULL)
            {
                temp = temp->sibling;
            }
            temp->sibling = temp2;
            temp2->parent = temp1;
            temp1->degree += 1;
            head = temp1;
        }
    }

    return head;
}

struct Node *create_b_tree(struct Node *H1, int order)
{
    struct Node *head1;
    struct Node *head2;
    struct Node *head;
    if (order == 0)
    {
        int val;
        printf("\nEnter a number for a node: ");
        scanf("%d", &val);
        struct Node *n_node = createNode(val);
        //head = n_node;
        return n_node;
    }

    head1 = create_b_tree(H1, order - 1);
    head2 = create_b_tree(H1, order - 1);

    head = b_tree_union(head1, head2);
    H1 = head;
    head = H1;
    return head;
}

/////////////////////////////////////////////////////////////// Main Function //////////////////////////////////////////////////////////////////////

void main()
{
    int ans = -1, choice = -1, order;
    int i, n, m, l, ans1;
    struct Node *p;
    struct Node *np;
    while (ans != 0)
    {
        //printf("\n#################### MENU ########################");
        printf("__________________________________________________________");
        printf("\nEnter your choice:");
        printf("\nENter 1 for Binomial Tree");
        printf("\nEnter 2 for Binomial Heap");
        printf("\nEnter 0 to exit.");
        scanf("%d", &ans);

        switch (ans)
        {
        case 2:
            printf("\nHow many elemets should be there?:");
            scanf("%d", &n);
            printf("\nEnter %d elements one by one:\n", n);
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &m);
                binomialHeapInsert(m);
            }

            printf("The formed Binomial Heap is:");
            display(root, "Root node", -1);
            while (choice != 0)
            {
                //printf("\n############### MENU No.2 ########################");
                printf("__________________________________________________________");
                printf("\nEnter 1 to Insert an element.");
                printf("\nEnter 2 to Delete a node");
                printf("\nEnter 0 to exit");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("\nEnter the key:");
                    scanf("%d", &m);
                    binomialHeapInsert(m);
                    printf("\nThe contents of the heap after insertion are:\n");
                    display(root, "Root node", -1);
                    break;
                case 2:
                    printf("\nEnter the key of the node to be deleted(it should be present in the heap): ");
                    scanf("%d", &m);
                    root = binomialHeapDelete(root, m);
                    printf("\nThe contents of the heap after deleting the node are:\n");
                    display(root, "Root node", -1);
                    break;
                case 0:
                    printf("Exiting the loop...");
                    break;
                default:
                    printf("Choose a Valid value!");
                    break;
                }
            }

            choice = -1;
            break;
        case 1:
            printf("Enter the order of B tree: ");
            scanf("%d", &order);
            bH = create_b_tree(bH, order);
            display(bH, "Tree Root", -1);
            break;
        case 0:
            printf("Exiting the code...");
            break;
        default:
            printf("Choose a valid value!");
            break;
        }
    }
}
