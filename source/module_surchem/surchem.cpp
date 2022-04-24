#include "surchem.h"

surchem::surchem()
{
    delta_phi = new double[GlobalC::pw.nrxx];
    TOTN_real = new double[GlobalC::pw.nrxx];
    qs = 0;
}

surchem::~surchem()
{
    delete[] delta_phi;
    delete[] TOTN_real;
}