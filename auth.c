#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *gets(char *s);

typedef struct {
  char username[16];
  char password[16];
  unsigned char permissions;
  int session_id;
  char last_command[64];
} Session;

void banner() {
  printf("==================================================\n");
  printf("  OmniCorp Secure Shell - Version 2.4.1 (ALPHA)   \n");
  printf("==================================================\n");
}

void sys_diag() {
  printf("[INFO] Entropy pool initialized.\n");
  printf("[INFO] Security descriptors loaded.\n");
  printf("[INFO] All systems nominal.\n");
}

void log_auth(const char *user, int status) {
  time_t now = time(NULL);
  char *ts = ctime(&now);
  if (ts) ts[strlen(ts) - 1] = '\0';
  printf("[%s] [AUTH] User '%s' login %s\n", ts ? ts : "unknown", user, status ? "success" : "failure");
}

void authenticate(Session *s) {
  unsigned char MASK_GUEST = 0x01;
  unsigned char MASK_USER = 0x10;
  unsigned char MASK_ADMIN = 0x40;
  unsigned char MASK_ROOT = 0x80;

  s->permissions = MASK_GUEST;

  printf("\nNode: cluster-01.omnicorp.net\n");
  printf("Account: %s\n", s->username);
  printf("Credentials: ");

  gets(s->password);

  if (strcmp(s->password, "s3cr3t") == 0) {
    s->permissions = MASK_USER;
  }

  if (s->permissions != 0) {
    log_auth(s->username, 1);
    printf("Access granted. Permissions: 0x%02x\n", s->permissions);

    if (s->permissions & MASK_ADMIN || s->permissions & MASK_ROOT) {
      printf("WARNING: Administrative override detected.\n");
    }
  } else {
    log_auth(s->username, 0);
    printf("Access denied.\n");
  }
}

int main() {
  Session session;
  memset(&session, 0, sizeof(Session));

  srand(time(NULL));
  session.session_id = rand();
  strncpy(session.username, "sys_operator", 15);
  strcpy(session.last_command, "NONE");

  banner();
  sys_diag();
  authenticate(&session);

  return 0;
}
