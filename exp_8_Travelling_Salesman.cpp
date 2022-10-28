#include <iostream>
using namespace std;
#define n 4
int costMatrix[][n] = {INT_MAX,10,15,20,10,INT_MAX,35,25,15,35,INT_MAX,30,20,25,30,INT_MAX};
// int costMatrix[][n] = {INT_MAX,4,1,3,4,INT_MAX,2,1,1,2,INT_MAX,5,3,1,5,INT_MAX};
int cost = 0;
int path[n],k=1;
bool checkpath(int c){
    for(int i=0;i<k;i++)
    if(path[i]==c)
    return false;
    return true;
}
void findpath(int j){
    int min = INT_MAX,ind;
    for(int i=0;i<n;i++)
    if(costMatrix[i][j]<min&&checkpath(i))
    {min = costMatrix[i][j];ind = i;}
    if(min==INT_MAX)
    min = costMatrix[0][j];
    cost+=min;
    
    costMatrix[ind][j]=INT_MAX;
    path[k++]=ind;
    //cout<<min<<"-";
}
void solve(){
    path[0] = 0;
    int j;
    for(j=0;j<n;j++)
    findpath(path[j]);

}
int main(){
    cout<<"\nYour Cost Matrix is:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        if(costMatrix[i][j]==INT_MAX)
        cout<<0<<" ";
        else
        cout<<costMatrix[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    
    solve();
    
    cout<<"\nThe Minimum Cost to Travel is: "<<cost<<"\n\nAnd the path is: ";

    for(int j=0;j<n;j++)
    cout<<path[j]+1<<"->";
    cout<<1;
    return 0;
}