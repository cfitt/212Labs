#ifndef GATEWAY_NODE_H
#define GATEWAY_NODE_H

#include "dataNode.h"
#include <string>
using namespace std;

class GatewayNode {
  private:
    const char key;
    GatewayNode *left, *right;
    DataNode *data;
  public:
    GatewayNode(const string &s) 
                     : key(s[0]), left(0), right(0), data(new DataNode(s,0)) 
    {
    }
  friend class GiggleTree;  
};

#endif

