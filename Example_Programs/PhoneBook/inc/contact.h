/** 
* @file contact.h
*
*/
#ifndef __CONTACT_H__
#define __CONTACT_H__

enum max_lengths {
    MAX_NAME_LEN = 32,
    MAX_PHONE_NUMBER_LEN = 15,
    MAX_EMAIL_ID_LEN = 100
};

typedef struct contact_t{
    char name[MAX_NAME_LEN];
    char ph_number[MAX_PHONE_NUMBER_LEN];
    char email_id[MAX_EMAIL_ID_LEN];
}contact_t;

#endif  //__CONTACT_H__
