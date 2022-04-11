#include<iostream> 

using namespace std; 

  

struct Node { 

    int coeff; 

    int pow; 

    struct Node* next; 

}; 

  

void create_node(int x, int y, struct Node** temp) 

{ 

    struct Node *r, *z; 

    z = *temp; 

    if (z == NULL) { 

        r = (struct Node*):: operator new(sizeof(struct Node)); 

        r->coeff = x; 

        r->pow = y; 

        *temp = r; 

        r->next = (struct Node*):: operator new(sizeof(struct Node)); 

        r = r->next; 

        r->next = NULL; 

    } 

    else { 

        r->coeff = x; 

        r->pow = y; 

        r->next = (struct Node*):: operator new(sizeof(struct Node)); 

        r = r->next; 

        r->next = NULL; 

    } 

} 

  

void polyadd(struct Node* poly1, struct Node* poly2, 

             struct Node* poly) 

{ 

    while (poly1->next && poly2->next) { 

         

        if (poly1->pow > poly2->pow) { 

            poly->pow = poly1->pow; 

            poly->coeff = poly1->coeff; 

            poly1 = poly1->next; 

        } 

  

        

        else if (poly1->pow < poly2->pow) { 

            poly->pow = poly2->pow; 

            poly->coeff = poly2->coeff; 

            poly2 = poly2->next; 

        } 

  

         

        else { 

            poly->pow = poly1->pow; 

            poly->coeff = poly1->coeff + poly2->coeff; 

            poly1 = poly1->next; 

            poly2 = poly2->next; 

        } 

  

         

        poly->next 

            = (struct Node*):: operator new(sizeof(struct Node)); 

        poly = poly->next; 

        poly->next = NULL; 

    } 

    while (poly1->next || poly2->next) { 

        if (poly1->next) { 

            poly->pow = poly1->pow; 

            poly->coeff = poly1->coeff; 

            poly1 = poly1->next; 

        } 

        if (poly2->next) { 

            poly->pow = poly2->pow; 

            poly->coeff = poly2->coeff; 

            poly2 = poly2->next; 

        } 

        poly->next 

            = (struct Node*):: operator new(sizeof(struct Node)); 

        poly = poly->next; 

        poly->next = NULL; 

    } 

} 

  

void show(struct Node* node) 

{ 

    while (node->next != NULL) { 

        printf("%dx^%d", node->coeff, node->pow); 

        node = node->next; 

        if (node->coeff >= 0) { 

            if (node->next != NULL) 

                printf("+"); 

        } 

    } 

} 

  

  

int main() 

{ 

    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 

    int x,y,z,a,b,c; 

    cout<<"Enter  coefficients of first polynomial :\n"; 

    cin>>x; 

    cin>>y; 

    cin>>z; 

    cout<<"Enter coefficients of first polynomial :\n"; 

    cin>>a; 

    cin>>b; 

    cin>>c; 

    create_node(x, 2, &poly1); 

    create_node(y, 1, &poly1); 

    create_node(z, 0, &poly1); 

  

    create_node(a, 2, &poly2); 

    create_node(b, 1, &poly2); 

    create_node(c, 0, &poly2); 

  

    cout<<"1st polynomial: "; 

    show(poly1); 

  

    cout<<"\n"<<"2nd polynomial: "; 

    show(poly2); 

  

    poly = (struct Node*):: operator new(sizeof(struct Node)); 

  

  

    polyadd(poly1, poly2, poly); 

  

    cout<<"\nAdded polynomial: "; 

    show(poly); 

  

    return 0; 

} 
