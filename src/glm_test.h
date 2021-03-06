#ifndef _GLM_H_
#define _GLM_H_



extern "C" {
/* Family */
#define NEGBIN    0
#define BINOMIAL  1
#define POISSON   2
#define GAUSSIAN  3
#define GAMMA     4

/* Link */
#define LOGIT     1
#define LOG       2
#define IDENTITY  3
#define INVERSE   4

/* GLM definition functions */
  int wcenter(const double *y, int n, const double *weight, const int *stratum, int nstrata, int resid, double *ynew);
  int wresid(const double *y, int n, const double *weight, const double *x, double *ynew);
  
  double wssq(const double *y, int n, const double *weight);
  double varfun(int, double, double);
  int muvalid(int, double, double);
  double linkfun(int, double);
  double invlink(int, double);
  double dlink(int, double);
  double loglik(int ,const double  *y, double *fitted, const double *prior, double );
  
  

/* Fit a base model */

  int glm_fit(int family, int link, int N, int M, int S,
	    const double *y, const double *prior, const double * offset, const double *X, 
	    const int *stratum, int maxit, double conv, int init, 
	    int *rank, double *Xb, 
	    double *fitted, double *resid, double *weights, 
	    double *scale, int *df_resid, double theta);
  

  int glm_nb(int N, int M, int S,
	    const double *y, const double *prior, const double * offset, const double *X, 
	    const int *stratum, int maxit, double conv, int init, 
	    int *rank, double *Xb, 
	    double *fitted, double *resid, double *weights, 
	    double *scale, int *df_resid, double *Rtheta);

/*Maximum likelihood estimation of theta*/
  double theta_ml(int N, double n, const double *y, double *mu, const double *prior, int maxit);
}
#endif
