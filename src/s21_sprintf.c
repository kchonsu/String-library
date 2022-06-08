#include "s21_string.h"

#define check_digit(d) ((d) >= '0' && (d) <= '9')
#define is_spec(ch) ((ch) == 'c' || \
    (ch) == 'd' || (ch) == 'i' || (ch) == 'f' || (ch) == 's' || (ch) == 'u' || (ch) == '%' || \
    (ch) == 'g' || (ch) == 'G' || (ch) == 'e' || (ch) == 'E' || (ch) == 'x' || (ch) == 'X' || \
    (ch) == 'o' || (ch) == 'n' || (ch) == 'p')
#define is_flag(ch) ((ch) == '-' || (ch) == '+' || (ch) == ' ' || (ch) == '#' || (ch) == '0')

int s21_sprintf(char *str, const char *format, ...) {
  va_list vl;
  int i = 0;
  va_start(vl, format);
  token tok;
  str = s21_strcpy(str, "");

  while (format && *format) {
    if (*format == '%') {
      init_struct(&tok);

      format++;
      if (is_flag(*format)) {
        while (is_flag(*format)) switch_flags(format++, &tok);
      }

      if (check_digit(*format) || *format == '*') format = read_digit(format, &tok.width, &vl);

      if (*format == '.') format = read_digit(++format, &tok.accur, &vl);

      if (*format == 'h' || *format == 'l' || *format == 'L') tok.length = *(format++);
      if (is_spec(*format)) tok.spec = *(format++);

      str = switch_spec(&tok, str, &vl, &i);
    } else {
      str[i++] = *(format++);
      str[i] = '\0';
    }
  }
  va_end(vl);
  return s21_strlen(str);
}

void init_struct(token *tok) {
  tok->flag_plus = 0;
  tok->flag_minus = 0;
  tok->flag_space = 0;
  tok->flag_grid = 0;
  tok->flag_zero = 0;
  tok->width = -1;
  tok->accur = -1;
  tok->minus = 0;
  tok->length = '0';
  tok->spec = '0';
}

void switch_flags(const char *format, token *tok) {
  switch (*format) {
    case '-' : tok->flag_minus = 1; break;
    case '+' : tok->flag_plus = 1; break;
    case ' ' : tok->flag_space = 1; break;
    case '#' : tok->flag_grid = 1; break;
    case '0' : tok->flag_zero = 1; break;
  }
}


char* switch_spec(token *tok, char *str, va_list *vl, int *i) {
  char *tmp = s21_NULL;
  tmp = calloc(1000 + tok->width + 2, sizeof (char));
  if (tmp != s21_NULL) {
    char *start = tmp;
    switch (tok->spec) {
      case 'c': c_print(tok, tmp, vl); break;
      case 's': s_print(tok, tmp, vl); break;
      case 'd':
      case 'i': d_print(tok, tmp, vl); break;
      case 'f': f_print(tok, tmp, vl); break;
      case 'u': u_print(tok, tmp, vl); break;
      case '%': s21_strcat(tmp, "%"); break;
    }
    s21_strcat(str, tmp);
    free(start);
    *i = s21_strlen(str);
  }
  return str;
}

char* read_digit(const char* format, int *dig, va_list *vl) {
  *dig = 0;
  while (check_digit(*format)) {
    *dig = *format - '0' + *dig * 10;
    format++;
  }
  if (*format == '*') {
    *dig = va_arg(*vl, int);
    format++;
  }
  return (char *) format;
}

char* c_print(token *tok, char *str, va_list *vl) {
  if (tok->length == 'l')
    str[0] = (char) va_arg(*vl, wchar_t);
  else
    str[0] = va_arg(*vl, int);
  str[1] = '\0';
  all_width(str, tok);
  return str;
}

char* wchar_to_str(token *tok, wchar_t* warr, char* str) {
  int count = 0;
  while (*warr != '\0' && (count++ < tok->accur || tok->accur == -1)) {
    *(str++) = (char)*(warr++);
  }
  return str;
}

char* s_print(token *tok, char *str, va_list *vl) {
  wchar_t *warr = s21_NULL;
  char *tmp = s21_NULL;

  switch (tok->length) {
    case 'l' :
      warr = va_arg(*vl, wchar_t*);
      if (!warr) {
        if (tok->accur < 6)
          s21_strncat(str, "(null)", tok->accur);
        else
          s21_strcat(str, "(null)");
      } else {
        wchar_to_str(tok, warr, str);
      }
      break;
    default : tmp = va_arg(*vl, char*);
      if (!tmp) {
        if (tok->accur < 6)
          s21_strncat(str, "(null)", tok->accur);
        else
          s21_strcat(str, "(null)");
      } else {
        if (tok->accur > -1)
          s21_strncat(str, tmp, tok->accur);
        else
          s21_strcat(str, tmp);
      }
  }
  all_width(str, tok);
  return str;
}


char* d_print(token *tok, char *str, va_list *vl) {
  if (tok->length == 'l') {
    long int l_val = (long int) va_arg(*vl, long int);
    if (l_val < 0) {
      l_val *= -1;
      tok->minus = 1;
    }
    unsigned_itoa(l_val, str);
  } else {
    int val = (int) va_arg(*vl, int);
    if (tok->length == 'h') val = (short) val;
    if (val == -2147483648) {
      s21_strcat(str, "-2147483648");
    } else {
      if (val < 0) {
        tok->minus = 1;
        val *= -1;
      }
      unsigned_itoa(val, str);
    }
  }
  paste_flags(str, tok);
  accur_dig(str, tok);
  all_width(str, tok);
  return str;
}

