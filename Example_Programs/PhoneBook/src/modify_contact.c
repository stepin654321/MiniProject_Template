#include "modify_contact.h"
#include "utility.h"

int modify_contact(char *name, contact_t *update_contact) {
  int result = 0;
  FILE *fptr;
  int flag = 0;
  contact_t old_contact;

  fptr = fopen("contacts.bin", "rb+");

  if (fptr == NULL) {
    return -2;
  } else {

    while (fread(&old_contact, sizeof(contact_t), 1, fptr) == 1) {
      if (strcmp(name, old_contact.name) == 0) {
        fseek(fptr, -sizeof(contact_t), SEEK_CUR);
        fwrite(update_contact, sizeof(contact_t), 1, fptr);
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      result = 0;
    } else {
      result = -1;
    }
    fclose(fptr);
  }
  return result;
}
