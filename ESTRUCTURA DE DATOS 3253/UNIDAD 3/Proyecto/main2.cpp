#include<bits/stdc++.h>
using namespace std;

long long n,m,i,l,r,mid,ans,tmp,cnt,haha;
long long ar[2621440];
long long func(long long x){
    haha = 0;
    for (i = 0; i < n; i++) haha += x/ar[i];
    return haha;
}

int main()
{
    cin >> n >> m;
    for(i = 0; i < n; i++) cin >> ar[i];
    sort(ar,ar+n);
    l = ar[0];
    r = ar[0]*m;
    mid = (l+r)/2;
    tmp = func(mid);
    while (tmp != m){
        mid = (l+r)/2;
        tmp = func(mid);
        if (l == r) break;
        if (tmp < m) l = mid+1;
        else if (tmp > m) r = mid-1;
        else break;
    }
    ans = 0;
    if (tmp == m) ans += 1;
    cnt = mid;
    while (func(cnt-1) == m){
        ans += 1;
        cnt -= 1;
    }
    cnt = mid;
    while (func(cnt+1) == m){
        ans += 1;
        cnt += 1;
    }
    cout << ans << endl;
}
