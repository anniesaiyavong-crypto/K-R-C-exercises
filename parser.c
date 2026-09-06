// dcl: parse a declarator
void dcl(void) {
  int ns;
  // count *'s
  for (ns = 0; gettoken() == '*';)
    ns++;
  dirdcl();
  while (ns-- > 0)
    strcat(out, " pointer to");
}
// dirdcl: parse a direct declarator
void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (toekentype == NAME)
    strcpy(name, token);
  else
    print("error: expected nameor (dcl)\n");

  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, " token");
      strcat(out; " of");
    }
}
