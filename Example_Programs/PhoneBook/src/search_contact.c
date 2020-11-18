#include "search_contact.h"
#include "utility.h"

int search_contact(const char *name) {
  contact_t contact;
  FILE *f;

  f = fopen("contacts.bin", "rb");
  if (f == NULL) {
    return -2;
  }

  while (fread(&contact, sizeof(contact_t), 1, f) == 1) {
    if (strcmp(contact.name, name) == 0) {
      printf("\nContact details for %s:\n", name);
      printf("Name = %s\nPhone Number = %s\nEmail ID = %s\n\n", contact.name,
             contact.ph_number, contact.email_id);
      fclose(f);
      return 0;
    }
  }
  fclose(f);
  return -1;
}
