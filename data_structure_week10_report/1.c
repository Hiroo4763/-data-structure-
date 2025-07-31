#include <stdio.h>  
#include <stdlib.h>  

#define MAX_TERMS 100  

typedef struct {  
   int coef;  
   int exp;  
} Term;  

typedef struct {  
   Term terms[MAX_TERMS];  
   int term_count;  
} Polynomial;  

void add_term(Polynomial* p, int coef, int exp) {  
   p->terms[p->term_count].coef = coef;  
   p->terms[p->term_count].exp = exp;  
   p->term_count++;  
}  

Polynomial poly_add(Polynomial* a, Polynomial* b) {  
   Polynomial result;  
   result.term_count = 0;  
   int i = 0, j = 0;  

   while (i < a->term_count && j < b->term_count) {  
       if (a->terms[i].exp == b->terms[j].exp) {  
           int sum = a->terms[i].coef + b->terms[j].coef;  
           if (sum != 0)  
               add_term(&result, sum, a->terms[i].exp);  
           i++; j++;  
       }  
       else if (a->terms[i].exp > b->terms[j].exp) {  
           add_term(&result, a->terms[i].coef, a->terms[i].exp);  
           i++;  
       }  
       else {  
           add_term(&result, b->terms[j].coef, b->terms[j].exp);  
           j++;  
       }  
   }  

   while (i < a->term_count)  
       add_term(&result, a->terms[i].coef, a->terms[i].exp), i++;  
   while (j < b->term_count)  
       add_term(&result, b->terms[j].coef, b->terms[j].exp), j++;  

   return result;  
}  

void display_poly(const char* name, Polynomial* p) {  
   printf("%s = ", name);  
   for (int i = 0; i < p->term_count; i++) {  
       int coef = p->terms[i].coef;  
       int exp = p->terms[i].exp;  

       printf("%d", coef);  
       if (exp > 1)  
           printf("x^%d", exp);  
       else if (exp == 1)  
           printf("x^1");  

       if (i != p->term_count - 1)  
           printf(" + ");  
   }  
   printf("\n");  
}  

int main() {  
   Polynomial A;  
   A.term_count = 0;  
   Polynomial B;  
   B.term_count = 0;  

   add_term(&A, 3, 6);  
   add_term(&A, 7, 3);  
   add_term(&A, -2, 2);  
   add_term(&A, -9, 0);  

   add_term(&B, -2, 6);  
   add_term(&B, -4, 4);  
   add_term(&B, 6, 2);  
   add_term(&B, 6, 1);  
   add_term(&B, 1, 0);  

   Polynomial C = poly_add(&A, &B);  

   display_poly("A_Poly", &A);  
   display_poly("B_Poly", &B);  
   display_poly("Sum_Poly", &C);  

   return 0;  
}