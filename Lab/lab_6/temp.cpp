#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Heap
{
    int arr[1000000];
    int sz = 0;

    multiset<int> mst;

    void insert(int val)
    {
        arr[sz++] = val;
        mst.insert(val);
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

    void min_heap(int m, int n)
    {
        int j, t;
        t = arr[m];
        j = 2 * m;
        while (j <= n)
        {
            if (j < n && arr[j + 1] < arr[j])
                j = j + 1;
            if (t < arr[j])
                break;
            else if (t >= arr[j])
            {
                arr[j / 2] = arr[j];
                j = 2 * j;
            }
        }
        arr[j / 2] = t;
        return;
    }

    void build_minheap()
    {
        int k;
        for (k = sz / 2; k >= 1; k--)
        {
            min_heap(k, sz);
        }
    }

    void deleteNode(int num)
    {
        mst.erase(*mst.find(num));

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

    int print_min()
    {
        build_minheap();
        return arr[0];
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

int main()
{
    Heap *heap = new Heap();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int v;
            cin >> v;
            heap->insert(v);
        }
        else if (x == 2)
        {
            int v;
            cin >> v;
            heap->deleteNode(v);
        }
        else
        {
            cout << heap->print_min() << endl;
        }
    }

    return 0;
}
