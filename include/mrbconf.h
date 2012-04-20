/*
** mrbconf.h - mruby core configuration
** 
** See Copyright Notice in mruby.h
*/

#ifndef MRUBYCONF_H
#define MRUBYCONF_H

#include <stdint.h>
typedef double mrb_float;
typedef int32_t mrb_int;
typedef intptr_t mrb_sym;
typedef intptr_t ssize_t;

#define readint(p,base) strtol((p),NULL,(base))
#define readfloat(p) strtod((p),NULL)

#undef  INCLUDE_ENCODING   /* not use encoding classes (ascii only) */
#define INCLUDE_ENCODING   /* use UTF-8 encoding classes */

#undef  INCLUDE_REGEXP     /* not use regular expression classes */
#define INCLUDE_REGEXP     /* use regular expression classes */

#ifdef  INCLUDE_REGEXP
# define INCLUDE_ENCODING  /* Regexp depends Encoding */
#endif

#undef  HAVE_UNISTD_H /* WINDOWS */

#define HAVE_STRING_H

#ifndef FALSE
# define FALSE 0
#endif

#ifndef TRUE
# define TRUE 1
#endif

#define snprintf _snprintf
#define strncasecmp(d, s, n) strnicmp(d, s, n)
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x) && !_isnan(x))

#endif	/* MRUBYCONF_H */
