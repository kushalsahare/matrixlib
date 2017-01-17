
#ifndef MATRIXLIB_BRAINCORPS_API_H
#define MATRIXLIB_BRAINCORPS_API_H

#ifdef MATRIXLIB_BRAINCORPS_STATIC_DEFINE
#  define MATRIXLIB_BRAINCORPS_API
#  define MATRIXLIB_BRAINCORPS_NO_EXPORT
#else
#  ifndef MATRIXLIB_BRAINCORPS_API
#    ifdef matrixlib_braincorps_shared_EXPORTS
        /* We are building this library */
#      define MATRIXLIB_BRAINCORPS_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define MATRIXLIB_BRAINCORPS_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MATRIXLIB_BRAINCORPS_NO_EXPORT
#    define MATRIXLIB_BRAINCORPS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MATRIXLIB_BRAINCORPS_DEPRECATED
#  define MATRIXLIB_BRAINCORPS_DEPRECATED __attribute__ ((__deprecated__))
#  define MATRIXLIB_BRAINCORPS_DEPRECATED_EXPORT MATRIXLIB_BRAINCORPS_API __attribute__ ((__deprecated__))
#  define MATRIXLIB_BRAINCORPS_DEPRECATED_NO_EXPORT MATRIXLIB_BRAINCORPS_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define MATRIXLIB_BRAINCORPS_NO_DEPRECATED
#endif

#endif
