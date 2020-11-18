#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "add_contact.h"
#include "utility.h"

int add_contact(contact_t *contact) {

  FILE *fptr;
  if ((fptr = fopen("contacts.bin", "ab+")) == NULL) {
    return -1;
  }
  fwrite(contact, sizeof(contact_t), 1, fptr);

  __fpurge(stdin);
  fclose(fptr);

  return 0;
}
/*
void create_new_contact(contact_t *contact) {
  printf("\nEnter name: ");
  get_data(contact->name);

  printf("\nEnter the Phone number: ");
  get_data(contact->ph_number);

  printf("\nEnter Email ID: ");
  get_data(contact->email_id);
}
*/