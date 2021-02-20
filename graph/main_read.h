#include <python3.6/Python.h>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

string readModuleTest(char const *module_name, int const a, int const b) {
	PyObject *pName, *pModule, *pFunc;
	PyObject *pArgs, *pValue;
	int i;

	Py_Initialize();
	PyRun_SimpleString("import sys, os");
	PyRun_SimpleString("sys.path.append(\".\")");
	//PyRun_SimpleString("print(sys.path)");

	pName = PyUnicode_DecodeFSDefault(module_name);
	printf("[S] PyUnicode_DecodeFSDefault.\n");
	/* Error checking of pName left out */

	pModule = PyImport_Import(pName);
	printf("[S] PyImport_Import.\n");
	Py_DECREF(pName);
	printf("[S] Py_DECREF.\n");

	if (pModule == NULL) {
		PyErr_Print();
		fprintf(stderr, "Failed to load \"%s\"\n", module_name);
		return "1";
	} else {
		printf("pFunc DONE.\n");
		pFunc = PyObject_GetAttrString(pModule, module_name);
        /* pFunc is a new reference */
		printf("pFunc DONE.\n");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
			PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));
                /* pValue reference stolen here: */
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            printf("pValue DONE.\n");
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return "1";
            }
	}
	if (Py_FinalizeEx() < 0) {
		return "120";
	}
	return "0";
}
