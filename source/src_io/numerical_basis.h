//==========================================================
// AUTHOR : mohan
// DATE : 2009-4-2
// Last Modify: 2009-08-28
//==========================================================
#ifndef NUMERICAL_BASIS_H
#define NUMERICAL_BASIS_H
#include "../src_pw/tools.h"
#include "bessel_basis.h"
#include <vector>
//==========================================================
// CLASS :
// NAME :  Numerical_Basis 
//==========================================================
class Numerical_Basis
{
	public:
	Numerical_Basis();
	~Numerical_Basis();

	void start_from_file_k( const int &ik, ComplexMatrix &psi);
	void output_overlap( const ComplexMatrix *psi);

	private:

	bool init_label = false;

	Bessel_Basis bessel_basis;

	std::vector<IntArray> mu_index;
	static std::vector<IntArray> init_mu_index(void);

	void numerical_atomic_wfc(const int &ik,const int &np,ComplexMatrix &psi);

	ComplexArray cal_overlap_Q(
		const int &ik, const int &np, const ComplexMatrix &psi,
		const int derivative_order ) const;
		
	ComplexArray cal_overlap_Sq(
		const int &ik, 
		const int &np,
		const int derivative_order ) const;

	static matrix cal_overlap_V(const ComplexMatrix *psi, const int derivative_order);
	
	static void output_info(
		ofstream &ofs,
		const Bessel_Basis &bessel_basis);

	static void output_k(ofstream &ofs);

	static void output_overlap_Q(
		ofstream &ofs,
		const std::vector<ComplexArray> &overlap_Q);

	static void output_overlap_Sq(
		const string &name,
		ofstream &ofs, 
		const std::vector<ComplexArray> &overlap_Sq);

	static void output_overlap_V(
		ofstream &ofs,
		const matrix &overlap_V);

};

#endif
