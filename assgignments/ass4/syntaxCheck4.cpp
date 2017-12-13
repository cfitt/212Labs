#include "FiloTree.h"

int main()
{
  FiloTree F("second.txt");
  F.dump( );
  FiloTree G("first.txt");
  G.dump( );
  int size = F.getsize();
  FiloTree::compare(F,G,size);
  return 0;
}
