#include <stdio.h>
#include <stdlib.h>

#include "display_contact.h"

int display_contact(void) {
  contact_t contact;
  FILE *fptr;
  int count = 0;
  if ((fptr = fopen("contacts.bin", "rb")) == NULL) {
    return -2;
  }

  printf("\n### Phone book contacts ###\n");
  while (fread(&contact, sizeof(contact), 1, fptr) == 1) {
    printf("Name = %s\nPhone Number = %s\nEmail ID = %s\n\n", contact.name,
           contact.ph_number, contact.email_id);
    count++;
  }
  printf("### Phone book contacts ###\n\n");
  fclose(fptr);
  return count;
}
