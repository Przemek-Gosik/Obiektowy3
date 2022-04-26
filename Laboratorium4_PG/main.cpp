#include <iostream>
#include <random>
#include <deque>
#include <ctime>
#include <algorithm>

using namespace std;
template <typename T>
void print(T tem){
cout<<tem<<" ";
};
int suma_cyfr(int num){
  int  suma=0;
  while(num>0){
    suma+=num%10;
    num=num/10;
  }
  return suma;
};
int ilosc_cyfr(int num){
    int  suma=0;
    while(num>0){
    suma++;
    num=num/10;
  }
  return suma;


}
int main()
{
    mt19937 milf(time(NULL));
    uniform_int_distribution<int> distance(1,25);
    uniform_int_distribution<int> dist(-100,100);
    uniform_int_distribution<int> dist2(0,3999);
    int n=distance(milf);
    deque<int> d;
    for(int i=0;i<n;i++){
        int wylosowana=dist(milf);
        if(wylosowana>=0){
            d.push_front(wylosowana);
        }
        else{
            d.push_back(wylosowana);
        }
    }

    for_each(d.begin(),d.end(),print<int>);
    cout<<endl<<"--------------"<<endl;
    vector<int> wektor;
    for(int i=0;i<n;i++){
        int x=dist2(milf);
        wektor.push_back(x);
    }
    for_each(wektor.begin(),wektor.end(),print<int>);
    cout<<endl;
    sort(wektor.begin(),wektor.end(),[](int a,int b){return suma_cyfr(a)<suma_cyfr(b);});
    for_each(wektor.begin(),wektor.end(),print<int>);
    cout<<endl;
    sort(wektor.begin(),wektor.end(),[](int a,int b){return ilosc_cyfr(a)>ilosc_cyfr(b);});
    for_each(wektor.begin(),wektor.end(),print<int>);
    return 0;
}
