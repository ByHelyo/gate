#include "http/request/sub_delims.h"

int is_sub_delims(char ch) {
  return ch == '!' || ch == '$' || ch == '&' || ch == '\'' || ch == '(' ||
         ch == ')' || ch == '*' || ch == '+' || ch == ',' || ch == ';' ||
         ch == '=';
}
