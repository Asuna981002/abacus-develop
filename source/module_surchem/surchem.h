#ifndef SURCHEM_H
#define SURCHEM_H

#include "../module_base/global_function.h"
#include "../module_base/global_variable.h"
#include "../module_base/matrix.h"
#include "../module_cell/unitcell.h"
#include "../src_parallel/parallel_reduce.h"
#include "../src_pw/global.h"
#include "../src_pw/pw_basis.h"
#include "../src_pw/use_fft.h"
#include "atom_in.h"

class surchem
{
  public:
    surchem();
    ~surchem();
    
    double* delta_phi;
    double* TOTN_real;
    ModuleBase::matrix Vcav;
    double qs;

    atom_in GetAtom;

    void cal_epsilon(PW_Basis &pwb, const double *PS_TOTN_real, double *epsilon, double *epsilon0);

    void cal_pseudo(const UnitCell &cell,
                           PW_Basis &pwb,
                           const complex<double> *Porter_g,
                           complex<double> *PS_TOTN);

    void gauss_charge(const UnitCell &cell, PW_Basis &pwb, complex<double> *N);

    void cal_totn(const UnitCell &cell,
                         PW_Basis &pwb,
                         const complex<double> *Porter_g,
                         complex<double> *N,
                         complex<double> *TOTN);

    ModuleBase::matrix cal_vcav(const UnitCell &ucell, PW_Basis &pwb, const complex<double> *PS_TOTN, int nspin);

    ModuleBase::matrix cal_vel(const UnitCell &cell,
                                      PW_Basis &pwb,
                                      const complex<double> *TOTN,
                                      const complex<double> *PS_TOTN,
                                      int nspin);

    double cal_Ael(const UnitCell &cell, PW_Basis &pwb);
    double cal_Acav(const UnitCell &cell, PW_Basis &pwb);

    // double cal_Ael(const UnitCell &cell, PW_Basis &pwb, const double *TOTN_real, const double *delta_phi_R);

    // double cal_Acav(const UnitCell &cell, PW_Basis &pwb, double qs);

    void minimize_cg(const UnitCell &ucell,
                            PW_Basis &pwb,
                            double *d_eps,
                            const complex<double> *tot_N,
                            complex<double> *phi,
                            int &ncgsol);

    void Leps2(const UnitCell &ucell,
                      PW_Basis &pwb,
                      complex<double> *phi,
                      double *epsilon, // epsilon from shapefunc, dim=nrxx
                      complex<double> *gradphi_x, // dim=ngmc
                      complex<double> *gradphi_y,
                      complex<double> *gradphi_z,
                      complex<double> *phi_work,
                      complex<double> *lp);

    ModuleBase::matrix v_correction(const UnitCell &cell,
                                           PW_Basis &pwb,
                                           const int &nspin,
                                           const double *const *const rho);

    void createcavity(const UnitCell &ucell, PW_Basis &pwb, const complex<double> *PS_TOTN, double *vwork);
  private:
};

#endif
