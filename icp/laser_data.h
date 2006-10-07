#ifndef H_LASER_DATA
#define H_LASER_DATA

#include <gsl/gsl_vector.h>

struct correspondence {
	int valid; 
	int j1; int j2;
};

struct laser_data {
	int nrays;
	double  min_theta;
	double  max_theta;
	double *readings;
	double *theta;
	
	int *cluster;
	
	double *alpha;
	double *cov_alpha;
	int *alpha_valid;
	
	/* Jump tables */
	int *up_bigger, *up_smaller, *down_bigger, *down_smaller;

	/* Cartesian points */
	gsl_vector**p;
	
	struct correspondence* corr;
};

#define LDP   struct laser_data*

void ld_alloc(LDP, int nrays);
void ld_free(LDP);

void ld_compute_cartesian(LDP);
void ld_create_jump_tables(LDP);
int  ld_valid_ray(LDP, int i);
// -1 if not found
int ld_next_valid(LDP ld, int i, int dir);


int ld_valid_corr(LDP, int i);
void ld_set_correspondence(LDP, int i, int j1, int j2);
void ld_set_null_correspondence(LDP, int i);
/** -1 if not found */
int ld_next_valid_up(LDP, int i);
int ld_next_valid_down(LDP, int i);

void ld_simple_clustering(LDP ld, double threshold);
void ld_compute_orientation(LDP ld, int size_neighbourhood);

#endif

