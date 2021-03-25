#include <stdio.h>
#include <stdlib.h>

struct complex
{
  int real, img;
};

int main()
{
  int choice, x, y, z;
  struct complex a, b, c;

  while(1)
  {
    printf("Press 1 to add two complex numbers.\n");
    printf("Press 2 to difference two complex numbers.\n");
    printf("Press 3 to product two complex numbers.\n");
    printf("Press 4 to divide two complex numbers.\n");
    printf("Press 5 to exit.\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);

    if (choice == 5)
      exit(0);

    if (choice >= 1 && choice <= 4)
    {
      printf("Enter a and b where a + ib is the first complex number.");
      printf("\na = ");
      scanf("%d", &a.real);
      printf("b = ");
      scanf("%d", &a.img);
      printf("Enter c and d where c + id is the second complex number.");
      printf("\nc = ");
      scanf("%d", &b.real);
      printf("d = ");
      scanf("%d", &b.img);
    }
    if (choice == 1)
    {
      c.real = a.real + b.real;
      c.img = a.img + b.img;

      if (c.img >= 0)
        printf("Sum of the complex numbers = %d + %di", c.real, c.img);
      else
        printf("Sum of the complex numbers = %d %di", c.real, c.img);
    }
    else if (choice == 2)
    {
      c.real = a.real - b.real;
      c.img = a.img - b.img;

      if (c.img >= 0)
        printf("Difference of the complex numbers = %d + %di", c.real, c.img);
      else
        printf("Difference of the complex numbers = %d %di", c.real, c.img);
    }
    else if (choice == 3)
    {
      c.real = a.real*b.real - a.img*b.img;
      c.img = a.img*b.real + a.real*b.img;

      if (c.img >= 0)
        printf("product of the complex numbers = %d + %di", c.real, c.img);
      else
        printf("product of the complex numbers = %d %di", c.real, c.img);
    }
    else if (choice == 4)
    {
      if (b.real == 0 && b.img == 0)
        printf("Division by 0 + 0i isn't allowed.");
      else
      {
        x = a.real*b.real + a.img*b.img;
        y = a.img*b.real - a.real*b.img;
        z = b.real*b.real + b.img*b.img;

        if (x%z == 0 && y%z == 0)
        {
          if (y/z >= 0)
            printf("Division of the complex numbers = %d + %di", x/z, y/z);
          else
            printf("Division of the complex numbers = %d %di", x/z, y/z);
        }
        else if (x%z == 0 && y%z != 0)
        {
          if (y/z >= 0)
            printf("Division of two complex numbers = %d + %d/%di", x/z, y, z);
          else
            printf("Division of two complex numbers = %d %d/%di", x/z, y, z);
        }
        else if (x%z != 0 && y%z == 0)
        {
          if (y/z >= 0)
            printf("Division of two complex numbers = %d/%d + %di", x, z, y/z);
          else
            printf("Division of two complex numbers = %d %d/%di", x, z, y/z);
        }
        else
        {
          if (y/z >= 0)
            printf("Division of two complex numbers = %d/%d + %d/%di",x, z, y, z);
          else
            printf("Division of two complex numbers = %d/%d %d/%di", x, z, y, z);
        }
      }
    }
    else
      printf("Invalid choice.");

    printf("\nPress any key to enter choice again...\n");
  }
}
