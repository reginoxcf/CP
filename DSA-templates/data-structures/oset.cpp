#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// in contest, this can also be replaced with segment / fenwick tree + walk on tree + number compression (if needed)
// set a tree saving number of elements
