/**
 * @brief Example to show the sequence points
 * Since compilers have option to implement the sequence points, every compiler implements in thier own way.
 * The same can be seen from this website: https://godbolt.org/ 
 */

unsigned counter = 0;

unsigned account(void) {
   return counter++;
}

int main()
{
    int i = 0;
    int a[10] ={};

    /* Expressions with no Sequnece points */
    a[i++] = i;
    a[i] = i++;

    f() + g();
     
     i++ * i++;

    i++ & i++;
    f(x++, x++); /* the ',' in a function call is *not* the same as the comma operator */
    i++ * i++;
    
    printf("the order is %u %u\n", account(), account());
}