char* f_print(token *tok, char *str, va_list *vl) {
  double tmp_val = va_arg(*vl, double);

  if (tmp_val < 0) {
    tok->minus = 1;
    tmp_val *= -1;
  }

  ftoa(tok, str, tmp_val);
  paste_flags(str, tok);
  accur_dig(str, tok);
  all_width(str, tok);

  return str;
}

char* u_print(token *tok, char *str, va_list *vl) {
  if (tok->length == 'l') {
    unsigned long l_val = (unsigned long) va_arg(*vl, unsigned long);
    unsigned_itoa(l_val, str);
  } else {
    unsigned val = (unsigned int) va_arg(*vl, unsigned int);
    if (tok->length == 'h') val = (unsigned short) val;
    unsigned_itoa(val, str);
  }
  paste_flags(str, tok);
  accur_dig(str, tok);
  all_width(str, tok);
  return str;
}

void ftoa(token *tok, char *str, long double num) {
  char _buf[1024] = {};
  char *buf = _buf;
  unsigned long long ipart;

  if (tok->accur == -1) tok->accur = 6;

  ipart = !tok->accur ? (unsigned long long)round(num) : (unsigned long long)num;
  unsigned_itoa(ipart, buf);
  if (tok->flag_grid || tok->accur) s21_strcat(buf, ".");
  if (tok->accur) {
    long double fpart = num - (long long) num;
    int acc = tok->accur;
    while (acc--) fpart *= 10;

    char _tmp[1024] = {};
    char *tmp = _tmp;
    unsigned_itoa((long long)roundl(fpart), tmp);
    int len = s21_strlen(tmp);
    while (len++ < tok->accur)
      s21_strcat(buf, "0");
    s21_strcat(buf, tmp);
  }
  s21_strcat(str, buf);
}

char* unsigned_itoa(unsigned long long num, char* str) {
  int flag = 1;
  char *in = s21_NULL;
  in = str;

  while (flag) {
    int digit;
    if (num >= 10) {
      digit = (unsigned long long) (num % 10);
      num = (num - digit) / 10;
    } else {
      digit = (unsigned long long) num;
      flag = 0;
    }
    *(in++) = (char) (digit + '0');
  }
  *in = '\0';
  reverse(str);
  return str;
}

char* reverse(char *str) {
  s21_size_t str_len = s21_strlen(str);
  for (s21_size_t i = 0; i < str_len / 2; i++) {
    char ch = str[i];
    str[i] = str[str_len - 1 - i];
    str[str_len - 1 - i] = ch;
  }
  return str;
}

char* paste_flags(char *str, token *tok) {
  if (check_digit(*str) || *str == 'i') {
    char num_str[2] = "";
    char *p = s21_NULL;
    p = num_str;
    if (tok->flag_plus && !tok->minus)
      *(p++) = '+';
    else if (tok->flag_space && !tok->flag_plus && !tok->minus)
      *(p++) = ' ';
    else if (tok->minus)
      *(p++) = '-';
    *p = '\0';
    reverse(str);
    s21_strcat(str, num_str);
    reverse(str);
  }
  return str;
}

char *all_width(char *str, token *tok) {
  int str_len = (int) s21_strlen(str);
  if (tok->width > (int) str_len) {
    char *num_str = calloc(1000 + tok->width + 2, sizeof (char));
    if (num_str) {
      for (int i = 0; i < tok->width; i++) {
        if (tok->flag_minus) {
          if (i < str_len) {
            num_str[i] = str[i];
          } else {
            num_str[i] = ' ';
          }
        } else {
          if (i < tok->width - str_len) {
            num_str[i] = ' ';
          } else {
            num_str[i] = str[i - (tok->width - str_len)];
          }
        }
      }
      num_str[tok->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *accur_dig(char *str, token *tok) {
  char *num_str = calloc(1000 + tok->width + 2, sizeof (char));
  if (num_str) {
    s21_size_t str_len = s21_strlen(str);

    char *p = s21_NULL;
    char *s = s21_NULL;
    p = num_str;
    s = str;

    int sign = tok->minus == 1 || tok->flag_plus || tok->flag_space == 1 ? -1 : 0;

    if (tok->flag_zero)
      tok->accur = (tok->accur + sign > tok->width + sign) ? tok->accur + sign : tok->width + sign;

    tok->accur = tok->accur > (int) str_len + sign ? tok->accur : (int) str_len + sign;


    reverse(str);

    for (int i = 0; i < tok->accur; i++) {
      if (i < (int) str_len + sign)
        *(p++) = *(s++);
      else
        *(p++) = '0';
    }

    if (sign < 0 && tok->minus)
      *(p++) = '-';
    else if (sign < 0 && tok->flag_plus)
      *(p++) = '+';
    else if (sign < 0 && tok->flag_space)
      *(p++) = ' ';

    *p = '\0';
    reverse(num_str);
    s21_strcpy(str, num_str);
    free(num_str);
  }
  return str;
}
