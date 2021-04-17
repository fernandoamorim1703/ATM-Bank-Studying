#ifndef ACCOUNTVECTOR_H
#define ACCOUNTVECTOR_H
#include<vector>
#include<personaccount.h>


class AccountVector
{
  private:
   static AccountVector *self;
  public:
   std::vector<PersonAccount> accounts;
  public:
   AccountVector();
   //
   inline static AccountVector *instance() {return self;}
 };

#endif // ACCOUNTVECTOR_H
