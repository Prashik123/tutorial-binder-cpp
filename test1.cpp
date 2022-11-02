#include<bits/stdc++.h>
using namespace std;
#define ll long double
int main()
{   
    //file handling
    ofstream fout;
    fout.open("my.dat");
    
    ll n,r;
    cout<<"dimention of grid : ";
    cin>>n;
    vector<vector<ll>>fi(n,vector<ll>(n,0));
    cout<<"radius : ";
    cin>>r;
    ll x0 = n/2;
    ll y0 = n/2;

    
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
           if((i-x0)*(i-x0)+(j-y0)*(j-y0)<=r*r)
                fi[i][j]=1;
        }
    }
    cout<<"time "<<"0 pe:"<<endl;
    fout<<"time "<<"0 pe:"<<endl;
    for(ll i=0;i<n;i++)
     {
        for(ll j=0;j<n;j++)
        {
            cout<<fi[i][j]<<" ";
           
            fout<<i<<" "<<j<<" "<<fi[i][j]<<endl;
        }
        cout<<endl;
     }
    
     cout<<endl;
    //H=1 , k=2;
    //dx = dy =1;
    //dt =1
    // time interval 1
    
    //LHS
    ll H,k,G,dx,dy,dt;
    cout<<"Value of H :";
    cin>>H;
    cout<<"Value of k :";
    cin>>k;
    cout<<"Value of G :";
    cin>>G;
    cout<<"Value of dx :";
    cin>>dx;
    cout<<"Value of dy:";
    cin>>dy;

    for(ll time=1;time<10;time++)
    { cout<<"time "<<time<<"pe:"<<endl;
      fout<<"time"<<time<<"pe:"<<endl;
     for(ll i=1;i<n-1;i++)
     {
        for(ll j=1;j<n-1;j++)
        {
             ll term1,term2;
             term1 = (-4*H)*fi[i][j]*(1-fi[i][j]*fi[i][j]);

             term2 = k*((fi[i+1][j]-2*fi[i][j]+fi[i-1][j])/(dx*dx)+(fi[i][j+1]-2*fi[i][j]+fi[i][j-1])/(dy*dy));
             // gama = 1
             ll lhs = (-G)*(term1 - term2);
             // update fi as a time changes
             dt=0.1;
             fi[i][j] = lhs*dt + fi[i][j];
        }
     }
     for(ll i=0;i<n;i++)
     {
        for(ll j=0;j<n;j++)
        {
            cout<<fi[i][j]<<" ";
             fout<<i<<" "<<j<<" "<<fi[i][j]<<endl;
        }
        cout<<endl;
     }
     cout<<endl;

    }
     fout.close();
    
    
}