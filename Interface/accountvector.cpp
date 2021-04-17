#include "accountvector.h"


AccountVector *AccountVector::self=0;

AccountVector::AccountVector()
 {
  AccountVector::self=this;
 }

