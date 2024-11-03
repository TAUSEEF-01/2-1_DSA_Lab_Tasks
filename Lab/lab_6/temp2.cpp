#include <bits/stdc++.h>

using namespace std;

struct Heap
{
    int arr[1000000];
    int sz = 0;

    void insert(int val)
    {
        arr[sz++] = val;
    }

    void heapify(int n, int indx)
    {
        int left_indx = indx * 2 + 1;
        int right_indx = indx * 2 + 2;

        int max_indx = indx;
        if (left_indx < n && arr[left_indx] > arr[max_indx])
        {
            max_indx = left_indx;
        }
        if (right_indx < n && arr[right_indx] > arr[max_indx])
        {
            max_indx = right_indx;
        }

        if (indx != max_indx)
        {
            int temp = arr[indx];
            arr[indx] = arr[max_indx];
            arr[max_indx] = temp;

            heapify(n, max_indx);
        }
    }

    void max_heap()
    {
        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapify(sz, i);
        }
    }

    void heap_sort()
    {
        max_heap();

        for (int i = sz - 1; i >= 0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(i, 0);
        }
    }

    void deleteNode(int num)
    {
        int pos = 0;
        for (int i = 0; i < sz; i++)
        {
            if (num == arr[i])
            {
                pos = i;
                break;
            }
        }

        int temp = arr[pos];
        arr[pos] = arr[sz - 1];
        arr[sz - 1] = temp;

        sz--;

        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapify(sz, i);
        }
    }

    int top()
    {
        return arr[sz-1];
    }

    int size()
    {
        return sz;
    }

    void make_neg()
    {
        for(int i=0; i<sz; i++)
        {
            arr[i] = -arr[i];
        }
    }

    void print_array()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int cookies(int k, vector<int> A)
{

    // int operations = 0;
    
    // // Create a max heap (priority queue) with negative values
    // priority_queue<int> p;
    // for (int cookie : A) {
    //     p.push(-cookie);
    // }
    
    // // Perform operations until the minimum element is greater than or equal to k
    // while (-p.top() < k && p.size() > 1) {
    //     int cookie1 = p.top();
    //     p.pop();
        
    //     int cookie2 = p.top();
    //     p.pop();
        
    //     int newCookie = cookie1 + 2 * cookie2;
    //     p.push(newCookie);
        
    //     operations++;
    // }
    
    // // Check if the minimum element is greater than or equal to k
    // if (-p.top() < k) 
    //     return -1; // Not possible to achieve k
    // else 
    //     return operations; // Return the number of operations

    // int n = A.size();
    // sort(A.begin(), A.end());

    // int pos = upper_bound(A.begin(), A.end(), k) - A.begin();
    // // if(pos == n)
    // // {
    // // int rem = n - pos;
    // // cout << pos << endl;
    // // for(int i=pos-1; i>0; i--)
    // // {
    // //     if()
    // // }

    // int cnt = 0;
    // int l = 0;
    // int r = pos - 1;
    // // cout << A[pos] << endl;

    // while (l < r)
    // {
    //     if (A[l] + 2 * A[r] >= k)
    //     {
    //         A[r] = -INT_MAX;
    //         A[l] = -INT_MAX;
    //         l++, r--;
    //     }
    //     else
    //     {
    //         r--;
    //     }
    // }

    // for (int i = 0; i < pos; i++)
    // {
    //     if (A[i] != -INT_MAX)
    //         cnt++;
    // }

    // return (pos - cnt == 0 ? -1 : pos - cnt);




    // int n = A.size();
    priority_queue<int> mst;

    // for (int i = 0; i < n; i++)
    for(auto &x: A)
    {
        mst.insert(x);
    }

    int cnt = 0;
    while (*mst.rbegin() < k && mst.size() > 1)
    {
        int x = *mst.rbegin();
        mst.erase(*mst.rbegin());
        int y = *mst.rbegin();
        mst.erase(*mst.rbegin());

        mst.insert(y * 2 + x);
        cnt++;
    }

    if(*mst.rbegin() < k)
        return -1;
    else 
        return cnt;

    // return (*mst.begin() < k ? -1 : cnt);














    // int n = A.size();
    // multiset<int> mst;

    // for (int i = 0; i < n; i++)
    // {
    //     mst.insert(-A[i]);
    // }

    // int cnt = 0;
    // while (-*mst.rbegin() < k && mst.size() > 1)
    // {
    //     int x = *mst.rbegin();
    //     mst.erase(*mst.rbegin());
    //     int y = *mst.rbegin();
    //     mst.erase(*mst.rbegin());

    //     mst.insert(y * 2 + x);
    //     cnt++;
    // }

    // return (-*mst.rbegin() < k ? -1 : cnt);












    // int operations = 0;
    
    // Heap *p = new Heap();
    // for (int x : A) {
    //     p->insert(x);
    // }
    // p->heap_sort();

    // p->make_neg();
    // // p->print_array();

    // // Perform operations until the minimum element is greater than or equal to k
    // // while (-p.top() < k && p.size() > 1) {
    // while(-(p->top()) < k && p->size() > 1)
    // {
    //     int c1 = p->top();
    //     p->deleteNode(c1);
        
    //     int c2 = p->top();
    //     p->deleteNode(c2);
        
    //     int c = c1 + 2 * c2;
    //     p->insert(c);
        
    //     operations++;
    // }
    
    // // Check if the minimum element is greater than or equal to k
    // if (-(p->top()) < k) 
    //     return -1; // Not possible to achieve k
    // else 
    //     return operations; // Return the number of operations


    // // // Perform operations until the minimum element is greater than or equal to k
    // // while (-p.top() < k && p.size() > 1) {
    // //     int cookie1 = p.top();
    // //     p.pop();
        
    // //     int cookie2 = p.top();
    // //     p.pop();
        
    // //     int newCookie = cookie1 + 2 * cookie2;
    // //     p.push(newCookie);
        
    // //     operations++;
    // // }
    
    // // // Check if the minimum element is greater than or equal to k
    // // if (-p.top() < k) 
    // //     return -1; // Not possible to achieve k
    // // else 
    // //     return operations; // Return the number of operations
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << cookies(k, a) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}

// int cookies(int k, vector<int>& A) {
//     int operations = 0;

//     // Create a max heap (priority queue) with negative values
//     priority_queue<int> p;
//     for (int cookie : A) {
//         p.push(-cookie);
//     }

//     // Perform operations until the minimum element is greater than or equal to k
//     while (-p.top() < k && p.size() > 1) {
//         int cookie1 = p.top();
//         p.pop();

//         int cookie2 = p.top();
//         p.pop();

//         int newCookie = cookie1 + 2 * cookie2;
//         p.push(newCookie);

//         operations++;
//     }

//     // Check if the minimum element is greater than or equal to k
//     if (-p.top() < k)
//         return -1; // Not possible to achieve k
//     else
//         return operations; // Return the number of operations
// }