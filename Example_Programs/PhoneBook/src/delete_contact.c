#include "delete_contact.h"
#include "utility.h"

int delete_contact(const char *name) {
  contact_t contact;
  FILE *f, *ft;
  int flag, result;

  f = fopen("contacts.bin", "rb");
  if (f == NULL) {
    return -2;
  } else {
    ft = fopen("temp.bin", "wb+");
    if (ft == NULL) {
      result = -3;
    } else {

      while (fread(&contact, sizeof(contact_t), 1, f) == 1) {
        if (strcmp(contact.name, name) != 0)
          fwrite(&contact, sizeof(contact_t), 1, ft);
        if (strcmp(contact.name, name) == 0)
          flag = 1;
      }
      fclose(f);
      f = NULL;
      fclose(ft);

      if (flag != 1) {
        remove("temp.bin");
        result = -1;
      } else {
        remove("contacts.bin");
        rename("temp.bin", "contacts.bin");
        result = 0;
      }
    }
  }
  if (NULL != f)
    fclose(f);

  return result;
}
