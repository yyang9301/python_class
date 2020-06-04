/* File: _write_sfcmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Sun Apr 19 13:57:06 2020
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <string.h>
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *_write_sfc_error;
static PyObject *_write_sfc_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
typedef char * string;

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
\
#define FAILNULL(p) do {                                            \
    if ((p) == NULL) {                                              \
        PyErr_SetString(PyExc_MemoryError, "NULL pointer found");   \
        goto capi_fail;                                             \
    }                                                               \
} while (0)

#define STRINGMALLOC(str,len)\
    if ((str = (string)malloc(sizeof(char)*(len+1))) == NULL) {\
        PyErr_SetString(PyExc_MemoryError, "out of memory");\
        goto capi_fail;\
    } else {\
        (str)[len] = '\0';\
    }

#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define STRINGFREE(str) do {if (!(str == NULL)) free(str);} while (0)

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(_write_sfc_error,errstring);\
        /*goto capi_fail;*/\
    } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif

#define STRINGCOPYN(to,from,buf_size)                           \
    do {                                                        \
        int _m = (buf_size);                                    \
        char *_to = (to);                                       \
        char *_from = (from);                                   \
        FAILNULL(_to); FAILNULL(_from);                         \
        (void)strncpy(_to, _from, sizeof(char)*_m);             \
        _to[_m-1] = '\0';                                      \
        /* Padding with spaces instead of nulls */              \
        for (_m -= 2; _m >= 0 && _to[_m] == '\0'; _m--) {      \
            _to[_m] = ' ';                                      \
        }                                                       \
    } while (0)


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
#ifdef __sgi
        *v = PyFloat_AsDouble(obj);
#else
        *v = PyFloat_AS_DOUBLE(obj);
