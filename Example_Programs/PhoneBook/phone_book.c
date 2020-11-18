#include "phone_book.h"

typedef enum options {
  NONE,
  ADD_CONTACT,
  MODIFY_CONTACT,
  DELETE_CONTACT,
  DISPLAY_CONTACTS,
  SEARCH_CONTACTS,
  EXIT
} options_t;

int main() {
  int choice = NONE;

  printf("\n\t****Welcome to Phone book application****\n");
  for (;;) {

    printf("\nSelect your choice: \n");
    printf("1.Add Contact \n2.Modify Contact \n3.Delete Contact \
        \n4.Display all Contacts \n5.Search for a contact\n6.Exit\n");

    printf("Enter your choice: ");
    __fpurge(stdin);
    scanf("%d", &choice);

    switch (choice) {
    case ADD_CONTACT: {
      contact_t *new_contact = (contact_t *)calloc(1, sizeof(contact_t));

      get_contact_details(new_contact);
      switch (add_contact(new_contact)) {
      case 0:
        printf("\n\t Add contact successful");
        break;
      default:
        printf("\n\t***Error in adding contact***");
      }
      free(new_contact);
      break;
    }
    case DELETE_CONTACT: {
      int contact_count = display_contact();
      if (0 < contact_count) {
        char name[MAX_NAME_LEN] = "";

        printf("Enter Contact'S Name from above list:");
        get_data(name);

        switch (delete_contact(name)) {
        case -1:
          printf("\n\t***No Matching contact found***\n");
          break;
        case -2:
          printf("\n\t***No contact found***\n");
          break;
        case 0:
          printf("\n\t***Contact record deleted successfuly***\n");
          break;
        default:
          printf("\n\t***Error in Delete contact***");
        }
      } else if (contact_count == 0) {
        printf("\n\t***No contact found***\n");
      }
      break;
    }
    case MODIFY_CONTACT: {
      int contact_count = display_contact();
      if (0 < contact_count) {
        char name[MAX_NAME_LEN] = "";
        contact_t *new_contact = (contact_t *)calloc(1, sizeof(contact_t));

        printf("Enter Contact'S Name from above list:");

        get_data(name);
        get_contact_details(new_contact);

        switch (modify_contact(name, new_contact)) {
        case -1:
          printf("\n\t***No Matching contact found***\n");
          break;
        case -2:
          printf("\n\t***No contact found***\n");
          break;
        case 0:
          printf("\n\t***Contact record Modify successfuly***\n");
          break;
        default:
          printf("\n\t***Error in Modify contact***");
        }
        free(new_contact);
      } else if (contact_count == 0) {
        printf("\n\t***No contact found***\n");
      }
      break;
    }
    case DISPLAY_CONTACTS:
      switch (display_contact()) {
      case -2:
        printf("\n\t***No Contacts found***\n\n");
        break;
      case 0:
        printf("\n\t***No Contacts found***\n\n");
        break;
      default:
        printf("\n\t***Display contacts record successfuly***\n");
      }
      break;

    case SEARCH_CONTACTS: {
      int contact_count = display_contact();
      if (0 < contact_count) {
        char name[MAX_NAME_LEN] = "";

        printf("\nEnter name of person to search\n");
        __fpurge(stdin);
        get_data(name);

        switch (search_contact(name)) {
        case -1:
          printf("\n\t***No Matching contact found***\n");
          break;
        case -2:
          printf("\n\t***No Contacts found***\n\n");
          break;
        case 0:
          printf("\n\t***Search Successful***\n");
          break;
        default:
          printf("\n\t***Error in Search contact***");
        }
      }

      else if (contact_count == 0) {
        printf("\n\t***No contact found***\n");
      }
      break;
    }
    case EXIT:
      printf("\n\t****Exiting application****\n");
      exit(0);
      break;

    default:
      printf("\n\t***Selected option not available***");
    }
  }
}
