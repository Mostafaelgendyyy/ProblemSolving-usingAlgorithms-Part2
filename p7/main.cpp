#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int arr[100000], Count[100000], Freq[100000], f[100000];
long long ans[100000];
vector<int> v;

class query {
    int l, r, id, k;
public:
    int getL() const {
        return l;
    }

    void setL(int l) {
        query::l = l;
    }

    int getR() const {
        return r;
    }

    void setR(int r) {
        query::r = r;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        query::id = id;
    }

    int getK() const {
        return k;
    }

    void setK(int k) {
        query::k = k;
    }
};


bool Compare2Queries(query a, query b) {
    if(a.getK() < b.getK() || (a.getK() == b.getK() && a.getR() < b.getR()))
        return true;
    return false;
}

void Update(int position, int val) {
    Freq[Count[position]]--;
    Count[position] += val;
    Freq[Count[position]]++;
}

int main() {
    query Queries[100000];
    int Num, m;
    cin >> Num;
    int size = sqrt(Num) + 1;
    for (int i = 1; i <= Num; i++) {
        cin >> arr[i];
        Count[arr[i]]++;
        if (Count[arr[i]] == size) {
            v.push_back(arr[i]);
        }
    }
    cin>>m;
    for (int i = 1; i <= m; i++) {
        int l,r;
        cin>> l >> r ;
        Queries[i].setL(l);
        Queries[i].setR(r);
        Queries[i].setId(i); Queries[i].setK(Queries[i].getL() / size);
    }
    sort(Queries + 1, Queries + m + 1, Compare2Queries);
    int l = 1;
    int r = 0;
    memset(reinterpret_cast<wchar_t *>(Count), 0, sizeof(Count));
    Freq[0] = Num;
    int k;
    for (int i = 1; i <= m; i++) {
        for (int j=1; l < Queries[i].getL(); j++) {
            Update(arr[l], -1);
            l++;
        }
        while (l != Queries[i].getL()) {
            l--;
            Update(arr[l], 1);
        }
        for (;r > Queries[i].getR();--r){
            Update(arr[r], -1);
        }
        while (r < Queries[i].getR()){
            r++;
            Update(arr[r], 1);
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        memcpy(f, Freq, sizeof(int) * (size + 5));
        ans[Queries[i].getId()] = 0;
        for (int j = 0; j < v.size(); j++) if (Count[v[j]] >= size) pq.push(Count[v[j]]);
        int last = 0;
        for (int j = 1; j < size; j++) {
            if (f[j] > 0) {
                if (last) {
                    f[j]--; ans[Queries[i].getId()] += (long long)(last + j);
                    if (last + j < size) f[last + j]++; else pq.push(last + j);
                    last = 0;
                }
                if (f[j] % 2 == 1) f[j]--, last = j;
                ans[Queries[i].getId()] += f[j] * j;
                if (2 * j >= size)
                    for (k = 1; k <= f[j] / 2; k++) pq.push(j * 2);
                else f[j * 2] += f[j] / 2;
            }
        }
        if (last) {
            pq.push(last);
        }
        while (pq.size() != 1) {
            int b = pq.top(); pq.pop();
            int c = pq.top(); pq.pop();
            ans[Queries[i].getId()] += (long long)(b + c);
            pq.push(b + c);
        }
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}