#endif
        return 1;
    }
    tmp = PyNumber_Float(obj);
    if (tmp) {
#ifdef __sgi
        *v = PyFloat_AsDouble(tmp);
#else
        *v = PyFloat_AS_DOUBLE(tmp);
#endif
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = _write_sfc_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int string_from_pyobj(string *str,int *len,const string inistr,PyObject *obj,const char *errmess) {
    PyArrayObject *arr = NULL;
    PyObject *tmp = NULL;
#ifdef DEBUGCFUNCS
fprintf(stderr,"string_from_pyobj(str='%s',len=%d,inistr='%s',obj=%p)\n",(char*)str,*len,(char *)inistr,obj);
#endif
    if (obj == Py_None) {
        if (*len == -1)
            *len = strlen(inistr); /* Will this cause problems? */
        STRINGMALLOC(*str,*len);
        STRINGCOPYN(*str,inistr,*len+1);
        return 1;
    }
    if (PyArray_Check(obj)) {
        if ((arr = (PyArrayObject *)obj) == NULL)
            goto capi_fail;
        if (!ISCONTIGUOUS(arr)) {
            PyErr_SetString(PyExc_ValueError,"array object is non-contiguous.");
            goto capi_fail;
        }
        if (*len == -1)
            *len = (PyArray_ITEMSIZE(arr))*PyArray_SIZE(arr);
        STRINGMALLOC(*str,*len);
        STRINGCOPYN(*str,PyArray_DATA(arr),*len+1);
        return 1;
    }
    if (PyString_Check(obj)) {
        tmp = obj;
        Py_INCREF(tmp);
    }
#if PY_VERSION_HEX >= 0x03000000
    else if (PyUnicode_Check(obj)) {
        tmp = PyUnicode_AsASCIIString(obj);
    }
    else {
        PyObject *tmp2;
        tmp2 = PyObject_Str(obj);
        if (tmp2) {
            tmp = PyUnicode_AsASCIIString(tmp2);
            Py_DECREF(tmp2);
        }
        else {
            tmp = NULL;
        }
    }
#else
    else {
        tmp = PyObject_Str(obj);
    }
#endif
    if (tmp == NULL) goto capi_fail;
    if (*len == -1)
        *len = PyString_GET_SIZE(tmp);
    STRINGMALLOC(*str,*len);
    STRINGCOPYN(*str,PyString_AS_STRING(tmp),*len+1);
    Py_DECREF(tmp);
    return 1;
capi_fail:
    Py_XDECREF(tmp);
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = _write_sfc_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

static int float_from_pyobj(float* v,PyObject *obj,const char *errmess) {
    double d=0.0;
    if (double_from_pyobj(&d,obj,errmess)) {
        *v = (float)d;
        return 1;
    }
    return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if (tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = _write_sfc_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC_US(write_griddata,WRITE_GRIDDATA)(string,int*,int*,int*,int*,float*,float*,float*,size_t);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/******************************* write_griddata *******************************/
static char doc_f2py_rout__write_sfc_write_griddata[] = "\
write_griddata(filename,idate,fhour,grids2d,grids3d,[nlons,nlats,lsoil])\n\nWrapper for ``write_griddata``.\
\n\nParameters\n----------\n"
"filename : input string(len=-1)\n"
"idate : input rank-1 array('i') with bounds (4)\n"
"fhour : input float\n"
"grids2d : input rank-3 array('f') with bounds (nlons,nlats,32)\n"
"grids3d : input rank-4 array('f') with bounds (nlons,nlats,lsoil,3)\n"
"\nOther Parameters\n----------------\n"
"nlons : input int, optional\n    Default: shape(grids2d,0)\n"
"nlats : input int, optional\n    Default: shape(grids2d,1)\n"
"lsoil : input int, optional\n    Default: shape(grids3d,2)";
/* extern void F_FUNC_US(write_griddata,WRITE_GRIDDATA)(string,int*,int*,int*,int*,float*,float*,float*,size_t); */
static PyObject *f2py_rout__write_sfc_write_griddata(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(string,int*,int*,int*,int*,float*,float*,float*,size_t)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  string filename = NULL;
  int slen(filename);
  PyObject *filename_capi = Py_None;
  int nlons = 0;
  PyObject *nlons_capi = Py_None;
  int nlats = 0;
  PyObject *nlats_capi = Py_None;
  int lsoil = 0;
  PyObject *lsoil_capi = Py_None;
  int *idate = NULL;
  npy_intp idate_Dims[1] = {-1};
  const int idate_Rank = 1;
  PyArrayObject *capi_idate_tmp = NULL;
  int capi_idate_intent = 0;
  PyObject *idate_capi = Py_None;
  float fhour = 0;
  PyObject *fhour_capi = Py_None;
  float *grids2d = NULL;
  npy_intp grids2d_Dims[3] = {-1, -1, -1};
  const int grids2d_Rank = 3;
  PyArrayObject *capi_grids2d_tmp = NULL;
  int capi_grids2d_intent = 0;
  PyObject *grids2d_capi = Py_None;
  float *grids3d = NULL;
  npy_intp grids3d_Dims[4] = {-1, -1, -1, -1};
  const int grids3d_Rank = 4;
  PyArrayObject *capi_grids3d_tmp = NULL;
  int capi_grids3d_intent = 0;
  PyObject *grids3d_capi = Py_None;
  static char *capi_kwlist[] = {"filename","idate","fhour","grids2d","grids3d","nlons","nlats","lsoil",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOO|OOO:_write_sfc.write_griddata",\
    capi_kwlist,&filename_capi,&idate_capi,&fhour_capi,&grids2d_capi,&grids3d_capi,&nlons_capi,&nlats_capi,&lsoil_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable idate */
  idate_Dims[0]=4;
  capi_idate_intent |= F2PY_INTENT_IN;
  capi_idate_tmp = array_from_pyobj(NPY_INT,idate_Dims,idate_Rank,capi_idate_intent,idate_capi);
  if (capi_idate_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_write_sfc_error,"failed in converting 2nd argument `idate' of _write_sfc.write_griddata to C/Fortran array" );
  } else {
    idate = (int *)(PyArray_DATA(capi_idate_tmp));

  /* Processing variable filename */
  slen(filename) = -1;
  f2py_success = string_from_pyobj(&filename,&slen(filename),"",filename_capi,"string_from_pyobj failed in converting 1st argument `filename' of _write_sfc.write_griddata to C string");
  if (f2py_success) {
  /* Processing variable grids2d */
  grids2d_Dims[2]=32;
  capi_grids2d_intent |= F2PY_INTENT_IN;
  capi_grids2d_tmp = array_from_pyobj(NPY_FLOAT,grids2d_Dims,grids2d_Rank,capi_grids2d_intent,grids2d_capi);
  if (capi_grids2d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_write_sfc_error,"failed in converting 4th argument `grids2d' of _write_sfc.write_griddata to C/Fortran array" );
  } else {
    grids2d = (float *)(PyArray_DATA(capi_grids2d_tmp));

  /* Processing variable fhour */
    f2py_success = float_from_pyobj(&fhour,fhour_capi,"_write_sfc.write_griddata() 3rd argument (fhour) can't be converted to float");
  if (f2py_success) {
  /* Processing variable nlats */
  if (nlats_capi == Py_None) nlats = shape(grids2d,1); else
    f2py_success = int_from_pyobj(&nlats,nlats_capi,"_write_sfc.write_griddata() 2nd keyword (nlats) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(grids2d,1)==nlats,"shape(grids2d,1)==nlats","2nd keyword nlats","write_griddata:nlats=%d",nlats) {
  /* Processing variable nlons */
  if (nlons_capi == Py_None) nlons = shape(grids2d,0); else
    f2py_success = int_from_pyobj(&nlons,nlons_capi,"_write_sfc.write_griddata() 1st keyword (nlons) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(grids2d,0)==nlons,"shape(grids2d,0)==nlons","1st keyword nlons","write_griddata:nlons=%d",nlons) {
  /* Processing variable grids3d */
  grids3d_Dims[0]=nlons,grids3d_Dims[1]=nlats,grids3d_Dims[3]=3;
  capi_grids3d_intent |= F2PY_INTENT_IN;
  capi_grids3d_tmp = array_from_pyobj(NPY_FLOAT,grids3d_Dims,grids3d_Rank,capi_grids3d_intent,grids3d_capi);
  if (capi_grids3d_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_write_sfc_error,"failed in converting 5th argument `grids3d' of _write_sfc.write_griddata to C/Fortran array" );
  } else {
    grids3d = (float *)(PyArray_DATA(capi_grids3d_tmp));

  /* Processing variable lsoil */
  if (lsoil_capi == Py_None) lsoil = shape(grids3d,2); else
    f2py_success = int_from_pyobj(&lsoil,lsoil_capi,"_write_sfc.write_griddata() 3rd keyword (lsoil) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(grids3d,2)==lsoil,"shape(grids3d,2)==lsoil","3rd keyword lsoil","write_griddata:lsoil=%d",lsoil) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(filename,&nlons,&nlats,&lsoil,idate,&fhour,grids2d,grids3d,slen(filename));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*CHECKSCALAR(shape(grids3d,2)==lsoil)*/
  } /*if (f2py_success) of lsoil*/
  /* End of cleaning variable lsoil */
  if((PyObject *)capi_grids3d_tmp!=grids3d_capi) {
    Py_XDECREF(capi_grids3d_tmp); }
  }  /*if (capi_grids3d_tmp == NULL) ... else of grids3d*/
  /* End of cleaning variable grids3d */
  } /*CHECKSCALAR(shape(grids2d,0)==nlons)*/
  } /*if (f2py_success) of nlons*/
  /* End of cleaning variable nlons */
  } /*CHECKSCALAR(shape(grids2d,1)==nlats)*/
  } /*if (f2py_success) of nlats*/
  /* End of cleaning variable nlats */
  } /*if (f2py_success) of fhour*/
  /* End of cleaning variable fhour */
  if((PyObject *)capi_grids2d_tmp!=grids2d_capi) {
    Py_XDECREF(capi_grids2d_tmp); }
  }  /*if (capi_grids2d_tmp == NULL) ... else of grids2d*/
  /* End of cleaning variable grids2d */
    STRINGFREE(filename);
  }  /*if (f2py_success) of filename*/
  /* End of cleaning variable filename */
  if((PyObject *)capi_idate_tmp!=idate_capi) {
    Py_XDECREF(capi_idate_tmp); }
  }  /*if (capi_idate_tmp == NULL) ... else of idate*/
  /* End of cleaning variable idate */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/*************************** end of write_griddata ***************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"write_griddata",-1,{{-1}},0,(char *)F_FUNC_US(write_griddata,WRITE_GRIDDATA),(f2py_init_func)f2py_rout__write_sfc_write_griddata,doc_f2py_rout__write_sfc_write_griddata},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_write_sfc",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit__write_sfc(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_write_sfc(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _write_sfc_module = PyModule_Create(&moduledef);
#else
  m = _write_sfc_module = Py_InitModule("_write_sfc", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _write_sfc (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_write_sfc' is auto-generated with f2py (version:2).\nFunctions:\n"
"  write_griddata(filename,idate,fhour,grids2d,grids3d,nlons=shape(grids2d,0),nlats=shape(grids2d,1),lsoil=shape(grids3d,2))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  _write_sfc_error = PyErr_NewException ("_write_sfc.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_write_sfc");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif