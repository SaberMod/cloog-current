#ifndef CLOOG_POLYLIB_DOMAIN_H
#define CLOOG_POLYLIB_DOMAIN_H
#if defined(__cplusplus)
extern "C" 
  {
#endif 

/* The Polyhedron structure comes directly from PolyLib (defined in
 * polylib/types.h) here is how it looks like (at least in PolyLib 5.20.0
 * version).
 *
 * typedef struct polyhedron { 
 *   unsigned Dimension,      // Dimension number (NbColumns-2 in Matrix).
 *            NbConstraints,  // Number of constraints (NbRows in Matrix).
 *            NbRays,         // Number of rays in dual representation.
 *            NbEq,           // Number of equalities.
 *            NbBid;          // Number of bidirectional rays.
 *   Value **Constraint;      // The pointers to rows in matrix representation.
 *   Value **Ray;             // The pointers to rays in dual representation.
 *   Value *p_Init;           // The whole data, consecutive in memory.
 *   int p_Init_size;         // To clear values in GMP mode.
 *   struct polyhedron *next; // Pointer to next component of the union.
 * } Polyhedron;
 */ 


/**
 * CloogDomain structure:
 * this structure contains a polyhedron in the PolyLib shape and the number of
 * active references to this structure. Because CLooG uses many copies of
 * domains there is no need to actually copy these domains but just to return
 * a pointer to them and to increment the number of active references. Each time
 * a CloogDomain will be freed, we will decrement the active reference counter
 * and actually free it if its value is zero.
 */
struct cloogdomain
{ Polyhedron * polyhedron ;      /**< The polyhedral domain. */
  int references ;               /**< Number of references to this structure. */
} ;
typedef struct cloogdomain CloogDomain ;

/******************************************************************************
 *                              PolyLib interface                             *
 ******************************************************************************/
CloogDomain * cloog_domain_alloc(Polyhedron *) ;
CloogDomain * cloog_domain_matrix2domain(Matrix *) ;
Matrix      * cloog_domain_domain2matrix(CloogDomain *) ;
CloogDomain * cloog_domain_image(CloogDomain *, Matrix *) ;
CloogDomain * cloog_domain_preimage(CloogDomain *, Matrix *) ;
void          cloog_polyhedron_print(FILE *, Polyhedron *) ;

/******************************************************************************
 *                            Processing functions                            *
 ******************************************************************************/
CloogDomain * cloog_domain_malloc(void);
CloogDomain * cloog_domain_bounds(CloogDomain * domain, int dim, int nb_par);

#define cloog_domain_polyhedron(x)    (x)->polyhedron
#define cloog_domain_nbconstraints(x) (x)->polyhedron->NbConstraints
/*
Polyhedron  * cloog_domain_polyhedron(CloogDomain *) ;
int           cloog_domain_nbconstraints(CloogDomain *) ;
int           cloog_domain_isconvex(CloogDomain *) ;
*/  


#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
