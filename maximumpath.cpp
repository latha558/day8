#include<iostream> 
#include<climits> 
using namespace std; 
  
// infinite value 
#define INF -1  
#define N 4 

int maxCostRec(int cost[][N], int s, int d) 
{ 
    
    if (s == d || s+1 == d) 
      return cost[s][d]; 
  
    
    int max = cost[s][d]; 
  
    
    for (int i = s+1; i<d; i++) 
    { 
        int c = maxCostRec(cost, s, i) +  maxCostRec(cost, i, d); 
        cout<<s<<i<<d;
        if (c > max) 
           max = c; 
    } 
    return max; 
} 
   
int main() 
{ 
    int cost[N][N] = { {0, 15, 80, 90}, 
                      {INF, 0, 40, 50}, 
                      {INF, INF, 0, 70}, 
                      {INF, INF, INF, 0} 
                    }; 
    cout << "The Max cost  " << N << " is " << maxCostRec(cost,0,N-1); 
    return 0; 
}


  
