#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>
#include "getQuadSolutions.h"
#include "getSqrt.h"

double cunit_dmacheps;

void test_root(void){
	double sqrt1 = getSqrt(9);
	double sqrt2 = getSqrt(4);

	printf("Sqrt of 9\n");
	CU_ASSERT_DOUBLE_EQUAL(3, sqrt1, cunit_dmacheps);
	printf("Sqrt of 4\n");
	CU_ASSERT_DOUBLE_EQUAL(2, sqrt2, cunit_dmacheps);	
}

void test_quad_solution(void){
	double coefs[3];    
	double* roots;
	double x1, x2;
 
	x1 = 3.1;
	x2 = 3.3;
	coefs[0] = 1.0;
	coefs[1] = -x1 + -x2;
	coefs[2] = x1 * x2;
 
	roots = getQuadSolutions(coefs);
 
	printf("X1\n");
	CU_ASSERT_DOUBLE_EQUAL(x1, roots[0], cunit_dmacheps);
	printf("X2\n");
	CU_ASSERT_DOUBLE_EQUAL(x2, roots[1], cunit_dmacheps);
}


int cunit_init_suite(void){
	double dm;	
	double dmacheps = 0.5;

	while((1.0 + (dm = dmacheps/2.0) ) != 1.0){
		dmacheps = dm;

	}
	cunit_dmacheps = dmacheps;
	return 0;
}

int clean_suite(void){
	return 0;
}

int main(){
	CU_pSuite pSuite = NULL;
	

	if(CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	pSuite = CU_add_suite("Suite", cunit_init_suite, clean_suite);
	if(NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if((NULL == CU_add_test(pSuite, "test quad solution()", test_quad_solution)) ||
		   	(NULL == CU_add_test(pSuite, "test of sqrt()", test_root)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	
	return CU_get_error();
}
