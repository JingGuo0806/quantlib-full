
// $Id$

#ifndef quantlib_config_decc_h
#define quantlib_config_decc_h

#define HAVE_STDLIB_H
#define QL_SIZE_T size_t

#define HAVE_MATH_H
#define QL_SQRT   sqrt
#define QL_FABS   fabs
#define QL_EXP    exp
#define QL_LOG    log
#define QL_SIN    sin
#define QL_COS    cos
#define QL_POW    pow
#define QL_MODF   modf

#define HAVE_LIMITS

#define HAVE_TIME_H
#define QL_CLOCK  clock
#define QL_TIME   time

#define HAVE_CTYPE_H
#define QL_STRLEN   strlen
#define QL_TOLOWER  tolower
#define QL_TOUPPER  toupper

#define HAVE_STDIO_H
#define QL_SPRINTF  sprintf

#define QL_ITERATOR         std::iterator
#define QL_ITERATOR_TRAITS  std::iterator_traits


#endif
